#pragma once

#include "umba.h"
#include "filesys.h"
#include "utf8.h"
#include "umba/string_plus.h"

#if defined(WIN32) || defined(_WIN32)
    #include <shellapi.h>
    //
    #include "win32_utils.h"
#endif

//----------------------------------------------------------------------------
// umba::shellapi::
namespace umba {
namespace shellapi {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Удаляет каталог со всем содержимым. path - в UTF-8
inline
bool deleteDirectory(const std::string &path)
{
#if defined(WIN32) || defined(_WIN32)

    std::wstring wp = filesys::encodeToNative(path);

    SHFILEOPSTRUCTW  shFileOpStruct = { 0 };
    wp.append(1, (wchar_t)0); // Надо два нуля в конце, потому что функция принимает разделяемый нулём список строк, и двойной ноль - окончание списка
    shFileOpStruct.wFunc  = FO_DELETE;
    shFileOpStruct.pFrom  = (PCZZWSTR)wp.c_str();
    shFileOpStruct.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR;  // FOF_NOERRORUI - FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR
    
    return SHFileOperationW(&shFileOpStruct)==0 ? true : false;

#else

    // !!!
    return false;

#endif
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
enum class MessageBoxKind
{
     mbDefault        = 0,
     iconNone         = 0,

     iconExclamation  = 1,  // !
     iconWarning      = 1,  // !

     iconAsterisk     = 2,  // i
     iconInformation  = 2,  // i

     iconQuestion     = 3,  // ?

     iconStop         = 4,  // [X]
     iconError        = 4   // [X]

};

//------------------------------
//! Отображает блокирующее выполнение GUI сообщение (Message Box), параметры - в в UTF-8
inline
void showMessageBox(const std::string &msg, std::string title=std::string(), MessageBoxKind mbKind=MessageBoxKind::mbDefault)
{

    #if defined(WIN32) || defined(_WIN32)

        UINT uType = MB_OK|MB_APPLMODAL;

        switch(mbKind)
        {
            case MessageBoxKind::mbDefault:
            {
                if (title.empty())
                    title = "Message";
                break;
            }

            case MessageBoxKind::iconExclamation: // aka iconWarning
            {
                if (title.empty())
                    title = "Warning";
                uType |= MB_ICONWARNING;
                break;
            }
            case MessageBoxKind::iconAsterisk: // aka iconInformation
            {
                if (title.empty())
                    title = "Information";
                uType |= MB_ICONASTERISK;
                break;
            }
            case MessageBoxKind::iconQuestion:
            {
                if (title.empty())
                    title = "Question";
                uType |= MB_ICONQUESTION;
                break;
            }
            case MessageBoxKind::iconStop: // aka iconError
            {
                if (title.empty())
                    title = "Error";
                uType |= MB_ICONSTOP;
                break;
            }
        
        }

        MessageBoxW( 0 // hwnd
                   , fromUtf8(msg).c_str()
                   , fromUtf8(title).c_str()
                   , uType
                   );

    #else

    // !!!

    #endif

}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32)

namespace win32 {


inline HKEY getRegShellExtentionsRootHkey(bool bSystemRoot = false)
{
    if (!bSystemRoot)
       return HKEY_CURRENT_USER;
    else
       return HKEY_CLASSES_ROOT;
}

inline std::wstring getRegShellExtentionHandlersRootPath(bool bSystemRoot = false)
{
    std::wstring regPath;

    if (!bSystemRoot)
    {
       regPath.append(L"Software");
       regPath.append(L"\\Classes");
    }

    return regPath;
}

inline bool regSetValue(HKEY hKey, const std::wstring &varName, const std::wstring &value)
{
    LSTATUS status = RegSetValueW(hKey, varName.c_str(), REG_SZ, (LPCWSTR)value.c_str(), (DWORD)(value.size()+1)*sizeof(wchar_t));
    return status==ERROR_SUCCESS;
}


inline bool registerShellExtentionHandlerApplication(bool bSystemRoot, const std::wstring &appNameId, const std::wstring &shellVerb, const std::wstring &appCommand)
{

    // Компьютер\HKEY_CLASSES_ROOT\md__auto_file
    //     shell
    //       open
    //         command
    //           default value: "F:\_github\umba-tools\umba-md-pp\.out\msvc2019\x86\Debug\umba-md-pp-view.exe" "%1"
    //
    // HKEY_CLASSES_ROOT\.md_
    //     default value md__auto_file
    //
    // The nameless key is the default one - https://learn.microsoft.com/en-us/dotnet/api/microsoft.win32.registry.setvalue?view=net-8.0&redirectedfrom=MSDN#overloads

    HKEY hRootKey = getRegShellExtentionsRootHkey(bSystemRoot);

    std::wstring regPath = getRegShellExtentionHandlersRootPath(bSystemRoot);

    if (!regPath.empty())
        regPath.append(L"\\");

    regPath.append(appNameId);
    regPath.append(L"\\shell");
    regPath.append(L"\\");
    regPath.append(shellVerb);
    regPath.append(L"\\command");

    //HKEY hKey = regCreateKeyHelper(hRootKey, regPath,  /* KEY_READ| */ KEY_WRITE);
    HKEY hKey = umba::win32_utils::regCreateKey(hRootKey, regPath, KEY_WRITE);

    if (!hKey)
        return false;

    bool res = regSetValue(hKey, L"" /* varName */ , appCommand);

    RegCloseKey(hKey);

    return res;
}

inline bool registerShellExtentionHandlerForExtention(bool bSystemRoot, const std::wstring &appNameId, std::wstring ext)
{

    if (ext.empty())
        return false;

    if (ext.front()!=L'.')
    {
        ext = L"." + ext;
    }

    //HKEY hRootKey = regGetShellExtentionsRoot();
    HKEY hRootKey = getRegShellExtentionsRootHkey(bSystemRoot);

    //std::wstring regPath = regShellExtentionHandlersRootPath();
    std::wstring regPath = getRegShellExtentionHandlersRootPath(bSystemRoot);

    if (!regPath.empty())
        regPath.append(L"\\");

    regPath.append(ext);

    //HKEY hKey = regCreateKeyHelper(hRootKey, regPath,  /* KEY_READ| */ KEY_WRITE);
    HKEY hKey = umba::win32_utils::regCreateKey(hRootKey, regPath, KEY_WRITE);

    if (!hKey)
        return false;

    bool res = regSetValue(hKey, L"" /* varName */ , appNameId);

    RegCloseKey(hKey);

    return res;
}

inline bool registerShellExtentionHandlerForExtentionList(bool bSystemRoot, const std::wstring &appNameId, const std::vector<std::wstring> &extList)
{
    bool res = true;

    for(auto ext: extList)
    {
        if (!registerShellExtentionHandlerForExtention(bSystemRoot, appNameId, ext))
            res = false;
    }

    return res;
}

inline bool registerShellExtentionHandlerForExtentionList(bool bSystemRoot, const std::wstring &appNameId, const std::wstring &extCommaList)
{
    //auto extList = marty_cpp::splitToLinesSimple(extCommaList, false, ',');
    auto extList = umba::string_plus::split(extCommaList, std::wstring(L",", true /* skipEmpty */ ));
    for(auto &ext: extList)
    {
        umba::string_plus::trim(ext);
    }

    return registerShellExtentionHandlerForExtentionList(bSystemRoot, appNameId, extList);
}


} // namespace win32

#endif





} // namespace shellapi
} // namespace umba

