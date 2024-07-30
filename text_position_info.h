#pragma once


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
    umba_text_position_info_line_number_type    lineNumber  ; //!< Zero based line number
    umba_text_position_info_file_id_type        fileId      ; //!< FileID

} umba_text_position_info;
#if defined(UMBA_TEXT_POSITION_INFO_COMPACT)
    #include "packpop.h"
#endif

static inline
void umba_text_position_info_init(umba_text_position_info *pPos, umba_text_position_info_file_id_type fileId)
{
    pPos->lineOffset   = 0u;
    pPos->symbolOffset = 0u;
    pPos->lineNumber   = 0u;
    pPos->fileId       = fileId;
}


#if defined(__cplusplus)

// umba::
namespace umba {


using TextPositionInfo = umba_text_position_info;

inline
void textPositionInfoInit(TextPositionInfo &tpi, TextPositionInfo::file_id_type fileId=0u)
{
    umba_text_position_info_init(&tpi, fileId);
}


} // namespace umba


#endif // #if defined(__cplusplus)

