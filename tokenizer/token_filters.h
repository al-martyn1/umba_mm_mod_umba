#pragma once

#ifndef UMBA_TOKENIZER_H__DCAEEDE0_7624_4E47_9919_08460EF65A3B__
    #error "Do not include this file directly, include 'umba/tokenizer.h header instead'"
#endif

#include "umba/warnings/push_disable_rel_inc_contains_dbldot.h"
#include "../rule_of_five.h"
#include "../string_plus.h"
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
#define UMBA_TOKENIZER_TOKEN_FILTERS_DECLARE_USING_DEPENDENT_TYPES(className)              \
            using token_handler_type       = typename className ::token_handler_type   ;   \
                                                                                           \
            using char_type                = typename className ::char_type            ;   \
            using value_type               = typename className ::value_type           ;   \
            using char_class_table_type    = typename className ::char_class_table_type;   \
            using trie_vector_type         = typename className ::trie_vector_type     ;   \
            using string_type              = typename className ::string_type          ;   \
            using iterator_type            = typename className ::iterator_type        ;   \
            using messages_string_type     = typename className ::messages_string_type ;   \
            using token_parsed_data        = typename className ::token_parsed_data


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

    UMBA_TOKENIZER_TOKEN_FILTERS_DECLARE_USING_DEPENDENT_TYPES(TokenizerType);
    using payload_type             = umba::tokenizer::payload_type                ;

protected:

    token_handler_type nextTokenHandler;


