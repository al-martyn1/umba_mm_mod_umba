/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief
*/

    /*
        See also
          https://devblogs.microsoft.com/cppblog/broken-warnings-theory/
          https://learn.microsoft.com/en-us/cpp/preprocessor/warning?view=msvc-170
    */

#if defined(_MSC_VER)
    #pragma warning(push)
#endif

#if defined(__GNUC__)
    #pragma GCC diagnostic push
#endif
