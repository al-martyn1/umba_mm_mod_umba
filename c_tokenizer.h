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
        #define UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE  uintptr_t
    #else
        #define UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE  std::uintptr_t
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
    UMBA_TOKENIZER_TOKEN_TYPE            token                ; // Токен или символ
    UMBA_TOKENIZER_PAYLOAD_TYPE          payload              ; // Полезная нагрузка
    UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE    payloadExtra         ; // Пользовательские флаги или данные, влезает указатель

#if !defined(UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE)
    UMBA_TOKENIZER_TRIE_INDEX_TYPE       level                ; // Нужно, чтобы делать красивый граф таблицы trie
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
    pNode->payloadExtra          = 0;
#endif
}


/* Dummy/control tokens without any payload and iterators, only signals for something special */

// Control tokens flag
#define UMBA_TOKENIZER_TOKEN_CTRL_FLAG                                                0x8000u


// Control token, which finalizes input
#define UMBA_TOKENIZER_TOKEN_CTRL_FIN                                                 (UMBA_TOKENIZER_TOKEN_CTRL_FLAG|0x0000u) /* empty token, finalizes processing current text */



#define UMBA_TOKENIZER_TOKEN_UNEXPECTED                                               0x0000u
#define UMBA_TOKENIZER_TOKEN_LINEFEED                                                 0x0001u
#define UMBA_TOKENIZER_TOKEN_SPACE                                                    0x0002u
#define UMBA_TOKENIZER_TOKEN_TAB                                                      0x0003u
#define UMBA_TOKENIZER_TOKEN_FORM_FEED                                                0x0004u /* Надо добавить поддержку FF */
#define UMBA_TOKENIZER_TOKEN_IDENTIFIER                                               0x0005u
#define UMBA_TOKENIZER_TOKEN_SEMIALPHA                                                0x0006u
#define UMBA_TOKENIZER_TOKEN_ESCAPE                                                   0x0007u
#define UMBA_TOKENIZER_TOKEN_LINE_CONTINUATION                                        0x0008u

#define UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_OPEN                                       0x0011u
#define UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_CLOSE                                      0x0012u
#define UMBA_TOKENIZER_TOKEN_CURLY_BRACKETS                                           UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_OPEN
#define UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_OPEN                                       0x0021u
#define UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_CLOSE                                      0x0022u
#define UMBA_TOKENIZER_TOKEN_ROUND_BRACKETS                                           UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_OPEN
#define UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_OPEN                                       0x0031u
#define UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_CLOSE                                      0x0032u
#define UMBA_TOKENIZER_TOKEN_ANGLE_BRACKETS                                           UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_OPEN
#define UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_OPEN                                      0x0041u
#define UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_CLOSE                                     0x0042u
#define UMBA_TOKENIZER_TOKEN_SQUARE_BRACKETS                                          UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_OPEN



#define UMBA_TOKENIZER_TOKEN_FLOAT_FLAG                                               0x0080u

