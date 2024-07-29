#pragma once

#if !defined(__cplusplus)
    #include <stddef.h>
    #include <stdint.h>
#else
    #include <cstddef>
    #include <cstdint>
#endif

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


#if defined(UMBA_TOKENISER_TYPES_COMPACT)

    #if !defined(UMBA_TOKENISER_TRIE_NODE_LEVEL_FIELD_DISABLE)
        #define UMBA_TOKENISER_TRIE_NODE_LEVEL_FIELD_DISABLE
    #endif

#endif



#include "c_char_class.h"


// std::size_t https://stackoverflow.com/questions/36594569/which-header-should-i-include-for-size-t

#if !defined(UMBA_TOKENISER_TRIE_INDEX_TYPE)
    #if !defined(__cplusplus)

        #if defined(UMBA_TOKENISER_TYPES_COMPACT)
            #define UMBA_TOKENISER_TRIE_INDEX_TYPE  uint_least16_t
        #else
            #define UMBA_TOKENISER_TRIE_INDEX_TYPE  size_t
        #endif

    #else

        #if defined(UMBA_TOKENISER_TYPES_COMPACT)
            #define UMBA_TOKENISER_TRIE_INDEX_TYPE  std::uint_least16_t
        #else
            #define UMBA_TOKENISER_TRIE_INDEX_TYPE  std::size_t
        #endif

    #endif
#endif

#if !defined(UMBA_TOKENISER_TRIE_INDEX_INVALID)
    #define UMBA_TOKENISER_TRIE_INDEX_INVALID ((UMBA_TOKENISER_TRIE_INDEX_TYPE)-1)
#endif

#if !defined(UMBA_TOKENISER_TRIE_INDEX_INITIAL)
    #define UMBA_TOKENISER_TRIE_INDEX_INITIAL ((UMBA_TOKENISER_TRIE_INDEX_TYPE)0)
#endif



#if !defined(UMBA_TOKENISER_TOKEN_ID_TYPE)
    #if !defined(__cplusplus)

        #if defined(UMBA_TOKENISER_TYPES_COMPACT)
            #define UMBA_TOKENISER_TOKEN_ID_TYPE  uint_least16_t
        #else
            #define UMBA_TOKENISER_TOKEN_ID_TYPE  size_t
        #endif

    #else

        #if defined(UMBA_TOKENISER_TYPES_COMPACT)
            #define UMBA_TOKENISER_TOKEN_ID_TYPE  std::uint_least16_t
        #else
            #define UMBA_TOKENISER_TOKEN_ID_TYPE  std::size_t
        #endif

    #endif
#endif

#if !defined(UMBA_TOKENISER_TOKEN_ID_INVALID)
    #define UMBA_TOKENISER_TOKEN_ID_INVALID ((UMBA_TOKENISER_TOKEN_ID_TYPE)-1)
#endif


typedef struct tag_umba_tokeniser_trie_node
{
    UMBA_TOKENISER_TRIE_INDEX_TYPE       parentNodeIndex      ;
    UMBA_TOKENISER_TRIE_INDEX_TYPE       lookupChunkStartIndex; /* Одно и то же значение для всех элементов lookupChunk'а */
    UMBA_TOKENISER_TRIE_INDEX_TYPE       lookupChunkSize      ; /* Одно и то же значение для всех элементов lookupChunk'а */
    UMBA_TOKENISER_TRIE_INDEX_TYPE       childsIndex          ;
#if !defined(UMBA_TOKENISER_TRIE_NODE_LEVEL_FIELD_DISABLE)
    UMBA_TOKENISER_TRIE_INDEX_TYPE       level                ; // Нужно, чтобы делать красивый граф таблицы trie
#endif
    UMBA_TOKENISER_TOKEN_ID_TYPE         tokenId              ;
    char                                 symbol               ;

} umba_tokeniser_trie_node;


static inline
void umba_tokeniser_trie_node_init_make_uninitialized(umba_tokeniser_trie_node *pNode)
{
    pNode->parentNodeIndex       = UMBA_TOKENISER_TRIE_INDEX_INVALID;
    pNode->lookupChunkStartIndex = UMBA_TOKENISER_TRIE_INDEX_INVALID;
    pNode->lookupChunkSize       = 0;
    pNode->childsIndex           = UMBA_TOKENISER_TRIE_INDEX_INVALID;
#if !defined(UMBA_TOKENISER_TRIE_NODE_LEVEL_FIELD_DISABLE)
    pNode->level                 = 0;
#endif
    pNode->tokenId               = UMBA_TOKENISER_TOKEN_ID_INVALID;
    pNode->symbol                = 0;
}



#define UMBA_TOKENISER_TOKEN_OPERATOR_FIRST                                    0

// C++
// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

#define UMBA_TOKENISER_TOKEN_OPERATOR_ADDITION                                 UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x10u  /*  +    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_SUBTRACTION                              UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x11u  /*  -    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_MULTIPLICATION                           UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x12u  /*  *    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_DIVISION                                 UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x13u  /*  /    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_MODULO                                   UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x14u  /*  %    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_INCREMENT                                UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x15u  /*  ++   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_DECREMENT                                UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x16u  /*  --   */

