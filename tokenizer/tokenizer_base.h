#pragma once

#ifndef UMBA_TOKENIZER_H__DCAEEDE0_7624_4E47_9919_08460EF65A3B__
    #error "Do not include this file directly, include 'umba/tokenizer.h header instead'"
#endif

#include "../the.h"

//----------------------------------------------------------------------------
// umba::tokenizer::
namespace umba {
namespace tokenizer {




//----------------------------------------------------------------------------
struct TokenizerOptions
{
    bool  singleLineCommentOnlyAtBeginning = false;
    bool  processLineContinuation          = true ;  // '\' before line feed marks next line to be continuation of current line
    bool  numbersAllowDigitsSeparator      = true ;  // apos ' (39/0x27) only can be used
    int   numberDefaultBase                = 10;     // Система счисления по умолчанию, применяется, когда не был указан префикс, явно задающий систему счисления.

};

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
enum class TokenizerInternalState
{
    stInitial              = 0,
    stReadSpace               ,
    stReadIdentifier          ,
    stReadNumberPrefix        ,
    stReadNumber              ,
    stReadNumberFloat         ,
    stReadNumberMayBeFloat    ,
    stReadOperator            ,
    stReadSingleLineComment   ,
    stReadMultilineLineComment,
    stReadStringLiteral       ,
    stContinuationWaitLinefeed

};

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
#if !defined(UMBA_TOKENIZER_DISABLE_TYPES_META)
template<typename StringType>
StringType getTokenizerInternalStateStr(TokenizerInternalState s)
{
    switch(s)
    {
        case TokenizerInternalState::stInitial                 : return umba::string_plus::make_string<StringType>("Initial");
        case TokenizerInternalState::stReadSpace               : return umba::string_plus::make_string<StringType>("ReadSpace");
        case TokenizerInternalState::stReadIdentifier          : return umba::string_plus::make_string<StringType>("ReadIdentifier");
        case TokenizerInternalState::stReadNumberPrefix        : return umba::string_plus::make_string<StringType>("ReadNumberPrefix");
        case TokenizerInternalState::stReadNumber              : return umba::string_plus::make_string<StringType>("ReadNumber");
        case TokenizerInternalState::stReadNumberFloat         : return umba::string_plus::make_string<StringType>("ReadNumberFloat");
        case TokenizerInternalState::stReadNumberMayBeFloat    : return umba::string_plus::make_string<StringType>("ReadNumberMayBeFloat");
        case TokenizerInternalState::stReadOperator            : return umba::string_plus::make_string<StringType>("ReadOperator");
        case TokenizerInternalState::stReadSingleLineComment   : return umba::string_plus::make_string<StringType>("ReadSingleLineComment");
        case TokenizerInternalState::stReadMultilineLineComment: return umba::string_plus::make_string<StringType>("ReadMultilineLineComment");
        case TokenizerInternalState::stReadStringLiteral       : return umba::string_plus::make_string<StringType>("ReadStringLiteral");
        case TokenizerInternalState::stContinuationWaitLinefeed: return umba::string_plus::make_string<StringType>("ContinuationWaitLinefeed");

        default:                         return umba::string_plus::make_string<StringType>("<UNKNOWN>");
    }
};

template<typename StringType>
StringType getTokenizerTokenStr(payload_type p)
{
    switch(p)
    {
        case UMBA_TOKENIZER_TOKEN_UNEXPECTED                       : return umba::string_plus::make_string<StringType>("<UNEXPECTED>");
        case UMBA_TOKENIZER_TOKEN_LINEFEED                         : return umba::string_plus::make_string<StringType>("LINEFEED");
        case UMBA_TOKENIZER_TOKEN_SPACE                            : return umba::string_plus::make_string<StringType>("SPACE");
        case UMBA_TOKENIZER_TOKEN_IDENTIFIER                       : return umba::string_plus::make_string<StringType>("IDENTIFIER");
        case UMBA_TOKENIZER_TOKEN_SEMIALPHA                        : return umba::string_plus::make_string<StringType>("SEMIALPHA");
        case UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_OPEN               : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_CLOSE              : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_OPEN               : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_CLOSE              : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_OPEN               : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_CLOSE              : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_OPEN              : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_CLOSE             : return umba::string_plus::make_string<StringType>("KIND_OF_BRACKET");
        case UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_START: return umba::string_plus::make_string<StringType>("COMMENT_START");
        case UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_END  : return umba::string_plus::make_string<StringType>("COMMENT_END");
        //case : return umba::string_plus::make_string<StringType>("");
        default:

            if (p>=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST && p<=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_LAST)
            {
                if (p&UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
                    return umba::string_plus::make_string<StringType>("KIND_OF_FLOAT_NUMBER");
                else
                    return umba::string_plus::make_string<StringType>("KIND_OF_NUMBER");
            }

            if (p>=UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST && p<=UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_LAST)
                return umba::string_plus::make_string<StringType>("KIND_OF_SINGLE_LINE_COMMENT");

            if (p>=UMBA_TOKENIZER_TOKEN_NUMBER_USER_LITERAL_FIRST && p<=UMBA_TOKENIZER_TOKEN_NUMBER_USER_LITERAL_LAST)
                return umba::string_plus::make_string<StringType>("KIND_OF_NUMBER");

            if (p>=UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST && p<=UMBA_TOKENIZER_TOKEN_OPERATOR_LAST)
                return umba::string_plus::make_string<StringType>("KIND_OF_OPERATOR");

            if (p>=UMBA_TOKENIZER_TOKEN_STRING_LITERAL_FIRST && p<=UMBA_TOKENIZER_TOKEN_STRING_LITERAL_LAST)
                return umba::string_plus::make_string<StringType>("KIND_OF_STRING_LITERAL");

            return umba::string_plus::make_string<StringType>("");
    }
};
#endif // !defined(UMBA_TOKENIZER_DISABLE_TYPES_META)
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
template< typename TBase
        , typename CharType            // Input chars type
        , typename CharClassTableType  = std::array<CharClass, 128>
        , typename TrieVectorType      = std::vector<TrieNode>
        , typename StringType          = std::basic_string<CharType>  // Тип строки, которая хранит входные символы
        , typename MessagesStringType  = std::string  // Тип строки, которая используется для сообщений (в том числе и от внешних суб-парсеров)
        , typename InputIteratorType   = umba::iterator::TextPositionCountingIterator<CharType>
        >
class TokenizerBaseImpl
{

//------------------------------
public: // depending types

    using char_type                = CharType;
    using value_type               = CharType;
    using char_class_table_type    = CharClassTableType;
    using trie_vector_type         = TrieVectorType;
    using string_type              = StringType;
    using iterator_type            = InputIteratorType;
    using messages_string_type     = MessagesStringType;

    using ITokenizerLiteralParser  = umba::tokenizer::ITokenizerLiteralParser<CharType, MessagesStringType, InputIteratorType>;


//------------------------------
public: // ctors and op=

    TokenizerBaseImpl() = default;
    TokenizerBaseImpl(const TokenizerBaseImpl &) = delete;
    TokenizerBaseImpl& operator=(const TokenizerBaseImpl &) = delete;
    TokenizerBaseImpl(TokenizerBaseImpl &&) = default;
    TokenizerBaseImpl& operator=(TokenizerBaseImpl &&) = default;


//------------------------------
protected: // internal types

    using TokenizerLiteralCharStringInserter  = umba::tokenizer::TokenizerLiteralCharStringInserter<CharType, StringType>;


//------------------------------
protected: // fileds

    CharClassTableType    charClassTable;

    TrieVectorType        numbersTrie   ;
    TrieVectorType        bracketsTrie  ;
    TrieVectorType        operatorsTrie ;
    TrieVectorType        literalsTrie  ;

    StringType            multiLineCommentEndStr;

    TokenizerOptions      options; // Не являются состоянием, обычно задаются в начале, и никогда не меняются


//------------------------------
protected: // fileds - состояние токенизатора

    mutable TokenizerInternalState st            = TokenizerInternalState::stInitial;
    mutable TokenizerInternalState stEscapeSaved = TokenizerInternalState::stInitial;

    mutable bool curPosAtLineBeginning = true;

    // Общее
    mutable InputIteratorType      tokenStartIt;

    // Операторы
    mutable trie_index_type        operatorIdx = trie_index_invalid;

    // Числовые литералы
    mutable payload_type           numberTokenId         = 0;
    mutable int                    numberExplicitBase    = 0;
    mutable trie_index_type        numberPrefixIdx       = trie_index_invalid;
    mutable payload_type           numberReadedDigits    = 0;
    mutable CharClass              allowedDigitCharClass = CharClass::none;
    mutable int                    numbersBase           = 0;

    // Коментарии
    mutable InputIteratorType      commentStartIt;
    mutable payload_type           commentTokenId = 0;

    // Строковые литералы
    mutable ITokenizerLiteralParser*            pCurrentLiteralParser = 0;
    mutable payload_type                        literalTokenId = 0;
    mutable MessagesStringType                  externHandlerMessage;
    mutable TokenizerLiteralCharStringInserter  stringLiteralValueCollector;



//------------------------------
protected: // methods


//------------------------------
public: // methods

    void setCharClassTable( const CharClassTableType &cht)
    {
        UMBA_ASSERT(cht.size()>=128);
        charClassTable = cht;
    }

    // charClassTable может модифицироваться, и тогда она составляет часть состояния токенизатора.
    // Если его надо сохранять, то charClassTable надо сохранять вручную, потому что по умолчанию сохранять
    // в состоянии всю charClassTable слишком жирно. Пользователь может сохранять лишь те элементы, которые
    // модифицировал сам.
    CharClassTableType getCharClassTable() const { return charClassTable; }

    //! Возвращает предыдущее состояние флагов
    umba::tokenizer::CharClass setResetCharClassFlags(CharType ch, umba::tokenizer::CharClass setFlags, umba::tokenizer::CharClass clrFlags)
    {
        std::size_t idx = umba::tokenizer::charToCharClassTableIndex(ch); // clamp 127
        UMBA_ASSERT(idx<charClassTable);

        auto res = charClassTable[idx];
        charClassTable[idx] |=  setFlags;
        charClassTable[idx] &= ~clrFlags;
        return res;
    }

    //! Возвращает предыдущее состояние флагов
    umba::tokenizer::CharClass invertCharClassFlags(CharType ch, umba::tokenizer::CharClass invertFlags)
    {
        std::size_t idx = umba::tokenizer::charToCharClassTableIndex(ch); // clamp 127
        UMBA_ASSERT(idx<charClassTable);

        auto res = charClassTable[idx];
        charClassTable[idx] ^=  invertFlags;
        return res;
    }

    umba::tokenizer::CharClass getCharClass(CharType ch) const
    {
        std::size_t idx = umba::tokenizer::charToCharClassTableIndex(ch); // clamp 127
        UMBA_ASSERT(idx<charClassTable);
        return charClassTable[idx];
    }

    umba::tokenizer::CharClass setCharClass(CharType ch, umba::tokenizer::CharClass cls)
    {
        std::size_t idx = umba::tokenizer::charToCharClassTableIndex(ch); // clamp 127
        UMBA_ASSERT(idx<charClassTable);
        std::swap(cls, charClassTable[idx]);
        return cls;
    }

    // Конец многострочного коментария ищется тупо как текст, поэтому он не входит в operatorsTrie (в отличие от начала)
    void setMultiLineCommentEndString(const StringType s) { multiLineCommentEndStr = s; }

    void setNumbersTrie  (const TrieVectorType &tv) { numbersTrie   = tv; }
    void setBracketsTrie (const TrieVectorType &tv) { bracketsTrie  = tv; }
    void setOperatorsTrie(const TrieVectorType &tv) { operatorsTrie = tv; }
    void setLiteralsTrie (const TrieVectorType &tv) { literalsTrie  = tv; }


    // Если у нас standalone токенизер, а не был получен из TokenizerBuilder, то
    // в указателях (которые лежат в payloadExtra) либо мусор, либо нули. Надо туда
    // установить актуальные указатели на парсеры строковых литералов
    // literalsTrie и charClass'ы соответствующих символов должны быть корректно установлены

    bool setLiteralParser(const StringType &strLiteralPrefix, ITokenizerLiteralParser* pParser, payload_type strLiteralPrefixTokenId)
    {
        UMBA_ASSERT(pParser);
        UMBA_ASSERT(!strLiteralPrefix.empty());

        auto tokenIdx = tokenTrieTraverse(literalsTrie, strLiteralPrefix.begin(), strLiteralPrefix.end());
        UMBA_ASSERT(tokenIdx!=trie_index_invalid); // Префикс должен быть в дереве

        // Флаг string_literal_prefix должен быть установлен у первого символа в последовательности префикса, мы по нему детектим префикс
        UMBA_ASSERT(umba::TheFlags(getCharClass(strLiteralPrefix[0])).oneOf(CharClass::string_literal_prefix));

        literalsTrie[tokenIdx].payloadExtra = reinterpret_cast<umba::tokenizer::payload_type>(pParser);
    }


//------------------------------
protected: // methods - helpers - из "грязного" проекта, где я наговнякал первую версию, выносим лямбды.

    //NOTE: !!! Надо ли semialpha проверять, не является ли она началом числового префикса? Наверное, не помешает

    void performStartReadingNumberLambda(CharType ch, InputIteratorType it) const
    {
        tokenStartIt = it;
        numberPrefixIdx = tokenTrieFindNext(numbersTrie, trie_index_invalid, (token_type)ch);
        numberTokenId = 0;
        numberReadedDigits = 0;
        numberExplicitBase = 0;
        if (numberPrefixIdx!=trie_index_invalid) // Найдено начало префикса числа
        {
            st = TokenizerInternalState::stReadNumberPrefix;
            allowedDigitCharClass = CharClass::digit; // Потом всё равно зададим, после определения префикса
            numbersBase = 0;
        }
        else
        {
            st = TokenizerInternalState::stReadNumber;
            numbersBase = options.numberDefaultBase;
            allowedDigitCharClass = CharClass::digit;
            if (utils::isNumberHexDigitsAllowed(numbersBase))
                allowedDigitCharClass |= CharClass::xdigit;
        }
    }

    bool performStartReadingOperatorLambda(CharType ch, InputIteratorType it) const
    {
        tokenStartIt = it;
        operatorIdx = tokenTrieFindNext(operatorsTrie, trie_index_invalid, (token_type)ch);
        if (operatorIdx==trie_index_invalid)
            return false;
        st = TokenizerInternalState::stReadOperator;
        return true;
    };

    bool performProcessBracketLambda(CharType ch, InputIteratorType it) const
    {
        auto idx = tokenTrieFindNext(bracketsTrie, trie_index_invalid, (token_type)ch);
        if (idx==trie_index_invalid)
            return false;
        parsingHandlerLambda(bracketsTrie[idx].payload, it, it+1); // выплюнули
        st = TokenizerInternalState::stInitial;
        return true;
    };

    bool processCommentStartFromNonCommentedLambda(payload_type curPayload, InputIteratorType it) const
    {
        // tokenStartIt - указывает на начало оператора, в данном случае - оператора коментария
        // входной итератор it - указывает на позицию сразу после оператора

        commentTokenId = curPayload;

        if (utils::isSingleLineCommentToken(curPayload))
        {
            if (options.singleLineCommentOnlyAtBeginning && !curPosAtLineBeginning)
            {
                // Error? Or process as regular operator?
                //UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FLAG_AS_REGULAR_OPERATOR
                parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FLAG_AS_REGULAR_OPERATOR|commentTokenId, tokenStartIt, it); // выплюнули как обычный оператор
                st = TokenizerInternalState::stInitial;
                return true;
            }
            //tokenStartIt   = it;
            commentStartIt = it; // Сохранили начало коментария без самого оператора начала коментария - текст коментария потом выдадим по окончании
            st = TokenizerInternalState::stReadSingleLineComment;
            operatorIdx = trie_index_invalid;
            return true;
        }
        else if (utils::isMultiLineCommentStartToken(curPayload))
        {
            //tokenStartIt   = it; // А тут бы надо оставить начало оператора !!!
            commentStartIt = it; // Сохранили начало коментария без самого оператора начала коментария - текст коментария потом выдадим по окончании
            st = TokenizerInternalState::stReadMultilineLineComment;
            operatorIdx = trie_index_invalid;
            // commentNestingLevel = 1; // Один вход сделали тут !!! Вложенные коментарии не поддерживаются
            return true;
        }
        else // коментарий, но не однострочный, и не начало многострочного - ошибка
        {
            return false;
        }
    };

    void processEscapeSymbolLambda(InputIteratorType it) const
    {
        if (options.processLineContinuation)
        {
            tokenStartIt = it;
            stEscapeSaved = st;
            st = TokenizerInternalState::stContinuationWaitLinefeed;
        }
        else
        {
            parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_ESCAPE, it, it+1); // выплюнули
            st = TokenizerInternalState::stInitial;
        }
    };

