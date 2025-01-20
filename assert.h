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

    #define UMBA_ASSERT( statement )         Q_ASSERT(statement)

#elif defined(UMBA_WIN32_USED) /* Win32 без Qt */

    #define UMBA_ASSERT( statement )         _ASSERTE(statement)

#elif defined(UMBA_MCU_USED)

    #if defined(UMBA_ARMCC_COMPILER_USED)

        // __disable_irq - armcc intrinsic
        #define UMBA_ASSERT( statement )         do { if(! (statement) ) { __disable_irq(); while(1){ __BKPT(0xAB); if(0) break;} }  } while(0)

    #else 

        // GCC/Clang - пока оставим без ассерта
        /* !!! Сделать как надо UMBA_ASSERT для GCC/Clang */
        #define UMBA_ASSERT( statement )

    #endif

#elif defined(UMBA_HAS_CRT_ASSERT) 

    #define UMBA_ASSERT( statement )         assert(statement)

#else

    #define UMBA_ASSERT( statement )

#endif

// UMBA_HAS_CRT_ASSERT

//---------------------------------------------------------
//! UMBA_ASSERT_FAIL срабатывает всегда, и ставится туда, куда по идее, никогда попадать не должны
#define UMBA_ASSERT_FAIL()           UMBA_ASSERT( 0 )



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