#define UMBA_TOKENISER_TOKEN_OPERATOR_EQUAL                                    UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x20u   /*  ==   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_NOT_EQUAL                                UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x21u   /*  !=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_GREATER                                  UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x22u   /*  >    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_LESS                                     UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x23u   /*  <    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_GREATER_EQUAL                            UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x24u   /*  >=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_LESS_EQUAL                               UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x25u   /*  <=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_THREE_WAY_COMPARISON                     UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x26u   /*  <=>  */

#define UMBA_TOKENISER_TOKEN_OPERATOR_LOGICAL_NOT                              UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x30u   /*  !    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_LOGICAL_AND                              UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x31u   /*  &&   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_LOGICAL_OR                               UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x32u   /*  ||   */

#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_NOT                              UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x40u   /*  ~    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_AND                              UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x41u   /*  &    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_OR                               UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x42u   /*  |    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_XOR                              UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x43u   /*  ^    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT                       UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x44u   /*  <<   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT                      UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x45u   /*  >>   */


#define UMBA_TOKENISER_TOKEN_OPERATOR_ASSIGNMENT                               UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x50u   /*  =    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_ADDITION_ASSIGNMENT                      UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x51u   /*  +=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_SUBTRACTION_ASSIGNMENT                   UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x52u   /*  -=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_MULTIPLICATION_ASSIGNMENT                UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x53u   /*  *=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_DIVISION_ASSIGNMENT                      UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x54u   /*  /=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_MODULO_ASSIGNMENT                        UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x55u   /*  %=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_AND_ASSIGNMENT                   UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x56u   /*  &=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_OR_ASSIGNMENT                    UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x57u   /*  |=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_XOR_ASSIGNMENT                   UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x58u   /*  ^=   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT_ASSIGNMENT            UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x59u   /*  <<=  */
#define UMBA_TOKENISER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT_ASSIGNMENT           UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x5Au   /*  >>=  */

// https://en.cppreference.com/w/cpp/language/operator_member_access
#define UMBA_TOKENISER_TOKEN_OPERATOR_STRUCTURE_DEREFERENCE                    UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x50u   /*  ->   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_MEMBER_OF_POINTER                        UMBA_TOKENISER_TOKEN_OPERATOR_STRUCTURE_DEREFERENCE
#define UMBA_TOKENISER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_POINTER             UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x52u   /*  ->*  */ /* Member of object   selected by pointer-to-member b of object pointed to by a 'a->*b' */
#define UMBA_TOKENISER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_OBJECT              UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x53u   /*  .*   */ /* Member of object a selected by pointer-to-member b 'a.*b' */

#define UMBA_TOKENISER_TOKEN_OPERATOR_DOT                                      UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x60u   /*  .    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_COMMA                                    UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x61u   /*  ,    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_COLON                                    UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x62u   /*  :    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_SEMICOLON                                UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x63u   /*  ;    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_QMARK                                    UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x64u   /*  ?    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_TERNARY_CONDITIONAL                      UMBA_TOKENISER_TOKEN_OPERATOR_QMARK
#define UMBA_TOKENISER_TOKEN_OPERATOR_TERNARY_ALTERNATIVE                      UMBA_TOKENISER_TOKEN_OPERATOR_COLON
#define UMBA_TOKENISER_TOKEN_OPERATOR_EXPRESSION_END                           UMBA_TOKENISER_TOKEN_OPERATOR_SEMICOLON

#define UMBA_TOKENISER_TOKEN_OPERATOR_SCOPE_RESOLUTION                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x70u   /*  ::   */


//  "new slot" operator '<-' - http://squirrel-lang.org/doc/squirrel3.html#tableconstructor
//  => C# - operator lambda  - https://learn.microsoft.com/ru-ru/dotnet/csharp/language-reference/operators/lambda-operator
//     JS - https://ru.stackoverflow.com/questions/528707/%D0%9E%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80-%D0%B2-javascript
//          https://developer.mozilla.org/ru/docs/Web/JavaScript/Reference/Functions/Arrow_functions

#define UMBA_TOKENISER_TOKEN_OPERATOR_LAMBDA                                   UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x80u   /*  =>  */


// ===  JS Strict_equality -  https://developer.mozilla.org/ru/docs/Web/JavaScript/Reference/Operators/Strict_equality
#define UMBA_TOKENISER_TOKEN_OPERATOR_STRICT_EQUAL                             UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x81u   /*  ===   */
#define UMBA_TOKENISER_TOKEN_OPERATOR_STRICT_NOT_EQUAL                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x82u   /*  !==   */

#if 0
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#define UMBA_TOKENISER_TOKEN_OPERATOR_                                         UMBA_TOKENISER_TOKEN_OPERATOR_FIRST+0x00u   /*    */
#endif





