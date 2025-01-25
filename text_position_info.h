#pragma once

#if defined(__cplusplus)
    #include <string>
    #include "string_plus.h"
#endif

#if defined(UMBA_TOKENIZER_TYPES_COMPACT)
    #if !defined(UMBA_TEXT_POSITION_INFO_COMPACT)
        #define UMBA_TEXT_POSITION_INFO_COMPACT
    #endif
#endif


#if defined(UMBA_TEXT_POSITION_INFO_COMPACT)
    #if !defined(UMBA_TOKENIZER_TYPES_COMPACT)
        #define UMBA_TOKENIZER_TYPES_COMPACT
    #endif
#endif



// Храним
// Смещение начала текущей строки от начала текста
// Смещение текущей позиции от начала текущей строки
// Номер текущей строки
// Что-то ещё?

#if defined(__cplusplus)

    typedef std::uint16_t umba_text_position_info_symbol_offset_delta_type;
    typedef std::uint16_t umba_text_position_info_line_number_delta_type  ;
    typedef std::uint16_t umba_text_position_info_line_offset_delta_type  ;

    #if defined(UMBA_TEXT_POSITION_INFO_COMPACT)

        typedef std::uint_least16_t umba_text_position_info_file_id_type      ;  // Пользовательский идентификатор файла
        typedef std::uint_least16_t umba_text_position_info_symbol_offset_type;  // Тип смещения текущей позиции от начала строки, в компактном варианте строки не могут быть более 64К длиной.
        typedef std::uint_least16_t umba_text_position_info_line_number_type  ;  // В компактном варианте строк не должно быть больше 64К - ну а куда больше-то для микроконтроллера?
        typedef std::size_t         umba_text_position_info_line_offset_type  ;  // А вот всего текста даже в компактном варианте может быть больше 64К символов

    #else

        typedef std::size_t umba_text_position_info_file_id_type      ;  // Пользовательский идентификатор файла
        typedef std::size_t umba_text_position_info_symbol_offset_type;  // Тип смещения текущей позиции от начала строки
        typedef std::size_t umba_text_position_info_line_number_type  ;
        typedef std::size_t umba_text_position_info_line_offset_type  ;

    #endif

#else

    typedef uint16_t umba_text_position_info_symbol_offset_delta_type;
    typedef uint16_t umba_text_position_info_line_number_delta_type  ;
    typedef uint16_t umba_text_position_info_line_offset_delta_type  ;

    #if defined(UMBA_TEXT_POSITION_INFO_COMPACT)

        typedef uint_least16_t umba_text_position_info_file_id_type      ;  // Пользовательский идентификатор файла
        typedef uint_least16_t umba_text_position_info_symbol_offset_type;  // Тип смещения текущей позиции от начала строки, в компактном варианте строки не могут быть более 64К длиной.
        typedef uint_least16_t umba_text_position_info_line_number_type  ;  // В компактном варианте строк не должно быть больше 64К - ну а куда больше-то для микроконтроллера?
        typedef size_t         umba_text_position_info_line_offset_type  ;  // А вот всего текста даже в компактном варианте может быть больше 64К символов

    #else

        typedef size_t umba_text_position_info_file_id_type      ;  // Пользовательский идентификатор файла
        typedef size_t umba_text_position_info_symbol_offset_type;  // Тип смещения текущей позиции от начала строки
        typedef size_t umba_text_position_info_line_number_type  ;
        typedef size_t umba_text_position_info_line_offset_type  ;

    #endif

#endif


#if defined(UMBA_TEXT_POSITION_INFO_COMPACT)
    #include "pushpack1.h"
#endif
typedef struct tag_umba_text_position_info
{
#if defined(__cplusplus)
    using symbol_offset_type = umba_text_position_info_symbol_offset_type;
    using line_number_type   = umba_text_position_info_line_number_type  ;
    using line_offset_type   = umba_text_position_info_line_offset_type  ;
    using file_id_type       = umba_text_position_info_file_id_type      ;

#endif // #if defined(__cplusplus)

    umba_text_position_info_line_offset_type    lineOffset  ; //!< From data origin to line start
    umba_text_position_info_symbol_offset_type  symbolOffset; //!< From line start
    umba_text_position_info_symbol_offset_type  lineLen     ; //!< From start to first line end symbol or to end of text
    umba_text_position_info_line_number_type    lineNumber  ; //!< Zero based line number
    umba_text_position_info_file_id_type        fileId      ; //!< FileID

#if defined(__cplusplus)

    std::string to_string() const
    {
        return std::to_string(lineNumber+1) + ":" + std::to_string(symbolOffset+1);
    }

    std::wstring to_wstring() const
    {
        return std::to_wstring(lineNumber+1) + L":" + std::to_wstring(symbolOffset+1);
    }

    template<typename StringType>
    StringType toString() const
    {
        //return umba::string_plus::make_string<StringType>(to_string());
        if constexpr (sizeof(typename StringType::value_type)>1)
            return to_wstring();
        else
            return to_string();
    }

#endif // #if defined(__cplusplus)


} umba_text_position_info;


