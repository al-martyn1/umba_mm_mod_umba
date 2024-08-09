#pragma once

#ifndef UMBA_TOKENIZER_H__DCAEEDE0_7624_4E47_9919_08460EF65A3B__
    #error "Do not include this file directly, include 'umba/tokenizer.h header instead'"
#endif

#include "umba/warnings/push_disable_rel_inc_contains_dbldot.h"
#include "../rule_of_five.h"
#include "umba/warnings/pop.h"

/*

Фильтры инсталлируются в токенизер в начало цепочки.
Для этого у tokenizer'а есть шаблонный метод:

  template<typename FilterType, typename... FilterTypeArgs >
  void installTokenFilter( FilterTypeArgs... args)

Мы не передаём экземпляр фильтра в installTokenFilter, мы его создаём внутри метода installTokenFilter,
и передаём параметры для инициализации в метод installTokenFilter

Сам фильтр должен иметь конструктор

  Filter(Tokenizer::token_handler_type prevHandler, FilterTypeArgs... args )

Схематоз такой: сначала добавляется финальный обработчик, затем добавляются фильтры в цепочку обработчиков,
в начало, при этом существующий обработчик вставляется после добавляемого.



template< typename CharType            // Input chars type
        , typename CharClassTableType  = std::array<CharClass, 128>
        , typename TrieVectorType      = std::vector<TrieNode>
        , typename StringType          = std::basic_string<CharType>  // Тип строки, которая хранит входные символы
        , typename MessagesStringType  = std::string  // Тип строки, которая используется для сообщений (в том числе и от внешних суб-парсеров)
        , typename InputIteratorType   = umba::iterator::TextPositionCountingIterator<CharType>
        >


using token_handler_type                         = std::function<bool( bool
                                                                     , payload_type
                                                                     , InputIteratorType
                                                                     , InputIteratorType
                                                                     , std::basic_string_view<value_type>
                                                                     , messages_string_type&)
                                                                     >;

TokenFilter должен
а) создаваться в изначальном готовом для работы начальном состоянии
б) по токену FIN должны сбрасываться все буфера, и фильтр должен врзвращаться в начальное состояние

*/

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// umba::tokenizer::filters::
namespace umba {
namespace tokenizer {
namespace filters {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Тестовый фильтр, который ничего не делает
template<typename TokenizerType>
struct SimplePassTroughFilter
{

    using token_handler_type       = typename TokenizerType::token_handler_type;

    using char_type                = typename TokenizerType::char_type            ;
    using value_type               = typename TokenizerType::value_type           ;
    using char_class_table_type    = typename TokenizerType::char_class_table_type;
    using trie_vector_type         = typename TokenizerType::trie_vector_type     ;
    using string_type              = typename TokenizerType::string_type          ;
    using iterator_type            = typename TokenizerType::iterator_type        ;
    using messages_string_type     = typename TokenizerType::messages_string_type ;
    using payload_type             = umba::tokenizer::payload_type                ;
    using token_parsed_data        = typename TokenizerType::token_parsed_data     ;


protected:

    token_handler_type nextTokenHandler;


public:

    SimplePassTroughFilter(token_handler_type curTokenHandler)
    : nextTokenHandler(curTokenHandler)
    {}

    UMBA_RULE_OF_FIVE(SimplePassTroughFilter, default, default, default, default, default);

    bool operator()( bool                                 lineStartFlag
                   , payload_type                         payloadToken
                   , iterator_type                        b
                   , iterator_type                        e
                   , token_parsed_data                    parsedData // std::basic_string_view<value_type>   strValue
                   , messages_string_type                 &msg
                   )
    {
        if (nextTokenHandler)
            return nextTokenHandler(lineStartFlag, payloadToken, b, e, parsedData, msg);
        return true;
    }

}; // struct SimplePassTroughFilter

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Хранит информацию для вызова tokenHandler'а
template<typename TokenizerType>
struct TokenInfo
{
    using token_handler_type       = typename TokenizerType::token_handler_type;

    using char_type                = typename TokenizerType::char_type            ;
    using value_type               = typename TokenizerType::value_type           ;
    using char_class_table_type    = typename TokenizerType::char_class_table_type;
    using trie_vector_type         = typename TokenizerType::trie_vector_type     ;
    using string_type              = typename TokenizerType::string_type          ;
    using iterator_type            = typename TokenizerType::iterator_type        ;
    //using messages_string_type     = typename TokenizerType::messages_string_type ;
    using payload_type             = umba::tokenizer::payload_type                ;
    using token_parsed_data        = typename TokenizerType::token_parsed_data    ;

    bool                                 lineStartFlag;
    payload_type                         payloadToken;
    iterator_type                        b;
    iterator_type                        e;
    // std::basic_string_view<value_type>   strValue;
    token_parsed_data                    parsedData;

    UMBA_RULE_OF_FIVE(TokenInfo, default, default, default, default, default);

    TokenInfo( bool                                 lineStartFlag_
             , payload_type                         payloadToken_
             , iterator_type                        b_
             , iterator_type                        e_
             , token_parsed_data                    parsedData_ // std::basic_string_view<value_type>   strValue_
             )
    : lineStartFlag(lineStartFlag_)
    , payloadToken(payloadToken_)
    , b(b_)
    , e(e_)
    //, strValue(strValue_)
    , parsedData(parsedData_)
    {}

}; // struct TokenInfo

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Предоставляет функционал буферизации токенов
/*! Возможно, тут стоит использовать boost::small_vector.
    Хотя, он тоже лезет в кучу, а единожды увеличившийся стандартный вектор не склонен к уменьшению объема
    аллоцированной памяти, если не вызывать shrink_to_fit
 */
template<typename TokenizerType, typename VectorType=std::vector<TokenInfo<TokenizerType> > >
struct FilterBase
{

