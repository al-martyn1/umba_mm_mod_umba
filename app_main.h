#pragma once

/* 1) Проверить русские имена файлов

*/

#include "umba.h"
//
#include "filesys.h"

#if defined(UMBA_FILESYS_USE_UTF8)
    #include "utf8.h"
#endif

#if !defined(UMBA_DISABLE_AUTO_ENCODING)
    #include "encoding/encoding.h"
#endif

#include "string_plus.h"

//
#include <string>
#include <vector>


#if defined(WIN32) || defined(_WIN32)
    #include <shellapi.h>
#endif

//alloca.h

// Если у нас юникод и винда и мы работаем с UTF8, то надо перекодировать wchar_t argv в char argv или LPWSTR lpCmdLine -> LPSTR lpCmdLine
// Если мы не работаем с UTF8, то у нас либо wmain/wWinMain, либо main/WinMain

// umba::app_main::
namespace umba {
namespace app_main {

#if defined(WIN32) || defined(_WIN32)

inline std::string reencodeArgv(const char* argv)
{
    if (!argv)
        return std::string();

    #if defined(UMBA_DISABLE_AUTO_ENCODING) || !defined(UMBA_FILESYS_USE_UTF8)

        return std::string(); // As is

    #else

        std::wstring wArgv = encoding::fromSystemMultibyte(argv); // Ansi -> Unicode
        return toUtf8(wArgv);                                     // Unicode -> UTF8

    #endif
}

inline std::string reencodeArgv(const wchar_t* wArgv)
{
    if (!wArgv)
        return std::string();

    #if defined(UMBA_DISABLE_AUTO_ENCODING) || !defined(UMBA_FILESYS_USE_UTF8)

        return string_plus::make_string<std::string>(wArgv); // Breaking convertion, not good for non-english

    #else

        return toUtf8(wArgv);

    #endif
}

inline std::vector<std::string> makeArgsVecForConsoleApp(int argc, char *argv[])
{
    std::vector<std::string> resVec; resVec.reserve((std::size_t)argc);

    for(int i=0; i<argc; ++i)
    {
       resVec.emplace_back(reencodeArgv(argv[i]));
    }

    return resVec;
}

inline std::vector<std::string> makeArgsVecForConsoleApp(int argc, wchar_t *argv[])
{
    std::vector<std::string> resVec; resVec.reserve((std::size_t)argc);

    for(int i=0; i<argc; ++i)
    {
       resVec.emplace_back(reencodeArgv(argv[i]));
    }

    return resVec;
}


inline std::vector<std::string> makeArgsVecForWindowedApp()
{
    int nArgs = 0;
    wchar_t ** wargv = CommandLineToArgvW( GetCommandLineW(), &nArgs );
    if (!wargv)
    {
        return std::vector<std::string>();
    }

    std::vector<std::string> resVec; resVec.reserve((std::size_t)nArgs);
    for(int i=0; i<nArgs; ++i)
    {
        resVec.emplace_back(reencodeArgv(wargv[i]));
    }

    return resVec;
}

inline std::vector<char*> makeCharPtrArgsVec(const std::vector<std::string> &strArgs)
{
    std::vector<char*> charPtrArgv; charPtrArgv.reserve(strArgs.size());
    for(const auto &a: strArgs)
    {
        charPtrArgv.emplace_back((char*)a.c_str());
    }

    return charPtrArgv;
}


#endif

} // namespace app_main
} // namespace umba






