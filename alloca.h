/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief Совместимая версия alloca/_alloca

    Repository: https://github.com/al-martyn1/umba
*/

#pragma once

//----------------------------------------------------------------------------

#include "zz_detect_environment.h"


#ifdef _WIN32

    #if !defined(_INC_MALLOC) && !defined(_MALLOC_H_) && !defined(_MALLOC_H)
        #include <malloc.h>
    #endif
    #ifndef alloca
        #define alloca  _alloca
    #endif

#else

    #include <alloca.h>
    #ifndef _alloca
        #define _alloca  alloca
    #endif

#endif