    // ITokenizerLiteralParser*            pCurrentLiteralParser = 0;
    // payload_type                        literalTokenId = 0;
    // MessagesStringType                  externHandlerMessage;
    // TokenizerLiteralCharStringInserter  stringLiteralValueCollector;
    //
    // ITokenizerLiteralParser

    ITokenizerLiteralParser* checkIsLiteralPrefix(InputIteratorType it, InputIteratorType end, payload_type &literalToken) const
    {
        if (it==end)
            return 0;

        auto idx = tokenTrieFindFirst(literalsTrie, *it);
        for(; idx!=trie_index_invalid && it!=end; ++it)
        {
            auto nextIdx = tokenTrieFindNext(literalsTrie, idx, *it);
            if (nextIdx==trie_index_invalid) // Дошли до конца, проверяем предыдущий индекс
            {
                if (literalsTrie[idx].payload==payload_invalid)
                    return 0;
                literalToken = literalsTrie[idx].payload;
                auto pParser = reinterpret_cast<ITokenizerLiteralParser*>(literalsTrie[idx].payloadExtra);
                if (pParser)
                {
                    pParser->reset();
                    stringLiteralValueCollector.clear();
                }
                return pParser;
            }

            idx = nextIdx;
        }

        return 0;
    };


public: // methods - методы собственно разбора


// enum class TokenizerInternalState
// {
//     stInitial              = 0,
//     stReadSpace               ,
//     stReadIdentifier          ,
//     stReadNumberPrefix        ,
//     stReadNumber              ,
//     stReadNumberFloat         ,
//     stReadNumberMayBeFloat    ,
//     stReadOperator            ,
//     stReadSingleLineComment   ,
//     stReadMultilineLineComment,
//     stReadStringLiteral       ,
//     stContinuationWaitLinefeed
//
// };

