#pragma once

#if !defined(__cplusplus)
    #include <stddef.h>
    #include <stdint.h>
#else
    #include <cstddef>
    #include <cstdint>
#endif

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


#if defined(UMBA_TOKENIZER_TYPES_COMPACT)

    #if !defined(UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE)
        #define UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE
    #endif

#endif



#include "c_char_class.h"


// std::size_t https://stackoverflow.com/questions/36594569/which-header-should-i-include-for-size-t

#if !defined(UMBA_TOKENIZER_TRIE_INDEX_TYPE)
    #if !defined(__cplusplus)

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_TRIE_INDEX_TYPE  uint_least16_t
        #else
            #define UMBA_TOKENIZER_TRIE_INDEX_TYPE  size_t
        #endif

    #else

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_TRIE_INDEX_TYPE  std::uint_least16_t
        #else
            #define UMBA_TOKENIZER_TRIE_INDEX_TYPE  std::size_t
        #endif

    #endif
#endif

#if !defined(UMBA_TOKENIZER_TRIE_INDEX_INVALID)
    #define UMBA_TOKENIZER_TRIE_INDEX_INVALID ((UMBA_TOKENIZER_TRIE_INDEX_TYPE)-1)
#endif

// #if !defined(UMBA_TOKENIZER_TRIE_INDEX_INITIAL)
//     #define UMBA_TOKENIZER_TRIE_INDEX_INITIAL ((UMBA_TOKENIZER_TRIE_INDEX_TYPE)0)
// #endif



#if !defined(UMBA_TOKENIZER_TOKEN_TYPE)
    #if !defined(__cplusplus)

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_TOKEN_TYPE  uint_least16_t
        #else
            #define UMBA_TOKENIZER_TOKEN_TYPE  size_t
        #endif

    #else

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_TOKEN_TYPE  std::uint_least16_t
        #else
            #define UMBA_TOKENIZER_TOKEN_TYPE  std::size_t
        #endif

    #endif
#endif

#if !defined(UMBA_TOKENIZER_TOKEN_INVALID)
    #define UMBA_TOKENIZER_TOKEN_INVALID ((UMBA_TOKENIZER_TOKEN_TYPE)-1)
#endif



#if !defined(UMBA_TOKENIZER_PAYLOAD_TYPE)
    #if !defined(__cplusplus)

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_PAYLOAD_TYPE  uint_least16_t
        #else
            #define UMBA_TOKENIZER_PAYLOAD_TYPE  size_t
        #endif

    #else

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_PAYLOAD_TYPE  std::uint_least16_t
        #else
            #define UMBA_TOKENIZER_PAYLOAD_TYPE  std::size_t
        #endif

    #endif
#endif

#if !defined(UMBA_TOKENIZER_PAYLOAD_INVALID)
    #define UMBA_TOKENIZER_PAYLOAD_INVALID ((UMBA_TOKENIZER_PAYLOAD_TYPE)-1)
#endif


#if !defined(UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE)
    #if !defined(__cplusplus)

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE  uint_least16_t
        #else
            #define UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE  uint_least32_t
        #endif

    #else

        #if defined(UMBA_TOKENIZER_TYPES_COMPACT)
            #define UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE  std::uint_least16_t
        #else
            #define UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE  std::uint_least32_t
        #endif

    #endif
#endif



#if defined(UMBA_TOKENIZER_TYPES_COMPACT)
    #include "pushpack1.h"
#endif
typedef struct tag_umba_tokenizer_trie_node
{
    UMBA_TOKENIZER_TRIE_INDEX_TYPE       parentNodeIndex      ;
    UMBA_TOKENIZER_TRIE_INDEX_TYPE       lookupChunkStartIndex; /* Одно и то же значение для всех элементов lookupChunk'а */
    UMBA_TOKENIZER_TRIE_INDEX_TYPE       lookupChunkSize      ; /* Одно и то же значение для всех элементов lookupChunk'а */
    UMBA_TOKENIZER_TRIE_INDEX_TYPE       childsIndex          ;
#if !defined(UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE)
    UMBA_TOKENIZER_TRIE_INDEX_TYPE       level                ; // Нужно, чтобы делать красивый граф таблицы trie
#endif
    UMBA_TOKENIZER_TOKEN_TYPE            token                ; // Токен или символ
    UMBA_TOKENIZER_PAYLOAD_TYPE          payload              ; // Полезная нагрузка
#if !defined(UMBA_TOKENIZER_NO_PAYLOAD_FLAGS)
    UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE    payloadFlags         ; // Пользовательские флаги
#endif

} umba_tokenizer_trie_node;
#if defined(UMBA_TOKENIZER_TYPES_COMPACT)
    #include "packpop.h"
