/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief Включает режим оптимизации по скорости

    Repository: https://github.com/al-martyn1/umba
*/

#ifdef UMBA_KEIL_ARMCC_COMPILER_USED
    #pragma push /* Save existing optimization level */
    #pragma O3 Otime   /* Optimization level now O3 */
#endif
