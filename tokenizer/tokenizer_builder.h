#pragma once

#ifndef UMBA_TOKENIZER_H__DCAEEDE0_7624_4E47_9919_08460EF65A3B__
    #error "Do not include this file directly, include 'umba/tokenizer.h header instead'"
#endif

#include <unordered_set>
#include <exception>
#include <stdexcept>


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
class TokenizerBuilder
{

//------------------------------
public: // depending types

    using char_type                = CharType;
    using value_type               = CharType;
    using char_class_table_type    = CharClassTableType;
    using trie_vector_type         = TrieVectorType;
    using string_type              = StringType;
    using iterator_type            = InputIteratorType;
    using messages_string_type     = MessagesStringType;
    using tokenizer_type           = TokenizerType;

    using ITokenizerLiteralParser  = umba::tokenizer::ITokenizerLiteralParser<CharType, MessagesStringType, InputIteratorType>;


//------------------------------
protected: // fileds

    char_class_table_type    charClassTable;

    TrieBuilder              numbersTrieBuilder;
    TrieBuilder              bracketsTrieBuilder;
    TrieBuilder              operatorsTrieBuilder;
    TrieBuilder              literalsTrieBuilder ;

    std::string              multiLineCommentEndStr; // Конец многострочного коментария ищем как строку, с забеганием вперёд


    std::unordered_set<payload_type>  addedTokens;


//------------------------------
protected: // methods - helpers

    // Вообще-то надо бы через enable_if провить, есть ли метод resize, но пока так

    template<std::size_t N>
    static
    void checkReserveCharClassTable(std::array<CharClass, N> &cct)
    {
        UMBA_USED(cct);
        UMBA_ASSERT(cct.size()>=128);
    }

    template<typename ContainerType>
    static
    void checkReserveCharClassTable(ContainerType &cct)
    {
        if (cct.size()<128)
            cct.resize(128, CharClass::none);
    }

    bool isCharTableValidSizeAndNonZero() const
    {
        if (charClassTable.size()<128)
            return false;
        for(auto cc : charClassTable)
        {
            if (cc!=CharClass::none)
                return true;
        }
        return false;
    }

    void addTokenToKnownSet(payload_type tk, bool allowExisting=false)
    {
        if (addedTokens.find(tk)!=addedTokens.end())
        {
            if (!allowExisting)
                throw std::runtime_error("token already used");
            return;
        }
        addedTokens.insert(tk);
    }

public:

    TokenizerBuilder& generateStandardCharClassTable()
    {
        checkReserveCharClassTable(charClassTable);
        generation::generateCharClassTable(charClassTable, false /* !addOperatorChars */, false /* addBrackets */ );
        return *this;
    }

    template<typename UpdaterType>
    TokenizerBuilder& generateStandardCharClassTable(UpdaterType updater)
    {
        checkReserveCharClassTable(charClassTable);
        generation::generateCharClassTable(charClassTable, false /* !addOperatorChars */, false /* addBrackets */ );
        updater(charClassTable);
        return *this;
    }

    template<typename GeneratorType>
    TokenizerBuilder& generateCustomCharClassTable(GeneratorType generator)
    {
        checkReserveCharClassTable(charClassTable);
        generator(charClassTable);
        return *this;
    }

    TokenizerBuilder& setCharClassFlags(CharType ch, CharClass clsFlags)
    {
        generation::setCharClassFlags(charClassTable, ch, clsFlags);
        return *this;
    }
    
    TokenizerBuilder& addBrackets(const StringType &bracketsPair, payload_type pairBaseToken)
    {
        UMBA_ASSERT(isCharTableValidSizeAndNonZero()); // need call generateStandardCharClassTable/generateCustomCharClassTable first

        if (bracketsPair.size()!=2)
            throw std::runtime_error("requires exact brackets pair");

        //TODO: !!! Проверить, что pairBaseToken один из:
        // UMBA_TOKENIZER_TOKEN_CURLY_BRACKETS
        // UMBA_TOKENIZER_TOKEN_ROUND_BRACKETS
        // UMBA_TOKENIZER_TOKEN_ANGLE_BRACKETS
        // UMBA_TOKENIZER_TOKEN_SQUARE_BRACKETS
        // или 0, для автоопределения, и сделать автоопределение

        addTokenToKnownSet(pairBaseToken  );
        addTokenToKnownSet(pairBaseToken+1);

        generation::setCharClassFlagsForBracePair(charClassTable, bracketsPair);
        bracketsTrieBuilder.addTokenSequence(bracketsPair[0], pairBaseToken  );
        bracketsTrieBuilder.addTokenSequence(bracketsPair[1], pairBaseToken+1);

        return *this;
    }

    TokenizerBuilder& addNumbersPrefix(const StringType &prefix, payload_type tokenId, bool allowUseExistingToken=false) // 
    {
        UMBA_ASSERT(isCharTableValidSizeAndNonZero()); // need call generateStandardCharClassTable/generateCustomCharClassTable first

        if (prefix.empty())
            throw std::runtime_error("number literal prefix can't be empty");

        if (!umba::TheFlags(charClassTable[charToCharClassTableIndex(prefix[0])]).oneOf(CharClass::digit))
            throw std::runtime_error("number literal prefix must starts with digit");

        //TODO: !!! Подумать, как сделать, чтобы числа можно было начинать с символов @ # $
        //TODO: !!! Проверить tokenId на вхождение в диапазон, или сделать автоопределение

        addTokenToKnownSet(tokenId, allowUseExistingToken);
        // numbersTrieBuilder.addTokenSequence(prefix, tokenId); // Не понятно, с чего я продублировал тут и на следующей строке в if'е - переглючило, наверное. Но может, был какой-то скрытый смысл
        if (numbersTrieBuilder.addTokenSequence(prefix, tokenId).payload!=tokenId)
            throw std::runtime_error("number literal prefix already used");

        return *this;
    }

