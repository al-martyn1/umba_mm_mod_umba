#pragma once

//----------------------------------------------------------------------------

/*! \file
    \brief Универсальная реализация UMBA_ASSERT
*/

//----------------------------------------------------------------------------

//
#include "zz_detect_environment.h"
//
#include "preprocessor.h"
//
#if defined(UMBA_WIN32_USED)
    #include <crtdbg.h>
#endif

// Подключаем заголовки, зависимые от платформы

#if defined(UMBA_QT_USED)

    //#include <>

#elif defined(UMBA_WIN32_USED) /* Win32 без Qt */

    #include <crtdbg.h>

#elif defined(UMBA_MCU_USED)

    //#include <>

#elif defined(UMBA_LINUX_USED)


#else

    #error "None of UMBA_*_USED macro defined, target not detected"

#endif


// https://gcc.gnu.org/onlinedocs/cpp/_005f_005fhas_005finclude.html

#if defined __has_include
    #if __has_include(<assert.h>)
        #include <assert.h>
        #define UMBA_HAS_CRT_ASSERT
    #endif
#endif



//---------------------------------------------------------
/*! \def UMBA_ASSERT(expr)
    Проверка условия и аварийный выход (или сообщение с последующим продолжением работы).

    При компиляции под Qt или Win32 будут вызваны соответствующие функции Qt/Windows, отображающие диалог с сообщением об ошибке.

    При компиляции для железа и работе под отладчиком последний должен показать место, где произошел assert.
    \note Не факт что это всегда работает.
*/

#if defined(UMBA_QT_USED)

    #define UMBA_ASSERT( expr )             Q_ASSERT(expr)
    #define UMBA_ASSERT_EX( expr, msg )     Q_ASSERT_X(expr, __FILE__ ":" UMBA_STRINGIFY(__LINE__), msg )


#elif defined(UMBA_WIN32_USED) /* Win32 без Qt */

    #if defined(UMBA_MSVC_COMPILER_USED)

        #define UMBA_ASSERT( expr )           _ASSERTE(expr)
        #define UMBA_ASSERT_EX( expr, msg )   _ASSERTE((msg, (expr)))

    #elif defined(UMBA_GCC_COMPILER_USED) /* У GCC (MinGW) внезапно, _ASSERTE ничего не делает, поэтому стырил реализацию из винды, только вместо _CrtDbgReportW которой нет у GCC, подсунул MessageBoxW */

        #define UMBA_CRT_WIDE_(s) L ## s
        #define UMBA_CRT_WIDE(s) UMBA_CRT_WIDE_(s)

        #define UMBA_CRT_DBG_BREAK() __debugbreak()

        // #define _CRT_ASSERT         2

        #define UMBA_MINGW_CRT_DBG_REPORT_MSG_IMPL2(msg, file_, line_) \
                    MessageBoxW( (HWND)0                               \
                               , msg L"\n\n" file_ L":" line_          \
                               , L"Assertion failed\n\n"               \
                               , MB_OK|MB_ICONERROR|MB_SYSTEMMODAL     \
                               )

        #define UMBA_MINGW_CRT_DBG_REPORT_MSG_IMPL(msg, file_, line_)  UMBA_MINGW_CRT_DBG_REPORT_MSG_IMPL2(msg, file_, line_)

        #define UMBA_MINGW_CRT_DBG_REPORT_MSG(msg) \
                              UMBA_MINGW_CRT_DBG_REPORT_MSG_IMPL(msg, UMBA_CRT_WIDE(__FILE__), UMBA_CRT_WIDE(UMBA_STRINGIFY(__LINE__)) )

        #if 0
        #define UMBA_MINGW_CRT_DBG_REPORT_MSG(msg) \
                    MessageBox( (HWND)0            \
                              , UMBA_CRT_WIDE(msg) ## L"\n\n" ## UMBA_CRT_WIDE(__FILE__) ## L":" ## UMBA_CRT_WIDE(UMBA_STRINGIFY(__LINE__)) \
                              , L"Assertion failed\n\n"  \
                              , MB_OK|MB_ICONEXCLAMATION \
                              )
        #endif


        #define UMBA_MINGW_CRT_DBG_REPORT(msg) ((UMBA_MINGW_CRT_DBG_REPORT_MSG(msg)), 0)


        #ifndef UMBA_ASSERT_EXPR
            #define UMBA_ASSERT_EXPR(expr, msg) \
                (void)(                                                                                             \
                    (!!(expr)) ||                                                                                   \
                    UMBA_MINGW_CRT_DBG_REPORT(msg) ||                                                               \
                    /*(1 != _CrtDbgReportW(_CRT_ASSERT, UMBA_CRT_WIDE(__FILE__), __LINE__, NULL, L"%ls", msg)) ||*/ \
                    (UMBA_CRT_DBG_BREAK(), 0)                                                                       \
                )
        #endif

        #ifndef UMBA_ASSERTE
            #define UMBA_ASSERTE(expr) UMBA_ASSERT_EXPR((expr), UMBA_CRT_WIDE(#expr))
        #endif

        #if !defined(NDEBUG)
            #define UMBA_ASSERT( expr )             UMBA_ASSERTE(expr)
            #define UMBA_ASSERT_EX( expr, msg )     UMBA_ASSERT_EXPR((expr), UMBA_CRT_WIDE(msg))
        #else
            #define UMBA_ASSERT( expr )
            #define UMBA_ASSERT_EX( expr, msg )
        #endif

    #else

        #pragma message("!!! UMBA_ASSERT not supported by this compiler")
        #define UMBA_ASSERT( expr )
        #define UMBA_ASSERT_EX( expr, msg )

    #endif

