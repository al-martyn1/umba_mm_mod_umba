// warning C4191: 'type cast': unsafe conversion from 'FARPROC' to '...'
#include "disable_C4191.h"

#if defined(__GNUC__)
    #pragma GCC diagnostic ignored "-Wcast-function-type"
#endif


