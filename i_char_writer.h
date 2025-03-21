#pragma once

#define UMBA_I_CHAR_WRITER_H


//-----------------------------------------------------------------------------

/*! \file
    \brief Интерфейс для использования в форматном выводе
*/

//-----------------------------------------------------------------------------

#if defined(UMBA_CXX_HAS_STD11)
    #include <stdint.h>
#endif

#include "interface.h"
#include "umba.h"

#include <cstring>
#include <stddef.h>


//-----------------------------------------------------------------------------

// umba::term::colors::

namespace umba
{



#include "zz_i_char_writer_term.h"
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
//! Интерфейс "писателя символов" в куда-то
//UMBA_INTERFACE
struct ICharWriter
{

    virtual ~ICharWriter() {}

    //! Запись символа
    virtual
    void writeChar( char ch ) = 0;

    //! Запись буфера/массива символов/байт
    virtual
    void writeBuf( const uint8_t* pBuf, size_t len )
    {
        for(size_t i = 0; i!=len; ++i, ++pBuf)
           writeChar((char)*pBuf);
    }

    //! Запись ASCII-Z строки
    virtual
    void writeString( const char* str )
    {
        for(; *str; ++str)
           writeChar(*str);
    }

    //! Сброс всех выходных буферов
    virtual
    void flush() = 0;

    //! Ожидание сброса буферов
    virtual
    void waitFlushDone()
    {}

    //! Выводит перевод строки по умолчанию для данного типа CharWriter
    virtual
    void putDefEndl() // end line - LF or CR LF
    {
        #if defined(UMBA_MCU_USED) || defined(_WIN32)
        writeString( "\r\n" ); // Под Windows или при использовании MCU манипулятор новой строки использует последовательность "\r\n"
        #else
        writeChar( '\n' ); // Под Linux принято для перевода строки использовать только \n
        #endif
    }

    //! Выводит перевод строки
    virtual
    void putEndl() // end line - LF or CR LF
    {
        //if (isTextMode())
        //   putDefEndl();
        //   writeChar( '\n' );
        //else
        writeChar( '\n' );
    }

    //! Выводит возврат каретки
    virtual
    void putCR() // carriage return
    {
        //writeChar( '\r' );
    }

    //! Выводит Form Feed
    virtual
    void putFF() // form feed
    {
        //writeChar( '\f' );
    }

    //! Возвращает true, если режим вывода - текстовый - символ '\n' транслируется в последовательность CR LF или LF в зависимости от платформы
    virtual
    bool isTextMode()
    {
        return false;
    }

    //! Возвращает true, если данный CharWriter - терминал
    virtual
    bool isTerminal() const
    {
        return false;
    }

    //----------------------------------------------------------------------------
    //! Возвращает true, если данный CharWriter - Ansi-терминал с поддержкой ESC-последовательностей
    virtual
    bool isAnsiTerminal() const
    {
        return false;
    }

    //! Возвращает максимальное число байт, которое может быть записано без блокировки
    virtual
    size_t getNonBlockMax()
    {
        return 1024*1024;
    }

    //! Производит установку цвета выводимого текста (текст и фон)
    virtual void setTermColors(term::colors::SgrColor clr) { UMBA_USED(clr);  }

    //! Производит установку значений цвета текста и фона по умолчанию
    virtual void setDefaultTermColors() {}

    //! Реализация установки цвета для Ansi-терминала
    void setAnsiTermColorsImpl(term::colors::SgrColor clr, bool fFastBlink = false)
    {
        char buf[32];
        term::formatAnsiTermColor( buf, clr, fFastBlink );
        writeString( buf );
    }

    //! Реализация установки цвета по умолчанию для Ansi-терминала
    void setAnsiTermDefaultColorsImpl()
    {
        setAnsiTermColorsImpl( term::colors::makeComposite( term::colors::white, term::colors::black,false, false, false ), false );
    }

    void terminalMoveRelativeImpl(int direction, int n)
    {
        char buf[32];
        term::formatAnsiTermMoveRelative(buf, direction, n);
        writeString( buf );
    }

    void terminalMoveToNextLineImpl(int n)
    {
        char buf[32];
        term::formatAnsiTermMoveToNextLine(buf, n);
        writeString( buf );
    }

    void terminalMoveToPrevLineImpl(int n)
    {
        char buf[32];
        term::formatAnsiTermMoveToPrevLine(buf, n);
        writeString( buf );
    }

    void terminalMoveToAbsColImpl(int n)
    {
        char buf[32];
        term::formatAnsiTermMoveToAbsCol(buf, n);
        writeString( buf );
    }

