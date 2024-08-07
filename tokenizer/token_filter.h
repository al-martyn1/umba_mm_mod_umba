#pragma once

#ifndef UMBA_TOKENIZER_H__DCAEEDE0_7624_4E47_9919_08460EF65A3B__
    #error "Do not include this file directly, include 'umba/tokenizer.h header instead'"
#endif

/*

Фильтры инсталлируются в токенизер в начало цепочки.
Для этого у tokenizer'а есть шаблонный метод:

  template<typename FilterType, typename... FilterTypeArgs >
  void installTokenFilter( FilterTypeArgs... args)

Мы не передаём экземпляр фильтра в installTokenFilter, мы его создаём внутри метода installTokenFilter,
и передаём параметры для инициализации в метод installTokenFilter

Сам фильтр должен иметь конструктор

  Filter(Tokenizer::token_handler_type prevHandler, FilterTypeArgs... args )

Схематоз такой: сначала добавляется финальный обработчик, затем добавляются фильтры в цепочку обработчиков,
в начало, при этом существующий обработчик вставляется после добавляемого.



template< typename CharType            // Input chars type
        , typename CharClassTableType  = std::array<CharClass, 128>
        , typename TrieVectorType      = std::vector<TrieNode>
        , typename StringType          = std::basic_string<CharType>  // Тип строки, которая хранит входные символы
        , typename MessagesStringType  = std::string  // Тип строки, которая используется для сообщений (в том числе и от внешних суб-парсеров)
        , typename InputIteratorType   = umba::iterator::TextPositionCountingIterator<CharType>
        >


using token_handler_type                         = std::function<bool( bool
                                                                     , payload_type
                                                                     , InputIteratorType
                                                                     , InputIteratorType
                                                                     , std::basic_string_view<value_type>
                                                                     , messages_string_type&)
                                                                     >;

*/


// umba::tokenizer::
namespace umba {
namespace tokenizer {


template<typename TokenizerType>
struct SimplePassTroughTokenizerFilter
{

    using typename TokenizerType::token_handler_type token_handler_type;

    using char_type                = typename TokenizerType::char_type            ;
    using value_type               = typename TokenizerType::value_type           ;
    using char_class_table_type    = typename TokenizerType::char_class_table_type;
    using trie_vector_type         = typename TokenizerType::trie_vector_type     ;
    using string_type              = typename TokenizerType::string_type          ;
    using iterator_type            = typename TokenizerType::iterator_type        ;
    using messages_string_type     = typename TokenizerType::messages_string_type ;


    token_handler_type nextTokenHandler;

    SimplePassTroughTokenizerFilter(token_handler_type curTokenHandler)
    : nextTokenHandler(curTokenHandler)
    {}

    bool operator()( bool                                 lineStartFlag
                   , umba::tokenizer::payload_type        payloadToken
                   , iterator_type                        b
                   , iterator_type                        e
                   , std::basic_string_view<value_type>   strValue
                   , messages_string_type                 &msg
                   )
    {
        if (nextTokenHandler)
            return nextTokenHandler(lineStartFlag, payloadToken, b, e, strValue, msg);
        return true;
    }

};



} // namespace tokenizer
} // namespace umba



