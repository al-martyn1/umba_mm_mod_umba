/*! \file
    \brief ZZ Утилиты для вывода в терминал
*/

#pragma once

#if !defined(UMBA_I_CHAR_WRITER_H)
    #error "zz_i_char_writer_term.h must be included from i_char_writer.h only"
#endif


#define UMBA_X_I_CHAR_WRITER_TERM_H

//-----------------------------------------------------------------------------

// https://ru.wikipedia.org/wiki/%D0%A3%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D1%8F%D1%8E%D1%89%D0%B8%D0%B5_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8_ANSI

//! Определения, относящиеся к терминалам
/*!
 */
namespace term
{


#include "zz_i_char_writer_term_colors.h"
#include "zz_i_char_writer_term_console_type.h"
#include "zz_i_char_writer_term_utils.h"


//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
// char* formatAnsiTermColor( char* pBuf, colors::SgrColor clr, bool fastBlink = false)
// char* formatAnsiTermMoveRelative( char* pBuf, int direction, int n) // A/B/C/D
// char* formatAnsiTermMoveToNextLine( char* pBuf, int n) // E
// char* formatAnsiTermMoveToPrevLine( char* pBuf, int n) // F
// char* formatAnsiTermMoveToAbsPos( char* pBuf, int x, int y) // H
// char* formatAnsiTermMoveToAbsCol( char* pBuf, int col) // G
// char* formatAnsiTermMoveToLineStart(char* pBuf)
// char* formatAnsiTermMoveToAbs0( char* pBuf)
// char* formatAnsiTermClearLine( char* pBuf) // 2K
// char* formatAnsiTermClearLineEnd( char* pBuf) // 0K
// char* formatAnsiTermClearScreen( char* pBuf) // 2J
// char* formatAnsiTermClearScreenEnd( char* pBuf) // 0J

//-----------------------------------------------------------------------------



// ANSI Escape Sequences cheatsheet  - https://gist.github.com/ConnerWill/d4b6c776b509add763e17f9f113fd25b
//    https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
// Управляющие последовательности ANSI - https://ru.wikipedia.org/wiki/%D0%A3%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D1%8F%D1%8E%D1%89%D0%B8%D0%B5_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8_ANSI
// ANSI escape code - https://en.wikipedia.org/wiki/ANSI_escape_code

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermEscStart( char* pBuf)
{
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = '\\';
    *pBuf++ = 'e';
    #else
    *pBuf++ = '\x1B';
    #endif
    *pBuf++ = '[';
    return pBuf;
}

//-----------------------------------------------------------------------------
// 0 Reset/Normal
// 1 Жирный или увеличить яркость
// 5 Мигание: Медленно
// 7 Отображение: Негатив
// 25 Мигание: выкл.

// 30–37 Установить цвет текста (на переднем плане)
// 40–47 Установить цвет фона

//! Формирует управляющую Escape-последовательность для установки цвета в ANSI-терминале
inline
char* formatAnsiTermColor( char* pBuf, colors::SgrColor clr, bool fastBlink = false)
{
    //#define UMBA_TERM_DEBUG_TERM_ESC_CSI

    // clr &= ~colors::full_mask; // Тут что-то странное
    clr &= colors::full_mask;

    pBuf = formatAnsiTermEscStart(pBuf);
    *pBuf++ = '0'; // reset/default colors  - 3 bytes written

    colors::SgrColor clrFg = 0;
    colors::SgrColor clrBg = 0;
    bool fBright   = false;
    bool fInvert   = false;
    bool fBlink    = false;

    colors::splitToOptions( clr, clrFg, clrBg, fBright, fInvert, fBlink );

    if ((clrFg&colors::color_default)==0) // +3 bytes
    {
        *pBuf++ = ';';
        pBuf = utils::formatUnsignedDec( pBuf, 30+clrFg);
    }

    if ((clrBg&colors::color_default)==0) // +3 bytes
    {
        *pBuf++ = ';';
        pBuf = utils::formatUnsignedDec( pBuf, 40+clrBg);
    }

    if (fBright) // +2 bytes
    {
        *pBuf++ = ';';
        *pBuf++ = '1';
    }

    if (fInvert) // +2 bytes
    {
        *pBuf++ = ';';
        *pBuf++ = '7';
    }

    if (fBlink) // +2 bytes
    {
        *pBuf++ = ';';
        if (fastBlink)
            *pBuf++ = '6';
        else
            *pBuf++ = '5';
    }

    *pBuf++ = 'm'; // +1
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' '; // +1
    #endif
    *pBuf++ = 0;

    return pBuf; // max - 16 bytes len
}

//-----------------------------------------------------------------------------
// static const int caretNo        = 0;       // No caret
// static const int caretDisable   = caretNo;
// static const int caretHid       = caretNo; // Hidden
// static const int caretMin       = 1;
// static const int caretMid       = 2;
// static const int caretMax       = 3;

inline
char* formatAnsiTermSetCaret( char* pBuf, int c) // ?25 l/h
{
    pBuf = formatAnsiTermEscStart(pBuf);
    *pBuf++ = '?'; *pBuf++ = '2'; *pBuf++ = '5';
    switch(c)
    {
        case  0: *pBuf++ = 'l'; break;
        case  1: *pBuf++ = 'h'; break;
        case  2: *pBuf++ = 'h'; break;
        case  3: *pBuf++ = 'h'; break;
        default: *pBuf++ = 'h'; break; // если что, показываем
    }

    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' ';
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermMoveRelative( char* pBuf, int direction, int n) // A/B/C/D
{
    pBuf = formatAnsiTermEscStart(pBuf);

    if (n>511) n = 511;
    if (n<0)   n = 0;

    pBuf = utils::formatUnsignedDec( pBuf, (unsigned)n);
    switch(direction)
    {
        case  0: *pBuf++ = 'A'; break;
        case  1: *pBuf++ = 'B'; break;
        case  2: *pBuf++ = 'C'; break;
        case  3: *pBuf++ = 'D'; break;
        default: *pBuf++ = 'B'; break; // если что, шагаем вниз
    }

    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' ';
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermMoveToNextLine( char* pBuf, int n) // E
{
    pBuf = formatAnsiTermEscStart(pBuf);

    if (n>511) n = 511;
    if (n<0)   n = 0;

    pBuf = utils::formatUnsignedDec( pBuf, (unsigned)n);
    *pBuf++ = 'E';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' ';
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermMoveToPrevLine( char* pBuf, int n) // F
{
    pBuf = formatAnsiTermEscStart(pBuf);

    if (n>511) n = 511;
    if (n<0)   n = 0;

    pBuf = utils::formatUnsignedDec( pBuf, (unsigned)n);
    *pBuf++ = 'F';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' ';
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermMoveToAbsPos( char* pBuf, int x, int y) // H
{
    pBuf = formatAnsiTermEscStart(pBuf);

    if (x>511) x = 511;
    if (x<0)   x = 0;
    if (y>511) y = 511;
    if (y<0)   y = 0;

    pBuf = utils::formatUnsignedDec( pBuf, (unsigned)y+1);
    *pBuf++ = ';';
    pBuf = utils::formatUnsignedDec( pBuf, (unsigned)x+1);

    *pBuf++ = 'H';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' ';
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermMoveToAbsCol( char* pBuf, int col) // G
{
    pBuf = formatAnsiTermEscStart(pBuf);
    if (col>511) col = 511;
    if (col<0)   col = 0;
    pBuf = utils::formatUnsignedDec( pBuf, (unsigned)col+1);
    *pBuf++ = 'G';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' ';
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermMoveToLineStart(char* pBuf)
{
    return formatAnsiTermMoveToAbsCol(pBuf, 0);
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermMoveToAbs0( char* pBuf)
{
    return formatAnsiTermMoveToAbsPos( pBuf, 0, 0);
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermClearLine( char* pBuf) // 2K
{
    pBuf = formatAnsiTermEscStart(pBuf);
    *pBuf++ = '2';
    *pBuf++ = 'K';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' '; // +1
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermClearLineEnd( char* pBuf) // 0K
{
    pBuf = formatAnsiTermEscStart(pBuf);
    *pBuf++ = '0';
    *pBuf++ = 'K';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' '; // +1
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermClearScreen( char* pBuf) // 2J
{
    pBuf = formatAnsiTermEscStart(pBuf);
    *pBuf++ = '2';
    *pBuf++ = 'J';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' '; // +1
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------
inline
char* formatAnsiTermClearScreenEnd( char* pBuf) // 0J
{
    pBuf = formatAnsiTermEscStart(pBuf);
    *pBuf++ = '0';
    *pBuf++ = 'J';
    #if defined(UMBA_TERM_DEBUG_TERM_ESC_CSI)
    *pBuf++ = ' '; // +1
    #endif
    *pBuf++ = 0;

    return pBuf;
}

//-----------------------------------------------------------------------------





#if defined(WIN32) || defined(_WIN32)

//! Подсистема Win32 для работы с терминалом (с консолью Windows)
namespace win32
{

/*
   WORD getConsoleTextAttribute( HANDLE hCon )
   WORD setConsoleTextAttribute( HANDLE hCon, WORD newAttr )
   colors::SgrColor convertColorFromConsole( WORD conColor )
   colors::SgrColor convertColorFromConsole( WORD conColor )
   WORD convertColorToConsole( colors::SgrColor clr )
*/


   //! Получение атрибутов текста для хэндла консоли
   inline
   WORD getConsoleTextAttribute( HANDLE hCon )
   {
       CONSOLE_SCREEN_BUFFER_INFO csb;
       ::GetConsoleScreenBufferInfo(hCon,&csb);
       return csb.wAttributes;
   }

   //! Установка атрибутов текста для хэндла консоли
   inline
   WORD setConsoleTextAttribute( HANDLE hCon, WORD newAttr )
   {
       CONSOLE_SCREEN_BUFFER_INFO csb;
       ::GetConsoleScreenBufferInfo(hCon,&csb);
       ::SetConsoleTextAttribute( hCon, newAttr );
       return csb.wAttributes;
   }

   //! Хелпер преобразования Win32-атрибута текста консоли в colors::SgrColor
   inline
   colors::SgrColor convertColorFromConsoleHelper( WORD conColor )
   {
       colors::SgrColor clr = 0;

       if (conColor&FOREGROUND_INTENSITY)
       {
           conColor &= ~FOREGROUND_INTENSITY;
           clr = colors::bright;
       }

       switch(conColor)
       {
           case 0                                                   : return clr | colors::black;
           case FOREGROUND_BLUE                                     : return clr | colors::blue;
           case FOREGROUND_GREEN                                    : return clr | colors::green;
           case FOREGROUND_RED                                      : return clr | colors::red;
           case (FOREGROUND_GREEN|FOREGROUND_RED  )                 : return clr | colors::yellow;
           case (FOREGROUND_BLUE |FOREGROUND_RED  )                 : return clr | colors::magenta;
           case (FOREGROUND_GREEN|FOREGROUND_BLUE )                 : return clr | colors::cyan;
           case (FOREGROUND_RED  |FOREGROUND_GREEN|FOREGROUND_BLUE) : return clr | colors::white;
           default: return clr | colors::black;
       }

   }

   //! Преобразование Win32-атрибута текста консоли в colors::SgrColor
   inline
   colors::SgrColor convertColorFromConsole( WORD conColor )
   {
       return convertColorFromConsoleHelper( conColor&0x0Fu )
            | convertColorFromConsoleHelper( (conColor>>4)&0x0Fu );
   }

   //! Хелпер преобразования цвета colors::SgrColor в Win32-атрибут текста консоли
   inline
   WORD convertColorToConsoleHelper( colors::SgrColor clr, WORD defAttr )
   {

       switch(clr&colors::color_mask)
          {
           case colors::red    : return FOREGROUND_RED;
           case colors::green  : return FOREGROUND_GREEN;
           case colors::yellow : return FOREGROUND_GREEN|FOREGROUND_RED;
           case colors::blue   : return FOREGROUND_BLUE;
           case colors::magenta: return FOREGROUND_RED|FOREGROUND_BLUE;
           case colors::cyan   : return FOREGROUND_GREEN|FOREGROUND_BLUE;
           case colors::white  : return FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE;
           case colors::color_default: return defAttr & 0x0Fu;
           default: return 0;
          }
   }

   //! Преобразование цвета colors::SgrColor в Win32-атрибут текста консоли
   inline
   WORD convertColorToConsole( colors::SgrColor clr, WORD defAttr )
   {
       colors::SgrColor fgClr = clr      & colors::color_mask;
       colors::SgrColor bgClr = (clr>>8) & colors::color_mask;

       WORD fg = convertColorToConsoleHelper(fgClr, defAttr);
       if (fgClr!=colors::color_default)
       {
           if (clr&colors::bright)
               fg |= FOREGROUND_INTENSITY;
       }

       WORD bg = convertColorToConsoleHelper(bgClr, (WORD)(defAttr>>4));
       if (bgClr!=colors::color_default)
       {
           if (clr&colors::bright)
               bg |= FOREGROUND_INTENSITY;
       }

       if (clr&colors::invert)
           std::swap(fg,bg);

       return (WORD)(fg | (WORD)(bg<<4)); //  | bright;
   }



} // namespace win32

#endif

} // namespace term
