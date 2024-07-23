/*!
    \file
    \brief Типы для указания положения в текстовом файле
 */

//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------

#include "umba.h"

//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
namespace umba
{

/*! \ingroup UMBA_CORE
 *  \addtogroup UMBA_LINEINFO
 *  @{
 */

//----------------------------------------------------------------------------
//! Содержит информацию о положении в файле в виде строка/столбец
/*!
    Обычно используется для хранения положения и последующего вывода пользователю
    (например, в случае обнаружения какой-либо ошибки в данном месте).

    \tparam SizeType Тип индекса строки/столбца
    Обычно используем std::size_t, но для MK можно использовать другие типы, например,uint16_t - для экономии памяти.
 */
template< typename SizeType >
struct LinePosInfo
{
    SizeType                fileId     ; //!< Идентификатор файла (в каком-либо хранилище)
    SizeType                lineNumber ; //!< Номер строки
    SizeType                linePos    ; //!< Номер позиции символа в строке (номер столбца)

}; // struct LinePosInfo

//----------------------------------------------------------------------------
//! Содержит стандартную информацию о положении в файле в виде строка/столбец, и расширенную - в виде указателя на данные
/*!
    Обычно используется для хранения положения и последующего вывода пользователю
    (например, в случае обнаружения какой-либо ошибки в данном месте).

    \tparam SizeType Тип индекса строки/столбца
    Обычно используем std::size_t, но для MK можно исползовать другие типы, например,uint16_t - дл экономии памяти.

    \tparam CharType Тип символов, обычно char/wchar_t
 */
template< typename SizeType, typename CharType >
struct LinePosInfoEx
{
    SizeType                fileId     ; //!< Идентификатор файла (в каком-либо хранилище)
    SizeType                lineNumber ; //!< Номер строки
    SizeType                linePos    ; //!< Номер позиции символа в строке (номер столбца)
    CharType               *pData      ; //!< Указатель на данные

    //! Оператор преобразования к "обычному" типу LinePosInfo
    operator LinePosInfo<SizeType>() const
    {
        return LinePosInfo<SizeType>( fileId, lineNumber, linePos );
    }

}; // struct LinePosInfoEx

// End of UMBA_LINEINFO
/*! @}*/



} // namespace umba




