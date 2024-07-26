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


#include "c_tokeniser.h"
//
#include "char_class.h"


// Наткнулся тут
// #include "microcode_tokenizer.h"
// В каком-то проекте же делал, надо поискать, что там


//
namespace umba {
namespace tokeniser {



using trie_index_type               = UMBA_TOKENISER_TRIE_INDEX_TYPE;
inline constexpr trie_index_invalid = UMBA_TOKENISER_TRIE_INDEX_INVALID;

using token_id_type                 = UMBA_TOKENISER_TOKEN_ID_TYPE;
inline constexpr token_id_invalid   = UMBA_TOKENISER_TOKEN_ID_INVALID;




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