#pragma once

#ifndef UMBA_TOKENIZER_H__DCAEEDE0_7624_4E47_9919_08460EF65A3B__
    #error "Do not include this file directly, include 'umba/tokenizer.h header instead'"
#endif



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
        , typename CharClassTable      = std::array<CharClass, 128>
        , typename TrieVector          = std::vector<TrieNode>
        , typename StringType          = std::basic_string<CharType>  // Тип строки, которая хранит входные символы
        , typename MessagesStringType  = std::string  // Тип строки, которая используется для сообщений (в том числе и от внешних суб-парсеров)
        , typename InputIteratorType   = umba::iterator::TextPositionCountingIterator<CharType>
        >
class TokenizerBaseImpl
{

//------------------------------
public: // depending types

    using char_type             = CharType;
    using value_type            = CharType;
    using char_class_table_type = CharClassTable;
    using trie_vector_type      = TrieVector;
    using string_type           = StringType;
    using iterator_type         = InputIteratorType;
    using messages_string_type  = MessagesStringType;

    using ITokenizerLiteralParser = umba::tokenizer::ITokenizerLiteralParser<CharType, MessagesStringType, InputIteratorType>;


//------------------------------
protected: // fileds

    CharClassTable        charClassTable;

    TrieVector            numbersTrie   ;
    TrieVector            bracketsTrie  ;
    TrieVector            operatorsTrie ;
    TrieVector            literalsTrie  ;

    StringType            multiLineCommentEndStr;

    TokenizerOptions      options; // Не являются состоянием, обычно задаются в начале, и никогда не меняются


//------------------------------
protected: // fileds - состояние токенизатора

    TokenizerInternalState st            = TokenizerInternalState::stInitial;
    TokenizerInternalState stEscapeSaved = TokenizerInternalState::stInitial;

    bool curPosAtLineBeginning = true;

    // Общее
    InputIteratorType      tokenStartIt;

    // Операторы
    trie_index_type        operatorIdx = trie_index_invalid;

    // Числовые литералы
    int                    numberExplicitBase    =  0;
    trie_index_type        numberPrefixIdx       = trie_index_invalid;
    payload_type           numberTokenId         = 0;
    payload_type           numberReadedDigits    = 0;
    CharClass              allowedDigitCharClass = CharClass::none;
    int                    numbersBase           = 0;

    // Коментарии
    InputIteratorType      commentStartIt;
    payload_type           commentTokenId = 0;

    // Строковые литералы
    ITokenizerLiteralParser* pCurrentLiteralParser = 0;
    payload_type             literalTokenId = 0;
    std::string              externHandlerMessage;
    ITokenizerLiteralCharNulInserterImpl<char> nullInserter;



//------------------------------
protected: // methods


//------------------------------
public: // methods

    void setCharClassTable( const CharClassTable &cht)
    {
        UMBA_ASSERT(cht.size()>=128);
        charClassTable = cht;
    }

    // charClassTable может модифицироваться, и тогда она составляет часть состояния токенизатора.
    // Если его надо сохранять, то charClassTable надо сохранять вручную, потому что по умолчанию сохранять
    // в состоянии всю charClassTable слишком жирно. Пользователь может сохранять лишь те элементы, которые
    // модифицировал сам.
    CharClassTable getCharClassTable() const { return charClassTable; }

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
    void setMultiLineCommentEndString(const StringType s) { multiLineCommentEndStr = s; };

    void setNumbersTrie  (const TrieVector &tv) { numbersTrie   = tv; }
    void setBracketsTrie (const TrieVector &tv) { bracketsTrie  = tv; }
    void setOperatorsTrie(const TrieVector &tv) { operatorsTrie = tv; }
    void setLiteralsTrie (const TrieVector &tv) { literalsTrie  = tv; }


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
protected: // methods - хандлеры из "грязного" проекта, где я наговнякал первую версию, выносим лямбды.
           // Это переходники к обработчикам, которые будут в дочернем классе
           // Нормальные имена потом сделаем, если захочется

