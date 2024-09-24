#pragma once

//----------------------------------------------------------------------------

/*! \file
    \brief Работа с переменными окружения
*/

//----------------------------------------------------------------------------

#include "../umba.h"
//
#include "../string_plus.h"

#if !defined(_INC_STDLIB) && !defined(_STDLIB_H_) && !defined(_STDLIB_H)
    #include <stdlib.h>
#endif

#include <utility>

#if defined(WIN32) || defined(_WIN32)
    #include <processenv.h>
#endif

#include "../warnings/push_disable_fn_or_var_unsafe.h"

// umba::env::internal
namespace umba
{
namespace env
{
namespace internal{


//! Получение переменной окружения, возвращает true, если значение получено
inline
bool getVar(const ::std::string &varName, ::std::string &val)
   {
    if (varName.empty()) return false;
    char * pval = ::getenv(varName.c_str());
    if (!pval) return false;
    val = pval;
    return true;
   }

//! Установка переменной окружения
inline
bool putVar(const ::std::string &varName, const ::std::string &val)
   {
    ::std::string tmp = varName + ::std::string("=") + val;
    // Могут быть утечки памяти, но зато везде безопасно.
    // Некоторые системы не делают копию передаваемого значения,
    // а запоминают непосредственно переданное значение, поэтому передача
    // автоматических переменных вызовет крах.
    char *ptmp = (char*)malloc(tmp.size()+1);
    if (!ptmp)
        return false;
    tmp.copy(ptmp, tmp.size());
    ptmp[tmp.size()] = 0;
    #ifdef _MSC_VER
    if (::_putenv(ptmp)<0) return false;
    #else
    if (::putenv(ptmp)<0) return false;
    #endif
    return true;
   }


#if defined(WIN32) || defined(_WIN32)

//! Получение переменной окружения, возвращает true, если значение получено
inline
bool getVar(const ::std::wstring &varName, ::std::wstring &val)
   {
    if (varName.empty()) return false;
    wchar_t * pval = ::_wgetenv(varName.c_str());
    if (!pval) return false;
    val = pval;
    return true;
   }

//! Получение переменной окружения, возвращает true, если значение получено
inline
bool getVar(const ::std::wstring &varName, ::std::string &val)
   {
    if (varName.empty()) return false;
    wchar_t * pval = ::_wgetenv(varName.c_str());
    if (!pval) return false;
    val = string_plus::make_string<std::string>(pval);
    return true;
   }

//! Получение переменной окружения, возвращает true, если значение получено
inline
bool getVar(const ::std::string &varName, ::std::wstring &val)
   {
    if (varName.empty()) return false;
    char * pval = ::getenv(varName.c_str());
    if (!pval) return false;
    val = string_plus::make_string<std::wstring>(pval);
    return true;
   }

//------------------------------
inline
bool putVar(const ::std::wstring &varName, const ::std::wstring &val)
   {
    ::std::wstring tmp = varName + ::std::wstring(L"=") + val;
    wchar_t *ptmp = (wchar_t*)malloc((tmp.size()+1)*sizeof(wchar_t));
    if (!ptmp)
        return false;
    tmp.copy(ptmp, tmp.size());
    ptmp[tmp.size()] = 0;
    if (::_wputenv(ptmp)<0) return false;
    return true;
   }

inline
bool getEnvVarsList( std::vector<std::pair<std::wstring,std::wstring> > &lst)
{
    auto env = GetEnvironmentStringsW();
    if (!env)
    {
        return false;
    }

    auto envOrg = env;

    while(*env)
    {
        std::wstring fullStr = env;
        std::wstring name, val;

        std::wstring::size_type eqPos = fullStr.find(L'=');
        if (eqPos==fullStr.npos)
        {
            name = fullStr;
        }
        else
        {
            name.assign(fullStr, 0, eqPos);
            val .assign(fullStr, eqPos+1, fullStr.npos);
        }

        if (!name.empty())
        {
            lst.emplace_back(std::make_pair(name, val));
        }

        env += fullStr.size()+1;
    }

    FreeEnvironmentStringsW(envOrg);

    return true;
}

inline
bool getEnvVarsList( std::vector<std::pair<std::string,std::string> > &lst)
{
#if defined(GetEnvironmentStrings)
    #undef GetEnvironmentStrings
#endif

    auto env = GetEnvironmentStrings();
    if (!env)
    {
        return false;
    }

    auto envOrg = env;

    while(*env)
    {
        std::string fullStr = env;
        std::string name, val;

        std::string::size_type eqPos = fullStr.find('=');
        if (eqPos==fullStr.npos)
        {
            name = fullStr;
        }
        else
        {
            name.assign(fullStr, 0, eqPos);
            val .assign(fullStr, eqPos+1, fullStr.npos);
        }

        if (!name.empty())
        {
            lst.emplace_back(std::make_pair(name, val));
        }

        env += fullStr.size()+1;
    }

    FreeEnvironmentStringsA(envOrg);

    return true;
}


#else

inline
bool getEnvVarsList( std::vector<std::pair<std::string,std::string> > &lst)
{
    extern char ** environ;
    char ** env = environ;
    for (; *env; ++env)
    {
        std::string fullStr = *env;
        std::string name, val;

        std::string::size_type eqPos = fullStr.find('=');
        if (eqPos==fullStr.npos)
        {
            name = fullStr;
        }
        else
        {
            name = std::string(fullStr, 0, eqPos);
            val  = std::string(fullStr, eqPos+1);
        }

        if (!name.empty())
        {
            lst.emplace_back(std::make_pair(name, val));
        }
    }

    return true;
}
//LPTCH WINAPI GetEnvironmentStrings(void);
// for (char **env = envp; *env != 0; env++)
//   {
//     char *thisEnv = *env;
//     printf("%s\n", thisEnv);
//   }


#endif


#include "../warnings/pop.h"

} // namespace internal
} // namespace env
} // namespace umba

