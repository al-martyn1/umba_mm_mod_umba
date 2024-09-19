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

#include "internal/filesys.h"


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32)
    #define UMBA_FILESYS_HAS_NATIVE_WIDE_API
#else
    // #define UMBA_FILESYS_HAS_NATIVE_CHAR_API
#endif

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// umba::filesys::
namespace umba{
namespace filesys{

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// Aliasing for current implementation
namespace fsysapi = ::umba::filesys::internal;

#if defined(UMBA_FILESYS_HAS_NATIVE_WIDE_API)

    using native_fs_string_t = std::wstring;

#else // !UMBA_FILESYS_HAS_NATIVE_WIDE_API

    using native_fs_string_t = std::string;

#endif // UMBA_FILESYS_HAS_NATIVE_WIDE_API


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

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
using impl_helpers::nameConvert;



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// Here goes API itself


//-----------------------------------------------------------------------------
// Use fsysapi::, Luke


//-----------------------------------------------------------------------------
using FileType = fsysapi::FileType; // пофиг, что проросло, надо переделывать

// enum FileType // Надо бы переделать в enum class, но уж больно много где проросло
// {
//     FileTypeInvalid = fsysapi::FileTypeInvalid, //!< Файл не найден, или ещё какая-то проблема
//     FileTypeUnknown = fsysapi::FileTypeUnknown, //!< Тип файла не известен
//     FileTypeDir     = fsysapi::FileTypeDir    , //!< Каталог, не файл
//     FileTypeFile    = fsysapi::FileTypeFile   , //!< Файл
//     FileTypeRam     = fsysapi::FileTypeRam      //!< Что-то просто лежит в памяти
// };




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
    return impl_helpers::encodeFromNative(fsysapi::formatFiletime(t, impl_helpers::encodeToNative(fmt)));
}

//-----------------------------------------------------------------------------
inline std::string formatFiletime(filetime_t t, const std::string &fmt)
{
    return impl_helpers::encodeFromNative(fsysapi::formatFiletime(t, impl_helpers::encodeToNative(fmt)));
}

//-----------------------------------------------------------------------------
inline std::string formatFiletime(filetime_t t, const wchar_t *fmt)
{
    return impl_helpers::encodeFromNative(fsysapi::formatFiletime(t, impl_helpers::encodeToNative(fmt)));
}

//-----------------------------------------------------------------------------
inline std::string formatFiletime(filetime_t t, const char *fmt)
{
    return impl_helpers::encodeFromNative(fsysapi::formatFiletime(t, impl_helpers::encodeToNative(fmt)));
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
using FileStat = fsysapi::FileStat;

//-----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Возвращает FileStat по пути (файл или каталог, не важно)
inline bool getPathStat(const std::wstring &path, FileStat &fileStat)
{
    return fsysapi::getPathStat(impl_helpers::encodeToNative(path), fileStat);
}

//------------------------------
//! Возвращает FileStat по пути (файл или каталог, не важно)
inline bool getPathStat(const std::string &path, FileStat &fileStat)
{
    return fsysapi::getPathStat(impl_helpers::encodeToNative(path), fileStat);
}

//------------------------------
//! Возвращает FileStat по пути (файл или каталог, не важно)
inline bool getPathStat(const wchar_t *path, FileStat &fileStat)
{
    return fsysapi::getPathStat(impl_helpers::encodeToNative(path), fileStat);
}

//------------------------------
//! Возвращает FileStat по пути (файл или каталог, не важно)
inline bool getPathStat(const char *path, FileStat &fileStat)
{
    return fsysapi::getPathStat(impl_helpers::encodeToNative(path), fileStat);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool isPathExist(const std::wstring &path)
{
    return fsysapi::isPathExist(impl_helpers::encodeToNative(path));
}

//------------------------------

inline bool isPathExist(const std::string &path)
{
    return fsysapi::isPathExist(impl_helpers::encodeToNative(path));
}

//------------------------------

inline bool isPathExist(const wchar_t *path)
{
    return fsysapi::isPathExist(impl_helpers::encodeToNative(path));
}

//------------------------------

inline bool isPathExist(const char *path)
{
    return fsysapi::isPathExist(impl_helpers::encodeToNative(path));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool isPathDirectory(const std::wstring &path)
{
    return fsysapi::isPathDirectory(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isPathDirectory(const std::string &path)
{
    return fsysapi::isPathDirectory(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isPathDirectory(const wchar_t *path)
{
    return fsysapi::isPathDirectory(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isPathDirectory(const char *path)
{
    return fsysapi::isPathDirectory(impl_helpers::encodeToNative(path));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool isPathFile(const std::wstring &path)
{
    return fsysapi::isPathFile(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isPathFile(const std::string &path)
{
    return fsysapi::isPathFile(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isPathFile(const wchar_t *path)
{
    return fsysapi::isPathFile(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isPathFile(const char *path)
{
    return fsysapi::isPathFile(impl_helpers::encodeToNative(path));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool isFileExist(const std::wstring &path)
{
    return fsysapi::isFileExist(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isFileExist(const std::string &path)
{
    return fsysapi::isFileExist(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isFileExist(const wchar_t *path)
{
    return fsysapi::isFileExist(impl_helpers::encodeToNative(path));
}

//------------------------------
inline bool isFileExist(const char *path)
{
    return fsysapi::isFileExist(impl_helpers::encodeToNative(path));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool isFileReadonly( const std::wstring &fname )
{
    return fsysapi::isFileReadonly(impl_helpers::encodeToNative(fname));
}

//------------------------------
inline bool isFileReadonly( const std::string &fname )
{
    return fsysapi::isFileReadonly(impl_helpers::encodeToNative(fname));
}

//------------------------------
inline bool isFileReadonly( const wchar_t *fname )
{
    return fsysapi::isFileReadonly(impl_helpers::encodeToNative(fname));
}

//------------------------------
inline bool isFileReadonly( const char *fname )
{
    return fsysapi::isFileReadonly(impl_helpers::encodeToNative(fname));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool isFileReadable( const std::wstring &fname )
{
    return fsysapi::isFileReadable(impl_helpers::encodeToNative(fname));
}

//------------------------------
inline bool isFileReadable( const std::string &fname )
{
    return fsysapi::isFileReadable(impl_helpers::encodeToNative(fname));
}

//------------------------------
inline bool isFileReadable( const wchar_t *fname )
{
    return fsysapi::isFileReadable(impl_helpers::encodeToNative(fname));
}

//------------------------------
inline bool isFileReadable( const char *fname )
{
    return fsysapi::isFileReadable(impl_helpers::encodeToNative(fname));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline filetime_t getFileTimeNow()
{
    return fsysapi::getFileTimeNow();
}

//----------------------------------------------------------------------------
inline bool isLastErrorAlreadyExists()
{
    return fsysapi::isLastErrorAlreadyExists();
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
inline std::string getTempFolderPath()
{
    return impl_helpers::encodeFromNative(fsysapi::getTempFolderPath<native_fs_string_t>());
}

//----------------------------------------------------------------------------
inline std::string getCurrentUserHomeDirectory()
{
    return impl_helpers::encodeFromNative(fsysapi::getCurrentUserHomeDirectory<native_fs_string_t>());
}

//----------------------------------------------------------------------------
inline std::string getCurrentDrive()
{
    return impl_helpers::encodeFromNative(fsysapi::getCurrentDrive<native_fs_string_t>());
}

//----------------------------------------------------------------------------
//! Получение текущего рабочего каталога
inline std::string getCurrentDirectory()
{
    return impl_helpers::encodeFromNative(fsysapi::getCurrentDirectory<native_fs_string_t>());
}

//------------------------------
//! Установка текущего рабочего каталога
inline bool setCurrentDirectory(const std::wstring &newCurDir)
{
    return fsysapi::setCurrentDirectory(impl_helpers::encodeToNative(newCurDir));
}

//------------------------------
//! Установка текущего рабочего каталога
inline bool setCurrentDirectory(const std::string &newCurDir)
{
    return fsysapi::setCurrentDirectory(impl_helpers::encodeToNative(newCurDir));
}

//------------------------------
//! Установка текущего рабочего каталога
inline bool setCurrentDirectory(const wchar_t *newCurDir)
{
    return fsysapi::setCurrentDirectory(impl_helpers::encodeToNative(newCurDir));
}

//------------------------------
//! Установка текущего рабочего каталога
inline bool setCurrentDirectory(const char *newCurDir)
{
    return fsysapi::setCurrentDirectory(impl_helpers::encodeToNative(newCurDir));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Удаление файла
inline bool deleteFile( const std::wstring &filename )
{
    return fsysapi::deleteFile(impl_helpers::encodeToNative(filename));
}

//------------------------------
//! Удаление файла
inline bool deleteFile( const std::string &filename )
{
    return fsysapi::deleteFile(impl_helpers::encodeToNative(filename));
}

//------------------------------
//! Удаление файла
inline bool deleteFile( const wchar_t *filename )
{
    return fsysapi::deleteFile(impl_helpers::encodeToNative(filename));
}

//------------------------------
//! Удаление файла
inline bool deleteFile( const char *filename )
{
    return fsysapi::deleteFile(impl_helpers::encodeToNative(filename));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Удаление каталога
inline bool deleteDirectory( const std::wstring &dirname )
{
    return fsysapi::deleteDirectory(impl_helpers::encodeToNative(dirname));
}

//------------------------------
//! Удаление каталога
inline bool deleteDirectory( const std::string &dirname )
{
    return fsysapi::deleteDirectory(impl_helpers::encodeToNative(dirname));
}

//------------------------------
//! Удаление каталога
inline bool deleteDirectory( const wchar_t *dirname )
{
    return fsysapi::deleteDirectory(impl_helpers::encodeToNative(dirname));
}

//------------------------------
//! Удаление каталога
inline bool deleteDirectory( const char *dirname )
{
    return fsysapi::deleteDirectory(impl_helpers::encodeToNative(dirname));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Создание каталога
inline bool createDirectory( const std::wstring &dirname )
{
    return fsysapi::createDirectory(impl_helpers::encodeToNative(dirname));
}

//------------------------------
//! Создание каталога
inline bool createDirectory( const std::string &dirname )
{
    return fsysapi::createDirectory(impl_helpers::encodeToNative(dirname));
}

//------------------------------
//! Создание каталога
inline bool createDirectory( const wchar_t *dirname )
{
    return fsysapi::createDirectory(impl_helpers::encodeToNative(dirname));
}

//------------------------------
//! Создание каталога
inline bool createDirectory( const char *dirname )
{
    return fsysapi::createDirectory(impl_helpers::encodeToNative(dirname));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Создание каталога с возможностью создания полного пути
inline bool createDirectoryEx( const std::wstring &dirname, bool forceCreatePath )
{
    return fsysapi::createDirectoryEx(impl_helpers::encodeToNative(dirname), forceCreatePath);
}

//------------------------------
//! Создание каталога с возможностью создания полного пути
inline bool createDirectoryEx( const std::string &dirname, bool forceCreatePath )
{
    return fsysapi::createDirectoryEx(impl_helpers::encodeToNative(dirname), forceCreatePath);
}

//------------------------------
//! Создание каталога с возможностью создания полного пути
inline bool createDirectoryEx( const wchar_t *dirname, bool forceCreatePath )
{
    return fsysapi::createDirectoryEx(impl_helpers::encodeToNative(dirname), forceCreatePath);
}

//------------------------------
//! Создание каталога с возможностью создания полного пути
inline bool createDirectoryEx( const char *dirname, bool forceCreatePath )
{
    return fsysapi::createDirectoryEx(impl_helpers::encodeToNative(dirname), forceCreatePath);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename DataType> inline
bool readFile( const std::wstring &filename, std::vector<DataType> &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//------------------------------
template<typename DataType> inline
bool readFile( const std::string &filename, std::vector<DataType> &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//------------------------------
template<typename DataType> inline
bool readFile( const wchar_t *filename, std::vector<DataType> &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//------------------------------
template<typename DataType> inline
bool readFile( const char *filename   , std::vector<DataType> &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool readFile( const std::wstring &filename, std::string &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//------------------------------
inline bool readFile( const std::string &filename, std::string &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//------------------------------
inline bool readFile( const wchar_t *filename, std::string &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//------------------------------
inline bool readFile( const char *filename   , std::string &filedata, FileStat *pFileStat = 0, bool ignoreSizeErrors = true)
{
    return fsysapi::readFile(impl_helpers::encodeToNative(filename), filedata, pFileStat, ignoreSizeErrors);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename DataType> inline
bool writeFile( const std::wstring &filename, const DataType *pData, size_t dataSize, bool bOverwrite = false)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), pData, dataSize, bOverwrite);
}

//------------------------------
template<typename DataType> inline
bool writeFile( const std::string &filename, const DataType *pData, size_t dataSize, bool bOverwrite = false)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), pData, dataSize, bOverwrite);
}

//------------------------------
template<typename DataType> inline
bool writeFile( const wchar_t *filename, const DataType *pData, size_t dataSize, bool bOverwrite = false)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), pData, dataSize, bOverwrite);
}

//------------------------------
template<typename DataType> inline
bool writeFile( const char *filename, const DataType *pData, size_t dataSize, bool bOverwrite = false)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), pData, dataSize, bOverwrite);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename DataType> inline
bool writeFile( const std::wstring &filename, const std::vector<DataType> &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//------------------------------
template<typename DataType> inline
bool writeFile( const std::string &filename, const std::vector<DataType> &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//------------------------------
template<typename DataType> inline
bool writeFile( const wchar_t *filename, const std::vector<DataType> &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//------------------------------
template<typename DataType> inline
bool writeFile( const char *filename, const std::vector<DataType> &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline bool writeFile( const std::wstring &filename, const std::string &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//------------------------------
inline bool writeFile( const std::string &filename, const std::string &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//------------------------------
inline bool writeFile( const wchar_t *filename, const std::string &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//------------------------------
inline bool writeFile( const char *filename, const std::string &filedata, bool bOverwrite)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(filename), filedata, bOverwrite);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename EnumDirectoryHandler> inline
bool enumerateDirectory(const std::wstring &path, EnumDirectoryHandler handler)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(path), handler);
}

//------------------------------
template<typename EnumDirectoryHandler> inline
bool enumerateDirectory(const std::string &path, EnumDirectoryHandler handler)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(path), handler);
}

//------------------------------
template<typename EnumDirectoryHandler> inline
bool enumerateDirectory(const wchar_t *path, EnumDirectoryHandler handler)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(path), handler);
}

//------------------------------
template<typename EnumDirectoryHandler> inline
bool enumerateDirectory(const char *path, EnumDirectoryHandler handler)
{
    return fsysapi::writeFile(impl_helpers::encodeToNative(path), handler);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------



//------------------------------












// Use fsysapi::, Luke
// Use impl_helpers::encodeToNative and impl_helpers::encodeFromNative, Luke
// native_fs_string_t

//-----------------------------------------------------------------------------

} // namespace filesys
} // namespace umba




