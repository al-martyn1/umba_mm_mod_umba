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
                   , iterator_type         &b
                   , iterator_type         &e
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

    bool flushTokenBuffer(TokenizerType &tokenizer, messages_string_type &msg, iterator_type &b, iterator_type &e, bool bClear=true)
    {
        if (!nextTokenHandler)
            return true;

        for(const auto &tki : tokenBuffer)
        {
            auto tmpB = tki.b;
            auto tmpE = tki.e;
            if (!nextTokenHandler(tokenizer, tki.lineStartFlag, tki.payloadToken, tmpB, tmpE, tki.parsedData /*strValue*/, msg))
            {
                if (bClear)
                   clearTokenBuffer();
                b = tmpB;
                e = tmpE;
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
                   , iterator_type         &b
                   , iterator_type         &e
                   , token_parsed_data     parsedData // std::variant<...>
                   , messages_string_type  &msg
                   )
    {
        if (payloadToken==UMBA_TOKENIZER_TOKEN_CTRL_FIN)
        {
            bool res = this->flushTokenBuffer(tokenizer, msg, b, e);
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
            if (!this->flushTokenBuffer(tokenizer, msg, b, e)) // сбрасываем буферизированное (с очисткой буфера)
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

    State st                          = stNormal;
    bool  isStartAngleBracketOperator = false;
    bool  inDefine                    = false; //TODO: !!! Вообще, по уму, надо бы сделать энум со значениями inDefine, inPragma, inError, inWarning, inCondition

    token_handler_type     nextTokenHandler;


    static
    auto makePreprocessorKeywords()
    {
        std::unordered_map<string_type, payload_type> m;
        m[string_plus::make_string<string_type>("include")]             = UMBA_TOKENIZER_TOKEN_CC_PP_INCLUDE | UMBA_TOKENIZER_TOKEN_CTRL_FLAG;
        m[string_plus::make_string<string_type>("define")]              = UMBA_TOKENIZER_TOKEN_CC_PP_DEFINE  | UMBA_TOKENIZER_TOKEN_CTRL_FLAG;
        m[string_plus::make_string<string_type>("undef")]               = UMBA_TOKENIZER_TOKEN_CC_PP_UNDEF;

        m[string_plus::make_string<string_type>("line")]                = UMBA_TOKENIZER_TOKEN_CC_PP_LINE;

        m[string_plus::make_string<string_type>("error")]               = UMBA_TOKENIZER_TOKEN_CC_PP_ERROR  ;
        m[string_plus::make_string<string_type>("warning")]             = UMBA_TOKENIZER_TOKEN_CC_PP_WARNING;

        m[string_plus::make_string<string_type>("pragma")]              = UMBA_TOKENIZER_TOKEN_CC_PP_PRAGMA;

        m[string_plus::make_string<string_type>("if")]                  = UMBA_TOKENIZER_TOKEN_CC_PP_IF;
        m[string_plus::make_string<string_type>("elif")]                = UMBA_TOKENIZER_TOKEN_CC_PP_ELIF;
        m[string_plus::make_string<string_type>("else")]                = UMBA_TOKENIZER_TOKEN_CC_PP_ELSE;
        m[string_plus::make_string<string_type>("endif")]               = UMBA_TOKENIZER_TOKEN_CC_PP_ENDIF;
        m[string_plus::make_string<string_type>("ifdef")]               = UMBA_TOKENIZER_TOKEN_CC_PP_IFDEF;
        m[string_plus::make_string<string_type>("ifndef")]              = UMBA_TOKENIZER_TOKEN_CC_PP_IFNDEF;
        m[string_plus::make_string<string_type>("elifdef")]             = UMBA_TOKENIZER_TOKEN_CC_PP_ELIFDEF;
        m[string_plus::make_string<string_type>("elifndef")]            = UMBA_TOKENIZER_TOKEN_CC_PP_ELIFNDEF;

        m[string_plus::make_string<string_type>("defined")]             = UMBA_TOKENIZER_TOKEN_CC_PP_DEFINED;
        m[string_plus::make_string<string_type>("__has_include")]       = UMBA_TOKENIZER_TOKEN_CC_PP_HAS_INCLUE;
        m[string_plus::make_string<string_type>("__has_cpp_attribute")] = UMBA_TOKENIZER_TOKEN_CC_PP_HAS_CPP_ATTRIBUTE;

        m[string_plus::make_string<string_type>("export")]              = UMBA_TOKENIZER_TOKEN_CC_PP_EXPORT;
        m[string_plus::make_string<string_type>("import")]              = UMBA_TOKENIZER_TOKEN_CC_PP_IMPORT;
        m[string_plus::make_string<string_type>("module")]              = UMBA_TOKENIZER_TOKEN_CC_PP_MODULE;

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

    bool reset(TokenizerType &tokenizer, bool res=true)
    {
        restoreAngleBracketsAndHashState(tokenizer);

        st                          = stNormal;
        isStartAngleBracketOperator = false;
        inDefine                    = false;

        return res;
    }

    void restoreAngleBracketsAndHashState(TokenizerType &tokenizer)
    {
        if (isStartAngleBracketOperator)
        {
            // Устанавливаем признак оператора обратно
            tokenizer.setResetCharClassFlags('<', umba::tokenizer::CharClass::opchar, umba::tokenizer::CharClass::none);
        }

        // Ничего не устанавливаем, сбрасываем string_literal_prefix
        tokenizer.setResetCharClassFlags('<', umba::tokenizer::CharClass::none, umba::tokenizer::CharClass::string_literal_prefix);

        tokenizer.setResetCharClassFlags('#', umba::tokenizer::CharClass::none, umba::tokenizer::CharClass::opchar); // Ничего не устанавливаем, сбрасываем opchar
    }



public:

    UMBA_RULE_OF_FIVE(CcPreprocessorFilter, default, default, default, default, default);

    CcPreprocessorFilter(token_handler_type curTokenHandler)
    : nextTokenHandler(curTokenHandler)
    {}

    bool operator()( TokenizerType         &tokenizer
                   , bool                  lineStartFlag
                   , payload_type          payloadToken
                   , iterator_type         &b
                   , iterator_type         &e
                   , token_parsed_data     parsedData // std::variant<...>
                   , messages_string_type  &msg
                   )
    {

        switch(st)
        {
            case stNormal:
            {
                if (payloadToken==UMBA_TOKENIZER_TOKEN_CTRL_FIN)
                {
                    //restoreAngleBracketsAndHashState(tokenizer);

                    if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData, msg))
                        return reset(tokenizer, false);
                    return reset(tokenizer, true);
                }

                if (lineStartFlag && b!=e && *b==(value_type)'#')
                {
                    reset(tokenizer);

                    if (!nextTokenHandler(tokenizer, lineStartFlag, UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_START, e, e, typename TokenizerType::EmptyData() /* strValue */ , msg))
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
                if (payloadToken==UMBA_TOKENIZER_TOKEN_CTRL_FIN)
                {
                    return reset(tokenizer, false);
                }

                if (payloadToken==UMBA_TOKENIZER_TOKEN_IDENTIFIER)
                {
                    st = stPreprocessor;

                    payload_type ppKewordId = getPreprocessorKeywordToken(string_type(tokenizer.makeStringView(b,e)));

                    if (ppKewordId!=payload_invalid)
                    {
                        if (ppKewordId&UMBA_TOKENIZER_TOKEN_CTRL_FLAG)
                        {
                            // Сигналим контрольным
                            if (!nextTokenHandler(tokenizer, lineStartFlag, ppKewordId, e, e, typename TokenizerType::EmptyData(), msg))
                                return false;
                        }

                        if (ppKewordId==UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_INCLUDE)
                        {
                            // Запоминаем предыдущее состояние символа '<' - opchar или нет
                            isStartAngleBracketOperator = (tokenizer.getCharClass('<') & umba::tokenizer::CharClass::opchar) != 0;

                            // устанавливаем string_literal_prefix, сбрасываем opchar
                            tokenizer.setResetCharClassFlags('<', umba::tokenizer::CharClass::string_literal_prefix, umba::tokenizer::CharClass::opchar);
                        }
                        else if (ppKewordId==UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_DEFINE)
                        {
                            // устанавливаем opchar, ничего не сбрасываем - # и ## - годные операторы внутри define'а
                            tokenizer.setResetCharClassFlags('#', umba::tokenizer::CharClass::opchar, umba::tokenizer::CharClass::none);
                            inDefine = true;
                        }

                        if (ppKewordId&UMBA_TOKENIZER_TOKEN_CTRL_FLAG)
                        {
                            // Сбрасываем флаг контрольного токена
                            ppKewordId &= ~UMBA_TOKENIZER_TOKEN_CTRL_FLAG;
                        }

                        // Пуляем найденным токеном
                        if (!nextTokenHandler(tokenizer, lineStartFlag, ppKewordId, b, e, typename TokenizerType::EmptyData() /* strValue */ , msg)) // Сигналим про дефайн
                            return false;
                    }
                    else
                    {
                        if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg)) // пробрасываем токен какой получили
                            return false;
                    }

                    return true;
                }
                else if (payloadToken==UMBA_TOKENIZER_TOKEN_CTRL_FIN || payloadToken==UMBA_TOKENIZER_TOKEN_LINEFEED)
                {
                    reset(tokenizer);

                    if (!nextTokenHandler(tokenizer, lineStartFlag, UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_END, e, e, typename TokenizerType::EmptyData() /* strValue */ , msg))
                        return false;

                    if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg)) // пробрасываем токен
                        return false;

                    return true;
                }

                break;
            }

            case stPreprocessor:
            {
                if (payloadToken==UMBA_TOKENIZER_TOKEN_CTRL_FIN || payloadToken==UMBA_TOKENIZER_TOKEN_LINEFEED)
                {
                    reset(tokenizer);

                    if (!nextTokenHandler(tokenizer, lineStartFlag, UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_END, e, e, typename TokenizerType::EmptyData() /* strValue */ , msg))
                        return false;

                    if (!nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg)) // пробрасываем токен
                        return false;

                    return true;
                }

                // Внутри дефайнов нет никаких ключевых слов
                if (inDefine)
                {
                    break;
                }

                // У нас что-то кроме дефайна

                // И у нас пришел идентификатор
                // Мы либо в условных операторах, либо всякие прагмы и прочий трэш. В трэше ключевые слова вроде не используются, поэтому пока по-простому

                if (payloadToken==UMBA_TOKENIZER_TOKEN_IDENTIFIER)
                {
                    payload_type ppKewordId = getPreprocessorKeywordToken(string_type(tokenizer.makeStringView(b,e)));

                    if ( TheValue(ppKewordId).oneOf( UMBA_TOKENIZER_TOKEN_CC_PP_DEFINED
                                                   , UMBA_TOKENIZER_TOKEN_CC_PP_HAS_INCLUE
                                                   , UMBA_TOKENIZER_TOKEN_CC_PP_HAS_CPP_ATTRIBUTE
                                                   )
                       )
                    {
                        return nextTokenHandler(tokenizer, lineStartFlag, ppKewordId, b, e, parsedData /* strValue */ , msg);
                    }
                    else
                    {
                        return nextTokenHandler(tokenizer, lineStartFlag, payloadToken, b, e, parsedData /* strValue */ , msg);
                    }
                }

                break;
            }

        } // switch(st)

        if (payloadToken==UMBA_TOKENIZER_TOKEN_CTRL_FIN)
        {
            reset(tokenizer);
            //st = stNormal;
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