#endif


// Standard mode   : Trie size : 32 items, 1024 bytes
// Compact mode    : Trie size : 32 items, 448 bytes
// Compact no flags: Trie size : 32 items, 384 bytes

static inline
void umba_tokenizer_trie_node_init_make_uninitialized(umba_tokenizer_trie_node *pNode)
{
    pNode->parentNodeIndex       = UMBA_TOKENIZER_TRIE_INDEX_INVALID;
    pNode->lookupChunkStartIndex = UMBA_TOKENIZER_TRIE_INDEX_INVALID;
    pNode->lookupChunkSize       = 0;
    pNode->childsIndex           = UMBA_TOKENIZER_TRIE_INDEX_INVALID;
#if !defined(UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE)
    pNode->level                 = 0;
#endif
    pNode->token                 = UMBA_TOKENIZER_TOKEN_INVALID;
    pNode->payload               = UMBA_TOKENIZER_PAYLOAD_INVALID;
#if !defined(UMBA_TOKENIZER_NO_PAYLOAD_FLAGS)
    pNode->payloadFlags          = 0;
#endif
}



#define UMBA_TOKENIZER_TOKEN_UNEXPECTED                                        0x0000u
#define UMBA_TOKENIZER_TOKEN_LINEFEED                                          0x0001u
#define UMBA_TOKENIZER_TOKEN_SPACE                                             0x0002u
#define UMBA_TOKENIZER_TOKEN_IDENTIFIER                                        0x0003u
#define UMBA_TOKENIZER_TOKEN_SEMIALPHA                                         0x0004u

#define UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_OPEN                                0x0011u
#define UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_CLOSE                               0x0012u
#define UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_OPEN                                0x0021u
#define UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_CLOSE                               0x0022u
#define UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_OPEN                                0x0031u
#define UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_CLOSE                               0x0032u
#define UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_OPEN                               0x0041u
#define UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_CLOSE                              0x0042u


// #define UMBA_TOKENIZER_CHARCLASS_OPEN             0x0010u /* Флаг для парных символов */
// #define UMBA_TOKENIZER_CHARCLASS_CLOSE            0x0020u /* Флаг для парных символов */

#define UMBA_TOKENIZER_TOKEN_NUMBER                                            0x1000u
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER                                      0x1001u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST                              0x1002u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_LAST                               0x11FFu
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_TOTAL_LAST                         0x1FFFu

// Кодируем признаки
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FLAG_MISS_DIGIT                    0x0800u  /* После префикса может не быть ни одной цифры */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_MASK                          0x0700u  /* Маска для системы счисления */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DEC                           0x0000u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_BIN                           0x0100u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_QUAT                          0x0200u  /* четвертичная quaternary number system */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_OCT                           0x0300u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DUOD                          0x0400u  /* двенадцатеричная duodecimal number system */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_HEX                           0x0500u

// quaternary number system


#define UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST                                    0x2000u
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LAST                                     0x2FFFu

#define UMBA_TOKENIZER_TOKEN_USER_LITERAL_FIRST                                0x3000u
#define UMBA_TOKENIZER_TOKEN_USER_LITERAL_LAST                                 0x3FFFu


#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST                UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x10u  /*  //    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_LAST                 UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1Fu  /*  #     */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_START                 UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x21u  /*  //    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_END                   UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x22u  /*  //    */


#define UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST_GENERIC                            UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x30u

// C++
// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

