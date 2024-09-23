#pragma once

//----------------------------------------------------------------------------

/*! \file
    \brief Работа с переменными окружения
*/

//----------------------------------------------------------------------------


#include "umba.h"
//
#include "filesys.h"
//
#include "internal/env.h"


//
#include <stdexcept>
#include <exception>
#include <string>


// umba::env::
namespace umba
{
namespace env
{

//----------------------------------------------------------------------------

namespace envapi       = umba::env::internal;
namespace impl_helpers = umba::filesys::impl_helpers;


//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename ValueType>
bool getVar(const std::string &varName, ValueType &val)
{
    // static_assert?
    throw std::runtime_error("umba::env::getVar not implemented for this type")
}

//----------------------------------------------------------------------------
template<>
bool getVar<std::string>(const std::string &varName, std::string &val)
{
    filesys::native_fs_string_t strRes;

    if (!envapi::getVar(impl_helpers::encodeToNative(varName), strRes))
        return false;

    val = impl_helpers::encodeFromNative(strRes);
    return true;
}

//----------------------------------------------------------------------------
#define UMBA_ENV_IMPLEMENT_CHAR_GETVAR_SPECIALIZATION(type, converterFunc) \
            template<>                                                     \
            bool getVar<type>(const std::string &varName, type &val)       \
            {                                                              \
                std::string strVal;                                        \
                if (!getVar<std::string>(varName, strVal))                 \
                    return false;                                          \
                try{                                                       \
                    val = (type)converterFunc(strVal);                     \
                } catch(...){                                              \
                    return false;                                          \
                }                                                          \
                return true;                                               \
            }

UMBA_ENV_IMPLEMENT_CHAR_GETVAR_SPECIALIZATION(int               , std::stoi  )
UMBA_ENV_IMPLEMENT_CHAR_GETVAR_SPECIALIZATION(long              , std::stol  )
UMBA_ENV_IMPLEMENT_CHAR_GETVAR_SPECIALIZATION(long long         , std::stoll )
UMBA_ENV_IMPLEMENT_CHAR_GETVAR_SPECIALIZATION(unsigned          , std::stoul )
UMBA_ENV_IMPLEMENT_CHAR_GETVAR_SPECIALIZATION(unsigned long     , std::stoul )
UMBA_ENV_IMPLEMENT_CHAR_GETVAR_SPECIALIZATION(unsigned long long, std::stoull)
// https://en.cppreference.com/w/cpp/string/basic_string/stof

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename ValueType> // for compatibility
bool getVar(const std::wstring &varName, ValueType &val)
{
    // static_assert?
    throw std::runtime_error("umba::env::getVar not implemented for this type")
}

//----------------------------------------------------------------------------
template<>
bool getVar<std::wstring>(const std::wstring &varName, std::wstring &val)
{
    filesys::native_fs_string_t strRes;

    if (!envapi::getVar(impl_helpers::encodeToNative(varName), strRes))
        return false;

    val = impl_helpers::encodeToWide(strRes);
    return true;
}

//----------------------------------------------------------------------------
#define UMBA_ENV_IMPLEMENT_WIDE_GETVAR_SPECIALIZATION(type, converterFunc) \
            template<>                                                     \
            bool getVar<type>(const std::wstring &varName, type &val)      \
            {                                                              \
                std::string strVal;                                        \
                if (!getVar<std::string>(impl_helpers::encodeToChar(varName), strVal))\
                    return false;                                          \
                try{                                                       \
                    val = (type)converterFunc(strVal);                     \
                } catch(...){                                              \
                    return false;                                          \
                }                                                          \
                return true;                                               \
            }

UMBA_ENV_IMPLEMENT_WIDE_GETVAR_SPECIALIZATION(int               , std::stoi  )
UMBA_ENV_IMPLEMENT_WIDE_GETVAR_SPECIALIZATION(long              , std::stol  )
UMBA_ENV_IMPLEMENT_WIDE_GETVAR_SPECIALIZATION(long long         , std::stoll )
UMBA_ENV_IMPLEMENT_WIDE_GETVAR_SPECIALIZATION(unsigned          , std::stoul )
UMBA_ENV_IMPLEMENT_WIDE_GETVAR_SPECIALIZATION(unsigned long     , std::stoul )
UMBA_ENV_IMPLEMENT_WIDE_GETVAR_SPECIALIZATION(unsigned long long, std::stoull)
// https://en.cppreference.com/w/cpp/string/basic_string/stof

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename ValueType>
bool setVar(const std::string &varName, const ValueType &val)
{
    throw std::runtime_error("umba::env::setVar not implemented for this type")
}

//----------------------------------------------------------------------------
template<>
bool setVar<std::string>(const std::string &varName, const std::string &val)
{
    return envapi::getVar(impl_helpers::encodeToNative(varName), impl_helpers::encodeToNative(val));
}

//----------------------------------------------------------------------------
#define UMBA_ENV_IMPLEMENT_CHAR_SETVAR_SPECIALIZATION(type)                            \
            template<> bool setVar<type>(const std::string &varName, const type &val)  \
            {                                                                          \
                return setVar<std::string>(varName, std::to_string(val));              \
            }

UMBA_ENV_IMPLEMENT_CHAR_SETVAR_SPECIALIZATION(int               )
UMBA_ENV_IMPLEMENT_CHAR_SETVAR_SPECIALIZATION(long              )
UMBA_ENV_IMPLEMENT_CHAR_SETVAR_SPECIALIZATION(long long         )
UMBA_ENV_IMPLEMENT_CHAR_SETVAR_SPECIALIZATION(unsigned          )
UMBA_ENV_IMPLEMENT_CHAR_SETVAR_SPECIALIZATION(unsigned long     )
UMBA_ENV_IMPLEMENT_CHAR_SETVAR_SPECIALIZATION(unsigned long long)

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename ValueType>
bool setVar(const std::wstring &varName, const ValueType &val)
{
    throw std::runtime_error("umba::env::setVar not implemented for this type")
}

//----------------------------------------------------------------------------
template<>
bool setVar<std::wstring>(const std::wstring &varName, const std::wstring &val)
{
    return envapi::getVar(impl_helpers::encodeToNative(varName), impl_helpers::encodeToNative(val));
}

//----------------------------------------------------------------------------
#define UMBA_ENV_IMPLEMENT_WIDE_SETVAR_SPECIALIZATION(type)                            \
            template<> bool setVar<type>(const std::wstring &varName, const type &val) \
            {                                                                          \
                return setVar<std::wstring>(varName, std::to_wstring(val));            \
            }

UMBA_ENV_IMPLEMENT_WIDE_SETVAR_SPECIALIZATION(int               )
UMBA_ENV_IMPLEMENT_WIDE_SETVAR_SPECIALIZATION(long              )
UMBA_ENV_IMPLEMENT_WIDE_SETVAR_SPECIALIZATION(long long         )
UMBA_ENV_IMPLEMENT_WIDE_SETVAR_SPECIALIZATION(unsigned          )
UMBA_ENV_IMPLEMENT_WIDE_SETVAR_SPECIALIZATION(unsigned long     )
UMBA_ENV_IMPLEMENT_WIDE_SETVAR_SPECIALIZATION(unsigned long long)

//----------------------------------------------------------------------------



// #if defined(WIN32) || defined(_WIN32)
//  
// inline
// bool getEnvVarsList( std::vector<std::pair<std::wstring,std::wstring> > &lst)
//  
// inline
// bool getEnvVarsList( std::vector<std::pair<std::string,std::string> > &lst)
//  
// #else
//  
// inline
// bool getEnvVarsList( std::vector<std::pair<std::string,std::string> > &lst)
//  
// #endif


} // namespace env
} // namespace umba

