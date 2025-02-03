/*! \file
    \brief Сохранение текущих настроек и установка упаковки структур по 1
*/

// #include "ppstringify.h"

// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124990875.htm
// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124982232.htm
// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124980173.htm
// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124968737.htm
#if defined(_WIN32)
    #include <pshpack1.h>
#else
    // Also good for GCC
    #pragma pack(push,1)
#endif

#if defined(_MSC_VER)
    #pragma warning(push) // save warnings config
    // https://learn.microsoft.com/en-us/cpp/preprocessor/warning
    // #pragma warning(disable:4810) // - warning C4810: value of pragma pack(show)
    // #pragma pack(show)
    // #pragma message("!!! pragma pack(1) used in " __FILE__ ":" UMBA_SIMPLE_PPSTRINGIFY(__LINE__) )
    #pragma warning( pop )
#endif
