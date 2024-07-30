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
    #defined UMBA_TOKEN_TRIE_FIND_NEXT_BINARY_SEARCH_CHUNK_SIZE_LIMIT  4u
#endif

//----------------------------------------------------------------------------
#include "c_tokenizer.h"
//
#include "char_class.h"

//
#include <map>
#include <deque>
#include <iostream>
#include <algorithm>
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

    // Чанк небольшой, фигачим линейным поиском
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
void tokenTriePrintGraph(const ContainerType &tokenTrie, StreamType &s, TokenToStringConverter converter)
{
    // requires UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE is not defined

    s << "digraph structs {\nnode [shape=record];\n";


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
                if (ch=='\'' || ch=='\"' || ch=='\\' || ch=='<' || ch=='>' || ch=='|')
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