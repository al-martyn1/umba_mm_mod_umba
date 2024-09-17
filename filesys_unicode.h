#pragma once

//-----------------------------------------------------------------------------

/*!
    \file
    \brief Прослойка абстракций для работы с файловой системой, версия, работающая одинаково с любыми типами имён (char/wchar_t)

    Все функции принимают как std::string, так и std::wstring, но возвращают всегда только std::string.

    В std::string юникод представлен в кодировке UTF-8.

    Надо подумать, и как-то объявить "umba/filesys.h" устаревшим заголовком, чтобы везде выдавались предупреждения при его использовании.
    Как вариант, спрятать "umba/filesys.h" в подкаталог internal. Переехать на эту тему везде
    Переименовать текущий umba::filesys в umba::filesys::internal. Переехать на эту тему везде


 */

//-----------------------------------------------------------------------------

#include "umba.h"
#include "utf.h"

#include "filesys.h"


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32)
    #define UMBA_FILESYS_HAS_NATIVE_WIDE_API
#else
    // #define UMBA_FILESYS_HAS_NATIVE_CHAR_API
#endif

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// umba::filesys_unicode::
namespace umba{
namespace filesys_unicode{

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// Aliasing for current implementation
namespace fsysapi = ::umba::filesys;

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
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
// encodeToWide

//-----------------------------------------------------------------------------
inline std::wstring encodeToWide(const std::wstring &name)
{
    return name;
}

//------------------------------
inline std::wstring encodeToWide(const wchar_t* name)
{
    return name ? std::wstring(name) : std::wstring();
}

//------------------------------
inline std::wstring encodeToWide(wchar_t nameChar)
{
    return std::wstring(1, nameChar);
}

//------------------------------
inline std::wstring encodeToWide(const std::string &name)
{
    return fromUtf8(name);
}

//------------------------------
inline std::wstring encodeToWide(const char* name)
{
    return name ? fromUtf8(name) : std::wstring();
}

//------------------------------
inline std::wstring encodeToWide(char nameChar)
{
    return fromUtf8(std::string(1, nameChar));
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// encodeToChar

//-----------------------------------------------------------------------------
inline std::string encodeToChar(const std::wstring &name)
{
    return toUtf8(name);
}

//------------------------------
inline std::string encodeToChar(const wchar_t* name)
{
    return name ? toUtf8(name) : std::string();
}

//------------------------------
inline std::string encodeToChar(wchar_t nameChar)
{
    return toUtf8(std::wstring(1, nameChar));
}

//------------------------------
inline std::string encodeToChar(const std::string &name)
{
    return name;
}

//------------------------------
inline std::string encodeToChar(const char* name)
{
    return name ? std::string(name) : std::string();
}

//------------------------------
inline std::string encodeToChar(char nameChar)
{
    return std::string(1, nameChar);
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
#if defined(UMBA_FILESYS_HAS_NATIVE_WIDE_API)

//-----------------------------------------------------------------------------
inline std::wstring encodeToNative(const std::wstring &name)
{
    return encodeToWide(name);
}

//------------------------------
inline std::wstring encodeToNative(const wchar_t* name)
{
    return encodeToWide(name);
}

//------------------------------
inline std::wstring encodeToNative(wchar_t nameChar)
{
    return encodeToWide(nameChar);
}

//------------------------------
inline std::wstring encodeToNative(const std::string &name)
{
    return encodeToWide(name);
}

//------------------------------
inline std::wstring encodeToNative(const char* name)
{
    return encodeToWide(name);
}

//------------------------------
inline std::wstring encodeToNative(char nameChar)
{
    return encodeToWide(nameChar);
}

//-----------------------------------------------------------------------------
inline std::string encodeFromNative(const std::wstring &name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(const wchar_t* name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(wchar_t nameChar)
{
    return encodeToChar(nameChar);
}

//------------------------------
inline std::string encodeFromNative(const std::string &name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(const char* name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(char nameChar)
{
    return encodeToChar(nameChar);
}

//-----------------------------------------------------------------------------

#else // !UMBA_FILESYS_HAS_NATIVE_WIDE_API

//-----------------------------------------------------------------------------
inline std::string encodeToNative(const std::wstring &name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeToNative(const wchar_t* name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeToNative(wchar_t nameChar)
{
    return encodeToChar(nameChar);
}

//------------------------------
inline std::string encodeToNative(const std::string &name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeToNative(const char* name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeToNative(char nameChar)
{
    return encodeToChar(nameChar);
}

//-----------------------------------------------------------------------------
inline std::string encodeFromNative(const std::wstring &name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(const wchar_t* name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(wchar_t nameChar)
{
    return encodeToChar(nameChar);
}

//------------------------------
inline std::string encodeFromNative(const std::string &name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(const char* name)
{
    return encodeToChar(name);
}

//------------------------------
inline std::string encodeFromNative(char nameChar)
{
    return encodeToChar(nameChar);
}

//-----------------------------------------------------------------------------

#endif // UMBA_FILESYS_HAS_NATIVE_WIDE_API


//-----------------------------------------------------------------------------
} // namespace impl_helpers

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// Here goes API itself


//-----------------------------------------------------------------------------
// Use fsysapi::, Luke


//-----------------------------------------------------------------------------
using FileType = fsysapi::FileType;



//-----------------------------------------------------------------------------
// Мы реализуем полную замену предыдущего API, так что делаем и те функции, которые от имён не зависят

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
template<typename DataType> inline
bool readFile(std::istream &fileIn, std::vector<DataType> &filedata)
{
    return fsysapi::readFile(fileIn, filedata);
}

//-----------------------------------------------------------------------------
inline bool readFile(std::istream &fileIn, std::string &filedata)
{
    return fsysapi::readFile(fileIn, filedata);
}

//-----------------------------------------------------------------------------
template<typename DataType> inline
bool writeFile(std::ostream &fileOut, const DataType *pData, size_t dataSize)
{
    return fsysapi::writeFile(fileOut, pData, dataSize);
}

//-----------------------------------------------------------------------------
template<typename DataType> inline
bool writeFile(std::ostream &fileOut, const std::vector<DataType> &data)
{
    return fsysapi::writeFile(fileOut, data);
}

//-----------------------------------------------------------------------------
inline bool writeFile(std::ostream &fileOut, const std::string &data)
{
    return fsysapi::writeFile(fileOut, data);
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
using filetime_t = fsysapi::filetime_t;
using filesize_t = fsysapi::filesize_t;

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// Use impl_helpers::encodeToNative and impl_helpers::encodeFromNative, Luke

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
inline std::string formatFiletime(filetime_t t, const std::wstring &fmt)
{
    return fsysapi::formatFiletime(t, impl_helpers::encodeToChar(fmt));
}

//-----------------------------------------------------------------------------
inline std::string formatFiletime(filetime_t t, const std::string &fmt)
{
    return fsysapi::formatFiletime(t, impl_helpers::encodeToChar(fmt));
}

//-----------------------------------------------------------------------------
inline std::string formatFiletime(filetime_t t, const wchar_t *fmt)
{
    return fsysapi::formatFiletime(t, impl_helpers::encodeToChar(fmt));
}

//-----------------------------------------------------------------------------
inline std::string formatFiletime(filetime_t t, const char *fmt)
{
    return fsysapi::formatFiletime(t, impl_helpers::encodeToChar(fmt));
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
using FileStat = fsysapi::FileStat;

//-----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Возвращает FileStat по пути (файл или каталог, не важно)
inline bool getPathStat()








template<typename StringType>
bool getPathStat(const StringType &path, FileStat &fileStat)


template<typename StringType>
bool isPathExist(const StringType &path)
{
    FileStat fileStat;
    return getPathStat(path, fileStat);
}

//----------------------------------------------------------------------------
template<typename StringType>
bool isPathDirectory(const StringType &path)
{
    FileStat fileStat;
    if (!getPathStat(path, fileStat))
        return false;

    return fileStat.isDir();
}

//----------------------------------------------------------------------------
template<typename StringType>
bool isPathFile(const StringType &path)
{
    FileStat fileStat;
    if (!getPathStat(path, fileStat))
        return false;

    return fileStat.isFile();
}

//----------------------------------------------------------------------------
template<typename StringType>
bool isFileExist(const StringType &path)
{
    FileStat fileStat;
    if (!getPathStat(path, fileStat))
        return false;
    return fileStat.isFile();
}

//----------------------------------------------------------------------------









// Use fsysapi::, Luke
// Use impl_helpers::encodeToNative and impl_helpers::encodeFromNative, Luke

//-----------------------------------------------------------------------------

} // namespace filesys_unicode
} // namespace umba