#elif defined(UMBA_MCU_USED)

    #if defined(UMBA_ARMCC_COMPILER_USED)

        // __disable_irq - armcc intrinsic
        #define UMBA_ASSERT( expr )            do { if(! (expr) ) { __disable_irq(); while(1){ __BKPT(0xAB); if(0) break;} }  } while(0)
        #define UMBA_ASSERT_EX( expr, msg )    UMBA_ASSERT( expr )     

    #else 

        // GCC/Clang - пока оставим без ассерта
        /* !!! Сделать как надо UMBA_ASSERT для GCC/Clang */
        #define UMBA_ASSERT( expr )
        #define UMBA_ASSERT_EX( expr, msg )    UMBA_ASSERT( expr )     

    #endif

#elif defined(UMBA_HAS_CRT_ASSERT) 

    #define UMBA_ASSERT( expr )                assert(expr)
    #define UMBA_ASSERT_EX( expr, msg )        UMBA_ASSERT( expr )     

#else

    #define UMBA_ASSERT( expr )
    #define UMBA_ASSERT_EX( expr, msg )        UMBA_ASSERT( expr )     

#endif

// UMBA_HAS_CRT_ASSERT

//---------------------------------------------------------
//! UMBA_ASSERT_FAIL срабатывает всегда, и ставится туда, куда по идее, никогда попадать не должны
#define UMBA_ASSERT_FAIL()           UMBA_ASSERT( 0 )
#define UMBA_ASSERT_FAIL_MSG(msg)    UMBA_ASSERT_EX( 0, msg )



//---------------------------------------------------------
//! Реализация assert'а времени компиляции
#define UMBA_STATIC_ASSERT_MSG(condition, msg)   typedef char umba_static_assertion_##msg[(condition)?1:-1]
//! @cond Doxygen_Suppress_Not_Documented
#define UMBA_STATIC_ASSERT3(X, L)                UMBA_STATIC_ASSERT_MSG(X, at_line_##L)
#define UMBA_STATIC_ASSERT2(X, L)                UMBA_STATIC_ASSERT3(X, L)
//! @endcond

//---------------------------------------------------------
//! UMBA_STATIC_ASSERT - assert времени компиляции
#define UMBA_STATIC_ASSERT(X) UMBA_STATIC_ASSERT2(X, __LINE__)






