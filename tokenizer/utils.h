#pragma once



// umba::tokenizer::
namespace umba {
namespace tokenizer {


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
            s << escapeStringGraphViz(strToken);
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










} // namespace tokenizer
} // namespace umba

