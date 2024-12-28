#pragma once

#include "umba/umba.h"
#include "umba/filename.h"
#include "umba/filesys.h"
//
#include <vector>
#include <string>
//

#if !defined(WIN32) && !defined(_WIN32)
    #error "This file is only for Win32/Win64"
#endif



//----------------------------------------------------------------------------
// umba::win32_utils::
namespace umba {
namespace win32_utils {

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
inline
bool isWindows32OnWindows64()
{

//#if defined(WIN64) || defined(_WIN64)

//    return false; // 64хбитное приложение, нет проблем

//#else

    // https://stackoverflow.com/questions/14184137/how-can-i-determine-whether-a-process-is-32-or-64-bit

    typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

    BOOL bIsWow64 = FALSE;

    auto hKernel = GetModuleHandle(TEXT("kernel32"));
    if (hKernel)
    {
        // disable_C4191.h
        // disable_unsafe_conversion.h
        #include "umba/warnings/push_disable_unsafe_conversion.h"
        LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(hKernel,"IsWow64Process");
        #include "umba/warnings/pop.h"
        if (fnIsWow64Process)
        {
            if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
            {
                //handle error
            }
        }
    }

    return bIsWow64 ? true : false;

//#endif
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
template<typename StringType>
std::vector<StringType> makeUninstallRegPathsVector()
{
    std::vector<StringType> v;
    v.emplace_back(umba::string_plus::make_string<StringType>("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall"));  // SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall
    v.emplace_back(umba::string_plus::make_string<StringType>("SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall")); // SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\Uninstall
    return v;
}

//----------------------------------------------------------------------------
template<typename StringType>
const std::vector<StringType>& getUninstallRegPathsVector()
{
    static auto v = makeUninstallRegPathsVector<StringType>();
    return v;
}

//----------------------------------------------------------------------------
inline
HKEY regCreateKey(HKEY hKeyRoot, const std::wstring &path, REGSAM samDesired)
{
    if (isWindows32OnWindows64()) // 32х-битные системы сейчас конечно уже экзотика, но на всякий случай - я же и на XP могу работать
    {
        samDesired |= KEY_WOW64_64KEY;
    }

    HKEY hKeyRes = 0;
    DWORD dwDisposition = 0;

    LSTATUS status = RegCreateKeyExW( hKeyRoot
                                    , path.c_str()
                                    , 0 // reserved
                                    , 0 // lpClass - The user-defined class type of this key. This parameter may be ignored. This parameter can be NULL.
                                    , REG_OPTION_NON_VOLATILE // default, 0
                                    , samDesired
                                    , 0 // lpSecurityAttributes
                                    , &hKeyRes
                                    , &dwDisposition
                                    );
    if (status!=ERROR_SUCCESS)
    {
        return 0;
    }

    return hKeyRes;

}

//----------------------------------------------------------------------------
inline
HKEY regCreateKey(HKEY hKeyRoot, const std::string &path, REGSAM samDesired)
{
    if (isWindows32OnWindows64()) // 32х-битные системы сейчас конечно уже экзотика, но на всякий случай - я же и на XP могу работать
    {
        samDesired |= KEY_WOW64_64KEY;
    }

    HKEY hKeyRes = 0;
    DWORD dwDisposition = 0;

    LSTATUS status = RegCreateKeyExA( hKeyRoot
                                    , path.c_str()
                                    , 0 // reserved
                                    , 0 // lpClass - The user-defined class type of this key. This parameter may be ignored. This parameter can be NULL.
                                    , REG_OPTION_NON_VOLATILE // default, 0
                                    , samDesired
                                    , 0 // lpSecurityAttributes
                                    , &hKeyRes
                                    , &dwDisposition
                                    );
    if (status!=ERROR_SUCCESS)
    {
        return 0;
    }

    return hKeyRes;

}

//----------------------------------------------------------------------------
inline
LSTATUS regOpenKeyEx( HKEY              hKey
                    , const std::string &subKey
                    , DWORD             ulOptions
                    , REGSAM            samDesired
                    , PHKEY             phkResult
                    )
{
    return RegOpenKeyExA(hKey, subKey.c_str(), ulOptions, samDesired, phkResult);
}

//----------------------------------------------------------------------------
inline
LSTATUS regOpenKeyEx( HKEY               hKey
                    , const std::wstring &subKey
                    , DWORD              ulOptions
                    , REGSAM             samDesired
                    , PHKEY              phkResult
                    )
{
    return RegOpenKeyExW(hKey, subKey.c_str(), ulOptions, samDesired, phkResult);
}

//----------------------------------------------------------------------------
inline
bool regQueryValueEx( HKEY               hKey
                    , const std::wstring valueName
                    , std::wstring       &value
                    , DWORD              *pType=0
                    )
{
    wchar_t buf[1024];
    DWORD type;
    DWORD cbData = sizeof(buf); // in bytes

    wchar_t *pBuf = &buf[0];

    LSTATUS 
    status = RegQueryValueExW( hKey
                             , valueName.c_str()
                             , 0 // reserved
                             , &type
                             , (LPBYTE)pBuf
                             , &cbData
                             );

    std::vector<wchar_t> dynBuf;
    if (status==ERROR_MORE_DATA)
    {
        std::size_t needChars = cbData/sizeof(buf[0]);
        if (cbData%sizeof(buf[0]))
            ++needChars;
        dynBuf.resize(needChars, 0);
        pBuf = dynBuf.data();
    }

    status = RegQueryValueExW( hKey
                             , valueName.c_str()
                             , 0 // reserved
                             , &type
                             , (LPBYTE)pBuf
                             , &cbData
                             );

    if (status==ERROR_SUCCESS && (type==REG_SZ || type==REG_EXPAND_SZ))
    {
        // if (cbData>(sizeof(buf)-1))
        //     cbData = sizeof(buf)-1;
        //  
        // std::size_t numChars = cbData/sizeof(wchar_t);
        // if (numChars>0)
        // {
        //     if (buf[numChars-1]==0)
        //         --numChars;
        //     value.assign(buf, numChars);
        // }
        // else
        // {
        //     value.clear();
        // }

        if (pType)
            *pType = type;

        std::size_t charsCopied = cbData/sizeof(buf[0]);
        if (cbData%sizeof(buf[0]))
            ++charsCopied;

        if (charsCopied>0 && pBuf[charsCopied-1]==0)
            --charsCopied; // strip terminating zero

        value.assign(pBuf, charsCopied);

        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
inline
bool regQueryValueEx( HKEY               hKey
                    , const std::string  valueName
                    , std::string        &value
                    , DWORD              *pType=0
                    )
{
    char  buf[1024];
    DWORD type;
    DWORD cbData = sizeof(buf); // in bytes

    char *pBuf = &buf[0];

    LSTATUS 
    status = RegQueryValueExA( hKey
                             , valueName.c_str()
                             , 0 // reserved
                             , &type
                             , (LPBYTE)pBuf
                             , &cbData
                             );

    std::vector<char> dynBuf;
    if (status==ERROR_MORE_DATA)
    {
        std::size_t needChars = cbData/sizeof(buf[0]);
        // if (cbData%sizeof(buf[0]))
        //     ++needChars;
        dynBuf.resize(needChars, 0);
        pBuf = dynBuf.data();
    }

    status = RegQueryValueExA( hKey
                             , valueName.c_str()
                             , 0 // reserved
                             , &type
                             , (LPBYTE)pBuf
                             , &cbData
                             );

    if (status==ERROR_SUCCESS && (type==REG_SZ || type==REG_EXPAND_SZ))
    {
        // if (cbData>(sizeof(buf)-1))
        //     cbData = sizeof(buf)-1;
        //  
        // std::size_t numChars = cbData; ///sizeof(wchar_t);
        // if (numChars>0)
        // {
        //     if (buf[numChars-1]==0)
        //         --numChars;
        //     value.assign(buf, numChars);
        // }
        // else
        // {
        //     value.clear();
        // }

        if (pType)
            *pType = type;

        std::size_t charsCopied = cbData/sizeof(buf[0]);
        if (cbData%sizeof(buf[0]))
            ++charsCopied;

        if (charsCopied>0 && pBuf[charsCopied-1]==0)
            --charsCopied; // strip terminating zero

        value.assign(pBuf, charsCopied);

        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
template<typename StringType>
bool regQueryAppInstallLocation(const StringType &appUninstallSectionName, StringType &foundPath)
{
    REGSAM samDesired = KEY_READ;
    if (isWindows32OnWindows64()) // 32х-битные системы сейчас конечно уже экзотика, но на всякий случай - я же и на XP могу работать
    {
        samDesired |= KEY_WOW64_64KEY;
    }

    const auto& regPaths = getUninstallRegPathsVector<StringType>();

    for(const auto &rp: regPaths)
    {
        HKEY hk = 0;
        LSTATUS
        status = regOpenKeyEx( HKEY_LOCAL_MACHINE
                             , rp + umba::string_plus::make_string<StringType>("\\") + appUninstallSectionName
                             , 0 // ulOptions
                             , samDesired
                             , &hk
                             );
        if (status==ERROR_SUCCESS)
        {
            if (regQueryValueEx(hk, umba::string_plus::make_string<StringType>("InstallLocation"), foundPath))
            {
                RegCloseKey(hk);
                umba::string_plus::unquote( foundPath, '\"', '\"');
                return true;
            }

            if (regQueryValueEx(hk, umba::string_plus::make_string<StringType>("UninstallString"), foundPath))
            {
                RegCloseKey(hk);

                umba::string_plus::unquote( foundPath, '\"', '\"');
                foundPath = umba::filename::getPath(foundPath);
                return true;
            }

            RegCloseKey(hk);
        }
    }

    return false;
}

//----------------------------------------------------------------------------
template<typename StringType>
bool regQueryAppInstallLocationBin(const StringType &appUninstallSectionName, StringType &foundPath)
{
    if (regQueryAppInstallLocation(appUninstallSectionName, foundPath))
    {
        if (umba::filesys::isPathDirectory(umba::filename::appendPath(foundPath, string_plus::make_string<StringType>("bin"))))
        {
            foundPath = umba::filename::appendPath(foundPath, string_plus::make_string<StringType>("bin"));
        }

        return true;
    }

    return false;
}


} // namespace win32_utils
} // namespace umba



