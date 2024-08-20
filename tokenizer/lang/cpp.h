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
        , typename TokenizerType       = Tokenizer< CharType, CharClassTableType, TrieVectorType, StringType, MessagesStringType, InputIteratorType >
        >
TokenizerBuilder<CharType, CharClassTableType, TrieVectorType, StringType, MessagesStringType, InputIteratorType, TokenizerType>
makeTokenizerBuilderCpp()
{
    using CppStringLiteralParser     = CppEscapedSimpleQuotedStringLiteralParser<CharType, MessagesStringType, InputIteratorType>;
    using AngleBracketsLiteralParser = SimpleQuotedStringLiteralParser<CharType, MessagesStringType, InputIteratorType>;

    auto tokenizerBuilder = TokenizerBuilder<CharType, CharClassTableType, TrieVectorType, StringType, MessagesStringType, InputIteratorType, TokenizerType>()

                          .generateStandardCharClassTable()


                          .addNumbersPrefix("0b", UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_BIN)
                          .addNumbersPrefix("0B", UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_BIN, true) // allowUseExistingToken

                          .addNumbersPrefix("0d", UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DEC)
                          .addNumbersPrefix("0D", UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_DEC, true) // allowUseExistingToken

                          .addNumbersPrefix("0" , UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_OCT | UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FLAG_MISS_DIGIT)

                          .addNumbersPrefix("0x", UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_HEX)
                          .addNumbersPrefix("0X", UMBA_TOKENIZER_TOKEN_INTEGRAL_NUMBER_HEX, true) // allowUseExistingToken


                          .addBrackets("{}", UMBA_TOKENIZER_TOKEN_CURLY_BRACKETS )
                          .addBrackets("()", UMBA_TOKENIZER_TOKEN_ROUND_BRACKETS )
                          .addBrackets("<>", UMBA_TOKENIZER_TOKEN_ANGLE_BRACKETS )
                          .addBrackets("[]", UMBA_TOKENIZER_TOKEN_SQUARE_BRACKETS)


                          .addSingleLineComment("//", UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST)
                          .setMultiLineComment("/*", "*/")


                          // Операторы # и ## доступны только внутри директивы define препроцессора.
                          // Для этого вначале работы мы сбрасываем признак umba::tokenizer::CharClass::opchar,
                          // при получении маркера директивы define - устанавливаем его,
                          // и при окончании блока препроцессора опять сбрасываем

                          // Тут надо операторы подключить не оптом, а по одному, с заданием идентификатора каждому персонально
                          .addOperators(UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST_GENERIC, std::vector<StringType>{".","#","##","...",".*","+","-","*","/","%","^","&","|","~","!","=","<",">","+=","-=","*=","/=","%=","^=","&=","|=","<<",">>",">>=","<<=","==","!=","<=",">=","<=>","&&","||","++","--",",","->*","->",":","::",";","?"})

                          .template addStringLiteralParser<CppStringLiteralParser>( UMBA_TOKENIZER_TOKEN_STRING_LITERAL
                                                                                  , { string_plus::make_string<StringType>("\"")   // UMBA_TOKENIZER_TOKEN_STRING_LITERAL itself
                                                                                    , string_plus::make_string<StringType>("\'")   // UMBA_TOKENIZER_TOKEN_CHAR_LITERAL (UMBA_TOKENIZER_TOKEN_STRING_LITERAL+1)
                                                                                    }
                                                                                  )
                          .template addStringLiteralParser< AngleBracketsLiteralParser >(UMBA_TOKENIZER_TOKEN_ANGLE_BACKETS_STRING_LITERAL, { string_plus::make_string<StringType>("<") } )

                          ;

    return tokenizerBuilder;

}

template<typename TokenizerBuilder, typename TokenHandler>
//typename TokenizerBuilder::tokenizer_type makeTokenizerCpp(const TokenizerBuilder &builder, TokenHandler tokenHandler, bool suffixGluing=true, bool preprocessorFilter=true)
typename TokenizerBuilder::tokenizer_type makeTokenizerCpp(TokenizerBuilder builder, TokenHandler tokenHandler, bool suffixGluing=true, bool preprocessorFilter=true)
{
    auto tokenizer = builder.makeTokenizer();
    tokenizer.tokenHandler = tokenHandler;

    // !!! Фильтры, установленные позже, отрабатывают раньше

    if (preprocessorFilter)
        tokenizer.template installTokenFilter<umba::tokenizer::filters::CcPreprocessorFilter<typename TokenizerBuilder::tokenizer_type> >();

    if (suffixGluing)
        tokenizer.template installTokenFilter<umba::tokenizer::filters::SimpleSuffixGluingFilter<typename TokenizerBuilder::tokenizer_type> >();

    return tokenizer;
}






} // namespace tokenizer
} // namespace umba