#define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER                                          0x1000u
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER                                             (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST                                     UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_LAST                                      0x1FFFu

#define UMBA_TOKENIZER_TOKEN_NUMBER_USER_LITERAL_FIRST                                (UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST+1)
#define UMBA_TOKENIZER_TOKEN_NUMBER_USER_LITERAL_LAST                                 0x11FFu


// Кодируем признаки числового литерала
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FLAG_MISS_DIGIT                           0x0800u  /* После префикса может не быть ни одной цифры */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_MASK                                 0x0700u  /* Маска для системы счисления */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DEC                                  0x0000u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_BIN                                  0x0100u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_QUAT                                 0x0200u  /* четвертичная quaternary number system */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_OCT                                  0x0300u
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DUOD                                 0x0400u  /* двенадцатеричная duodecimal number system */
#define UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_HEX                                  0x0500u


// #define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER                                          0x1000u
#define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DEC                                      (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DEC )
#define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_BIN                                      (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_BIN )
#define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_QUAT                                     (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_QUAT)
#define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_OCT                                      (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_OCT )
#define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DUOD                                     (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_DUOD)
#define UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_HEX                                      (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_BASE_HEX )

// #define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER                                             (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER|UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER_DEC                                         (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DEC |UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER_BIN                                         (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_BIN |UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER_QUAT                                        (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_QUAT|UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER_OCT                                         (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_OCT |UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER_DUOD                                        (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DUOD|UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
#define UMBA_TOKENIZER_TOKEN_FLOAT_NUMBER_HEX                                         (UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_HEX |UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)



#define UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST                                           0x2000u
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LAST                                            0x2FFFu

#define UMBA_TOKENIZER_TOKEN_USER_OPERATOR_FIRST                                      0x2800u
#define UMBA_TOKENIZER_TOKEN_USER_OPERATOR_LAST                                       UMBA_TOKENIZER_TOKEN_OPERATOR_LAST


#define UMBA_TOKENIZER_TOKEN_STRING_LITERAL_FIRST                                     0x3000u
#define UMBA_TOKENIZER_TOKEN_STRING_LITERAL_LAST                                      0x3FFFu

#define UMBA_TOKENIZER_TOKEN_STRING_LITERAL                                           0x3000u
#define UMBA_TOKENIZER_TOKEN_CHAR_LITERAL                                             0x3001u
#define UMBA_TOKENIZER_TOKEN_ANGLE_BACKETS_STRING_LITERAL                             0x3002u
#define UMBA_TOKENIZER_TOKEN_RAW_STRING_LITERAL                                       0x3003u

#define UMBA_TOKENIZER_TOKEN_STRING_USER_LITERAL_FIRST                                0x3010u
#define UMBA_TOKENIZER_TOKEN_STRING_USER_LITERAL_LAST                                 UMBA_TOKENIZER_TOKEN_LITERAL_LAST


// На каждый сет встроенных кейвордов - по 1024 значений хватит?

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET1_FIRST                                       0x4000u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET1_LAST                                        0x43FFu

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET2_FIRST                                       0x4400u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET2_LAST                                        0x47FFu

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET3_FIRST                                       0x4800u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET3_LAST                                        0x4BFFu

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET4_FIRST                                       0x4C00u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET4_LAST                                        0x4CFFu

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET5_FIRST                                       0x5000u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET5_LAST                                        0x53FFu

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET6_FIRST                                       0x5400u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET6_LAST                                        0x57FFu

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET7_FIRST                                       0x5800u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET7_LAST                                        0x5BFFu

#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET8_FIRST                                       0x5C00u
#define UMBA_TOKENIZER_TOKEN_KEYWORD_SET8_LAST                                        0x5CFFu


// #define UMBA_TOKENIZER_TOKEN_CTRL_PP_DEFINE                                           (UMBA_TOKENIZER_TOKEN_CTRL_FLAG|0x0003u) /* empty token, that "define" PP directive detected. Non-paired token */
// #define UMBA_TOKENIZER_TOKEN_CTRL_PP_INCLUDE                                          (UMBA_TOKENIZER_TOKEN_CTRL_FLAG|0x0004u) /* empty token, that "include" PP directive detected. Non-paired token */



#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST                       (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x010u)  /*  //    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_LAST                        (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x01Fu)  /*        */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT                             UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST


#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_START                        (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x021u)  /*        */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_END                          (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x022u)  /*        */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FLAG_AS_REGULAR_OPERATOR                                         0x040u   /*        */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST_AS_REGULAR_OPERATOR   (UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST|UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FLAG_AS_REGULAR_OPERATOR)
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_LAST_AS_REGULAR_OPERATOR    (UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_LAST |UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FLAG_AS_REGULAR_OPERATOR)


#define UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST_GENERIC                            (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x030u)

// C++
// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

#define UMBA_TOKENIZER_TOKEN_OPERATOR_ADDITION                                 (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x130u)  /*  +    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_ONE_MORE_REPETITION                      UMBA_TOKENIZER_TOKEN_OPERATOR_ADDITION        /*  +  regex mark alias */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SUBTRACTION                              (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x131u)  /*  -    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION                           (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x132u)  /*  *    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_ANY_NUM_REPETITIONS                      UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION  /*  *   regex mark alias */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_DIVISION                                 (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x133u)  /*  /    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MODULO                                   (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x134u)  /*  %    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_INCREMENT                                (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x135u)  /*  ++   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_DECREMENT                                (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x136u)  /*  --   */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_EQUAL                                    (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x140u)   /*  ==   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_NOT_EQUAL                                (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x141u)   /*  !=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_GREATER                                  (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x142u)   /*  >    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LESS                                     (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x143u)   /*  <    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_GREATER_EQUAL                            (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x144u)   /*  >=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LESS_EQUAL                               (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x145u)   /*  <=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_THREE_WAY_COMPARISON                     (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x146u)   /*  <=>  */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_NOT                              (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x150u)   /*  !    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_AND                              (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x151u)   /*  &&   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_OR                               (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x152u)   /*  ||   */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_NOT                              (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x160u)   /*  ~    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_AND                              (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x161u)   /*  &    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_OR                               (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x162u)   /*  |    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_XOR                              (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x163u)   /*  ^    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT                       (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x164u)   /*  <<   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT                      (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x165u)   /*  >>   */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_BNF_ALTER                                UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_OR


#define UMBA_TOKENIZER_TOKEN_OPERATOR_ASSIGNMENT                               (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x170u)   /*  =    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_ADDITION_ASSIGNMENT                      (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x171u)   /*  +=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SUBTRACTION_ASSIGNMENT                   (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x172u)   /*  -=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION_ASSIGNMENT                (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x173u)   /*  *=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_DIVISION_ASSIGNMENT                      (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x174u)   /*  /=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MODULO_ASSIGNMENT                        (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x175u)   /*  %=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_AND_ASSIGNMENT                   (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x176u)   /*  &=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_OR_ASSIGNMENT                    (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x177u)   /*  |=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_XOR_ASSIGNMENT                   (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x178u)   /*  ^=   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT_ASSIGNMENT            (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x179u)   /*  <<=  */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT_ASSIGNMENT           (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x17Au)   /*  >>=  */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_PASCAL_ASSIGNMENT                        (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x17Bu)   /*  :=   */
// https://stackoverflow.com/questions/7294217/scala-what-do-and-operator-do
// Also used in BNF notation
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SCALA_CONCAT_ASSIGNMENT                  (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x17Cu)   /*  ::=   */


// https://en.cppreference.com/w/cpp/language/operator_member_access
#define UMBA_TOKENIZER_TOKEN_OPERATOR_STRUCTURE_DEREFERENCE                    (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x180u)   /*  ->   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_MEMBER_OF_POINTER                        (UMBA_TOKENIZER_TOKEN_OPERATOR_STRUCTURE_DEREFERENCE)
#define UMBA_TOKENIZER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_POINTER             (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x181u)   /*  ->*  */ /* Member of object   selected by pointer-to-member b of object pointed to by a 'a->*b' */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_OBJECT              (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x182u)   /*  .*   */ /* Member of object a selected by pointer-to-member b 'a.*b' */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_DOT                                      (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x183u)   /*  .    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_COMMA                                    (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x184u)   /*  ,    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_COLON                                    (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x185u)   /*  :    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_SEMICOLON                                (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x186u)   /*  ;    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_QMARK                                    (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x187u)   /*  ?    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_ZERO_OR_ONE_REPETITIONS                  UMBA_TOKENIZER_TOKEN_OPERATOR_QMARK            /*  regex mark alias */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_TERNARY_CONDITIONAL                      UMBA_TOKENIZER_TOKEN_OPERATOR_QMARK
#define UMBA_TOKENIZER_TOKEN_OPERATOR_TERNARY_ALTERNATIVE                      UMBA_TOKENIZER_TOKEN_OPERATOR_COLON
#define UMBA_TOKENIZER_TOKEN_OPERATOR_EXPRESSION_END                           UMBA_TOKENIZER_TOKEN_OPERATOR_SEMICOLON

#define UMBA_TOKENIZER_TOKEN_OPERATOR_SCOPE_RESOLUTION                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x190u)   /*  ::   */


//  "new slot" operator '<-' - http://squirrel-lang.org/doc/squirrel3.html#tableconstructor
//  => C# - operator lambda  - https://learn.microsoft.com/ru-ru/dotnet/csharp/language-reference/operators/lambda-operator
//     JS - https://ru.stackoverflow.com/questions/528707/%D0%9E%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80-%D0%B2-javascript
//          https://developer.mozilla.org/ru/docs/Web/JavaScript/Reference/Functions/Arrow_functions

#define UMBA_TOKENIZER_TOKEN_OPERATOR_NEW_SLOT                                 (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1A0u)   /*  <-  */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_LAMBDA                                   (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1A1u)   /*  =>  */


// ===  JS Strict_equality -  https://developer.mozilla.org/ru/docs/Web/JavaScript/Reference/Operators/Strict_equality
#define UMBA_TOKENIZER_TOKEN_OPERATOR_STRICT_EQUAL                             (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1A2u)   /*  ===   */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_STRICT_NOT_EQUAL                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1A3u)   /*  !==   */

#define UMBA_TOKENIZER_TOKEN_OPERATOR_AT                                       (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1A4u)   /*  @     */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_HASH                                     (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1A5u)   /*  #     */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_USD                                      (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x1A6u)   /*  $     */





// C/C++ препроцессор относится ко второму набору ключевых слов
#define UMBA_TOKENIZER_TOKEN_CC_PP_BASE                                        UMBA_TOKENIZER_TOKEN_KEYWORD_SET2_FIRST

#define UMBA_TOKENIZER_TOKEN_CC_PP_INCLUDE                                     (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0008u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_DEFINE                                      (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0009u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_UNDEF                                       (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x000Au)
                                                                              
#define UMBA_TOKENIZER_TOKEN_CC_PP_LINE                                        (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0010u)
                                                                              
#define UMBA_TOKENIZER_TOKEN_CC_PP_ERROR                                       (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0020u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_WARNING                                     (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0021u)
                                                                              
#define UMBA_TOKENIZER_TOKEN_CC_PP_PRAGMA                                      (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0030u)
                                                                              
#define UMBA_TOKENIZER_TOKEN_CC_PP_IF                                          (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0040u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_ELIF                                        (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0041u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_ELSE                                        (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0042u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_ENDIF                                       (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0043u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_IFDEF                                       (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0044u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_IFNDEF                                      (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0045u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_ELIFDEF                                     (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0046u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_ELIFNDEF                                    (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0047u)
                                                                              
#define UMBA_TOKENIZER_TOKEN_CC_PP_DEFINED                                     (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0050u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_HAS_INCLUE                                  (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0051u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_HAS_CPP_ATTRIBUTE                           (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0052u)
                                                                              
#define UMBA_TOKENIZER_TOKEN_CC_PP_EXPORT                                      (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0060u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_IMPORT                                      (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0061u)
#define UMBA_TOKENIZER_TOKEN_CC_PP_MODULE                                      (UMBA_TOKENIZER_TOKEN_CC_PP_BASE|0x0062u)


// #define UMBA_TOKENIZER_TOKEN_CTRL_FLAG                                                0x8000u

#define UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_START                                  (UMBA_TOKENIZER_TOKEN_CTRL_FLAG|0x0001u)                            /* empty token, signals that C/C++ preprocessor mode starts */
#define UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_END                                    (UMBA_TOKENIZER_TOKEN_CTRL_FLAG|0x0002u)                            /* empty token, signals that C/C++ preprocessor mode ends */
#define UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_DEFINE                                 (UMBA_TOKENIZER_TOKEN_CTRL_FLAG|UMBA_TOKENIZER_TOKEN_CC_PP_DEFINE)  /* empty token, that "define" PP directive detected. Non-paired token */
#define UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_INCLUDE                                (UMBA_TOKENIZER_TOKEN_CTRL_FLAG|UMBA_TOKENIZER_TOKEN_CC_PP_INCLUDE) /* empty token, that "include" PP directive detected. Non-paired token */



#if 0
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#define UMBA_TOKENIZER_TOKEN_OPERATOR_                                         (UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST+0x100)u   /*    */
#endif





