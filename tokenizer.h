#pragma once

#if defined(UMBA_TOKENIZER_TYPES_COMPACT)
    #if !defined(UMBA_CHAR_CLASS_UNDERLYING_COMPACT)
        #define UMBA_CHAR_CLASS_UNDERLYING_COMPACT
    #endif
#endif

#if defined(UMBA_CHAR_CLASS_UNDERLYING_COMPACT)
    #if !defined(UMBA_TOKENIZER_TYPES_COMPACT)
        #define UMBA_TOKENIZER_TYPES_COMPACT
    #endif
#endif

#if !defined(UMBA_TOKEN_TRIE_FIND_NEXT_BINARY_SEARCH_CHUNK_SIZE_LIMIT)
    #define UMBA_TOKEN_TRIE_FIND_NEXT_BINARY_SEARCH_CHUNK_SIZE_LIMIT  4u
#endif

//----------------------------------------------------------------------------
#include "c_tokenizer.h"
//
#include "char_class.h"
//
#include "iterator.h"

//
#include <map>
#include <deque>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <type_traits>
		

//
#include "assert.h"


//----------------------------------------------------------------------------
// boost::tokenizer (где-то в середине)
//  Перевод  - https://habr.com/ru/companies/piter/articles/650945/
//  Оригинал - https://www.j-labs.pl/blog-technologiczny/find-a-better-solution-with-boost/


//----------------------------------------------------------------------------

// Наткнулся тут
// #include "microcode_tokenizer.h"
// В каком-то проекте же делал, надо поискать, что там

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

