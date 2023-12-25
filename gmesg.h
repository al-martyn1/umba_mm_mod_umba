#pragma once

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
void setGlobalMessage(const StringType &msg)
{
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


template<typename StringType> inline
StringType gmesg()
{
    return getGlobalMessage<StringType>();
}

template<typename StringType> inline
void gmesg(const StringType &msg)
{
    setGlobalMessage<StringType>(msg);
}

template<typename StringTypeA, typename StringTypeB> inline
void gmesg(const StringTypeA &file, const StringTypeB &msg)
{
    setGlobalMessage<std::wstring>(fromUtf8(file) + L": " + fromUtf8(msg));
}

void gmesgClr()
{
    getGlobalMessageStringImpl().clear();
}



} // namespace umba