    using token_handler_type       = typename TokenizerType::token_handler_type;

    using char_type                = typename TokenizerType::char_type            ;
    using value_type               = typename TokenizerType::value_type           ;
    using char_class_table_type    = typename TokenizerType::char_class_table_type;
    using trie_vector_type         = typename TokenizerType::trie_vector_type     ;
    using string_type              = typename TokenizerType::string_type          ;
    using iterator_type            = typename TokenizerType::iterator_type        ;
    using messages_string_type     = typename TokenizerType::messages_string_type ;
    using payload_type             = umba::tokenizer::payload_type                ;
    using token_parsed_data        = typename TokenizerType::token_parsed_data     ;


protected:

    token_handler_type     nextTokenHandler;
    VectorType             tokenBuffer;

    void clearTokenBuffer()
    {
        tokenBuffer.clear();
    }

    bool flushTokenBuffer(messages_string_type &msg, bool bClear=true)
    {
        if (!nextTokenHandler)
            return true;

        for(const auto &tki : tokenBuffer)
        {
            if (!nextTokenHandler(tki.lineStartFlag, tki.payloadToken, tki.b, tki.e, tki.parsedData /*strValue*/, msg))
            {
                if (bClear)
                   clearTokenBuffer();
                return false;
            }
        }

        if (bClear)
           clearTokenBuffer();

        return true;
    }

    void reset()
    {
        clearTokenBuffer();
    }


public:

    UMBA_RULE_OF_FIVE(FilterBase, default, default, default, default, default);

    FilterBase(token_handler_type curTokenHandler)
    : nextTokenHandler(curTokenHandler)
    {}

}; // struct FilterBase

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename TokenizerType, typename VectorType=std::vector<TokenInfo<TokenizerType> > >
struct SimpleNumberSuffixGluing : FilterBase<TokenizerType, VectorType>
{
    using TBase = FilterBase<TokenizerType, VectorType>;

    using token_handler_type       = typename TBase::token_handler_type;

    using char_type                = typename TBase::char_type            ;
    using value_type               = typename TBase::value_type           ;
    using char_class_table_type    = typename TBase::char_class_table_type;
    using trie_vector_type         = typename TBase::trie_vector_type     ;
    using string_type              = typename TBase::string_type          ;
    using iterator_type            = typename TBase::iterator_type        ;
    using messages_string_type     = typename TBase::messages_string_type ;
    using payload_type             = umba::tokenizer::payload_type        ;
    using token_parsed_data        = typename TBase::token_parsed_data    ;


    UMBA_RULE_OF_FIVE(SimpleNumberSuffixGluing, default, default, default, default, default);

    SimpleNumberSuffixGluing(token_handler_type curTokenHandler)
    : TBase(curTokenHandler)
    {}

    static
    bool isNumberLiteral(payload_type payloadToken)
    {
        return payloadToken>=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST && payloadToken<=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_LAST;
    }

    bool operator()( bool                                 lineStartFlag
                   , payload_type                         payloadToken
                   , iterator_type                        b
                   , iterator_type                        e
                   , token_parsed_data                    parsedData // std::basic_string_view<value_type>   strValue
                   , messages_string_type                 &msg
                   )
    {
        if (payloadToken==UMBA_TOKENIZER_TOKEN_FIN)
        {
            bool res = this->flushTokenBuffer(msg);
            // https://stackoverflow.com/questions/9941987/there-are-no-arguments-that-depend-on-a-template-parameter
            // https://web.archive.org/web/20130423054841/http://www.agapow.net/programming/cpp/no-arguments-that-depend-on-a-template-parameter
            this->reset();
            return res;
        }

        if (this->tokenBuffer.empty())
        {
            if (isNumberLiteral(payloadToken))
            {
                this->tokenBuffer.emplace_back(lineStartFlag, payloadToken, b, e, parsedData /* strValue */ );
                return true;
            }
            else
            {
                return this->nextTokenHandler(lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg);
            }
        }
        else // в буфере лежит токен числового литерала
        {
            if (payloadToken==UMBA_TOKENIZER_TOKEN_IDENTIFIER) // Если после числового токена идёт идентификатор - это число с суффиксом
            {
                UMBA_ASSERT(!this->tokenBuffer.empty());
                bool res = this->nextTokenHandler(this->tokenBuffer[0].lineStartFlag, this->tokenBuffer[0].payloadToken, this->tokenBuffer[0].b, e, parsedData /* strValue */ , msg);
                this->clearTokenBuffer();
                return res;
                //tokenBuffer[0]
            }
            else // после числового токена идёт хз что
            {
                if (!this->flushTokenBuffer(msg)) // сбрасываем буферизированное (с очисткой буфера)
                {
                     return false;
                }

                // прокидываем текущий токен
                return this->nextTokenHandler(lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg);
            }
        }

    }

}; // struct SimpleNumberSuffixGluing

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

} // namespace filters
} // namespace tokenizer
} // namespace umba