    bool tokenizeFinalize(InputIteratorType itEnd) const
    {
        return true;
    }

    bool tokenize(InputIteratorType it, InputIteratorType itEnd) const
    {
        const auto ch = *it;
        UMBA_ASSERT(charClassTable.size()>charToCharClassTableIndex(ch));
        CharClass charClass = charClassTable[charToCharClassTableIndex(ch)];

        switch(st)
        {
            //------------------------------
            explicit_initial:
            case TokenizerInternalState::stInitial:
            {

                // st = stReadNumber;
                // numbersBase = numberDefaultBase;
                // allowedDigitCharClass = CharClass::digit;
                // if (utils::isNumberHexDigitsAllowed(numbersBase))
                //     allowedDigitCharClass |= CharClass::xdigit;

                if (ch==(std::decay_t<decltype(ch)>)'.')
                {
                    st = TokenizerInternalState::stReadNumberMayBeFloat;
                    tokenStartIt = it;
                    numberPrefixIdx = trie_index_invalid;
                    numberTokenId = 0;
                    numberReadedDigits = 0;
                    numberExplicitBase = 0;
                    numbersBase = options.numberDefaultBase;
                    allowedDigitCharClass = CharClass::digit;
                    if (utils::isNumberHexDigitsAllowed(numbersBase))
                        allowedDigitCharClass |= CharClass::xdigit;
                    break;
                }

                if (umba::TheFlags(charClass).oneOf(CharClass::string_literal_prefix))
                {
                    pCurrentLiteralParser = checkIsLiteralPrefix(it, itEnd, literalTokenId);
                    if (pCurrentLiteralParser)
                    {
                        tokenStartIt = it;
                        st = TokenizerInternalState::stReadStringLiteral;
                        goto explicit_readstringliteral;
                    }
                }

                if (umba::TheFlags(charClass).oneOf(CharClass::linefeed))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_LINEFEED, it, it+1); // Перевод строки мы всегда отдельно выплёвываем
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::space))
                {
                    tokenStartIt = it;
                    st = TokenizerInternalState::stReadSpace;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::opchar))
                {
                    if (!performStartReadingOperatorLambda(ch, it))
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::identifier_first))
                {
                    //parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it); // выплюнули
                    tokenStartIt = it;
                    st = TokenizerInternalState::stReadIdentifier;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::digit))
                {
                    performStartReadingNumberLambda(ch, it);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::open, CharClass::close)) // Открывающая или закрывающая скобка
                {
                    if (!performProcessBracketLambda(ch, it))
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::semialpha))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SEMIALPHA, it, it+1); // выплюнули
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    processEscapeSymbolLambda(it);
                }
                else
                {
                    return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }

                //if ((charClass::linefeed))
            } break;


            //------------------------------
            case TokenizerInternalState::stReadSpace:
            {
                if (ch==(std::decay_t<decltype(ch)>)'.')
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it);
                    st = TokenizerInternalState::stReadNumberMayBeFloat;
                    tokenStartIt = it;
                    numberPrefixIdx = trie_index_invalid;
                    numberTokenId = 0;
                    numberReadedDigits = 0;
                    numberExplicitBase = 0;
                    numbersBase = options.numberDefaultBase;
                    allowedDigitCharClass = CharClass::digit;
                    if (utils::isNumberHexDigitsAllowed(numbersBase))
                        allowedDigitCharClass |= CharClass::xdigit;
                    break;
                }

                if (umba::TheFlags(charClass).oneOf(CharClass::string_literal_prefix))
                {
                    pCurrentLiteralParser = checkIsLiteralPrefix(it, itEnd, literalTokenId);
                    if (pCurrentLiteralParser)
                    {
                        parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it);
                        tokenStartIt = it;
                        st = TokenizerInternalState::stReadStringLiteral;
                        goto explicit_readstringliteral;
                    }
                }

                if (umba::TheFlags(charClass).oneOf(CharClass::linefeed))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it);
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_LINEFEED, it, it+1); // Перевод строки мы всегда отдельно выплёвываем
                    st = TokenizerInternalState::stInitial;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::space))
                {
                    if (*tokenStartIt!=*it) // пробелы бывают разные, одинаковые мы коллекционируем, разные - выплевываем разными пачками
                    {
                        parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it); // выплюнули
                        tokenStartIt = it; // Сохранили начало нового токена
                    }
                    else
                    {
                        break; // коллекционируем
                    }
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::opchar))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it);
                    if (!performStartReadingOperatorLambda(ch, it))
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::identifier_first))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it); // выплюнули
                    tokenStartIt = it;
                    st = TokenizerInternalState::stReadIdentifier;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::digit))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it); // выплюнули
                    performStartReadingNumberLambda(ch, it);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::open, CharClass::close)) // Открывающая или закрывающая скобка
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it); // выплюнули
                    if (!performProcessBracketLambda(ch, it))
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::semialpha))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it); // выплюнули
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SEMIALPHA, it, it+1); // выплюнули
                    st = TokenizerInternalState::stInitial;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_SPACE, tokenStartIt, it); // выплюнули
                    processEscapeSymbolLambda(it);
                }
                else
                {
                    return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
            } break;


            //------------------------------
            case TokenizerInternalState::stReadIdentifier:
            {
                if (umba::TheFlags(charClass).oneOf(CharClass::identifier, CharClass::identifier_first))
                {
                    break; // коллекционируем
                }

                parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_IDENTIFIER, tokenStartIt, it); // выплюнули
                charClass = charClassTable[charToCharClassTableIndex(ch)]; // Перечитали значение класса символа - оно могло измениться
                tokenStartIt = it; // Сохранили начало нового токена

                if (umba::TheFlags(charClass).oneOf(CharClass::string_literal_prefix))
                {
                    pCurrentLiteralParser = checkIsLiteralPrefix(it, itEnd, literalTokenId);
                    if (pCurrentLiteralParser)
                    {
                        tokenStartIt = it;
                        st = TokenizerInternalState::stReadStringLiteral;
                        goto explicit_readstringliteral;
                    }
                }

                if (umba::TheFlags(charClass).oneOf(CharClass::linefeed))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_LINEFEED, it, it+1); // Перевод строки мы всегда отдельно выплёвываем
                    st = TokenizerInternalState::stInitial;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::space))
                {
                    st = TokenizerInternalState::stReadSpace;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::opchar))
                {
                    if (!performStartReadingOperatorLambda(ch, it))
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::open, CharClass::close)) // Открывающая или закрывающая скобка
                {
                    if (!performProcessBracketLambda(ch, it))
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    processEscapeSymbolLambda(it);
                }
                else
                {
                    return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }
            } break;


            //------------------------------
            case TokenizerInternalState::stReadNumberPrefix:
            {
                //NOTE: !!! У нас пока так: префикс числа начинается с любой цифры, потом могут следовать любые символы, после префикса - те символы, которые разрешены префиксом
                payload_type curPayload = payload_invalid;
                bool prefixIsNumber     = true ;
                bool requiresDigits     = false;

                auto nextNumberPrefixIdx = tokenTrieFindNext(numbersTrie, numberPrefixIdx, (token_type)ch);
                if (nextNumberPrefixIdx!=trie_index_invalid)
                {
                    numberPrefixIdx = nextNumberPrefixIdx; // Всё в порядке, префикс числа продолжается
                    break;
                }
                else // Нет продолжения префикса, вероятно, он у нас окончился
                {
                    curPayload = numbersTrie[numberPrefixIdx].payload;
                    if (curPayload==payload_invalid) // текущий префикс нифига не префикс
                    {
                        // Надо проверить, является ли то, что уже есть, чисто числом
                        // int charToDigit(CharType ch)

                        numbersBase = options.numberDefaultBase;
                        allowedDigitCharClass = CharClass::digit;
                        if (utils::isNumberHexDigitsAllowed(numbersBase))
                            allowedDigitCharClass |= CharClass::xdigit;

                        tokenTrieBackTrace( numbersTrie
                                          , numberPrefixIdx
                                          , [&](token_type ch)
                                            {
                                                if (!utils::isDigitAllowed(ch, numbersBase))
                                                    prefixIsNumber = false;
                                            }
                                          );

                        if (!prefixIsNumber)
                            return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                        //parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_NUMBER, tokenStartIt, it); // выплёвываем накопленное число как число без префикса, с системой счисления по умолчанию
                        //st = stInitial; // на всякий случай, если в stInitial обрабтчике состояние не переустанавливается, а подразумевается, что уже такое и есть
                        //goto explicit_initial;

                        st = TokenizerInternalState::stReadNumber;
                        goto explicit_readnumber; // надо обработать текущий символ
                    }

                    // Префикс нашелся

                    requiresDigits   = utils::isNumberPrefixRequiresDigits(curPayload);
                    numberPrefixIdx       = trie_index_invalid; // сбрасываем индекс префикса, чтобы потом не париться

                    numberTokenId         = curPayload;
                    numberExplicitBase    = utils::numberPrefixGetBase(numberTokenId);
                    numberReadedDigits    = 0;
                    numbersBase           = numberExplicitBase;
                    allowedDigitCharClass = CharClass::digit;
                    if (utils::isNumberHexDigitsAllowed(numbersBase))
                        allowedDigitCharClass |= CharClass::xdigit;

                    // Теперь тут у нас либо цифра, либо что-то другое
                    if (umba::TheFlags(charClass).oneOf(allowedDigitCharClass) && utils::isDigitAllowed(ch, numbersBase))
                    {
                        //NOTE: !!! Да, сразу после префикса у нас не может быть разделителя разрядов
                        st = TokenizerInternalState::stReadNumber; // Тут у нас годная цифра, продолжаем
                        numberReadedDigits = 1;
                        break;
                    }

                    if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                    {
                        // Проблема будет, если на половине префикса пришел эскейп. Или не будет. В общем, если и будет, то выше выдадут ошибку, и в здравом уме никто такое не напишет в сорцах
                        parsingHandlerLambda(numberTokenId, tokenStartIt, it); // выплёвываем префикс как число
                        processEscapeSymbolLambda(it);
                        break;
                    }


                    if (requiresDigits)
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__); // нужна хоть одна цифра, а её нет

                    parsingHandlerLambda(numberTokenId, tokenStartIt, it); // выплёвываем префикс (он является годным числом и без доп цифр)

                    // у тут понеслась вся та же тема, как и в состоянии stInitial, только без обработки цифр

                    st = TokenizerInternalState::stInitial; // на всякий случай, если в stInitial обрабтчике состояние не переустанавливается, а подразумевается, что уже такое и есть
                    goto explicit_initial;

                }

            } break;


            //------------------------------
            explicit_readnumber:
            case TokenizerInternalState::stReadNumber:
            {
                if (ch==(std::decay_t<decltype(ch)>)'.')
                {
                    st = TokenizerInternalState::stReadNumberFloat;
                    break;
                }

                if (umba::TheFlags(charClass).oneOf(allowedDigitCharClass) && utils::isDigitAllowed(ch, numbersBase))
                {
                    break; // Тут у нас годная цифра
                }

                if (options.numbersAllowDigitsSeparator && ch==(std::decay_t<decltype(ch)>)'\'')
                {
                    break; // Тут у нас разделитель разрядов
                }

                if (numberTokenId==0 || numberTokenId==payload_invalid)
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_NUMBER, tokenStartIt, it); // выплёвываем накопленное число как число без префикса, с системой счисления по умолчанию
                else
                    parsingHandlerLambda(numberTokenId, tokenStartIt, it); // выплёвываем накопленное число с явно указанной системой счисления

                if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    processEscapeSymbolLambda(it);
                    break;
                }

                numberTokenId = 0;
                //return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                // Далее у нас всё как начальном состоянии
                st = TokenizerInternalState::stInitial; // на всякий случай, если в stInitial обрабтчике состояние не переустанавливается, а подразумевается, что уже такое и есть
                goto explicit_initial;

            } break;


            //------------------------------
            case TokenizerInternalState::stReadNumberMayBeFloat:
            {
                if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    processEscapeSymbolLambda(it); // !!! Вот тут гавно какое-то получится, надо подумать
                    break;
                }

                if (umba::TheFlags(charClass).oneOf(allowedDigitCharClass) && utils::isDigitAllowed(ch, numbersBase))
                {
                    break; // Тут у нас годная цифра
                }

                CharClass dotCharClass = charClassTable[charToCharClassTableIndex((std::decay_t<decltype(ch)>)'.')];

                if (umba::TheFlags(dotCharClass).oneOf(CharClass::opchar)) // Точка - операторный символ?
                {
                    if (!performStartReadingOperatorLambda((std::decay_t<decltype(ch)>)'.', tokenStartIt))
                        return unexpectedHandlerLambda(tokenStartIt, __FILE__, __LINE__); // но у нас нет операторов, начинающихся с точки
                    goto explicit_readoperator; // Надо обработать текущий символ
                }
                else // точка - не операторный символ, и не начало дробной части плавающего числа
                {
                    return unexpectedHandlerLambda(tokenStartIt, __FILE__, __LINE__);
                }

                st = TokenizerInternalState::stReadNumberFloat;

                goto explicit_readnumberfloat; // Текущий символ таки надо обработать

            } break;


            //------------------------------
            explicit_readnumberfloat:
            case TokenizerInternalState::stReadNumberFloat:
            {
                if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    processEscapeSymbolLambda(it); // !!! Вот тут гавно какое-то получится, надо подумать
                    break;
                }

                if (umba::TheFlags(charClass).oneOf(allowedDigitCharClass) && utils::isDigitAllowed(ch, numbersBase))
                {
                    break; // Тут у нас годная цифра
                }

                if (numberTokenId==0 || numberTokenId==payload_invalid)
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_NUMBER|UMBA_TOKENIZER_TOKEN_FLOAT_FLAG, tokenStartIt, it); // выплёвываем накопленное число с системой счисления по умолчанию
                else
                    parsingHandlerLambda(numberTokenId|UMBA_TOKENIZER_TOKEN_FLOAT_FLAG, tokenStartIt, it); // выплёвываем накопленное число с явно указанной системой счисления

                st = TokenizerInternalState::stInitial; // на всякий случай, если в stInitial обрабтчике состояние не переустанавливается, а подразумевается, что уже такое и есть
                goto explicit_initial;

            } break;


            //------------------------------
            explicit_readoperator:
            case TokenizerInternalState::stReadOperator:
            {
                if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    processEscapeSymbolLambda(it); // !!! Вот тут гавно какое-то получится, надо подумать
                    break;
                }

                if (umba::TheFlags(charClass).oneOf(CharClass::opchar))
                {
                    auto nextOperatorIdx = tokenTrieFindNext(operatorsTrie, operatorIdx, (token_type)ch);

                    if (nextOperatorIdx!=trie_index_invalid)
                    {
                        operatorIdx = nextOperatorIdx; // Всё в порядке, оператор продолжается
                    }
                    else
                    {
                        // Нет продолжения, у нас был, вероятно, полностью заданный оператор
                        auto curPayload = operatorsTrie[operatorIdx].payload;
                        if (curPayload==payload_invalid) // текущий оператор нифига не оператор
                        {
                            reportPossibleUnknownOperatorLambda(tokenStartIt, it);
                            return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                        }
                        if (utils::isCommentToken(curPayload)) // на каждом операторе в обрабатываемом тексте у нас это срабатывает. Жирно или нет?
                        {
                            if (!processCommentStartFromNonCommentedLambda(curPayload, it))
                                return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                            break;
                        }

                        parsingHandlerLambda(curPayload, tokenStartIt, it); // выплюнули текущий оператор
                        tokenStartIt = it; // Сохранили начало нового токена

                        operatorIdx = tokenTrieFindNext(operatorsTrie, trie_index_invalid, (token_type)ch); // Начали поиск нового оператора с начала
                        if (operatorIdx==trie_index_invalid)
                        {
                            reportPossibleUnknownOperatorLambda(it,it+1);
                            return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                        }
                    }
                    break; // коллекционируем символы оператора
                }

                // Заканчиваем обработку оператора на неоператорном символе

                if (operatorIdx==trie_index_invalid) // Текущий оператор почему-то не оператор
                    return unexpectedHandlerLambda(it, __FILE__, __LINE__);

                if (operatorsTrie[operatorIdx].payload==payload_invalid)
                {
                    reportPossibleUnknownOperatorLambda(tokenStartIt, it);
                    return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }

                auto curPayload = operatorsTrie[operatorIdx].payload;

                // Всё тоже самое, что и выше, наверное, надо как-то это потом вынести
                if (utils::isCommentToken(curPayload)) // на каждом операторе в обрабатываемом тексте у нас это срабатывает. Жирно или нет?
                {
                    if (!processCommentStartFromNonCommentedLambda(curPayload, it))
                        return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                    break;
                }

                parsingHandlerLambda(curPayload, tokenStartIt, it); // выплюнули
                tokenStartIt = it; // Сохранили начало нового токена

                // Далее у нас всё как начальном состоянии
                st = TokenizerInternalState::stInitial; // на всякий случай, если в stInitial обрабтчике состояние не переустанавливается, а подразумевается, что уже такое и есть
                goto explicit_initial;

            } break;


            //------------------------------
            explicit_readstringliteral:
            case TokenizerInternalState::stReadStringLiteral:
            {
                // литералы сами ловят хвостовой escape, если умеют
                externHandlerMessage.clear();
                auto res = pCurrentLiteralParser->parseChar(it, &stringLiteralValueCollector, &externHandlerMessage);

                if (res==StringLiteralParsingResult::error)
                {
                    reportStringLiteralMessageLambda(true /* bErr */ , it, externHandlerMessage);
                    return unexpectedHandlerLambda(it, __FILE__, __LINE__);
                }

                if (res==StringLiteralParsingResult::warnContinue || res==StringLiteralParsingResult::warnStop)
                {
                   reportStringLiteralMessageLambda(false /* !bErr */ , it, externHandlerMessage);
                }

                if (res==StringLiteralParsingResult::okStop || res==StringLiteralParsingResult::warnStop)
                {
                    parsingHandlerLambda(literalTokenId, tokenStartIt, it+1); // выплюнули текущий литерал
                    st = TokenizerInternalState::stInitial;
                }

            } break;


            //------------------------------
            case TokenizerInternalState::stReadSingleLineComment:
            {

                if (umba::TheFlags(charClass).oneOf(CharClass::escape))
                {
                    auto nextIt = it+1;
                    if (nextIt==itEnd)
                    {
                        parsingHandlerLambda(commentTokenId, tokenStartIt, it, commentStartIt, it);
                        processEscapeSymbolLambda(it /* , stInitial */ );
                        break;
                    }

                    CharClass nextCharClass = charClassTable[charToCharClassTableIndex(*nextIt)];
                    if (umba::TheFlags(nextCharClass).oneOf(CharClass::linefeed))
                    {
                        parsingHandlerLambda(commentTokenId, tokenStartIt, it, commentStartIt, it);
                        processEscapeSymbolLambda(it /* , stInitial */ );
                        break;
                    }

                    // Если не конец текста и не перевод строки - то слэш просто внутри строки коментария, и ничего делать не надо
                    break;
                }
                else if (umba::TheFlags(charClass).oneOf(CharClass::linefeed))
                {
                    //TODO: !!! Разобраться с continuation
                    parsingHandlerLambda(commentTokenId, tokenStartIt, it, commentStartIt, it);
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_LINEFEED, it, it+1); // Перевод строки мы всегда отдельно выплёвываем
                    st = TokenizerInternalState::stInitial;
                }
                else
                {
                    // Иначе - ничего не делаем
                }

            } break;


            //------------------------------
            case TokenizerInternalState::stReadMultilineLineComment:
            {
                // auto nextOperatorIdx = tokenTrieFindNext(operatorsTrie, operatorIdx, (token_type)ch);
                if (multiLineCommentEndStr.empty())
                    return unexpectedHandlerLambda(it, __FILE__, __LINE__);

                if (multiLineCommentEndStr[0]!=*it) // текущий входной символ не является первым символом маркера конца коментария
                    break;

                auto it2 = it;
                auto savedIt2 = it2;
                auto strIt    = multiLineCommentEndStr.begin();
                auto strItEnd = multiLineCommentEndStr.end();

                for(; it2!=itEnd && strIt!=strItEnd && *it2==*strIt; ++/*Проверка многострочника*/it2, ++strIt)
                {
                    savedIt2 = it2; // Сохраняем предыдущее (до инкремента) значение it2
                }

                if (strIt==strItEnd) // дошли до конца строки окончания коментария, не прервались на общий конец и не прервались по несовпадению символа - значит, целиком совпало
                {
                    parsingHandlerLambda(commentTokenId, tokenStartIt, it2, commentStartIt, it); // выплюнули текст коментария
                    it = savedIt2; // переместили it на позицию последнего символа конца многострочника, инкремент в основном цикле переместит его на следующий символ за многострочником, как надо
                    st = TokenizerInternalState::stInitial;
                }

            } break;


            //------------------------------
            case TokenizerInternalState::stContinuationWaitLinefeed:
            {
                // stReadSingleLineComment, stInitial
                if (umba::TheFlags(charClass).oneOf(CharClass::linefeed))
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_LINE_CONTINUATION, tokenStartIt, it+1);

                    st = stEscapeSaved;
                    tokenStartIt = it+1;

                    // Если у нас был однострочный комент, и linefeed сразу после слеша, то выплёвываем коментарий (уже), выплёвываем continuation,
                    // и затем не возвращаемся в предыдущее состояние, а в самое начальное
                    // таким образом, если следующий после continuation токен (помимо пробелов) будет не коментарий
                    // то всё будет отработано нормально, но можно выдать варнинг, что однострок использует continuation
                    if (st==TokenizerInternalState::stReadSingleLineComment)
                    {
                        st = TokenizerInternalState::stInitial;
                    }
                    break;
                }
                else
                {
                    parsingHandlerLambda(UMBA_TOKENIZER_TOKEN_ESCAPE, tokenStartIt, it);
                    st = TokenizerInternalState::stInitial;
                    goto explicit_initial;
                }
            }


            //------------------------------
            default:
            {
                return unexpectedHandlerLambda(it, __FILE__, __LINE__);
            }

        } // end switch

        return true;
    }