    //! Эта "лямбда" вызывается при распознавании очередного токена. Тут надо вызвать метода класса-наследника, пока не будем
    /* @param b, e - итераторы начала и конца текста токена

       Итераторы передаем по значению. Предполагается, что у нас будет использоваться TextPositionCountingIterator, он жирный,
       но, теоретически, можно использовать и обычные итераторы или указатели, если не нужна информация о строке и позиции в ней.
       В принципе, TextPositionCountingIterator можно сделать полегче на 8 байт (24 vs 32 сейчас на x86)
    */
    void parsingHandlerLambda(payload_type tokenType, InputIteratorType b, InputIteratorType e)
    {
        if (tokenType==UMBA_TOKENIZER_TOKEN_LINEFEED)
        {
            curPosAtLineBeginning = true; // Для поддержки однострочного комента только в начале строки
        }
        else if (tokenType==UMBA_TOKENIZER_TOKEN_SPACE)
        {} // Пробелы - пропускаем, они ничего не меняют
        else
        {
            curPosAtLineBeginning = false; // Для поддержки однострочного комента только в начале строки
        }

        UMBA_USED(b); UMBA_USED(e);

        // Тут надо вызвать хэндлер в наследнике
    }

    bool unexpectedHandlerLambda(InputIteratorType it, const char* srcFile, int srcLine)
    {
        UMBA_USED(it); UMBA_USED(srcFile); UMBA_USED(srcLine);
        return false; // ошибка
        // Тут надо вызвать хэндлер в наследнике, и вернуть его результат
    }

    // Дополнительное сообщение о неизвестном операторе, перед вызовом unexpectedHandlerLambda - типа чуть чуть улучшили диагностику
    void reportPossibleUnknownOperatorLambda(InputIteratorType b, InputIteratorType e)
    {
        UMBA_USED(b); UMBA_USED(e);
        // Тут надо вызвать хэндлер в наследнике
    }

    // Либо предупреждение, либо сообщение об ошибке от парсера литералов
    void reportStringLiteralMessageLambda(bool bErr, InputIteratorType it, const std::string msg)
    {
        UMBA_USED(bErr); UMBA_USED(it); UMBA_USED(msg);
        // Тут надо вызвать хэндлер в наследнике
    }


//------------------------------
protected: // methods - helpers - из "грязного" проекта, где я наговнякал первую версию, выносим лямбды.

    //NOTE: !!! Надо ли semialpha проверять, не является ли она началом числового префикса? Наверное, не помешает

    void performStartReadingNumberLambda(CharType ch, InputIteratorType it)
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

    bool performStartReadingOperatorLambda(CharType ch, InputIteratorType it)
    {
        tokenStartIt = it;
        operatorIdx = tokenTrieFindNext(operatorsTrie, trie_index_invalid, (token_type)ch);
        if (operatorIdx==trie_index_invalid)
            return false;
        st = TokenizerInternalState::stReadOperator;
        return true;
    };

    bool performProcessBracketLambda(CharType ch, InputIteratorType it)
    {
        auto idx = tokenTrieFindNext(bracketsTrie, trie_index_invalid, (token_type)ch);
        if (idx==trie_index_invalid)
            return false;
        parsingHandlerLambda(bracketsTrie[idx].payload, it, it+1); // выплюнули
        st = TokenizerInternalState::stInitial;
        return true;
    };

    bool processCommentStartFromNonCommentedLambda(payload_type curPayload, InputIteratorType it)
    {
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
            tokenStartIt   = it;
            commentStartIt = it; // Сохранили начало коментария без самого оператора начала коментария - текст коментария потом выдадим по окончании
            st = TokenizerInternalState::stReadSingleLineComment;
            operatorIdx = trie_index_invalid;
            return true;
        }
        else if (utils::isMultiLineCommentStartToken(curPayload))
        {
            tokenStartIt   = it; // А тут бы надо оставить начало оператора !!!
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

    void processEscapeSymbolLambda(InputIteratorType it)
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



// trie_index_type tokenTrieFindFirst(const ContainerType &tokenTrie, token_type tk)
// trie_index_type tokenTrieFindNext(const ContainerType &tokenTrie, trie_index_type curIndex, token_type tk)
// trie_index_type tokenTrieTraverse(const ContainerType &tokenTrie, TokenSequenceIteratorType b, TokenSequenceIteratorType e)


}; // class TokenizerBaseImpl



} // namespace tokenizer
} // namespace umba

