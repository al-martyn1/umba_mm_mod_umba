/*! \file
    \brief Сохранение текущих настроек и установка упаковки структур по 2
*/

#include "ppstringify.h"

// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124990875.htm
// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124982232.htm
// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124980173.htm
// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124968737.htm
#if defined(_WIN32)
    #include <pshpack2.h>
#else
    // Also good for GCC
    #pragma pack(push,2)
#endif

#if defined(_MSC_VER)
    #pragma warning(push) // save warnings config
    // #pragma warning(disable:4810) // - warning C4810: value of pragma pack(show)
    // #pragma pack(show)
    #pragma message("!!! pragma pack(2) used")
    #pragma warning( pop )
#endif
