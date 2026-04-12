/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief

    Repository: https://github.com/al-martyn1/umba
*/

#if defined(_MSC_VER)
    #if defined(UMBA_ENABLE_WARNING_DISABLE_VERBOSE)
        #pragma message("!!! Non-portable use of class as an argument to a variadic function - need to be reafactored to variadic templates")
    #endif
    #pragma warning(disable:4840) // - warning C4840: non-portable use of class 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' as an argument to a variadic function
#endif
