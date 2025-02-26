/*! \file
    \brief Хелперы для утилит командной строки (CLI)
*/
#pragma once

//----------------------------------------------------------------------------

#include "filename.h"
#include "filesys.h"
#include "debug_helpers.h"
//
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
//

#if defined(WIN32) || defined(_WIN32)

    #if !defined(NO_CLIPBOARD_SUPPORT)
        #define HAS_CLIPBOARD_SUPPORT 1
        #include "clipboard_win32.h"
    #endif

#endif


#if defined(UMBA_PRINT_NAME_VERSION_NO_PLATFORM_ARCHITECTURE) || defined(UMBA_PRINT_NAME_VERSION_NO_COMPILER_INFO) || defined(UMBA_PRINT_NAME_VERSION_NO_BUILD_DATE_TIME)
#else
    #include "compiler_info.h"
#endif



//----------------------------------------------------------------------------

// requires vars deckared/defined before
//   appVersion defined before
//   appFullName defined before
//   appCommitHash std::string compatible defined before
//   appBuildDate and appBuildTime

extern std::string appFullName  ;
extern std::string appVersion   ;
extern std::string appCommitHash;  //UNDONE
extern std::string appBuildDate ;
extern std::string appBuildTime ;




//----------------------------------------------------------------------------
// umba::cli_tool_helpers::
namespace umba {
namespace cli_tool_helpers {




//----------------------------------------------------------------------------
template<typename StringType> inline
bool findProjectOptionsFile(const StringType &prjFile, StringType &foundOptionsFile, const std::vector<StringType> &names)
{
    StringType optPath = umba::filename::getPath(prjFile);

    while(true)
    {
        for(const auto &name : names)
        {
            StringType optFile = umba::filename::appendPath(optPath, name);
            if (umba::filesys::isFileReadable(optFile))
            {
                foundOptionsFile = optFile;
                return true;
            }
        }

        umba::filename::stripLastPathSep(optPath);
        StringType optPathNext = umba::filename::getPath(optPath);
        if (optPathNext.empty() || optPathNext==optPath)
        {
            return false;
        }

        optPath = optPathNext;
    }

    return false;
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// https://stackoverflow.com/questions/11697820/how-to-use-date-and-time-predefined-macros-in-as-two-integers-then-stri

template<typename StreamType> inline
StreamType& printOnlyVersion(StreamType &os)
{
    os << appVersion << "\n";
    return os;
}

template<typename StreamType> inline
StreamType& printCommitHash( StreamType &os, const std::string &indent = "" )
{
    if (appCommitHash.empty())
        return os;

    os << indent << "#" << appCommitHash << "\n";

    return os;
}

template<typename StreamType> inline
StreamType& printBuildDateTime( StreamType &os, const std::string &indent = "" )
{
    os << indent << "Built at " << appBuildDate << " "<< appBuildTime << "\n";
    return os;
}

template<typename StreamType> inline
StreamType& printNameVersion( StreamType &os, const std::string &indent = "" )
{
    os << indent << appFullName << " version ";
    printOnlyVersion(os);

    #if !defined(UMBA_PRINT_NAME_VERSION_NO_PLATFORM_ARCHITECTURE)
    os << umba::getAppPlatformArchitecture() <<"\n";
    #endif

    #if !defined(UMBA_PRINT_NAME_VERSION_NO_COMPILER_INFO)
    std::string compilerFullInfoString = umba::getCompilerNameVersionString();
    {
        std::string compilerSimulateFullInfoString = umba::getCompilerSimulateNameVersionString();
        if (!compilerSimulateFullInfoString.empty())
        {
            compilerFullInfoString += " (as ";
            compilerFullInfoString += compilerSimulateFullInfoString;
            compilerFullInfoString += ")";
        }
    }

    os << "Built with " << compilerFullInfoString <<" compiler\n";
    #endif

    #if !defined(UMBA_PRINT_NAME_VERSION_NO_BUILD_DATE_TIME)
    // os << "Built at "<< appBuildDate <<" "<< appBuildTime <<"\n";
    printBuildDateTime(os);
    #endif

    #if !defined(UMBA_PRINT_NAME_VERSION_COMMIT_HASH)
    printCommitHash(os);
    #endif

    return os;
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
enum class IoFileType
{
    nameEmpty,
    regularFile,
    stdinFile,
    stdoutFile,
    clipboard
};

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
inline
IoFileType detectFilenameType(const std::string &n, bool bInput=false)
{
    if (n.empty())
        return IoFileType::nameEmpty;

    std::string N = umba::string_plus::toupper_copy(n);

    if (N=="-")
    {
        return bInput ? IoFileType::stdinFile : IoFileType::stdoutFile;
    }

    if (N=="STDIN")
        return IoFileType::stdinFile;

    if (N=="STDOUT")
        return IoFileType::stdoutFile;

#if defined(HAS_CLIPBOARD_SUPPORT)
    if (N=="CLPB"|| N=="CLIPBRD" /* || N=="{CLIPBRD}" || N=="{CLIPBOARD}" */ )
        return IoFileType::clipboard;
#endif

    return IoFileType::regularFile;
}

//----------------------------------------------------------------------------
inline
bool checkIoFileType(IoFileType ioFt, std::string &msg, bool bInput /* =false */, bool enableClipboard=true  )
{
    if (ioFt==IoFileType::nameEmpty)
    {
        msg = bInput ? "no input file name taken" : "no output file name taken";
        return false;
    }

    if (bInput)
    {
        if (ioFt==IoFileType::stdoutFile)
        {
            msg = "can't use STDOUT for input";
            return false;
        }
    }
    else // output file
    {
        if (ioFt==IoFileType::stdinFile)
        {
            msg = "can't use STDIN for output";
            return false;
        }
    }

    if (ioFt==IoFileType::clipboard && !enableClipboard)
    {
        msg = bInput ? "input from clipboard not supported" : "output to clipboard not supported";
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
inline
std::string adjustInputFilename(const std::string &inputFilename)
{
    if (inputFilename.empty())
    {
        return "STDIN";
    }

    //return inputFilename;
    return umba::filename::makeCanonical(umba::filename::makeAbsPath(inputFilename));
}

//----------------------------------------------------------------------------
inline
std::string adjustOutputFilename(const std::string &outputFilename, const std::string &inputFilename, IoFileType inputFileType)
{
    if (outputFilename=="STDOUT")
    {
        return outputFilename;
    }

    if (!outputFilename.empty())
    {
        //return outputFilename;
        return umba::filename::makeCanonical(umba::filename::makeAbsPath(outputFilename));
    }

    if (inputFileType==IoFileType::stdinFile)
        return "STDOUT";

    //return inputFilename;
    return umba::filename::makeCanonical(umba::filename::makeAbsPath(inputFilename));
}

//----------------------------------------------------------------------------
inline
void adjustInputOutputFilenames( std::string &inputFilename , umba::cli_tool_helpers::IoFileType &inputFileType
                               , std::string &outputFilename, umba::cli_tool_helpers::IoFileType &outputFileType
                               )
{
    std::string checkMsg;
    inputFilename = adjustInputFilename(inputFilename);
    inputFileType = detectFilenameType(inputFilename, true /* input file */);
    if (!checkIoFileType(inputFileType, checkMsg, true /* input file */))
    {
        #ifdef UMBA_DEBUGBREAK
            UMBA_DEBUGBREAK();
        #endif
        throw std::runtime_error(checkMsg);
    }

    outputFilename = adjustOutputFilename(outputFilename, inputFilename, inputFileType);
    outputFileType = detectFilenameType(outputFilename, false /* not input file */);
    if (!checkIoFileType(outputFileType, checkMsg, false /* not input file */))
    {
        #ifdef UMBA_DEBUGBREAK
            UMBA_DEBUGBREAK();
        #endif
        throw std::runtime_error(checkMsg);
    }
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
inline
bool isFileReadable( const std::string &fileName )
{
    return umba::filesys::isFileReadable(fileName);
}

//----------------------------------------------------------------------------
inline
bool readStream(std::istream &fileIn, std::string &data)
{
    std::vector<char> buf;

    if (!umba::filesys::readFile(fileIn, buf))
        return false;

    data.clear();
    if (buf.empty())
        return true;

    data = std::string(&buf[0], buf.size());

    return true;
}

//----------------------------------------------------------------------------
inline
bool writeStream(std::ostream &fileOut, const std::string &data)
{
    auto dataSize = data.size();
    if (!dataSize)
        return true;

    return umba::filesys::writeFile(fileOut, data.data(), dataSize);
}

//----------------------------------------------------------------------------
inline
bool readFile( const std::string &fileName, std::string &data )
{
    std::vector<char> buf;

    if (!umba::filesys::readFile(umba::filename::makeCanonical(fileName), buf))
        return false;

    data.clear();
    if (buf.empty())
        return true;

    data = std::string(&buf[0], buf.size());

    return true;
}

//----------------------------------------------------------------------------
inline
bool writeFile( const std::string &fileName, const std::string &data, bool bOverwrite )
{
    return umba::filesys::writeFile(umba::filename::makeCanonical(fileName), data.data(), data.size(), bOverwrite);
}

//----------------------------------------------------------------------------
inline
bool readFile(umba::cli_tool_helpers::IoFileType ioFt, const std::string &fileName, std::string &data)
{
    if (ioFt==IoFileType::stdinFile)
        return readStream(std::cin, data);

    return readFile(umba::filename::makeCanonical(fileName), data);
}

//----------------------------------------------------------------------------
inline
bool writeFile(umba::cli_tool_helpers::IoFileType ioFt, const std::string &fileName, const std::string &data, bool bOverwrite)
{
    if (ioFt==IoFileType::stdoutFile)
        return writeStream(std::cout, data);

    return writeFile(umba::filename::makeCanonical(fileName), data, bOverwrite);
}

//----------------------------------------------------------------------------






//----------------------------------------------------------------------------
template<typename ToUtfConverter> inline
std::string readInput( const std::string &inputFilename , umba::cli_tool_helpers::IoFileType inputFileType
                     , const ToUtfConverter &toUtfConverter
                     , bool &checkBom, bool &fromFile, bool &utfSource
                     //, ELinefeedType &outputLinefeed
                     )
{
    std::string text;

#if defined(HAS_CLIPBOARD_SUPPORT)
    if (inputFileType==umba::cli_tool_helpers::IoFileType::clipboard)
    {
        checkBom = false;
        fromFile = false;
        #if defined(WIN32) || defined(_WIN32)
        if (!umba::win32::clipboardTextGet(text, toUtfConverter, &utfSource, umba::win32::clipboardGetConsoleHwnd()))
        #else
        if (!clipboardTextGet(text, toUtfConverter, &utfSource))
        #endif
        {
            //LOG_ERR_OPT << "failed to get clipboard text\n";
            //return 1;
            #ifdef UMBA_DEBUGBREAK
                UMBA_DEBUGBREAK();
            #endif
            throw std::runtime_error("failed to get text from the clipboard");
        }
        #if defined(WIN32) || defined(_WIN32)
        //outputLinefeed = ELinefeedType::crlf;
        #endif
    }
    else
#endif
    if (!readFile(inputFileType, inputFilename, text))
    {
        #ifdef UMBA_DEBUGBREAK
            UMBA_DEBUGBREAK();
        #endif
        throw std::runtime_error(std::string("failed to read input file '") + inputFilename + std::string("'"));
        //LOG_ERR_OPT << "failed to read input file '" << inputFilename << "'\n";
        //return 1;
    }

    return text;
}

//----------------------------------------------------------------------------
#if 0
template<typename BomStripper>
std::string stripTheBom(std::string &text, bool checkForBom, const BomStripper &bomStripper)
{
    if (!checkForBom)
    {
        return std::string();
    }

    std::string bomData = bomStripper(text); // app_utils::stripBom(srcData);
    if (!bomData.empty() && bomData.size()!=3)
    {
        // https://ru.wikipedia.org/wiki/%D0%9C%D0%B0%D1%80%D0%BA%D0%B5%D1%80_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8_%D0%B1%D0%B0%D0%B9%D1%82%D0%BE%D0%B2
        //LOG_ERR_OPT << "unsupported input file encoding, found BOM but not UTF-8\n";
        throw std::runtime_error("unsupported input file encoding, found BOM but not UTF-8");
        //return 1;
    }

    return bomData;
}
#endif
//----------------------------------------------------------------------------
// template<typename FromUtfConverter> inline
// bool clipboardTextSet(const std::string &text, const FromUtfConverter &fromUtfConverter, bool utf, HWND hWndNewOwner=0)



template<typename ToUtfConverter, typename FromUtfConverter> inline
void writeOutput( const std::string &outputFilename, umba::cli_tool_helpers::IoFileType outputFileType
                , const ToUtfConverter   &toUtfConverter
                , const FromUtfConverter &fromUtfConverter
                , std::string text, const std::string &bom
                , bool fromFile, bool utfSource, bool bOverwrite
                )
{
#if defined(HAS_CLIPBOARD_SUPPORT)
    if (outputFileType==umba::cli_tool_helpers::IoFileType::clipboard)
    {
        if (fromFile)
        {
            // Вход был прочитан из файла, хз какая кодировка
            // Но кодировка не поменялась в процессе сортировки, просто строки местами поменялись
            // Детектим кодировку и конвертим в UTF-8, присунув исходный BOM, если был
            text = toUtfConverter(bom+text); // BOM нужен для детекта, и он отрезается
            //resultText = encoding::toUtf8(bomData+resultText);
            utfSource  = true;
        }

        #if defined(WIN32) || defined(_WIN32)
        if (!umba::win32::clipboardTextSet(text, fromUtfConverter, utfSource, umba::win32::clipboardGetConsoleHwnd()))
        #else
        if (!clipboardTextSet(text, fromUtfConverter, utfSource))
        #endif
        {
            #ifdef UMBA_DEBUGBREAK
                UMBA_DEBUGBREAK();
            #endif
            throw std::runtime_error("failed to set clipboard text");
            // LOG_ERR_OPT << "failed to set clipboard text\n";
            // return 1;
        }
    }
    else
#endif
    if (!umba::cli_tool_helpers::writeFile(outputFileType, outputFilename, bom+text, bOverwrite))
    {
        #ifdef UMBA_DEBUGBREAK
            UMBA_DEBUGBREAK();
        #endif
        throw std::runtime_error(std::string("failed to write output file '") + outputFilename + std::string("'"));
        //LOG_ERR_OPT << "failed to write output file '" << outputFilename << "'\n";
        //return 1;
    }
}




//----------------------------------------------------------------------------






} // namespace cli_tool_helpers
} // namespace umba


