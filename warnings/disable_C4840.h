#if defined(_MSC_VER)
    #pragma message("!!! Non-portable use of class as an argument to a variadic function - need to be reafactored to variadic templates")
    #pragma warning(disable:4840) // - warning C4840: non-portable use of class 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' as an argument to a variadic function
#endif
