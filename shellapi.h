#pragma once

#include "umba.h"
#include "filesys.h"
#include "utf8.h"
#include "umba/string_plus.h"

#if defined(WIN32) || defined(_WIN32)
    #include <shellapi.h>
    #if defined(_MSC_VER)
        #pragma comment( lib, "Shell32" )
        // https://ru.stackoverflow.com/questions/15077/%D0%98%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-pragma-comment
    #endif
    #include "win32_utils.h"
    #include "winconhelpers.h"
#endif

#include <process.h>
#include <cerrno>


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
//! Открывает заданный URL в браузере по умолчанию
inline
bool openUrl(const std::string &url)
{
#if defined(WIN32) || defined(_WIN32)

    // https://learn.microsoft.com/ru-ru/windows/win32/shell/launch
    // https://learn.microsoft.com/en-us/windows/win32/shell/launch
    // https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shellexecutea
    auto res = (INT_PTR)ShellExecuteW( 0, L"open", fromUtf8(url).c_str(), 0, 0, SW_SHOW );
    return res>32; // If the function succeeds, it returns a value greater than 32

#else

    return false;

#endif
}

//----------------------------------------------------------------------------
//! Производит экраинрование одиночного аргумента для вызова в командной строке.
inline
std::string escapeCommandLineArgument(const std::string &str)
{

#if defined(WIN32) || defined(_WIN32)

    // http://learn.microsoft.com/en-us/cpp/c-language/parsing-c-command-line-arguments?view=msvc-170

    bool needEscape = false;
    if (str.find_first_of(" \"")!=str.npos)
       needEscape = true;

    if (!needEscape)
        return str;

    //using CharType = typename StringType::value_type;

    std::string res; res.reserve(str.size());
    res.append(1, '\"');
    for(auto ch : str)
    {
        if (ch=='\"')
            res.append(2, '\"');
        else
            res.append(1, ch);
    }
    res.append(1, '\"');

    return res;

#else

    return str; // Для *nix - пока ничего не делаем, надо разбираться

#endif

}

//----------------------------------------------------------------------------
//! Делает единственную строук из имени команды и аргументов, экранирует, и прочее
inline
std::string makeSystemFunctionCommandString(const std::string &cmd, std::vector<std::string> cmdArgs)
{
    cmdArgs.insert(cmdArgs.begin(), cmd);
    for(auto &cmdArg : cmdArgs)
    {
        cmdArg = escapeCommandLineArgument(cmdArg);
    }

    //using CharType = typename StringType::value_type;

    return umba::string_plus::merge<std::string, typename std::vector<std::string>::const_iterator>( cmdArgs.begin(), cmdArgs.end(), ' '/*, [](auto s) { return s; }*/ );
}

//----------------------------------------------------------------------------
//! Производит вызов функции "system". Командная строка должна быть соответственно подготовлена (экранирование и тп)
inline
int callSystem(const std::string &cmd, std::string *pErrMsg=0, bool allocateConsole=true)
{
    // system returns the value that is returned by the command interpreter.
    // It returns the value 0 only if the command interpreter returns the value 0.
    // A return value of -1 indicates an error, and errno is set

    // https://lastpixel.tv/win32-application-as-both-gui-and-console/
    // https://stackoverflow.com/questions/48444176/win32-gui-application-compiled-as-gui-need-to-use-a-console-in-c
    // https://learn.microsoft.com/ru-ru/windows/console/attachconsole
    // BOOL WINAPI AttachConsole( _In_ DWORD dwProcessId);

    // Нет разницы, использовать ли AttachConsole, и при ошибке - AllocConsole, или сразу использовать AllocConsole.
    // Если используем AllocConsole, то она не откроет новое консольное окно, если мы уже прикреплены к консоли.
    // AllocConsole нужно использовать, потому, что если мы используем функцию system без этого, то она на каждый запуск
    // создаёт консоль, и потом закрывает. Это плохо, и антивири могут ругаться, когда из одного приложения много таких
    // окон выскакивает.
    // Это годно для GUI программ, которые не долго работают, но часто вызывают 'system'.
    // Для GUI программ, которые делают это редко, а работают долго - ситуация наоборот - не надо постоянно держать открытую консоль
    // Так что, пожалуй, сделаем это опцией

#if defined(WIN32) && defined(_WIN32)

    if (allocateConsole)
        AllocConsole();

    int resVal = _wsystem(fromUtf8(cmd).c_str());

#else

    int resVal = system(cmd.c_str());

#endif

    if (resVal!=0)
    {
        if (pErrMsg)
        {
            if (resVal==-1)
               *pErrMsg = std::string("Launch command failed: ") + std::strerror(errno);
            else
               *pErrMsg = "Command result code: " + std::to_string(resVal);
        }
    }

    return resVal;
}