protected:

    void checkLineStart(payload_type tokenType) const
    {
        if (tokenType==UMBA_TOKENIZER_TOKEN_LINEFEED)
            curPosAtLineBeginning = true; // Для поддержки однострочного комента только в начале строки
        else if (tokenType==UMBA_TOKENIZER_TOKEN_SPACE) {} // Пробелы - пропускаем, они ничего не меняют
        else
            curPosAtLineBeginning = false; // Для поддержки однострочного комента только в начале строки
    }


    static
    std::basic_string_view<value_type> makeStringView( const umba::iterator::TextPositionCountingIterator<CharType> b, const umba::iterator::TextPositionCountingIterator<CharType> &e)
    {
        return umba::iterator::makeStringView(b,e);
    }

    template<typename GenericIteratorType>
    static
    std::basic_string_view<value_type> makeStringView(GenericIteratorType b, GenericIteratorType e)
    {
        return std::basic_string_view<value_type>(&*b, distance( b, e ));
    }


//------------------------------
protected: // methods - хандлеры из "грязного" проекта, где я наговнякал первую версию, выносим лямбды.
           // Это переходники к обработчикам, которые будут в дочернем классе
           // Нормальные имена потом сделаем, если захочется
           // Все хелперы и вся обработка трогают только то, что отвечает за состояние парсера. Все входные таблицы/деревья,
           // опции и тп - оно не должно трогать, поэтому состояние - mutable, а методы логически константные

    //! Эта "лямбда" вызывается при распознавании очередного токена. Тут надо вызвать метода класса-наследника, пока не будем
    /* @param b, e - итераторы начала и конца текста токена

       Итераторы передаем по значению. Предполагается, что у нас будет использоваться TextPositionCountingIterator, он жирный,
       но, теоретически, можно использовать и обычные итераторы или указатели, если не нужна информация о строке и позиции в ней.
       В принципе, TextPositionCountingIterator можно сделать полегче на 8 байт (24 vs 32 сейчас на x86)

       Для некоторых типов токенов нужно отдавать дополнительную информацию:
       - для строковых литералов - разобранную строку
       - для цифровых - пока хз что
       - для коментариев - текст без маркеров коментария

       Т.е. нужна вторая пара итераторов

       во внешний обработчик будем передавать string_view с полным варантом всегда
       и string_view с доп инфой.
       если доп инфы нет - второй string_view будет пустой - begin==end

    */
    void parsingHandlerLambda(payload_type tokenType, InputIteratorType b, InputIteratorType e) const
    {
        checkLineStart(tokenType);
        static_cast<const TBase*>(this)->hadleToken(tokenType, b, e, std::basic_string_view<value_type>());
    }

    void parsingHandlerLambda(payload_type tokenType, InputIteratorType inputDataBegin, InputIteratorType inputDataEnd, InputIteratorType parsedDataBegin, InputIteratorType parsedDataEnd) const
    {
        checkLineStart(tokenType);
        static_cast<const TBase*>(this)->hadleToken(tokenType, inputDataBegin, inputDataEnd, makeStringView(parsedDataBegin, parsedDataEnd));
    }

    void parsingHandlerLambda(payload_type tokenType, InputIteratorType inputDataBegin, InputIteratorType inputDataEnd, std::basic_string_view<value_type> parsedData) const
    {
        checkLineStart(tokenType);
        static_cast<const TBase*>(this)->hadleToken(tokenType, inputDataBegin, inputDataEnd, parsedData);
    }

    bool unexpectedHandlerLambda(InputIteratorType it, const char* srcFile, int srcLine) const
    {
        return static_cast<const TBase*>(this)->hadleUnexpected(it, srcFile, srcLine);
    }

    // Дополнительное сообщение о неизвестном операторе, перед вызовом unexpectedHandlerLambda - типа чуть чуть улучшили диагностику
    void reportPossibleUnknownOperatorLambda(InputIteratorType b, InputIteratorType e) const
    {
        static_cast<const TBase*>(this)->reportPossibleUnknownOperator(b, e);
    }

    // Либо предупреждение, либо сообщение об ошибке от парсера литералов
    void reportStringLiteralMessageLambda(bool bErr, InputIteratorType it, const MessagesStringType &msg) const
    {
        static_cast<const TBase*>(this)->reportStringLiteralMessage(bErr, it, msg);
    }



// trie_index_type tokenTrieFindFirst(const ContainerType &tokenTrie, token_type tk)
// trie_index_type tokenTrieFindNext(const ContainerType &tokenTrie, trie_index_type curIndex, token_type tk)
// trie_index_type tokenTrieTraverse(const ContainerType &tokenTrie, TokenSequenceIteratorType b, TokenSequenceIteratorType e)


}; // class TokenizerBaseImpl



} // namespace tokenizer
} // namespace umba

