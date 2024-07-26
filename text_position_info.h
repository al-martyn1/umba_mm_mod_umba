#pragma once


// #if defined(UMBA_TOKENISER_TYPES_COMPACT)
//     #if !defined(UMBA_CHAR_CLASS_UNDERLYING_COMPACT)
//         #define UMBA_CHAR_CLASS_UNDERLYING_COMPACT
//     #endif
// #endif


// umba::
namespace umba {


// Храним
// Смещение начала текущей строки от начала текста
// Смещение текущей позиции от начала текущей строки
// Номер текущей строки
// Что-то ещё?

#if defined(UMBA_TEXT_POSITION_INFO_COMPACT)

    using symbol_offset_type = std::uint_least16_t;  // Тип смещения текущей позиции от начала строки
    using line_number_type   = std::uint_least16_t;  // В компактном варианте строк не должно быть больше 64К - ну а куда больше-то для микроконтроллера?
    using line_offset_type   = std::size_t;          // А вот всего текста даже в компактном варианте может быть больше 64К символов

#else

    using symbol_offset_type = std::size_t;          // Тип смещения текущей позиции от начала строки
    using line_number_type   = std::size_t;

#endif








} // namespace umba