//----------------------------------------------------------------------------
inline
int callSystem(const std::string &cmd, const std::vector<std::string> &cmdArgs, std::string *pErrMsg=0, bool allocateConsole=true)
{
    return callSystem(makeSystemFunctionCommandString(cmd, cmdArgs), pErrMsg, allocateConsole);
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
enum class ProcessParentKind
{
    unknown      = -1,
    msDevenv     = 1, // MS Visual Studio
    vsCode       = 2, // VSCode
    bash         = 3, // bash/git-bash
    cmd          = 4, // cmd/git-cmd
    conEmu       = 5,
    farManager   = 6,
    explorer     = 7,

    conHost      = 127
};

//------------------------------
inline ProcessParentKind getProcessParentKind()
{
#if !(defined(WIN32) || defined(_WIN32))

    return ProcessParentKind::unknown;

#else

    if (winhelpers::isProcessHasParentOneOf({"devenv"}))
        return ProcessParentKind::msDevenv;
    else if (winhelpers::isProcessHasParentOneOf({"code"}))
        return ProcessParentKind::vsCode;
    else if (winhelpers::isProcessHasParentOneOf({"bash","git-bash"}))
        return ProcessParentKind::bash;
    else if (winhelpers::isProcessHasParentOneOf({"cmd","git-cmd"}))
        return ProcessParentKind::cmd;
    else if (winhelpers::isProcessHasParentOneOf({"ConEmuC64","ConEmu64","ConEmuC","ConEmu"}))
        return ProcessParentKind::conEmu;
    else if (winhelpers::isProcessHasParentOneOf({"far"}))
        return ProcessParentKind::farManager;
    else if (winhelpers::isProcessHasParentOneOf({"explorer"}))
        return ProcessParentKind::explorer;
    else if (winhelpers::isProcessHasParentOneOf({"conhost"}))
        return ProcessParentKind::conHost;

    return ProcessParentKind::unknown;

#endif

}

//----------------------------------------------------------------------------
inline std::string getDebugAppRootFolder( std::string *pCwd )
{
    std::string cwd = umba::filesys::getCurrentDirectory();

    std::string rootPath;
    umba::shellapi::ProcessParentKind processParentKind = umba::shellapi::getProcessParentKind();

    if (processParentKind==umba::shellapi::ProcessParentKind::msDevenv)
    {
        // По умолчанию студия задаёт текущим каталогом на уровень выше от того, где лежит бинарник
        // Задаём c учетом принятого формата выходного каталога ".out/toolchain/platform/config"
        rootPath = umba::filename::makeCanonical(umba::filename::appendPath(cwd, std::string("..\\..\\..\\")));
    }
    else if (processParentKind==umba::shellapi::ProcessParentKind::vsCode)
    {
        // По умолчанию VSCode задаёт текущим каталогом тот, где лежит бинарник
        // Задаём c учетом принятого формата выходного каталога ".out/toolchain/platform/config"
        rootPath = umba::filename::makeCanonical(umba::filename::appendPath(cwd, std::string("..\\..\\..\\..\\")));
    }

    if (!rootPath.empty())
    {
        rootPath = umba::filename::appendPathSepCopy(rootPath);
    }

    if (pCwd)
    {
        *pCwd = cwd;
    }

    return rootPath;

}


//----------------------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32)

namespace win32 {

// https://superuser.com/questions/266268/where-in-the-registry-does-windows-store-with-which-program-to-open-certain-file
// https://learn.microsoft.com/en-us/windows/win32/shell/how-to-register-a-file-type-for-a-new-application
// https://stackoverflow.com/questions/1387769/create-registry-entry-to-associate-file-extension-with-application-in-c

//----------------------------------------------------------------------------
inline HKEY getRegShellExtentionsRootHkey(bool bSystemRoot = false)
{
    if (!bSystemRoot)
       return HKEY_CURRENT_USER;
    else
       return HKEY_CLASSES_ROOT;
}

//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
inline bool regSetValue(HKEY hKey, const std::wstring &varName, const std::wstring &value)
{
    LSTATUS status = RegSetValueW(hKey, varName.c_str(), REG_SZ, (LPCWSTR)value.c_str(), (DWORD)(value.size()+1)*sizeof(wchar_t));
    return status==ERROR_SUCCESS;
}

//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
inline bool registerShellExtentionHandlerApplication(bool bSystemRoot, const std::string &appNameId, const std::string &shellVerb, const std::string &appCommand)
{
    return registerShellExtentionHandlerApplication(bSystemRoot, fromUtf8(appNameId), fromUtf8(shellVerb), fromUtf8(appCommand));

}

//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
inline bool registerShellExtentionHandlerForExtention(bool bSystemRoot, const std::string &appNameId, const std::string &ext)
{
    return registerShellExtentionHandlerForExtention(bSystemRoot, fromUtf8(appNameId), fromUtf8(ext));
}

//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
inline bool registerShellExtentionHandlerForExtentionList(bool bSystemRoot, const std::string &appNameId, const std::vector<std::string> &extList)
{
    std::vector<std::wstring> extListW;
    for(const auto &ext: extList)
    {
        extListW.emplace_back(fromUtf8(ext));
    }

    return registerShellExtentionHandlerForExtentionList(bSystemRoot, fromUtf8(appNameId), extListW);
}

//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
inline bool registerShellExtentionHandlerForExtentionList(bool bSystemRoot, const std::string &appNameId, const std::string &extCommaList)
{
    return registerShellExtentionHandlerForExtentionList(bSystemRoot, fromUtf8(appNameId), fromUtf8(extCommaList));
}

} // namespace win32

#endif





} // namespace shellapi
} // namespace umba

