/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief ZZ Правильный порядок инклюдов для винды

    Repository: https://github.com/al-martyn1/umba
*/

#pragma once

#if defined(UMBA_WIN32_USED) || defined(WIN32) || defined(_WIN32)

    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif

    #ifndef VC_EXTRALEAN
        #define VC_EXTRALEAN
    #endif

    #ifndef STRICT
        #define STRICT
    #endif


    // Делаем вид, что WinSock.h уже подключен, иначе, если потом подключается
    // WinSock2.h, то будет конфликт

    // #ifndef _WINSOCKAPI_
    //     #define _WINSOCKAPI_
    // #endif

    //
    #include <winsock2.h>
    //
    #include "windows.h"

    #if defined(min)
        #undef min
    #endif

    #if defined(max)
        #undef max
    #endif

#endif