    TokenizerBuilder& addSingleLineComment(const StringType &seq, payload_type tokenId, bool allowUseExistingToken=false)
    {
        UMBA_ASSERT(isCharTableValidSizeAndNonZero()); // need call generateStandardCharClassTable/generateCustomCharClassTable first

        if (seq.empty())
            throw std::runtime_error("single line comment sequence can't be empty");

        //TODO: !!! Проверить tokenId на вхождение в диапазон, или сделать автоопределение

        addTokenToKnownSet(tokenId, allowUseExistingToken);
        if (operatorsTrieBuilder.addTokenSequence(seq, tokenId).payload!=tokenId)
            throw std::runtime_error("single line comment sequence already used");

        generation::setCharClassFlags(charClassTable, seq, CharClass::opchar);

        return *this;
    }

    TokenizerBuilder& setMultiLineComment(const StringType &seqStart, const StringType &seqEnd, payload_type tokenId=payload_invalid)
    {
        UMBA_ASSERT(isCharTableValidSizeAndNonZero()); // need call generateStandardCharClassTable/generateCustomCharClassTable first

        if (seqStart.empty())
            throw std::runtime_error("multi line comment start sequence can't be empty");

        if (seqEnd.empty())
            throw std::runtime_error("multi line comment end sequence can't be empty");

        if (tokenId==payload_invalid)
            tokenId = UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_START;

        addTokenToKnownSet(tokenId);
        if (operatorsTrieBuilder.addTokenSequence(seqStart, tokenId).payload!=tokenId)
            throw std::runtime_error("multiline comment start sequence already used");

        // for(auto it=seqStart; it!=seqEnd; ++it)
        //     generation::setCharClassFlags(charClassTable, seq, CharClass::opchar);
        generation::setCharClassFlags(charClassTable, seqStart, CharClass::opchar);

        multiLineCommentEndStr = seqEnd;

        return *this;
    }

    TokenizerBuilder& addOperator(const StringType &seq, payload_type tokenId, bool allowUseExistingToken=false)
    {
        UMBA_ASSERT(isCharTableValidSizeAndNonZero()); // need call generateStandardCharClassTable/generateCustomCharClassTable first

        if (seq.empty())
            throw std::runtime_error("operator sequence can't be empty");

        //TODO: !!! Проверить tokenId на вхождение в диапазон, или сделать автоопределение

        addTokenToKnownSet(tokenId, allowUseExistingToken);
        if (operatorsTrieBuilder.addTokenSequence(seq, tokenId).payload!=tokenId)
            throw std::runtime_error("operator sequence already used");

        generation::setCharClassFlags(charClassTable, seq, CharClass::opchar);

        return *this;
    }

    template<typename StringContainerType>
    TokenizerBuilder& addOperators(payload_type tokenId, const StringContainerType ops)
    {
        for(const auto &op : ops)
        {
            addOperator(op, tokenId++);
        }

        return *this;
    }

    TokenizerBuilder& addStringLiteralParser(const StringType &seq, ITokenizerLiteralParser *pParser, payload_type tokenId=payload_invalid)
    {
        UMBA_ASSERT(isCharTableValidSizeAndNonZero()); // need call generateStandardCharClassTable/generateCustomCharClassTable first

        if (seq.empty())
            throw std::runtime_error("string literal prefix sequence can't be empty");

        generation::setCharClassFlags(charClassTable, seq[0], CharClass::string_literal_prefix);
        if (tokenId==payload_invalid)
            tokenId = UMBA_TOKENIZER_TOKEN_STRING_LITERAL;

        literalsTrieBuilder.addTokenSequence(seq, tokenId).payloadExtra = reinterpret_cast<payload_type>(pParser);

        return *this;
    }

    tokenizer_type makeTokenizer() const
    {
        tokenizer_type tokenizer;

        tokenizer.setCharClassTable(charClassTable);

        typename tokenizer_type::trie_vector_type  numbersTrie  ;
        typename tokenizer_type::trie_vector_type  bracketsTrie ;
        typename tokenizer_type::trie_vector_type  operatorsTrie;
        typename tokenizer_type::trie_vector_type  literalsTrie ;

        numbersTrieBuilder  .buildTokenTrie(numbersTrie  );
        bracketsTrieBuilder .buildTokenTrie(bracketsTrie );
        operatorsTrieBuilder.buildTokenTrie(operatorsTrie);
        literalsTrieBuilder .buildTokenTrie(literalsTrie );

        tokenizer.setNumbersTrie  (numbersTrie  );
        tokenizer.setBracketsTrie (bracketsTrie );
        tokenizer.setOperatorsTrie(operatorsTrie);
        tokenizer.setLiteralsTrie (literalsTrie );

        tokenizer.setMultiLineCommentEndString(multiLineCommentEndStr);

        return tokenizer;
    }



}; // class TokenizerBuilder





} // namespace tokenizer
} // namespace umba

