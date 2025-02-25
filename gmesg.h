#pragma once

#include "umba.h"
//
#include "preprocessor.h"
#include "debug_helpers.h"

//
#include "utf.h"
#include <exception>
#include <stdexcept>

namespace umba {


namespace {

std::wstring& getGlobalMessageStringImpl()
{
    static std::wstring msg;
    return msg;
}

} // namespace


template<typename StringType> inline
StringType getGlobalMessage()
{
    #ifdef UMBA_DEBUGBREAK
        UMBA_DEBUGBREAK();
    #endif
    throw std::runtime_error("umba::getGlobalMessage not implemented for this string type");
}

template<> inline
std::string getGlobalMessage<std::string>()
{
    return toUtf8(getGlobalMessageStringImpl());
}

template<> inline
std::wstring getGlobalMessage<std::wstring>()
{
    return getGlobalMessageStringImpl();
}

template<typename StringType> inline
void setGlobalMessage(const StringType &)
{
    #ifdef UMBA_DEBUGBREAK
        UMBA_DEBUGBREAK();
    #endif
    throw std::runtime_error("umba::setGlobalMessage not implemented for this string type");
}

template<> inline
void setGlobalMessage<std::string>(const std::string &msg)
{
    getGlobalMessageStringImpl() = fromUtf8(msg);
}

template<> inline
void setGlobalMessage<std::wstring>(const std::wstring &msg)
{
    getGlobalMessageStringImpl() = msg;
}

inline
void setGlobalMessage(const char* pMsg)
{
    if (pMsg)
    {
        getGlobalMessageStringImpl() = fromUtf8(pMsg);
    }
}

inline
void setGlobalMessage(const wchar_t* pMsg)
{
    if (pMsg)
    {
        getGlobalMessageStringImpl() = pMsg;
    }
}


template<typename StringType> inline
StringType gmesg()
{
    return getGlobalMessage<StringType>();
}

template<typename StringType> inline
void gmesg(const StringType &msg)
{
    setGlobalMessage(msg);
}

inline
void gmesg(const char* pMsg)
{
    setGlobalMessage(pMsg);
}

inline
void gmesg(const wchar_t* pMsg)
{
    setGlobalMessage(pMsg);
}


template<typename StringTypeA, typename StringTypeB> inline
void gmesg(const StringTypeA &file, const StringTypeB &msg)
{
    setGlobalMessage<std::wstring>(fromUtf8(file) + L": " + fromUtf8(msg));
}

template<typename StringType>
void gmesg(const StringType &file, const char *pMsg)
{
    if (pMsg)
    {
        setGlobalMessage<std::wstring>(fromUtf8(file) + L": " + fromUtf8(pMsg));
    }
}

template<typename StringType>
void gmesg(const StringType &file, const wchar_t *pMsg)
{
    if (pMsg)
    {
        setGlobalMessage<std::wstring>(fromUtf8(file) + L": " + fromUtf8(pMsg));
    }
}

void gmesgClr()
{
    getGlobalMessageStringImpl().clear();
}



} // namespace umba

