#pragma once

#include <climits>
#include <string>

//
#include "utf_impl.h"



namespace umba {


inline
std::string toUtf8(const std::wstring &str)
{

    #if WCHAR_MAX <= 0xFFFFu /* wchar_t is 16 bit width, signed or unsigned */

        auto  utfCharsStr32        = utf32_from_utf16(str);
        const utf32_char_t *pBegin = utfCharsStr32.data();
        return string_from_utf32(pBegin, pBegin+utfCharsStr32.size());

    #else

        const utf32_char_t *pBegin = str.data();
        return string_from_utf32(pBegin, pBegin+str.size());

    #endif

    // auto pApi = getEncodingsApi();
    // return pApi->encode(str, EncodingsApi::cpid_UTF8);
}

inline
std::string toUtf8(const wchar_t *pStr)
{
    if (!pStr)
    {
        return std::string();
    }

    return toUtf8(std::wstring(pStr));
}

inline
std::string toUtf8(const std::string &str)
{
    return str;
}

inline
std::string toUtf8(const char *pStr)
{
    if (!pStr)
    {
        return std::string();
    }

    return std::string(pStr);
}

inline
std::wstring fromUtf8(const std::string &str)
{
    #if WCHAR_MAX <= 0xFFFFu /* wchar_t is 16 bit width, signed or unsigned */

        std::basic_string<utf32_char_t> stringU32 = utf32_from_utf8(str);
        std::basic_string<utf16_char_t> stringU16 = utf16_from_utf32(stringU32);
        return wstring_from_utf16(stringU16);

    #else

        return wstring32_from_utf8(str);

    #endif

}

inline
std::wstring fromUtf8(const char *pStr)
{
    if (!pStr)
    {
        return std::wstring();
    }

    return fromUtf8(std::string(pStr));
}

inline
std::wstring fromUtf8(const std::wstring &str)
{
    return str;
}

inline
std::wstring fromUtf8(const wchar_t *pStr)
{
    if (!pStr)
    {
        return std::wstring();
    }

    return std::wstring(pStr);
}


//template<typename StringType> inline
//void utfToStringType(StringType &to, )

inline
void utfToStringTypeHelper(std::string &to, const char *pStr)
{
    to = pStr;
}

inline
void utfToStringTypeHelper(std::string &to, const std::string &str)
{
    to = str;
}

inline
void utfToStringTypeHelper(std::wstring &to, const char *pStr)
{
    to = fromUtf8(pStr);
}

inline
void utfToStringTypeHelper(std::wstring &to, const std::string &str)
{
    to = fromUtf8(str);
}



inline
void utfToStringTypeHelper(std::wstring &to, const wchar_t *pStr)
{
    to = pStr;
}

inline
void utfToStringTypeHelper(std::wstring &to, const std::wstring &str)
{
    to = str;
}

inline
void utfToStringTypeHelper(std::string &to, const wchar_t *pStr)
{
    to = toUtf8(pStr);
}

inline
void utfToStringTypeHelper(std::string &to, const std::wstring &str)
{
    to = toUtf8(str);
}


template<typename StringTypeFrom, typename StringTypeTo>
void utfFromTo(const StringTypeFrom &from, StringTypeTo &to)
{
    std::wstring wideStr = fromUtf8(from);
    to = toUtf8(wideStr);
}

template<typename StringTypeFrom, typename StringTypeTo>
StringTypeTo utfFromToReturn(const StringTypeFrom &from)
{
    std::wstring wideStr = fromUtf8(from);
    return toUtf8(wideStr);
}


//template<typename StringType> inline
//void utfToStringType(StringType &to, )



} // namespace umba {


