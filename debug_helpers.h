#pragma once

//-----------------------------------------------------------------------------

/*! \file
    \brief Поддержка отладки
*/

//-----------------------------------------------------------------------------

#include "assert.h"
#include "umba.h"
#include "zz_inc_windows.h"

#if defined(UMBA_WIN32_USED)

    #include <debugapi.h>

#endif


namespace umba
{

/*! \fn bool isDebuggerPresent()
    Возвращает true, если приложение запущно из-под отладчика. Работает для Win32 / STM32 F1/F3/F4.
 */

/*! \fn void debugBreak()
    Выкидывает в отладчик, если приложение запущно из-под отладчика. Работает для Win32 / STM32 F1/F3/F4.

    Для STM32 продолжение выполнения невозможно, для Win32 - продолжение выполнения работает
 */

#if defined(UMBA_WIN32_USED)

    inline
    bool isDebuggerPresent()
    {
        return IsDebuggerPresent() ? true : false;
    }

    inline
    void debugBreak()
    {
        if (isDebuggerPresent())
        {
            #if defined(_MSC_VER)
                __debugbreak();
            #else
                DebugBreak();
            #endif
        }
    }

    #if defined(_MSC_VER)
        #define UMBA_DEBUGBREAK()                         \
                do                                        \
                {                                         \
                using umba::isDebuggerPresent; \
                    if (isDebuggerPresent())              \
                    {                                     \
                        __debugbreak();                   \
                    }                                     \
                }                                         \
                while(false)
    #else
        #define UMBA_DEBUGBREAK()                         \
                do                                        \
                {                                         \
                using umba::isDebuggerPresent; \
                    if (isDebuggerPresent())              \
                    {                                     \
                        DebugBreak();                     \
                    }                                     \
                }                                         \
                while(false)
    #endif


#elif defined(UMBA_MCU_USED) && ( defined(STM32F1_SERIES) || defined(STM32F3_SERIES) || defined(STM32F4_SERIES) )

    inline
    bool isDebuggerPresent()
    {
        // http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka14536.html
        // http://www.onarm.com/forum/62218/
        // https://community.st.com/s/question/0D50X00009XkbSDSAZ/detect-debugger-connected-to-stm32l0-
        // https://www.google.com/search?q=stm32+detect+debugging&rlz=1C1GCEU_ruRU819RU819&oq=stm32+how+to+detect+debug&aqs=chrome.1.69i57j0l2.11847j0j7&sourceid=chrome&ie=UTF-8

        #if defined(CoreDebug)
        return CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk ? true : false;
        #else
        return false;
        #endif
    }

    inline
    void debugBreak()
    {
        if (isDebuggerPresent())
        {
            // https://stackoverflow.com/questions/173618/is-there-a-portable-equivalent-to-debugbreak-debugbreak
            // __BKPT(0xDE); // CMSIS
            // See also https://github.com/scottt/debugbreak/blob/master/debugbreak.h

            asm volatile ("bkpt");
        }
    }

    #define UMBA_DEBUGBREAK()                             \
            do                                            \
            {                                             \
                using umba::isDebuggerPresent; \
                if (isDebuggerPresent())                  \
                {                                         \
                    asm volatile ("bkpt");                \
                }                                         \
            }                                             \
            while(false)

#else

    inline
    bool isDebuggerPresent()
    {
        return false; // Can't detect debugger
    }

    inline
    void debugBreak()
    {
    }

    #define UMBA_DEBUGBREAK()                             \
            do                                            \
            {                                             \
                using umba::isDebuggerPresent; \
                if (isDebuggerPresent())                  \
                {                                         \
                }                                         \
            }                                             \
            while(false)                                  

#endif


} // namespace umba


//! Ассерция, под отладчиком останавливается до самого ассерта
#define UMBA_DEBUG_SESSION_ASSERT( expr )    if (umba::isDebuggerPresent()) do { if (!(expr)) UMBA_DEBUGBREAK(); UMBA_ASSERT( expr ); } while(0)

//! Безусловный фейл только при работе под отладчиком
#define UMBA_DEBUG_SESSION_ASSERT_FAIL()     if (umba::isDebuggerPresent()) do { UMBA_DEBUGBREAK(); UMBA_ASSERT_FAIL( ); } while(0)