#if defined(WIN32) || defined(_WIN32)

    #if defined(CONSOLE) || defined(_CONSOLE)

        // Консольное приложение, работаем с UTF8

        #if defined(UNICODE) || defined(_UNICODE)

            // Юникодное консольное приложение
            #define UMBA_APP_MAIN()    int umbaMainImpl(int argc, char* argv[]); /* UTF8 entry */                        \
                                       int wmain(int argc, wchar_t* argv[])                                              \
                                       {                                                                                 \
                                           std::vector<std::string> encodedArgs =                                        \
                                                                    umba::app_main::makeArgsVecForConsoleApp(argc, argv);\
                                           std::vector<char*>       encodedArgv =                                        \
                                                                    umba::app_main::makeCharPtrArgsVec(encodedArgs);     \
                                           return umbaMainImpl(argc, &encodedArgv[0]);                                   \
                                       }                                                                                 \
                                       int umbaMainImpl(int argc, char* argv[])

        #else

            // Анси консольное приложение
            #define UMBA_APP_MAIN()    int umbaMainImpl(int argc, char* argv[]); /* UTF8 entry */                        \
                                       int main(int argc, char* argv[])                                                  \
                                       {                                                                                 \
                                           std::vector<std::string> encodedArgs =                                        \
                                                                    umba::app_main::makeArgsVecForConsoleApp(argc, argv);\
                                           std::vector<char*>       encodedArgv =                                        \
                                                                    umba::app_main::makeCharPtrArgsVec(encodedArgs);     \
                                           return umbaMainImpl(argc, &encodedArgv[0]);                                   \
                                       }                                                                                 \
                                       int umbaMainImpl(int argc, char* argv[])


        #endif // UNICODE

    #else // !CONSOLE

        // GUI приложение, работаем с UTF8

        #if defined(UNICODE) || defined(_UNICODE)

            #define UMBA_APP_MAIN()    int umbaMainImpl(int argc, char* argv[]); /* UTF8 entry */                        \
                                       HINSTANCE hInstance     = 0;                                                      \
                                       HINSTANCE hPrevInstance = 0;                                                      \
                                       int       nCmdShow      = 0;                                                      \
                                       int APIENTRY wWinMain(HINSTANCE hInstance_, HINSTANCE hPrevInstance_, LPWSTR lpCmdLine, int nCmdShow_)\
                                       {                                                                                 \
                                           hInstance     = hInstance_;                                                   \
                                           hPrevInstance = hPrevInstance_;                                               \
                                           nCmdShow      = nCmdShow_;                                                    \
                                                                                                                         \
                                           std::vector<std::string> encodedArgs =                                        \
                                                                    umba::app_main::makeArgsVecForWindowedApp();         \
                                           std::vector<char*>       encodedArgv =                                        \
                                                                    umba::app_main::makeCharPtrArgsVec(encodedArgs);     \
                                           return umbaMainImpl((int)encodedArgv.size(), &encodedArgv[0]);                \
                                       }                                                                                 \
                                       int umbaMainImpl(int argc, char* argv[])
                                       
        #else

            #define UMBA_APP_MAIN()    int umbaMainImpl(int argc, char* argv[]); /* UTF8 entry */                        \
                                       HINSTANCE hInstance     = 0;                                                      \
                                       HINSTANCE hPrevInstance = 0;                                                      \
                                       int       nCmdShow      = 0;                                                      \
                                       int APIENTRY WinMain(HINSTANCE hInstance_, HINSTANCE hPrevInstance_, LPSTR lpCmdLine, int nCmdShow_)\
                                       {                                                                                 \
                                           hInstance     = hInstance_;                                                   \
                                           hPrevInstance = hPrevInstance_;                                               \
                                           nCmdShow      = nCmdShow_;                                                    \
                                                                                                                         \
                                           std::vector<std::string> encodedArgs =                                        \
                                                                    umba::app_main::makeArgsVecForWindowedApp();         \
                                           std::vector<char*>       encodedArgv =                                        \
                                                                    umba::app_main::makeCharPtrArgsVec(encodedArgs);     \
                                           return umbaMainImpl((int)encodedArgv.size(), &encodedArgv[0]);                \
                                       }                                                                                 \
                                       int umbaMainImpl(int argc, char* argv[])


        #endif // UNICODE

    #endif // CONSOLE

#else // !WIN32

    // Под другими системами всегда один и тот же main
    #define UMBA_APP_MAIN()    int umbaMainImpl(int argc, char* argv[]); /* UTF8 entry */                        \
                               int main(int argc, char* argv[])                                                  \
                               {                                                                                 \
                                   std::vector<std::string> encodedArgs =                                        \
                                                            umba::app_main::makeArgsVecForConsoleApp(argc, argv);\
                                   std::vector<char*>       encodedArgv =                                        \
                                                            makeCharPtrArgsVec(encodedArgs);                     \
                                   return umbaMainImpl(argc, &encodedArgv[0]);                                   \
                               }                                                                                 \
                               int umbaMainImpl(int argc, char* argv[])

#endif

