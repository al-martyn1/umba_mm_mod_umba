// warning C4191: 'type cast': unsafe conversion from 'FARPROC' to '...'
#include "disable_C4191.h"

#if defined(__GNUC__)
    // https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wcast-function-type
    // __GNUC__              // major
    // __GNUC_MINOR__        // minor
    // __GNUC_PATCHLEVEL__
    #if (__GNUC__>7) //TODO: Проверить на 8/9/10/11/12 ой версии GCC - на 13ой точно есть
        #pragma GCC diagnostic ignored "-Wcast-function-type"
    #endif
#endif


