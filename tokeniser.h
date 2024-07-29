#pragma once

#if defined(UMBA_TOKENISER_TYPES_COMPACT)
    #if !defined(UMBA_CHAR_CLASS_UNDERLYING_COMPACT)
        #define UMBA_CHAR_CLASS_UNDERLYING_COMPACT
    #endif
#endif

#if defined(UMBA_CHAR_CLASS_UNDERLYING_COMPACT)
    #if !defined(UMBA_TOKENISER_TYPES_COMPACT)
        #define UMBA_TOKENISER_TYPES_COMPACT
    #endif
#endif

//----------------------------------------------------------------------------
#include "c_tokeniser.h"
//
#include "char_class.h"

//
#include <map>
#include <deque>
#include <iostream>

//
#include "umba/assert.h"


//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

// Наткнулся тут
// #include "microcode_tokenizer.h"
// В каком-то проекте же делал, надо поискать, что там

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

// umba::tokeniser::
namespace umba {
namespace tokeniser {



//----------------------------------------------------------------------------
using  trie_index_type                                     = UMBA_TOKENISER_TRIE_INDEX_TYPE;
inline constexpr const trie_index_type trie_index_invalid  = UMBA_TOKENISER_TRIE_INDEX_INVALID;
inline constexpr const trie_index_type trie_index_initial  = UMBA_TOKENISER_TRIE_INDEX_INITIAL;

//----------------------------------------------------------------------------
using  token_id_type                                       = UMBA_TOKENISER_TOKEN_ID_TYPE;
inline constexpr const token_id_type token_id_invalid      = UMBA_TOKENISER_TOKEN_ID_INVALID;

//----------------------------------------------------------------------------
using TrieNode = umba_tokeniser_trie_node;

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline
void trieNodeInitMakeUninitialized(TrieNode &node)
{
    umba_tokeniser_trie_node_init_make_uninitialized(&node);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename ContainerType>
trie_index_type tokenTrieFindNext(const ContainerType &tokenTrie, trie_index_type curIndex, char ch)
{
    // Если на входе инвалид, то начинать надо со старта

    trie_index_type lookupChunkStartIdx  = 0;
    trie_index_type lookupChunkSize      = 0;

    if (curIndex==umba::tokeniser::trie_index_invalid)
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
        // if (levelStartIdx>=tokenTrie.size()) // тут бы assert, тут не штатная ситуация
        // {
        //     return umba::tokeniser::trie_index_invalid;
        // }

        lookupChunkSize = tokenTrie[levelStartIdx].lookupChunkSize;
    }

    for(trie_index_type i=0; i!=lookupChunkSize; ++i)
    {
        const auto idx = lookupChunkStartIdx + i;
        UMBA_ASSERT(idx<tokenTrie.size());
        // if (idx>=tokenTrie.size()) // тут бы assert, тут не штатная ситуация
        // {
        //     return umba::tokeniser::trie_index_invalid;
        // }

        if (tokenTrie[idx].symbol==ch)
            return idx;

        if (tokenTrie[idx].symbol>ch)
            return trie_index_invalid; // у нас символы отсортированы по возрастанию, и если код искомого символа больше того, что мы обнаружили в очередной entry, то дальше искать нет смысла
    }

    return trie_index_invalid; // Не нашли, обломс
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
class TrieBuilder
{

protected:

    struct TrieBuilderMapNode
    {
        umba::tokeniser::TrieNode             trieNode;
        std::map<char, TrieBuilderMapNode>    childs  ;
    
        TrieBuilderMapNode() : trieNode(), childs()
        {
            trieNodeInitMakeUninitialized(trieNode);
        }
    
        TrieBuilderMapNode(const TrieBuilderMapNode &) = default;
        TrieBuilderMapNode& operator=(const TrieBuilderMapNode &) = default;
        TrieBuilderMapNode(TrieBuilderMapNode &&) = default;
        TrieBuilderMapNode& operator=(TrieBuilderMapNode &&) = default;
    
    };
    
    typedef std::map<char, TrieBuilderMapNode> TrieNodesMap;


public: // пока public, потом, скорее всего, будет спрятано

    TrieNodesMap     m_trieNodesMap;

public:

    bool addTokenSequence(const std::string &seqStr, token_id_type tokenId)
    {
        UMBA_ASSERT(!seqStr.empty());

        TrieNodesMap *pCurMap  = &m_trieNodesMap;
        MapTrieNode  *pCurNode = 0;

        for(auto ch: seqStr)
        {
            TrieNodesMap 
            &curMap  = *pCurMap;
            pCurNode = &curMap[ch]; // .second;
            pCurMap  = &pCurNode->childs;

            pCurNode->trieNode.symbol = ch;

            // ++finalTableNumEntries;
        }

        // Прошагали всё символы обрабатываемой строки
        // Финальный узел у нас есть

        if (pCurNode->trieNode.tokenId!=token_id_invalid && pCurNode->trieNode.tokenId!=tokenId)
            return false; // Такой путь в дереве уже есть, и там другой идентификатор токена

        // Записываем туда идентификатор оператора
        pCurNode->trieNode.tokenId = token;

        return true;
    }



}; // class TrieBuilder


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

  Префиксные деревья (без них таки никак)
  https://ru.hexlet.io/courses/algorithms-trees/lessons/prefix/theory_unit
  https://habr.com/ru/companies/otus/articles/676692/
  https://otus.ru/nest/post/676/


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


} // namespace tokeniser
} // namespace umba