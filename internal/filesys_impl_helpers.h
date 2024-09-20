#pragma once

#include "../umba.h"
//
#include "../utf.h"
//
#include <string>
//


//-----------------------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32)
    #if !defined(UMBA_FILESYS_HAS_NATIVE_WIDE_API)
        #define UMBA_FILESYS_HAS_NATIVE_WIDE_API
    #endif
#else
    // #define UMBA_FILESYS_HAS_NATIVE_CHAR_API
#endif

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// umba::filesys::
namespace umba{
namespace filesys{
namespace impl_helpers {

/* Я пока не разбирался детально, как работают кодировки файловой системы во всяких *nix'ах.
   Пока завязываемся на то, что все файловые API *nix принимают UTF-8.
   Это должно работать в большинстве случаев в современном мире.
 */

// umba ("utf.h")
// std::wstring fromUtf8(const std::string &str)
// std::wstring fromUtf8(const char *pStr)
// std::string toUtf8(const std::wstring &str)
// std::string toUtf8(const wchar_t *pStr)

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
template<typename StringTypeTo> inline StringTypeTo nameConvert(const std::wstring &name)
{
    if constexpr (sizeof(typename StringTypeTo::value_type)>1)
        return name;
    else
        return toUtf8(name);
}

template<typename StringTypeTo> inline StringTypeTo nameConvert(const std::string &name)
{
    if constexpr (sizeof(typename StringTypeTo::value_type)>1)
        return fromUtf8(name);
    else
        return name;
}

template<typename StringTypeTo> inline StringTypeTo nameConvert(const wchar_t *name)
{
    if constexpr (sizeof(typename StringTypeTo::value_type)>1)
        return name ? std::wstring(name) : std::wstring();
    else
        return toUtf8(name);
}

template<typename StringTypeTo> inline StringTypeTo nameConvert(const char* name)
{
    if constexpr (sizeof(typename StringTypeTo::value_type)>1)
        return fromUtf8(name);
    else
        return name ? std::string(name) : std::string();
}

//-----------------------------------------------------------------------------
inline std::wstring encodeToWide(const std::wstring &name)    { return name; }
inline std::wstring encodeToWide(const wchar_t* name)         { return name ? std::wstring(name) : std::wstring(); }
inline std::wstring encodeToWide(wchar_t nameChar)            { return std::wstring(1, nameChar); }
inline std::wstring encodeToWide(const std::string &name)     { return fromUtf8(name); }
inline std::wstring encodeToWide(const char* name)            { return name ? fromUtf8(name) : std::wstring(); }
inline std::wstring encodeToWide(char nameChar)               { return fromUtf8(std::string(1, nameChar)); }

//-----------------------------------------------------------------------------
inline std::string encodeToChar(const std::wstring &name)     { return toUtf8(name); }
inline std::string encodeToChar(const wchar_t* name)          { return name ? toUtf8(name) : std::string(); }
inline std::string encodeToChar(wchar_t nameChar)             { return toUtf8(std::wstring(1, nameChar)); }
inline std::string encodeToChar(const std::string &name)      { return name; }
inline std::string encodeToChar(const char* name)             { return name ? std::string(name) : std::string(); }
inline std::string encodeToChar(char nameChar)                { return std::string(1, nameChar); }

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
#if defined(UMBA_FILESYS_HAS_NATIVE_WIDE_API)

//-----------------------------------------------------------------------------
inline std::wstring encodeToNative(const std::wstring &name)  { return encodeToWide(name); }
inline std::wstring encodeToNative(const wchar_t* name)       { return encodeToWide(name); }
inline std::wstring encodeToNative(wchar_t nameChar)          { return encodeToWide(nameChar); }
inline std::wstring encodeToNative(const std::string &name)   { return encodeToWide(name); }
inline std::wstring encodeToNative(const char* name)          { return encodeToWide(name); }
inline std::wstring encodeToNative(char nameChar)             { return encodeToWide(nameChar); }

//-----------------------------------------------------------------------------

inline std::string encodeFromNative(const std::wstring &name) { return encodeToChar(name); }
inline std::string encodeFromNative(const wchar_t* name)      { return encodeToChar(name); }
inline std::string encodeFromNative(wchar_t nameChar)         { return encodeToChar(nameChar); }
inline std::string encodeFromNative(const std::string &name)  { return encodeToChar(name); }
inline std::string encodeFromNative(const char* name)         { return encodeToChar(name); }
inline std::string encodeFromNative(char nameChar)            { return encodeToChar(nameChar); }

//-----------------------------------------------------------------------------

#else // !UMBA_FILESYS_HAS_NATIVE_WIDE_API

//-----------------------------------------------------------------------------
inline std::string encodeToNative(const std::wstring &name)   { return encodeToChar(name); }
inline std::string encodeToNative(const wchar_t* name)        { return encodeToChar(name); }
inline std::string encodeToNative(wchar_t nameChar)           { return encodeToChar(nameChar); }
inline std::string encodeToNative(const std::string &name)    { return encodeToChar(name); }
inline std::string encodeToNative(const char* name)           { return encodeToChar(name); }
inline std::string encodeToNative(char nameChar)              { return encodeToChar(nameChar); }

//-----------------------------------------------------------------------------
inline std::string encodeFromNative(const std::wstring &name) { return encodeToChar(name); }
inline std::string encodeFromNative(const wchar_t* name)      { return encodeToChar(name); }
inline std::string encodeFromNative(wchar_t nameChar)         { return encodeToChar(nameChar); }
inline std::string encodeFromNative(const std::string &name)  { return encodeToChar(name); }
inline std::string encodeFromNative(const char* name)         { return encodeToChar(name); }
inline std::string encodeFromNative(char nameChar)            { return encodeToChar(nameChar); }

//-----------------------------------------------------------------------------

#endif // UMBA_FILESYS_HAS_NATIVE_WIDE_API


//-----------------------------------------------------------------------------
} // namespace impl_helpers
} // namespace filesys{
} // namespace umba{