    void terminalMoveToLineStartImpl()
    {
        char buf[32];
        term::formatAnsiTermMoveToLineStart(buf);
        writeString( buf );
    }

    void terminalMoveToAbsPosImpl( int x, int y )
    {
        char buf[32];
        term::formatAnsiTermMoveToAbsPos(buf, x, y);
        writeString( buf );
    }

    void terminalMoveToAbs0Impl()
    {
        char buf[32];
        term::formatAnsiTermMoveToAbs0(buf);
        writeString( buf );
    }

    void terminalClearScreenEndImpl()
    {
        char buf[32];
        term::formatAnsiTermClearScreenEnd(buf);
        writeString( buf );
    }

    void terminalClearScreenImpl()
    {
        char buf[32];
        term::formatAnsiTermClearScreen(buf);
        writeString( buf );
    }

    void terminalClearLineImpl()
    {
        char buf[32];
        term::formatAnsiTermClearLine(buf);
        writeString( buf );
    }

    void terminalClearLineEndImpl()
    {
        char buf[32];
        term::formatAnsiTermClearLineEnd(buf);
        writeString( buf );
    }

    void terminalSetCaretImpl(int c)
    {
        char buf[32];
        term::formatAnsiTermSetCaret(buf, c);
        writeString( buf );
    }



    //----------------------------------------------------------------------------
    // Позиционирование в консоли

    /* Что нужно обязательно (необходимый минимум):

       Перейти в абсолютный 0.                         term::move2abs0   or term_move2abs0
       Перейти ниже на строку на нулевую позицию.      term::move2down   or term_move2down     - может, еще какое-то имя можно получше придумать?
       Перейти в нулевую позицию в текущей строке      term::move2line0  or term_move2line0
       Перейти на заданную позицию в текущей строке    term::move2lp(n)  or term_move2lp(n)

       Что желательно:
       (и можно реализовать при помощи базовых функций, но лучше - нативно)

       Переход в абсолютную позицию                    term::move2pos    or term_move2pos


       Что я забыл?

       Относительные переходы в текущей архитектуре пока не возможны - char writter'ы однонаправленные пока,
       и никаких данных получать не умеют, так что сорян.


       //------------------------------

       Кстати, надо сделать бы сделать манипулятор spinner(int|unsigned).
       Символы - '-', '\', '|', '/'

       Что он будет делать    : переходить в 0 текущей строки - lout<<term::move2line0
                                выводить spinCharsTable[n%4]
                                выводить пробел
                                после чего пользователь (библиотеки) может выводить своё сообщение

       Как оно будет выглядеть:
                                lout<<spinner(counter)<<"Just a message";

       Иногда таки полезная штука

       В зависимости от типа потока:
          если какая-то интерактивная консоль - будет выведен текущий символ спиннера с пробелом и сообщением
          если выводим в файл (тот же stdout перенаправлен в файл) - в него будут высраты только сообщения,
          спиннеры и пробелы будут скушаны.

       Можно подумать потом на тему спиннер-mode для потока вывода, чтобы лишняя хуйня вообще не сралась бы.
       Типа:
             lout << umba::omanip::term::spinner(cnt) << "My emergency urgent message" << umba::omanip::endl;
             Тут что: Выводим спиннер в текущей фазе, выводим месагу, заканчиваем вывод. Если что - повторяем в той же строчке консольки.

             Если вывод идёт не в терминал, тойэто говно нах не нужно в логах.

       Бонусы: как уже есть - можно срать текст либо в консоль STM32-отладчика через SWV или как оно - и тогда это просто текст,
                              либо срать в STM32 UART (старый добрый), на котором висит putty и умеет в цвета и позиционирование - ANSI-терминал,
                              либо это тупая виндовая консоль, и ни разу не ANSI-терминал, но в цвета и позиционирование умееет,
                              либо это git bash, который умеет в ANSI-терминал (и хз, умеет лишнегов виндовую консоль)
                              либо это cout/cerr, который перенаправлен в файл
                              либо это обычный файл
             - во всех этих случаях никакого лишнего говна не выводится.

             В Win10 - вроде консоль научилась быть ANSI-терминалом, но технология работает и под семёркой и ниже, W2K скорее всего точно, Win95/98 - вероятно

             Можно срать даже в std::string (тогда это аналог std::ostringstream) или в тупой буфер char'ов в памяти.

             Можно срать даже в UI - тогда (например)
                                     lout<<umba::omanip::term::spinner(cnt) будет показывать крутящееся колёсико в нужной фазе в нужной в жопке графического интерфейса
                                     lout<<umba::omanip::error будет добавлять в отображаемую таблицу лога строчку с маркером 'ошибка'
                                     lout<<umba::omanip::debug будет добавлять в отображаемую таблицу лога строчку с маркером 'отладка'
                   и всё это можно фильтровать как захочется.

       Просто надо биндить umba::SimpleFormatter с соответсвующим char_writter'ом
       Да - ICharWriter, как интерфейс, начал немного распухать. Возможно, что-то упростится через dynamic_cast и QueryInterface :)
            Обычных пользователей это не затронет. Только имплементаторов ICharWritter

       И опять же, Рома наконец-то будет доволен :) и перестанет таскать какашки с помоек

     */


