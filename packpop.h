/*! \file
    \brief Восстановление значения по умолчанию для упаковки структур
*/
#if defined(_WIN32)
    #include <poppack.h>
#else
    // Also good for GCC
    #pragma pack(pop)
#endif