public:

    SimplePassTroughFilter(token_handler_type curTokenHandler)
    : nextTokenHandler(curTokenHandler)
    {}

    UMBA_RULE_OF_FIVE(SimplePassTroughFilter, default, default, default, default, default);

    bool operator()( TokenizerType         &tokenizer
                   , bool                  lineStartFlag
                   , payload_type          payloadToken
                   , iterator_type         b
                   , iterator_type         e
                   , token_parsed_data     parsedData // std::variant<...>
                   , messages_string_type  &msg
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
    UMBA_TOKENIZER_TOKEN_FILTERS_DECLARE_USING_DEPENDENT_TYPES(TokenizerType);
    using payload_type             = umba::tokenizer::payload_type                ;


    bool                                 lineStartFlag;
    payload_type                         payloadToken;
    iterator_type                        b;
    iterator_type                        e;
    // std::basic_string_view<value_type>   strValue;
    token_parsed_data                    parsedData;

    UMBA_RULE_OF_FIVE(TokenInfo, default, default, default, default, default);

    TokenInfo( bool               lineStartFlag_
             , payload_type       payloadToken_
             , iterator_type      b_
             , iterator_type      e_
             , token_parsed_data  parsedData_ // std::variant<...>
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
    UMBA_TOKENIZER_TOKEN_FILTERS_DECLARE_USING_DEPENDENT_TYPES(TokenizerType);
    using payload_type             = umba::tokenizer::payload_type                ;

protected:

    token_handler_type     nextTokenHandler;
    VectorType             tokenBuffer;

    void clearTokenBuffer()
    {
        tokenBuffer.clear();
    }

    bool flushTokenBuffer(TokenizerType &tokenizer, messages_string_type &msg, bool bClear=true)
    {
        if (!nextTokenHandler)
            return true;

        for(const auto &tki : tokenBuffer)
        {
            if (!nextTokenHandler(tokenizer, tki.lineStartFlag, tki.payloadToken, tki.b, tki.e, tki.parsedData /*strValue*/, msg))
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
struct SimpleSuffixGluingFilter : FilterBase<TokenizerType, VectorType>
{
    using TBase = FilterBase<TokenizerType, VectorType>;

    UMBA_TOKENIZER_TOKEN_FILTERS_DECLARE_USING_DEPENDENT_TYPES(TBase);
    using payload_type             = umba::tokenizer::payload_type        ;

    UMBA_RULE_OF_FIVE(SimpleSuffixGluingFilter, default, default, default, default, default);


    enum class GluingOption
    {
        glueAll,
        glueNumbers,
        glueStrings
    };

    GluingOption gluingOption = GluingOption::glueAll;


    SimpleSuffixGluingFilter(token_handler_type curTokenHandler, GluingOption gOpt=GluingOption::glueAll)
    : TBase(curTokenHandler), gluingOption(gOpt)
    {}


protected:

    static
    bool isNumberLiteral(payload_type payloadToken)
    {
        return payloadToken>=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST && payloadToken<=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_LAST;
    }

    static
    bool isStringLiteral(payload_type payloadToken)
    {
        return payloadToken>=UMBA_TOKENIZER_TOKEN_STRING_LITERAL_FIRST && payloadToken<=UMBA_TOKENIZER_TOKEN_STRING_LITERAL_LAST;
    }

    const
    bool glueNumbers() const
    {
        return gluingOption==GluingOption::glueAll || gluingOption==GluingOption::glueNumbers;
    }

    const
    bool glueStrings() const
    {
        return gluingOption==GluingOption::glueAll || gluingOption==GluingOption::glueStrings;
    }


public:

    bool operator()( TokenizerType         &tokenizer
                   , bool                  lineStartFlag
                   , payload_type          payloadToken
                   , iterator_type         b
                   , iterator_type         e
                   , token_parsed_data     parsedData // std::variant<...>
                   , messages_string_type  &msg
                   )
    {
        if (payloadToken==UMBA_TOKENIZER_TOKEN_FIN)
        {
            bool res = this->flushTokenBuffer(tokenizer, msg);
            // https://stackoverflow.com/questions/9941987/there-are-no-arguments-that-depend-on-a-template-parameter
            // https://web.archive.org/web/20130423054841/http://www.agapow.net/programming/cpp/no-arguments-that-depend-on-a-template-parameter
            this->reset();
            return res;
        }

        if (this->tokenBuffer.empty())
        {
            if (isNumberLiteral(payloadToken) && glueNumbers()) // Если числовой литерал и разрешено приклеивать к ним суффиксы
            {
                this->tokenBuffer.emplace_back(lineStartFlag, payloadToken, b, e, parsedData /* strValue */ );
                return true;
            }
            else if (isStringLiteral(payloadToken) && glueStrings()) // Если строковый литерал и разрешено приклеивать к ним суффиксы
            {
                this->tokenBuffer.emplace_back(lineStartFlag, payloadToken, b, e, parsedData /* strValue */ );
                return true;
            }
            else
            {
                return this->nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg);
            }
        }

        // В буфере что-то есть

        if (payloadToken!=UMBA_TOKENIZER_TOKEN_IDENTIFIER) // Что у нас пришло?
        {
            // У нас пришел не идентификатор, значит, склейка не состоится
            if (!this->flushTokenBuffer(tokenizer, msg)) // сбрасываем буферизированное (с очисткой буфера)
                 return false;

            // Пробрасываем пришедшее на текущем шаге
            return this->nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg);
        }


        // в буфере лежит токен числового литерала
        
        UMBA_ASSERT(!this->tokenBuffer.empty()); // точно ли ы буфере что-то есть?
        TokenInfo prevTokenInfo = this->tokenBuffer[0]; // инфа по числовому или строковому литералу
        UMBA_ASSERT(prevTokenInfo.e==b); // Начало текущего токена должно совпадать с концом предыдущего

        auto literalStartIter = prevTokenInfo.b;
        auto suffixStartIter  = prevTokenInfo.e; // началом суффикса является конец числового литерала
        auto literalEndIter   = e;

        auto updatePayloadDataAndCallNextHandler = [&](auto payloadData) -> bool
        {
            payloadData.hasSuffix      = true;
            payloadData.suffixStartPos = suffixStartIter;
            return this->nextTokenHandler( tokenizer, prevTokenInfo.lineStartFlag, prevTokenInfo.payloadToken
                                         , literalStartIter, literalEndIter, payloadData, msg
                                         );
        };
        

        bool res = true;

        if (isNumberLiteral(prevTokenInfo.payloadToken))
        {
            if (prevTokenInfo.payloadToken&UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
            {
                res = updatePayloadDataAndCallNextHandler(std::get<typename TokenizerType::FloatNumericLiteralData>(prevTokenInfo.parsedData));
            }
            else
            {
                res = updatePayloadDataAndCallNextHandler(std::get<typename TokenizerType::IntegerNumericLiteralData>(prevTokenInfo.parsedData));
            }
        }
        else if (isStringLiteral(prevTokenInfo.payloadToken))
        {
            res = updatePayloadDataAndCallNextHandler(std::get<typename TokenizerType::StringLiteralData>(prevTokenInfo.parsedData));
        }
        else
        {
            UMBA_ASSERT(0);
        }

        this->clearTokenBuffer();
        return res;

    }

}; // struct SimpleSuffixGluingFilter

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Вставляет маркеры начала и конца C/C++ препроцессора. Не требует буферизации, так что FilterBase не нужен
/*! Возможно, тут стоит использовать boost::small_vector.
    Хотя, он тоже лезет в кучу, а единожды увеличившийся стандартный вектор не склонен к уменьшению объема
    аллоцированной памяти, если не вызывать shrink_to_fit
 */
template<typename TokenizerType >
struct CcPreprocessorFilter
{
    UMBA_TOKENIZER_TOKEN_FILTERS_DECLARE_USING_DEPENDENT_TYPES(TokenizerType);
    using payload_type             = umba::tokenizer::payload_type           ;

protected:

    enum State
    {
        stNormal,
        stWaitPreprocessorKeyword,
        stPreprocessor
    };

    State st = stNormal;

    token_handler_type     nextTokenHandler;


    static
    auto makePreprocessorKeywords()
    {
        std::unordered_map<string_type, payload_type> m;
        m[string_plus::make_string<string_type>("define")]  = UMBA_TOKENIZER_TOKEN_PP_DEFINE;
        m[string_plus::make_string<string_type>("include")] = UMBA_TOKENIZER_TOKEN_PP_INCLUDE;
        return m;
    }

    static
    const auto& getPreprocessorKeywords()
    {
        static auto m = makePreprocessorKeywords();
        return m;
    }
    
    static
    payload_type getPreprocessorKeywordToken(const string_type &ident)
    {
        const auto& m = getPreprocessorKeywords();
        auto it = m.find(ident);
        if (it==m.end())
            return payload_invalid;
        return it->second;
    }

    //

public:

    UMBA_RULE_OF_FIVE(CcPreprocessorFilter, default, default, default, default, default);

    CcPreprocessorFilter(token_handler_type curTokenHandler)
    : nextTokenHandler(curTokenHandler)
    {}

    bool operator()( TokenizerType         &tokenizer
                   , bool                  lineStartFlag
                   , payload_type          payloadToken
                   , iterator_type         b
                   , iterator_type         e
                   , token_parsed_data     parsedData // std::variant<...>
                   , messages_string_type  &msg
                   )
    {


        switch(st)
        {
            case stNormal:
            {
                if (lineStartFlag && b!=e && *b==(value_type)'#')
                {
                    if (!nextTokenHandler(tokenizer, lineStartFlag, UMBA_TOKENIZER_TOKEN_PP_START, e, e, typename TokenizerType::EmptyData() /* strValue */ , msg))
                        return false;
                    if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg))
                        return false;
                    st = stWaitPreprocessorKeyword;
                    return true;
                }

                break;
            }

            case stWaitPreprocessorKeyword:
            {
                if (payloadToken==UMBA_TOKENIZER_TOKEN_IDENTIFIER)
                {
                    st = stPreprocessor;

                    if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg)) // Сначала пробрасываем токен
                        return false;

                    payload_type ppKewordId = getPreprocessorKeywordToken(string_type(tokenizer.makeStringView(b,e)));
                    if (ppKewordId!=payload_invalid)
                    {
                        if (!nextTokenHandler(tokenizer, lineStartFlag, ppKewordId, e, e, typename TokenizerType::EmptyData() /* strValue */ , msg)) // Сигналим про дефайн
                            return false;
                    }

                    //  
                    // auto idStrView = tokenizer.makeStringView(b,e);
                    // if (idStrView==string_plus::make_string<string_type>("define"))

                    return true;
                }
                else if (payloadToken==UMBA_TOKENIZER_TOKEN_FIN || payloadToken==UMBA_TOKENIZER_TOKEN_LINEFEED)
                {
                    if (!nextTokenHandler(tokenizer, lineStartFlag, UMBA_TOKENIZER_TOKEN_PP_END, e, e, typename TokenizerType::EmptyData() /* strValue */ , msg))
                        return false;

                    if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg)) // пробрасываем токен
                        return false;

                    st = stNormal;

                    return true;
                }

                break;
            }

            case stPreprocessor:
            {
                if (payloadToken==UMBA_TOKENIZER_TOKEN_FIN || payloadToken==UMBA_TOKENIZER_TOKEN_LINEFEED)
                {
                    if (!nextTokenHandler(tokenizer, lineStartFlag, UMBA_TOKENIZER_TOKEN_PP_END, e, e, typename TokenizerType::EmptyData() /* strValue */ , msg))
                        return false;

                    if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg)) // пробрасываем токен
                        return false;

                    st = stNormal;

                    return true;
                }

                break;
            }

        } // switch(st)

        if (payloadToken==UMBA_TOKENIZER_TOKEN_FIN)
        {
            st = stNormal;
        }
        
        // прокидываем текущий токен
        return nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg);
    
    }


}; // struct CcPreprocessorFilter

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

} // namespace filters
} // namespace tokenizer
} // namespace umba