    //! Установка каретки (курсора) консоли. 0 - выключена, 1 - полоска внизу, 2 - половина, 3 - во всю высоту
    virtual void terminalSetCaret( int csz ) { UMBA_USED(csz); }

    //! Helper для спиннера
    virtual void terminalSetSpinnerMode( bool m ) { UMBA_USED(m); }


    // virtual void terminalMoveToAbs0()
    // virtual void terminalMoveRelative(int direction, int n)
    // virtual void terminalMoveToNextLine(int n)
    // virtual void terminalMoveToPrevLine(int n)
    // virtual void terminalMoveToAbsCol(int n)
    // virtual void terminalMoveToLineStart()
    // virtual void terminalMoveToAbsPos( int x, int y )
    // virtual void terminalClearScreenEnd()
    // virtual void terminalClearScreen()
    // virtual void terminalClearLine()
    // virtual void terminalClearLineEnd()



// #define UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION

    //! Перейти в абсолютный 0.
    virtual void terminalMoveToAbs0()
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    {}
#endif

    //! Перейти относительно текущей позиции на n шагов в направлении direction: 0 - up, 1 - down, 2 - forward, 3 - backward (A/B/C/D commands)
    virtual void terminalMoveRelative(int direction, int n)
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    { UMBA_USED(direction); UMBA_USED(n); }
#endif

    //! Перейти на n строк ниже и установить курсор в нулевую позицию (E)
    virtual void terminalMoveToNextLine(int n)
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    { UMBA_USED(n); }
#endif

    //! Перейти на n строк выше и установить курсор в нулевую позицию (F)
    virtual void terminalMoveToPrevLine(int n)
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    { UMBA_USED(n); }
#endif

    //! Перейти в абсолютную позицию в текущей строке (G)
    virtual void terminalMoveToAbsCol(int n)
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    { UMBA_USED(n); }
#endif

    //! Перейти в нулевую позицию в текущей строке (см. выше)
    virtual void terminalMoveToLineStart()
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    {}
#endif

    //! Переход в абсолютную позицию (H)
    virtual void terminalMoveToAbsPos( int x, int y )
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    { UMBA_USED(x); UMBA_USED(y); }
#endif

    //! Очистить от текущего положения до конца экрана (0J)
    virtual void terminalClearScreenEnd()
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    {}
#endif

    //! Очистить экран (2J)
    virtual void terminalClearScreen()
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    {}
#endif

    //! Очистить текущую строку (2K)
    virtual void terminalClearLine()
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    {}
#endif

    //! Очистить от текущего положения до конца строки (0K)
    virtual void terminalClearLineEnd()
#if defined(UMBA_I_CHAR_WRITTER_DISABLE_TERMINAL_METHODS_DEFAULT_IMPLEMENTATION)
    = 0;
#else
    {}
#endif



    // //! Перейти ниже на строку на нулевую позицию.
    // virtual void terminalMoveDown(int n)
    // {}



    // //! Очистить в текущей строке N позиции от текущего положения
    // virtual void terminalClearLine( int n=-1 ){ UMBA_USED(n); } // Пока не нужно


    // Пока не нужно
    // //! Очистить текущую строку до конца, и очистить всё, что ниже, но не больше, чем maxLines - для ускорения
    // virtual void terminalClearRemaining( int maxLines = -1 )
    // { UMBA_USED(maxLines); }

    // {
    //     // Реализация по умолчанию использует огранниченные методы, перечисленные выше, если терминал не поддерживает такое позиционирование напрямую
    //     terminalMove2Abs0();
    //     // int i = 0;
    //     for( auto j = 0; j<y; ++j)
    //         terminalMove2Down();
    //
    //     terminalMove2LinePos(x);
    // }


}; // UMBA_INTERFACE ICharWriter

//-----------------------------------------------------------------------------




} // namespace umba


