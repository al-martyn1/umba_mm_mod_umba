#pragma once

#include "umba/umba.h"
//
#include "umba/tokenizer.h"
#include "umba/tokenizer/token_filters.h"
#include "umba/tokenizer/string_literal_parsing.h"
#include "umba/string_plus.h"



// umba::tokenizer::
namespace umba {
namespace tokenizer {


template< typename CharType            // Input chars type
        , typename CharClassTableType  = std::array<CharClass, 128>
        , typename TrieVectorType      = std::vector<TrieNode>
        , typename StringType          = std::basic_string<CharType>  // Тип строки, которая хранит входные символы
        , typename MessagesStringType  = std::string  // Тип строки, которая используется для сообщений (в том числе и от внешних суб-парсеров)
        , typename InputIteratorType   = umba::iterator::TextPositionCountingIterator<CharType>
        , typename InputIteratorTraits = umba::iterator::TextIteratorTraits<InputIteratorType>
        , typename TokenizerType       = Tokenizer< CharType, CharClassTableType, TrieVectorType, StringType, MessagesStringType, InputIteratorType >
        >
TokenizerBuilder<CharType, CharClassTableType, TrieVectorType, StringType, MessagesStringType, InputIteratorType, InputIteratorTraits, TokenizerType>
makeTokenizerBuilderPlantUml()
{
    using CppStringLiteralParser     = CppEscapedSimpleQuotedStringLiteralParser<CharType, MessagesStringType, InputIteratorType, InputIteratorTraits>;
    //using AngleBracketsLiteralParser = SimpleQuotedStringLiteralParser<CharType, MessagesStringType, InputIteratorType, InputIteratorTraits>;

    using umba::string_plus::make_string;

    auto tokenizerBuilder = TokenizerBuilder<CharType, CharClassTableType, TrieVectorType, StringType, MessagesStringType, InputIteratorType, InputIteratorTraits, TokenizerType>()

                          .generateStandardCharClassTable()


                          .addNumbersPrefix(make_string<StringType>("0b"), UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_BIN)
                          .addNumbersPrefix(make_string<StringType>("0B"), UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_BIN, true) // allowUseExistingToken

                          .addNumbersPrefix(make_string<StringType>("0d"), UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DEC)
                          .addNumbersPrefix(make_string<StringType>("0D"), UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DEC, true) // allowUseExistingToken

                          .addNumbersPrefix(make_string<StringType>("0") , UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_OCT | UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FLAG_MISS_DIGIT)

                          .addNumbersPrefix(make_string<StringType>("0x"), UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_HEX)
                          .addNumbersPrefix(make_string<StringType>("0X"), UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_HEX, true) // allowUseExistingToken


                          .addBrackets(make_string<StringType>("{}"), UMBA_TOKENIZER_TOKEN_CURLY_BRACKETS )
                          .addBrackets(make_string<StringType>("()"), UMBA_TOKENIZER_TOKEN_ROUND_BRACKETS )
                          .addBrackets(make_string<StringType>("<>"), UMBA_TOKENIZER_TOKEN_ANGLE_BRACKETS )
                          .addBrackets(make_string<StringType>("[]"), UMBA_TOKENIZER_TOKEN_SQUARE_BRACKETS)


                          .addSingleLineComment(make_string<StringType>("'"), UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST)
                          .setMultiLineComment(make_string<StringType>("/'"), make_string<StringType>("'/"))



                          .addOperator(make_string<StringType>("#"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_HASH                          )
                          .addOperator(make_string<StringType>("@"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_AT                            )
 
                          //.addOperator(make_string<StringType>("[*]"), UMBA_TOKENIZER_TOKEN_OPERATOR_PSEUDO_STATE                    )

                          .addOperator(make_string<StringType>("+"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_ADDITION                      )
                          .addOperator(make_string<StringType>("-"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_SUBTRACTION                   )
                          .addOperator(make_string<StringType>("*"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION                )
                          .addOperator(make_string<StringType>("/"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_DIVISION                      )

                          .addOperator(make_string<StringType>(":"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_COLON                         )

                          .addOperator(make_string<StringType>("->"              ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )
                          .addOperator(make_string<StringType>("-->"             ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )
                          .addOperator(make_string<StringType>("--->"            ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )
                          .addOperator(make_string<StringType>("---->"           ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )
                          .addOperator(make_string<StringType>("----->"          ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )
                          .addOperator(make_string<StringType>("------>"         ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )
                          .addOperator(make_string<StringType>("------->"        ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )
                          .addOperator(make_string<StringType>("-------->"       ), UMBA_TOKENIZER_TOKEN_OPERATOR_TRANSITION, true )

                          

                          #if 0
                          .addOperator(make_string<StringType>("%"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_MODULO                        )

                          .addOperator(make_string<StringType>("++" ), UMBA_TOKENIZER_TOKEN_OPERATOR_INCREMENT                     )
                          .addOperator(make_string<StringType>("--" ), UMBA_TOKENIZER_TOKEN_OPERATOR_DECREMENT                     )
                          .addOperator(make_string<StringType>("==" ), UMBA_TOKENIZER_TOKEN_OPERATOR_EQUAL                         )
                          .addOperator(make_string<StringType>("!=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_NOT_EQUAL                     )
                          .addOperator(make_string<StringType>(">"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_GREATER                       )
                          .addOperator(make_string<StringType>("<"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_LESS                          )
                          .addOperator(make_string<StringType>(">=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_GREATER_EQUAL                 )
                          .addOperator(make_string<StringType>("<=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_LESS_EQUAL                    )
                          .addOperator(make_string<StringType>("<=>"), UMBA_TOKENIZER_TOKEN_OPERATOR_THREE_WAY_COMPARISON          )
                          .addOperator(make_string<StringType>("!"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_NOT                   )
                          .addOperator(make_string<StringType>("&&" ), UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_AND                   )
                          .addOperator(make_string<StringType>("||" ), UMBA_TOKENIZER_TOKEN_OPERATOR_LOGICAL_OR                    )
                          .addOperator(make_string<StringType>("~"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_NOT                   )
                          .addOperator(make_string<StringType>("&"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_AND                   )
                          .addOperator(make_string<StringType>("|"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_OR                    )
                          .addOperator(make_string<StringType>("^"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_XOR                   )
                          .addOperator(make_string<StringType>("<<" ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT            )
                          .addOperator(make_string<StringType>(">>" ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT           )
                          .addOperator(make_string<StringType>("="  ), UMBA_TOKENIZER_TOKEN_OPERATOR_ASSIGNMENT                    )
                          .addOperator(make_string<StringType>("+=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_ADDITION_ASSIGNMENT           )
                          .addOperator(make_string<StringType>("-=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_SUBTRACTION_ASSIGNMENT        )
                          .addOperator(make_string<StringType>("*=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION_ASSIGNMENT     )
                          .addOperator(make_string<StringType>("/=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_DIVISION_ASSIGNMENT           )
                          .addOperator(make_string<StringType>("%=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_MODULO_ASSIGNMENT             )
                          .addOperator(make_string<StringType>("&=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_AND_ASSIGNMENT        )
                          .addOperator(make_string<StringType>("|=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_OR_ASSIGNMENT         )
                          .addOperator(make_string<StringType>("^=" ), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_XOR_ASSIGNMENT        )
                          .addOperator(make_string<StringType>("<<="), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_LEFT_ASSIGNMENT )
                          .addOperator(make_string<StringType>(">>="), UMBA_TOKENIZER_TOKEN_OPERATOR_BITWISE_SHIFT_RIGHT_ASSIGNMENT)
                          .addOperator(make_string<StringType>(","  ), UMBA_TOKENIZER_TOKEN_OPERATOR_COMMA)
                          .addOperator(make_string<StringType>("->" ), UMBA_TOKENIZER_TOKEN_OPERATOR_MEMBER_OF_POINTER             )
                          .addOperator(make_string<StringType>("->*"), UMBA_TOKENIZER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_POINTER  )
                          .addOperator(make_string<StringType>(".*" ), UMBA_TOKENIZER_TOKEN_OPERATOR_POINTER_TO_MEMBER_OF_OBJECT   )
                          //.addOperator(make_string<StringType>(":"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_TERNARY_ALTERNATIVE           )
                          .addOperator(make_string<StringType>("?"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_TERNARY_CONDITIONAL           )
                          .addOperator(make_string<StringType>("::" ), UMBA_TOKENIZER_TOKEN_OPERATOR_SCOPE_RESOLUTION              )
                          .addOperator(make_string<StringType>(";"  ), UMBA_TOKENIZER_TOKEN_OPERATOR_EXPRESSION_END                )
                          //.addOperator( )
                          #endif

                          .template addStringLiteralParser<CppStringLiteralParser>( UMBA_TOKENIZER_TOKEN_STRING_LITERAL
                                                                                  , { make_string<StringType>("\"")   // UMBA_TOKENIZER_TOKEN_STRING_LITERAL itself
                                                                                    // , make_string<StringType>("\'")   // UMBA_TOKENIZER_TOKEN_CHAR_LITERAL (UMBA_TOKENIZER_TOKEN_STRING_LITERAL+1)
                                                                                    }
                                                                                  )
                          //.template addStringLiteralParser< AngleBracketsLiteralParser >(UMBA_TOKENIZER_TOKEN_ANGLE_BACKETS_STRING_LITERAL, { make_string<StringType>("<") } )

                          ;

    return tokenizerBuilder;

}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
namespace pluntuml {

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

} // namespace pluntuml

//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
template<typename TokenizerBuilder, typename TokenHandler>
typename TokenizerBuilder::tokenizer_type makeTokenizerPlantUml(TokenizerBuilder builder, TokenHandler tokenHandler)
{
    auto tokenizer = builder.makeTokenizer();
    tokenizer.tokenHandler = tokenHandler;

    // !!! Фильтры, установленные позже, отрабатывают раньше

    using SimpleSequenceComposingFilter = umba::tokenizer::filters::SimpleSequenceComposingFilter<typename TokenizerBuilder::tokenizer_type>;

    tokenizer.template installTokenFilter<SimpleSequenceComposingFilter>( UMBA_TOKENIZER_TOKEN_PLANTUML_PSEUDO_STATE // заменяем последовательность на UMBA_TOKENIZER_TOKEN_PLANTUML_PSEUDO_STATE
                                                                        , 0u // Нагрузку берём по нулевому индексу
                                                                        , std::vector<payload_type>{ UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_OPEN, UMBA_TOKENIZER_TOKEN_OPERATOR_MULTIPLICATION, UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_CLOSE }
                                                                        );


    // if (preprocessorFilter)
    //     tokenizer.template installTokenFilter<umba::tokenizer::filters::CcPreprocessorFilter<typename TokenizerBuilder::tokenizer_type> >();
    //  
    // if (suffixGluing)
    //     tokenizer.template installTokenFilter<umba::tokenizer::filters::SimpleSuffixGluingFilter<typename TokenizerBuilder::tokenizer_type> >();

    // // Символ хэша приобретает значение операторного только внутри директивы define
    // // По умолчанию он не операторный
    // // Сбрасываем операторный флаг для символа '#'
    // tokenizer.setResetCharClassFlags('#', umba::tokenizer::CharClass::none, umba::tokenizer::CharClass::opchar); // Ничего не устанавливаем, сбрасываем opchar

    return tokenizer;
}






} // namespace tokenizer
} // namespace umba