typedef struct tag_umba_text_position_info_no_file_id
{
#if defined(__cplusplus)
    using symbol_offset_type = umba_text_position_info_symbol_offset_type;
    using line_number_type   = umba_text_position_info_line_number_type  ;
    using line_offset_type   = umba_text_position_info_line_offset_type  ;

#endif // #if defined(__cplusplus)

    umba_text_position_info_line_offset_type    lineOffset  ; //!< From data origin to line start
    umba_text_position_info_symbol_offset_type  symbolOffset; //!< From line start
    umba_text_position_info_symbol_offset_type  lineLen     ; //!< From start to first line end symbol or to end of text
    umba_text_position_info_line_number_type    lineNumber  ; //!< Zero based line number

#if defined(__cplusplus)

    std::string to_string() const
    {
        return std::to_string(lineNumber+1) + ":" + std::to_string(symbolOffset+1);
    }

    std::wstring to_wstring() const
    {
        return std::to_wstring(lineNumber+1) + L":" + std::to_wstring(symbolOffset+1);
    }

    template<typename StringType>
    StringType toString() const
    {
        //return umba::string_plus::make_string<StringType>(to_string());
        if constexpr (sizeof(typename StringType::value_type)>1)
            return to_wstring();
        else
            return to_string();
    }

#endif // #if defined(__cplusplus)


} umba_text_position_info_no_file_id;


//! Разница между двумя позициями, все поля дельты не могут превышать 65535
typedef struct tag_umba_text_position_info_compact_delta
{
#if defined(__cplusplus)
    using symbol_offset_delta_type = umba_text_position_info_symbol_offset_delta_type;
    using line_number_delta_type   = umba_text_position_info_line_number_delta_type  ;
    using line_offset_delta_type   = umba_text_position_info_line_offset_delta_type  ;

#endif // #if defined(__cplusplus)

    umba_text_position_info_line_offset_delta_type    lineOffsetDelta  ; //!< From data origin to line start
    umba_text_position_info_symbol_offset_delta_type  symbolOffsetDelta; //!< From line start
    umba_text_position_info_symbol_offset_delta_type  lineLenDelta     ; //!< From start to first line end symbol or to end of text
    umba_text_position_info_line_number_delta_type    lineNumberDelta  ; //!< Zero based line number

} umba_text_position_info_compact_delta;





#if defined(UMBA_TEXT_POSITION_INFO_COMPACT)
    #include "packpop.h"
#endif

static inline
void umba_text_position_info_init(umba_text_position_info *pPos, umba_text_position_info_file_id_type fileId)
{
    pPos->lineOffset   = 0u;
    pPos->symbolOffset = 0u;
    pPos->lineNumber   = 0u;
    pPos->lineLen      = 0u;
    pPos->fileId       = fileId;
}

static inline
void umba_text_position_info_no_file_id_init(umba_text_position_info_no_file_id *pPos)
{
    pPos->lineOffset   = 0u;
    pPos->symbolOffset = 0u;
    pPos->lineNumber   = 0u;
    pPos->lineLen      = 0u;
}


#if defined(__cplusplus)

// umba::
namespace umba {


using TextPositionInfo             = umba_text_position_info;
using TextPositionInfoNoFileId     = umba_text_position_info_no_file_id;
using TextPositionInfoCompactDelta = umba_text_position_info_compact_delta;

inline
void textPositionInfoInit(TextPositionInfo &tpi, TextPositionInfo::file_id_type fileId=0u)
{
    umba_text_position_info_init(&tpi, fileId);
}

inline
void textPositionInfoInit(TextPositionInfoNoFileId &tpi)
{
    umba_text_position_info_no_file_id_init(&tpi);
}


template<typename StringType>
StringType makeSimpleTextPositionInfoString(const TextPositionInfo &tpi, bool forHumans=true)
{
    return umba::string_plus::make_string<StringType>(std::to_string(tpi.lineNumber+(forHumans?1:0)) + ":" + std::to_string(tpi.symbolOffset+(forHumans?1:0)));
}


} // namespace umba


#endif // #if defined(__cplusplus)

