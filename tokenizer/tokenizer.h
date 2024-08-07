#pragma once

#ifndef UMBA_TOKENIZER_H__DCAEEDE0_7624_4E47_9919_08460EF65A3B__
    #error "Do not include this file directly, include 'umba/tokenizer.h header instead'"
#endif


// umba::tokenizer::
namespace umba {
namespace tokenizer {


template< typename CharType            // Input chars type
        , typename CharClassTable      = std::array<CharClass, 128>
        , typename TrieVector          = std::vector<TrieNode>
        , typename StringType          = std::basic_string<CharType>  // Тип строки, которая хранит входные символы
        , typename MessagesStringType  = std::string  // Тип строки, которая используется для сообщений (в том числе и от внешних суб-парсеров)
        , typename InputIteratorType   = umba::iterator::TextPositionCountingIterator<CharType>
        >
using Tokenizer = TokenizerFunctionHandlers< CharType, CharClassTable, TrieVector, StringType, MessagesStringType, InputIteratorType >;



} // namespace tokenizer
} // namespace umba