// umba::tokenizer::
namespace umba {
namespace tokenizer {



//----------------------------------------------------------------------------
using  trie_index_type                                     = UMBA_TOKENIZER_TRIE_INDEX_TYPE;
inline constexpr const trie_index_type trie_index_invalid  = UMBA_TOKENIZER_TRIE_INDEX_INVALID;
//inline constexpr const trie_index_type trie_index_initial  = UMBA_TOKENIZER_TRIE_INDEX_INITIAL;

//----------------------------------------------------------------------------
using  token_type                                          = UMBA_TOKENIZER_TOKEN_TYPE;
inline constexpr const token_type token_id_invalid         = UMBA_TOKENIZER_TOKEN_INVALID;

//----------------------------------------------------------------------------
using  payload_type                                        = UMBA_TOKENIZER_PAYLOAD_TYPE;
inline constexpr const payload_type payload_invalid        = UMBA_TOKENIZER_PAYLOAD_INVALID;

//----------------------------------------------------------------------------
using payload_flags_type                                   = UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE;

//----------------------------------------------------------------------------
using TrieNode = umba_tokenizer_trie_node;

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline
void trieNodeInitMakeUninitialized(TrieNode &node)
{
    umba_tokenizer_trie_node_init_make_uninitialized(&node);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename ContainerType>
trie_index_type tokenTrieFindNext(const ContainerType &tokenTrie, trie_index_type curIndex, token_type tk)
{
    // Если на входе инвалид, то начинать надо со старта

    trie_index_type lookupChunkStartIdx  = 0;
    trie_index_type lookupChunkSize      = 0;

    if (curIndex==trie_index_invalid)
    {
        lookupChunkStartIdx  = tokenTrie[0].lookupChunkStartIndex;
        lookupChunkSize      = tokenTrie[0].lookupChunkSize;
    }
    else
    {
        if (curIndex>=tokenTrie.size())
        {
            return trie_index_invalid;
        }

        if (tokenTrie[curIndex].childsIndex==trie_index_invalid)
        {
            // Детей нет, дальше искать нечего
            return trie_index_invalid;
        }

        lookupChunkStartIdx = tokenTrie[curIndex].childsIndex;
        UMBA_ASSERT(lookupChunkStartIdx<tokenTrie.size());
        lookupChunkSize = tokenTrie[lookupChunkStartIdx].lookupChunkSize;
    }

    UMBA_ASSERT((lookupChunkStartIdx+lookupChunkSize)<=tokenTrie.size());

    // Двоичный поиск
    // https://codelessons.dev/ru/binarnyj-poisk-po-massivu-c/
    // https://brestprog.by/topics/binsearch/
    // Интересная статья, может списюганить там поиск? https://habr.com/ru/companies/ruvds/articles/756422/
    // На самом деле надо будет просто проверить сначала обычный lower_bound
    // И ещё вопрос для исследования - оставлять ли для мелких чанков линейный поиск или нет?

    // С двоичным поиском что-то не так идёт, добавил возможность его запретить
    #if !defined(UMBA_TOKEN_TRIE_FIND_NEXT_BINARY_SEARCH_DISABLED)
    if (lookupChunkSize>=UMBA_TOKEN_TRIE_FIND_NEXT_BINARY_SEARCH_CHUNK_SIZE_LIMIT)
    {
        TrieNode cmpNode;
        cmpNode.token = tk;
        auto resIt = std::lower_bound( &tokenTrie[lookupChunkStartIdx]
                                     , &tokenTrie[lookupChunkStartIdx+lookupChunkSize]
                                     , cmpNode
                                     , [](const TrieNode &tn1, const TrieNode &tn2)
                                       {
                                           return tn1.token < tn2.token;
                                       }
                                     );
        if (resIt==&tokenTrie[lookupChunkStartIdx+lookupChunkSize] || resIt->token!=tk)
            return trie_index_invalid; // Не нашли, обломс

        return resIt-&tokenTrie[lookupChunkStartIdx];
    }
    #endif

    // Чанк небольшой, фигачим линейным поиском
    // Или, возможно, двоичный поиск запрещён настройками
    // Линейный поиск
    for(trie_index_type i=0; i!=lookupChunkSize; ++i)
    {
        const auto idx = lookupChunkStartIdx + i;

        if (tokenTrie[idx].token==tk)
            return idx;

        if (tokenTrie[idx].token>tk)
            return trie_index_invalid; // у нас символы отсортированы по возрастанию, и если код искомого символа больше того, что мы обнаружили в очередной entry, то дальше искать нет смысла
    }

    return trie_index_invalid; // Не нашли, обломс
}

//----------------------------------------------------------------------------
template<typename ContainerType, typename BackTraceHandlerType>
void tokenTrieBackTrace(const ContainerType &tokenTrie, trie_index_type curIndex, BackTraceHandlerType handler)
{
    while(curIndex!=trie_index_invalid)
    {
        UMBA_ASSERT(curIndex<tokenTrie.size());
        handler(tokenTrie[curIndex].token);
        curIndex = tokenTrie[curIndex].parentNodeIndex;
    }
}

//----------------------------------------------------------------------------
#if !defined(UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE)
template<typename ContainerType, typename StreamType, typename TokenToStringConverter>
void tokenTriePrintTableGraph(const std::string &name, const ContainerType &tokenTrie, StreamType &s, TokenToStringConverter converter)
{
    // requires UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE is not defined

    s << "digraph " << name << " {\nnode [shape=record];\n";


    //s << "L"<<lvl<< "[label=\"";

    trie_index_type lvl = trie_index_invalid;
    trie_index_type idx = 0;
    bool levelChanged = false;
    for( const auto &t : tokenTrie)
    {
        if (lvl!=t.level)
        {
            lvl = t.level;
            if (lvl!=0)
                s << "\"];\n";
            s << "L"<<lvl<< "[label=\"";
            levelChanged = true;
        }

        if (!levelChanged)
           s << "|";
        levelChanged = false;

        s << "{<I" << idx << ">";

        std::string strToken = converter(t.token);
        if (strToken.empty())
        {
            s << t.token;
        }
        else
        {
            for(auto ch : strToken)
            {
                if (ch=='\'' || ch=='\"' || ch=='\\' || ch=='<' || ch=='>' || ch=='|' || ch=='{' || ch=='}')
                {
                    s << "\\";
                }

                s << ch;
            }
        }

        s << "|<O" << idx << ">" << idx << "}";

        // //l2 [label="
        // {<t4>+|<f4>4}
        // |{<t5>-|<f5>5}|{<t6>=|<f6>6}|{<t7>\>|<f7>7}|{<t8>+|<f8>8}|{<t9>-|<f9>9}|{<t10>=|<f10>10}|{<t11>-|<f11>11}|{<t12>=|<f12>12}|{<t13>\>|<f13>13}"] // |{<t15>=|<f15>15}|{<t16>\>|<f16>16}

        ++idx;
    }

    s << "\"];\n";

    //trie_index_type lvl = trie_index_invalid;
    //trie_index_type
    idx = 0;
    for( const auto &t : tokenTrie)
    {
        // l1:f0  -> l2:t4

        if (t.childsIndex!=trie_index_invalid)
        {
            s << "L" << t.level << ":O" << idx << " -> L" << tokenTrie[t.childsIndex].level << ":I" << t.childsIndex <<"\n";
        }

        ++idx;
    }

    s << "}\n";

}
#endif
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// Префиксные деревья (без них таки никак)
// https://ru.hexlet.io/courses/algorithms-trees/lessons/prefix/theory_unit
// https://habr.com/ru/companies/otus/articles/676692/
// https://otus.ru/nest/post/676/

class TrieBuilder
{

protected:

public:

    struct TrieBuilderMapNode
    {
        TrieNode                                    trieNode ;
        std::map<token_type, TrieBuilderMapNode>    childs   ;
        trie_index_type                             nodeIndex;
        trie_index_type                             level    ;

        TrieBuilderMapNode() : trieNode(), childs()
        {
            trieNodeInitMakeUninitialized(trieNode);
        }

        TrieBuilderMapNode(const TrieBuilderMapNode &) = default;
        TrieBuilderMapNode& operator=(const TrieBuilderMapNode &) = default;
        TrieBuilderMapNode(TrieBuilderMapNode &&) = default;
        TrieBuilderMapNode& operator=(TrieBuilderMapNode &&) = default;

    };

    typedef std::map<token_type, TrieBuilderMapNode> TrieNodesMap;


public: // пока public, потом, скорее всего, будет спрятано

    TrieNodesMap     m_trieNodesMap;

public:


    template<typename TokenSequenceIterator>
    TrieNode& addTokenSequence(TokenSequenceIterator b, TokenSequenceIterator e, payload_type payload)
    {
        //UMBA_ASSERT(!seqStr.empty());
        UMBA_ASSERT(b!=e);

        TrieNodesMap *pCurMap  = &m_trieNodesMap;
        TrieBuilderMapNode  *pCurNode = 0;

        //for(auto ch: seqStr)
        for(; b!=e; ++b)
        {
            TrieNodesMap
            &curMap  = *pCurMap;
            pCurNode = &curMap[*b]; // .second;
            pCurMap  = &pCurNode->childs;

            pCurNode->trieNode.token = static_cast<token_type>(*b);

            // ++finalTableNumEntries;
        }

        // Прошагали всё символы обрабатываемой строки
        // Финальный узел у нас есть

        if (pCurNode->trieNode.payload!=token_id_invalid && pCurNode->trieNode.payload!=payload)
            return pCurNode->trieNode; // Такой путь в дереве уже есть, и там другой корректный идентификатор токена

        // Записываем туда идентификатор оператора
        pCurNode->trieNode.payload = payload;

        return pCurNode->trieNode;
    }

    TrieNode& addTokenSequence(const std::string &seqStr, payload_type payload)
    {
        return addTokenSequence(seqStr.begin(), seqStr.end(), payload);
    }

    TrieNode& addTokenSequence(char ch, payload_type payload)
    {
        const char *pCh = &ch;
        return addTokenSequence(pCh, pCh+1, payload);
    }


    template<typename ContainerType>
    void buildTokenTrie(ContainerType &buildTo) const
    {
        buildTo.clear();

        struct QueItem
        {
            umba::tokenizer::TrieBuilder::TrieNodesMap   *pMap;
            umba::tokenizer::trie_index_type             level;
            umba::tokenizer::trie_index_type             parentNodeIndex;
        };

        TrieNodesMap trieNodesMapCopy = m_trieNodesMap;

        std::deque<QueItem>  que;
        que.emplace_back( QueItem{ &trieNodesMapCopy
                                 , 0u                                    // level
                                 , trie_index_invalid  // parentNodeIndex
                                 }
                        );

        std::size_t nodeIdx = 0;
        while(!que.empty())
        {
            QueItem qi = que.front();  que.pop_front();
            auto &m = *qi.pMap;
            for(auto &kv : m)
            {
                kv.second.nodeIndex = nodeIdx++;
                kv.second.level     = qi.level;
                if (!kv.second.childs.empty())
                {
                    que.emplace_back(QueItem{&kv.second.childs, kv.second.level+1u });
                }
            }
        }

        que.emplace_back( QueItem{ &trieNodesMapCopy
                                 , 0u                                    // level
                                 , trie_index_invalid  // parentNodeIndex
                                 }
                        );

        while(!que.empty())
        {
            QueItem qi = que.front();  que.pop_front();
            auto &m = *qi.pMap;
            std::size_t curParentNodeIndex = qi.parentNodeIndex;

            if (m.empty())
            {
                continue;
            }

            umba::tokenizer::trie_index_type lookupChunkStartIndex = m.begin()->second.nodeIndex;
            for(auto &kv : m)
            {
                buildTo.emplace_back(kv.second.trieNode); // tokenId тут уже настроен, а childsIndex - инвалид
                buildTo.back().parentNodeIndex       = curParentNodeIndex;
                buildTo.back().lookupChunkStartIndex = lookupChunkStartIndex;
                buildTo.back().lookupChunkSize       = m.size();
                buildTo.back().token                 = kv.first;
#if !defined(UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE)
                buildTo.back().level                 = qi.level;
#endif
                if (!kv.second.childs.empty())
                {
                    buildTo.back().childsIndex = kv.second.childs.begin()->second.nodeIndex;
                    que.emplace_back(QueItem{&kv.second.childs, kv.second.level+1u, kv.second.nodeIndex});
                }
            }
        }

    }

}; // class TrieBuilder

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
namespace utils {




//----------------------------------------------------------------------------
// bool isCommentToken(payload_type tokenType)
// bool isSingleLineCommentToken(payload_type tokenType)
// bool isMultiLineCommentStartToken(payload_type tokenType)
// bool isMultiLineCommentEndToken(payload_type tokenType)

//----------------------------------------------------------------------------
constexpr
inline
bool isCommentToken(payload_type tokenType)
{
    return ((tokenType>=UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST && tokenType<=UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_END))
         ? true
         : false
         ;
};

// Тут надо, чтобы это уже был коммент - вызывать только после вызова isCommentToken
constexpr
inline
bool isSingleLineCommentToken(payload_type tokenType)
{
    return (tokenType<=UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_LAST) ? true : false;
}

// Тут надо, чтобы это уже был коммент, и не однострочный - вызывать только после вызова isCommentToken
constexpr
inline
bool isMultiLineCommentStartToken(payload_type tokenType)
{
    return tokenType==UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_START;
}

// Тут надо, чтобы это уже был коммент, и не однострочный - вызывать только после вызова isCommentToken
constexpr
inline
bool isMultiLineCommentEndToken(payload_type tokenType)
{
    return tokenType==UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_END;
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// bool isNumberPrefixRequiresDigits(payload_type tokenType)
// bool isNumberPrefixAllowMissDigits(payload_type tokenType)
// int numberPrefixGetBase(payload_type tokenType)
// bool isNumberHexDigitsAllowed(int base)
// bool isDigitAllowed(CharType ch, int base)
// int getNumberBaseFromExplicitAndDefault(int explicitBase, int defaultBase)

//----------------------------------------------------------------------------
// Достаточно ли только префикса для валидного числа, или обязательно нужны цыфры?
constexpr
inline
bool isNumberPrefixRequiresDigits(payload_type tokenType)
{
    return (tokenType & UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FLAG_MISS_DIGIT)==0;
}

// Превикс допускает отсутствие дополнительных цифр
constexpr
inline
bool isNumberPrefixAllowMissDigits(payload_type tokenType)
{
    return (tokenType & UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FLAG_MISS_DIGIT)!=0;
}

//constexpr
inline
int numberPrefixGetBase(payload_type tokenType)
{
    auto masked = tokenType&UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_MASK;
    switch(masked)
    {
        case UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DEC : return 10u;
        case UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_BIN : return  2u;
        case UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_QUAT: return  4u;
        case UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_OCT : return  8u;
        case UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DUOD: return 12u;
        case UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_HEX : return 16u;
        default: return 10u;
    }
}

constexpr
inline
bool isNumberHexDigitsAllowed(int base)
{
    return base > 10;
}

template<typename CharType>
inline
int charToDigit(CharType ch)
{
    if (ch>=(CharType)'0' && ch<=(CharType)'9') return ch-(CharType)'0';
    if (ch>=(CharType)'A' && ch<=(CharType)'F') return ch-(CharType)'A'+10;
    if (ch>=(CharType)'a' && ch<=(CharType)'f') return ch-(CharType)'a'+10;
    return -1;
}

template<typename CharType>
inline
bool isDigitAllowed(CharType ch, int base)
{
    int d = charToDigit(ch);
    if (d<0)
        return false;
    return d<base ? true : false;
}

//----------------------------------------------------------------------------
constexpr
inline
int getNumberBaseFromExplicitAndDefault(int explicitBase, int defaultBase)
{
    return (explicitBase<=0) ? defaultBase : explicitBase;
}

//----------------------------------------------------------------------------




} // namespace utils
//----------------------------------------------------------------------------





//----------------------------------------------------------------------------
enum class StringLiteralParsingResult : unsigned
{
    okContinue    , // Нормас, продолжаем парсить
    okStop        , // Нормас, обнаружен конец литерала
    warnContinue  , // Предупреждение - некорректная строка, но обработку можно продолжить
    warnStop      , // Предупреждение - некорректная строка, и производим нормальную обработку парсинга
    error           // Ошибка, останавливает парсинг
};

//----------------------------------------------------------------------------

template<typename CharType>
struct ITokenizerLiteralCharInserter
{
    using difference_type = std::ptrdiff_t;
    using value_type = CharType;

    virtual void insert(CharType ch) = 0;
};

template<typename CharType>
struct ITokenizerLiteralCharNulInserterImpl : public ITokenizerLiteralCharInserter<CharType>
{
    virtual void insert(CharType ch) override
    {
        UMBA_USED(ch);
    }
};

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------

// Вообще, LiteralProcessor'ы должны не только проверять корректность строки для токенизера,
// но и уметь разбирать, может, даже в то же самое время, как и парсить


// Токенизер получает и хранит сырые указатели на литерал парсеры, но не владеет ими. Пользовательский
// код сам должен обеспечивать достаточное время жизни объектам парсеров, хоть в куче, хоть на стеке.
// Можно было бы попробовать заморочиться, и сделать, чтобы всё работало в компайл-тайме, чтобы запихывать
// эффективно в микроконтроллер, но одна из идей токенизера - это возможность настройки в рантайме, например,
// для раскрашивания кода произвольных языков программирования в текстовом редакторе.

// Хорошо ли использовать для сообщений тот же CharType, что и для обрабатываемых данных?
// Или сообщения будем всегда, например, в std::string помещать?
// Наверное, второе, а потом где-то выше уровнем, можно и локализованное сообщение подогнать.
// Исходим из того, что MessageStringType всегда строка однобайтовых символов


//----------------------------------------------------------------------------
// Или не задаём в компайл-тайме inserter?
// template< typename CharType
//         , typename InputIteratorType    = umba::iterator::TextPositionCountingIterator<CharType>
//         , typename InserterIteratorType = umba::null_insert_iterator<CharType>
//         >
template< typename CharType
        , typename MessageStringType    = std::string // std::basic_string<CharType>
        , typename InputIteratorType    = umba::iterator::TextPositionCountingIterator<CharType>
        >
struct ITokenizerLiteralParser
{
    using value_type = CharType;

    virtual void reset() = 0;
    virtual StringLiteralParsingResult parseChar(InputIteratorType it, ITokenizerLiteralCharInserter<CharType> *pInserter, MessageStringType *pMsg) = 0;

protected:

    static
    void setMessage(MessageStringType *pMsg, const MessageStringType &msg) 
    {
        if (pMsg)
           *pMsg = msg;
    }

    static
    void insertChar(ITokenizerLiteralCharInserter<CharType> *pInserter, CharType ch)
    {
        if (pInserter)
            pInserter->insert(ch);
    }

}; // struct ITokenizerLiteralParser

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Литерал парсер, который тупо заканчивает разбор на закрывающей кавычке, никаких escape-последовательностей не умеет, может обрабатывать как quot, так и apos литералы, quot может быть внутри apos литерала, и наоборот, но quot не может быть внутри quot литерала
/*! Литерал парсер... Что я тут хотел написать?
*/

template< typename CharType
        , typename MessageStringType    = std::string // std::basic_string<CharType>
        , typename InputIteratorType    = umba::iterator::TextPositionCountingIterator<CharType>
        >
class SimpleQuotedStringLiteralParser : public ITokenizerLiteralParser<CharType, MessageStringType, InputIteratorType>
{

protected:

    enum State
    {
        stInitial,
        stRead
    };

    CharType quotType = 0;
    State    st       = stInitial;


public:

    void reset()
    {
        quotType = 0;
        st       = stInitial;
    }

    virtual StringLiteralParsingResult parseChar(InputIteratorType it, ITokenizerLiteralCharInserter<CharType> *pInserter, MessageStringType *pMsg) override
    {
        if (st==stInitial)
        {
            quotType = *it;
            st = stRead;
        }
        else
        {
            if (*it==quotType)
            {
                return StringLiteralParsingResult::okStop;
            }
            else
            {
                insertChar(pInserter, *it);
            }
        }

        return StringLiteralParsingResult::okContinue;
    }


}; // class SimpleQuotedStringLiteralParser

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! SimpleQuoted, хотя и CppEscaped - потому, что он не парсит сырые литералы, и всякие другие новые модные плюсовые строковые литералы
//! ExtraEscapes позволяют заменять кастомные escape последовательности на произвольные строки
template< typename CharType
        , typename MessageStringType    = std::string // std::basic_string<CharType>
        , typename InputIteratorType    = umba::iterator::TextPositionCountingIterator<CharType>
        , typename ExtraEscapesMapType  = std::unordered_map<CharType, std::basic_string<CharType> >
        >
class CppEscapedSimpleQuotedStringLiteralParser : public ITokenizerLiteralParser<CharType, MessageStringType, InputIteratorType>
{

    using InterfaceParentType = ITokenizerLiteralParser<CharType, MessageStringType, InputIteratorType>;

protected:

    // Про плюсовые литералы ссылок
    // Пользовательские литералы в C++11 - https://habr.com/ru/articles/140357/
    // Escape-последовательности - https://learn.microsoft.com/ru-ru/cpp/c-language/escape-sequences?view=msvc-170
    // Строковые и символьные литералы (C++) - https://learn.microsoft.com/ru-ru/cpp/cpp/string-and-character-literals-cpp?view=msvc-170
    // Numeric, boolean, and pointer literals - https://learn.microsoft.com/en-us/cpp/cpp/numeric-boolean-and-pointer-literals-cpp?view=msvc-170

    // Юникодные литералы поддерживаем, но юникодные HEX последовательности не поддерживаем пока при выводе в в inserter, если у нас парсер char, а не wchar_t.

    enum State
    {
        stInitial                   ,
        stWideWaitQuot              ,
        stReadChars                 ,
        stWaitEscapeData            ,
        stReadEscapeNumericSequence
    };

    CharType             quotType              = 0;
    State                st                    = stInitial;
    bool                 wideLiteral           = false;
    std::uint_least32_t  hexCode               = 0; // also for octal code too
    unsigned             numReadedHexItems     = 0; // also for octal code too
    unsigned             hexBase               = 0; // also for octal code too

    bool                 allowEscapedLfContinuation = true ;
    bool                 warnOnUnknownEscape        = true ;
    bool                 disableStandardEscapes     = false;
    ExtraEscapesMapType  extraEscapes;


    CharType getKnownEcapedCharCode(CharType ch) const
    {
        // Совсем-совсем базовые последовательности не запрещаются
        switch(ch)
        {
            case (CharType)'\'': return (CharType)'\'';
            case (CharType)'\"': return (CharType)'\"';
            case (CharType)'\\': return (CharType)'\\';
        }

        if (disableStandardEscapes)
            return (CharType)0; // если ничего не найдено

        switch(ch)
        {
            case (CharType)'n': return (CharType)'\n';
            case (CharType)'t': return (CharType)'\t';
            case (CharType)'r': return (CharType)'\r';
            case (CharType)'b': return (CharType)'\b';
            case (CharType)'f': return (CharType)'\f';
            case (CharType)'v': return (CharType)'\v';
            case (CharType)'a': return (CharType)'\a';
            case (CharType)'?': return (CharType)'?';
            default: return (CharType)0; // если ничего не найдено
        }
    }

    auto getExtraEscapeCharSequence(CharType ch) const
    {
        auto it = extraEscapes.find(ch);

        // Секреты auto и decltype - https://habr.com/ru/articles/206458/
        // https://stackoverflow.com/questions/25732386/what-is-stddecay-and-when-it-should-be-used
        if (it==extraEscapes.end())
            return std::decay_t<decltype(it->second)>();
        return it->second;
    }


    bool isValidHexDigit(CharType ch) const
    {
        int d = utils::charToDigit(ch);
        if (d<0)
            return false;

        if ((unsigned)d<hexBase)
            return true;

        return false;
    }

    void initHexSequence(unsigned base, int d=0)
    {
        UMBA_ASSERT(base==8u || base==16u);
        hexCode           = (base==8) ? (unsigned)d : 0u; // воьмеричная - есть сразу первая цифра, для HEX'а первой цифры нет
        numReadedHexItems = (base==8) ? 1 : 0;
        hexBase           = base;
    }

    bool addHexSequenceDigit(int d)
    {
        if (d<0)
            return false;
        if ((unsigned)d>=hexBase)
            return false;

        hexCode*=hexBase;
        hexCode+=(unsigned)d;

        ++numReadedHexItems;

        return true;
    }

    bool addHexSequenceChar(CharType ch)
    {
        return addHexSequenceDigit(utils::charToDigit(ch));
    }

    bool canAddHexDigit() const
    {
        if (hexBase==8)
        {
            return numReadedHexItems < 3;
        }
        else
        {
            unsigned maxHexDigits = wideLiteral ? 8 : 2;
            return numReadedHexItems < maxHexDigits;
        }
    }


public:

    CppEscapedSimpleQuotedStringLiteralParser& setContinuationMode(bool allowEscapedLfContinuation_=true)
    {
        allowEscapedLfContinuation = allowEscapedLfContinuation_;
        return *this;
    }

    CppEscapedSimpleQuotedStringLiteralParser& setWarnOnUnknownEscape(bool warn=true)
    {
        warnOnUnknownEscape = warn;
        return *this;
    }

    CppEscapedSimpleQuotedStringLiteralParser& setDisableStandardEscapes(bool disable=true)
    {
        disableStandardEscapes = disable;
        return *this;
    }

    CppEscapedSimpleQuotedStringLiteralParser& setExtraEscapes(const ExtraEscapesMapType &extra)
    {
        extraEscapes = extra;
    }



    void reset()
    {
        quotType          = 0;
        st                = stInitial;
        wideLiteral       = false;
        hexCode           = 0;
        numReadedHexItems = 0;
        hexBase           = 0;
    }

    // \a     Звонок (предупреждение)
    // \b     Backspace
    // \f     Подача страницы
    // \n     Новая строка
    // \r     Возврат каретки
    // \t     Горизонтальная табуляция
    // \v     Вертикальная табуляция
    // \'     Одиночная кавычка
    // \"     Двойная кавычка
    // \\     Обратная косая черта
    // \?     Литерал вопросительного знака
    // \ooo     Символ ASCII в восьмеричной нотации
    // \x hh     Символ ASCII в шестнадцатеричной нотации
    // \x hhhh     Символ юникода в шестнадцатеричном формате, если эта escape-последовательность используется в многобайтовой знаковой константе или строковом литерале юникода.

    virtual StringLiteralParsingResult parseChar(InputIteratorType it, ITokenizerLiteralCharInserter<CharType> *pInserter, MessageStringType *pMsg) override
    {
        CharType ch = *it;

        switch(st)
        {
            case stInitial:
            {
                 if (ch=='L') // а маленькая L считается за маркер юникодного литерала?
                 {
                     st = stWideWaitQuot;
                     wideLiteral = true;
                 }
                 else if (ch=='\'' || ch=='\"')
                 {
                     st = stReadChars;
                     quotType = ch;
                 }
                 else
                 {
                     //!!! В MSVC работает, в GCC надо через явное указание базы
                     InterfaceParentType::setMessage(pMsg, "unrecognised string literal type");
                     return StringLiteralParsingResult::error;
                 }
            }
            break;

            case stWideWaitQuot:
            {
                 if (ch=='\'' || ch=='\"')
                 {
                     st = stReadChars;
                     quotType = ch;
                 }
                 else
                 {
                     InterfaceParentType::setMessage(pMsg, "unrecognised wide string literal type");
                     return StringLiteralParsingResult::error;
                 }
            }
            break;

            ReadCharsLabel:
            case stReadChars:
            {
                if (ch=='\\')
                {
                    st = stWaitEscapeData;
                }
                else if (ch==quotType) // сравниваем с той кавычкой, что была на входе, противоположные кавычки '<->" внутри допустимы, они не заканчивают строку
                {
                    return StringLiteralParsingResult::okStop;
                }
                else if (ch=='\r' || ch=='\n')
                {
                    InterfaceParentType::setMessage(pMsg, (quotType=='\"') ? "missing terminating quot ('\"')" : "missing terminating apos (\"'\")");
                    return StringLiteralParsingResult::error;
                }
                else // просто символ
                {
                    InterfaceParentType::insertChar(pInserter, ch);
                    return StringLiteralParsingResult::okContinue;
                }
            }
            break;

            case stWaitEscapeData:
            {
                auto extraEsc = getExtraEscapeCharSequence(ch);
                CharType knownEsc = getKnownEcapedCharCode(ch);
                int d = utils::charToDigit(ch);

                if (!extraEsc.empty())
                {
                    st = stReadChars;
                    for(auto ech : extraEsc)
                        InterfaceParentType::insertChar(pInserter, ech);
                    return StringLiteralParsingResult::okContinue;
                }
                else if (knownEsc!=0)
                {
                    st = stReadChars;
                    InterfaceParentType::insertChar(pInserter, knownEsc);
                    return StringLiteralParsingResult::okContinue;
                }
                else if (ch=='x' || ch=='X') // А большой X допустим в шестнадцатиричных esc-последовательностях?
                {
                    st = stReadEscapeNumericSequence;
                    initHexSequence(16);
                    return StringLiteralParsingResult::okContinue;
                }
                else if (d>=0 && d<8)
                {
                    st = stReadEscapeNumericSequence;
                    initHexSequence(8, d);
                    return StringLiteralParsingResult::okContinue;
                }
                else if (ch=='\n' || ch=='\r')
                {
                    if (allowEscapedLfContinuation)
                    {
                        st = stReadChars;
                        return StringLiteralParsingResult::okContinue;
                    }
                    else
                    {
                        InterfaceParentType::setMessage(pMsg, (quotType=='\"') ? "missing terminating quot ('\"')" : "missing terminating apos (\"'\")");
                        return StringLiteralParsingResult::error;
                    }
                }
                else // вроде все варианты проверили
                {
                    st = stReadChars;
                    InterfaceParentType::insertChar(pInserter, ch);
                    if (warnOnUnknownEscape)
                        InterfaceParentType::setMessage(pMsg, "unknown escape sequence char");
                    return StringLiteralParsingResult::warnContinue;
                }
            }
            break;

            case stReadEscapeNumericSequence:
            {
                if (isValidHexDigit(ch) && canAddHexDigit())
                {
                    addHexSequenceChar(ch);
                    return StringLiteralParsingResult::okContinue;
                }
                goto ReadCharsLabel;
            }
            break;

        }

        return StringLiteralParsingResult::okContinue;
    }

}; // class CppEscapedSimpleQuotedStringLiteralParser

    // enum State
    // {
    //     stInitial,
    //     stWideWaitQuot,
    //     stReadChars,
    //     stWaitEscape
    // };





// enum class StringLiteralParsingResult : unsigned
// {
//     okContinue    , // Нормас, продолжаем парсить
//     okStop        , // Нормас, обнаружен конец литерала
//     warnContinue  , // Предупреждение - некорректная строка, но обработку можно продолжить
//     warnStop      , // Предупреждение - некорректная строка, и производим нормальную обработку парсинга
//     error           // Ошибка, останавливает парсинг
// };


//----------------------------------------------------------------------------
// Tokenizer

// TrieBuilder
/*

Разбираем текст на токены.

Какие бывают токены.

Пробелы - это сами пробелы, табуляция, переводы строки и тп.

Операторы. Это все символы пунктуации, операторов, скобок, брейсов и тп в различных комбинациях. (или скобки, брейсы - не операторные символы?)

Литералы.

  Литералы числовые - тут всё понятно

  Литералы строковые.

      Примитивные варианты - бэктик, apos и quot - начинаются с определённого символа

      Сложные варианты - начинаются с последовательности символов

      Очень сложные варианты - начинаются с последовательности символов, часть из которых вариативная, и участвует в определении конца литерала


Что мы будем делать?

Пока не будем парится по сложным строковым литералам.
Также не будем поддерживать экспоненциальную форму чисел с плавающей точкой.


1) Делаем таблицу, из которой получаем класс символа
   Таблица - это 128 позиций на базоые ASCII-символы
   Делаем это не вручную.
   Таблица генерируется не константная, надо уметь менять её в рантайме - например,
   чтобы управлять поведением символов $/@ в зависимости от контекста - то ли они могутт быть в идентификаторе, то ли нет

   а) Имеем список операторов с названиями - "!==" -> "STRICT_NEQ"
      Все операторы разбираем посимвольно, для каждого символа ставим флаг CharClass::opchar

   б) Всё, что меньше пробела - флаг nonprintable, а также 0x7F
      \r, \n - linefeed
      \t     - tab
      \r, \n, \t, ' ' - space

   в) кавычка, двойная кавычка, бэктик - quot
   г) Для {}()<>[] - расставляем флаги brace, open, close
   д) ! ? , . ( ) - punctuation (что ещё?) - можно добавлять/менять в рантайме
   е) A-Za-z - alpha, identifier, identifier_first
   ж) 0-9    - digit, identifier
   з) '-'    - hyphen, opchar
   и) '_'    - underscore, identifier, identifier_first


2) Для каждого opchar приписываем ему индекс.

   Также у нас есть таблица операторов. Что там?

   Как мы обрабатываем операторы.
   У нас есть длина текущего оператора. Изначально она равна нулю.
   Получили opchar. Лезем в первую таблицу (по индексу 0).
   Видим там идентификатор оператора. Также видим флаг, что может быть продолжение.
   Тогда ждём следующего символа.
   Если нет продолжения, то сразу выплёвываем токен (если он там есть, иначе - ошибка).


   Зачем бы это делать? Уменьшить

  opchar - нельзя менять в рантайме



Операторы
+
-
*
/
%
^
&
|
~
!
=
<
>
+=
-=
*=
/=
%=
^=
&=
|=
<<
>>
>>=
<<=
==
!=
<=
>=
<=>
(since C++20)
&&
||
++
--
,
->*
.*
->
(
)
[
]


Операторы (всевозможные)

@
$

===
!==
<-
---

*/


} // namespace tokenizer
} // namespace umba