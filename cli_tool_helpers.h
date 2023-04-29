/*! \file
    \brief Хелперы для утилит командной строки (CLI)
*/

//----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

//#include "encoding/encoding.h"
//#include "umba/filesys.h"




//----------------------------------------------------------------------------
// umba::cli_tool_helpers::
namespace umba {
namespace cli_tool_helpers {




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

    std::string N = marty_cpp::toUpper(n);

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
};

//----------------------------------------------------------------------------
inline
bool checkIoFileType(IoFileType ioFt, std::string &msg, bool bInput=false)
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

    return inputFilename;
}

//----------------------------------------------------------------------------
inline
std::string adjustOutputFilename(const std::string &outputFilename, const std::string &inputFilename, IoFileType inputFileType)
{
    if (!outputFilename.empty())
        return outputFilename;

    if (inputFileType==IoFileType::stdinFile)
        return "STDOUT";

    return inputFilename;
}







} // namespace cli_tool_helpers
} // namespace umba


