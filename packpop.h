/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief Восстановление значения по умолчанию для упаковки структур
*/

#if defined(_WIN32)
    #include <poppack.h>
#else
    // Also good for GCC
    #pragma pack(pop)
#endif
