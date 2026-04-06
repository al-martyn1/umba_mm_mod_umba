/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief Реализация критической секции

    Repository: https://github.com/al-martyn1/umba
*/

#include "critical_section.h"

namespace umba{




#if defined(UMBA_WIN32_USED)

//---------------------------------------------------------
// Реализация критической секции для Win32
//---------------------------------------------------------
CriticalSection::CriticalSection()
{
    InitializeCriticalSection(&m_criticalSection);
}

//---------------------------------------------------------
CriticalSection::~CriticalSection()
{
    DeleteCriticalSection(&m_criticalSection);
}

//---------------------------------------------------------
void CriticalSection::lock()
{
    EnterCriticalSection(&m_criticalSection);
}

//---------------------------------------------------------
void CriticalSection::unlock()
{
    LeaveCriticalSection(&m_criticalSection);
}

#endif


#ifndef UMBA_NO_GLOBAL_CS
    //! Глобальная критическая секция, доступная для использования, если не определен макрос \b UMBA_NO_GLOBAL_CS
    CriticalSection globalCriticalSection;
#endif




} // namespace umba