#define UMBA_TOKENIZER_TOKEN_OPERATOR_ADDITION                                 UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x30u  /*  +    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SUBTRACTION                              UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x31u  /*  -    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION                           UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x32u  /*  *    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_DIVISION                                 UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x33u  /*  /    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MODULO                                   UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x34u  /*  %    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_INCREMENT                                UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x35u  /*  ++   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_DECREMENT                                UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x36u  /*  --   */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_EQUAL                                    UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x40u   /*  ==   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_NOT_EQUAL                                UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x41u   /*  !=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_GREATER                                  UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x42u   /*  >    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LESS                                     UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x43u   /*  <    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_GREATER_EQUAL                            UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x44u   /*  >=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LESS_EQUAL                               UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x45u   /*  <=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_THREE_WAY_COMPARISON                     UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x46u   /*  <=>  */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_NOT                              UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x50u   /*  !    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_AND                              UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x51u   /*  &&   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_OR                               UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x52u   /*  ||   */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_NOT                              UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x60u   /*  ~    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_AND                              UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x61u   /*  &    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_OR                               UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x62u   /*  |    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_XOR                              UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x63u   /*  ^    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT                       UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x64u   /*  <<   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT                      UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x65u   /*  >>   */


#define UMBA_TOKENIZER_TOKEN_OPERATOR_ASSIGNMENT                               UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x70u   /*  =    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_ADDITION_ASSIGNMENT                      UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x71u   /*  +=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SUBTRACTION_ASSIGNMENT                   UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x72u   /*  -=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION_ASSIGNMENT                UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x73u   /*  *=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_DIVISION_ASSIGNMENT                      UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x74u   /*  /=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MODULO_ASSIGNMENT                        UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x75u   /*  %=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_AND_ASSIGNMENT                   UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x76u   /*  &=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_OR_ASSIGNMENT                    UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x77u   /*  |=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_XOR_ASSIGNMENT                   UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x78u   /*  ^=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT_ASSIGNMENT            UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x79u   /*  <<=  */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT_ASSIGNMENT           UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x7Au   /*  >>=  */

// https://en.cppreference.com/w/cpp/language/operator_member_access
#define UMBA_TOKENIZER_TOKEN_OPERATOR_STRUCTURE_DEREFERENCE                    UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x70u   /*  ->   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MEMBER_OF_POINTER                        UMBA_TOKENIZER_TOKEN_OPERATOR_STRUCTURE_DEREFERENCE
#define UMBA_TOKENIZER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_POINTER             UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x72u   /*  ->*  */ /* Member of object   selected by pointer-to-member b of object pointed to by a 'a->*b' */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_OBJECT              UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x73u   /*  .*   */ /* Member of object a selected by pointer-to-member b 'a.*b' */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_DOT                                      UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x80u   /*  .    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_COMMA                                    UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x81u   /*  ,    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_COLON                                    UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x82u   /*  :    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SEMICOLON                                UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x83u   /*  ;    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_QMARK                                    UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x84u   /*  ?    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_TERNARY_CONDITIONAL                      UMBA_TOKENIZER_TOKEN_OPERATOR_QMARK
#define UMBA_TOKENIZER_TOKEN_OPERATOR_TERNARY_ALTERNATIVE                      UMBA_TOKENIZER_TOKEN_OPERATOR_COLON
#define UMBA_TOKENIZER_TOKEN_OPERATOR_EXPRESSION_END                           UMBA_TOKENIZER_TOKEN_OPERATOR_SEMICOLON

#define UMBA_TOKENIZER_TOKEN_OPERATOR_SCOPE_RESOLUTION                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x90u   /*  ::   */


//  "new slot" operator '<-' - http://squirrel-lang.org/doc/squirrel3.html#tableconstructor
//  => C# - operator lambda  - https://learn.microsoft.com/ru-ru/dotnet/csharp/language-reference/operators/lambda-operator
//     JS - https://ru.stackoverflow.com/questions/528707/%D0%9E%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80-%D0%B2-javascript
//          https://developer.mozilla.org/ru/docs/Web/JavaScript/Reference/Functions/Arrow_functions

#define UMBA_TOKENIZER_TOKEN_OPERATOR_LAMBDA                                   UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0xA0u   /*  =>  */


// ===  JS Strict_equality -  https://developer.mozilla.org/ru/docs/Web/JavaScript/Reference/Operators/Strict_equality
#define UMBA_TOKENIZER_TOKEN_OPERATOR_STRICT_EQUAL                             UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0xA1u   /*  ===   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_STRICT_NOT_EQUAL                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0xA2u   /*  !==   */

#if 0
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#endif





