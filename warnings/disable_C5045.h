/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief

    Repository: https://github.com/al-martyn1/umba
*/

#if defined(_MSC_VER)
    #if defined(UMBA_ENABLE_WARNING_DISABLE_VERBOSE)
        //#pragma message("!!! This function or variable may be unsafe")
        // #pragma message("!!! Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified")
    #endif
    #pragma warning(disable:5045) // - warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
#endif
