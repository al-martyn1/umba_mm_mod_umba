#pragma once

#include "filesys_scanners.h"

#if defined(_MSC_VER)
    #pragma message("!!! Direct using 'umba::scanners' now deprecated, use 'umba::filesys::scanners' and 'umba/filesys_scanners.h' header file instead")
#endif


namespace umba {
namespace scanners {

using namespace umba::filesys::scanners;

using umba::filesys::scanners::scanForOptionsFile;
using umba::filesys::scanners::scanForFlagsFile;
using umba::filesys::scanners::fromSimpleMaskToRegexVector;
using umba::filesys::scanners::fromSimpleMaskToRegexMap;
using umba::filesys::scanners::scanFolders;

#if 0
//----------------------------------------------------------------------------
//! Сканирует каталоги начиная с заданного и выше, в поисках конфиг файла flagsFileName
template<typename StringType> inline
StringType scanForOptionsFile( const StringType &flagsFileName, StringType basePath)
{

}




//----------------------------------------------------------------------------
//! Сканирует каталоги начиная с заданного и выше, в поисках конфиг файлов flagsFileNames
template<typename StringType> inline
StringType scanForOptionsFile( const std::vector<StringType> &flagsFileNames, StringType basePath)
{
    return
}





//----------------------------------------------------------------------------
template<typename StringType> inline
StringType scanForFlagsFile( const StringType &flagsFileName, StringType basePath)
{






//----------------------------------------------------------------------------
template<typename StringType> inline
StringType scanForFlagsFile( const std::vector<StringType> &flagsFileNames, StringType basePath)
{




template<typename StringType> inline
std::vector< std::basic_regex<typename StringType::value_type> >
fromSimpleMaskToRegexVector(const std::vector<StringType> &regexStrings, bool useAnchoring = false, bool allowRawRegexes = true)
{





//----------------------------------------------------------------------------
template<typename StringType> inline
std::vector< std::basic_regex<typename StringType::value_type> >
fromSimpleMaskToRegexMap(const std::vector<StringType> &regexStrings, bool useAnchoring = false, bool allowRawRegexes = true)
{





template<typename AppConfigType, typename LogMsgType> inline
void scanFolders( const AppConfigType      &appConfig        // with includeFilesMaskList and excludeFilesMaskList
                , LogMsgType               &logMsg           // logMsg or logNul
                , std::vector<std::string> &foundFiles
                , std::vector<std::string> &excludedFiles
                , std::set<std::string>    &foundExtentions
                , std::vector<std::string> *pFoundFilesRootFolders = 0
                )

#endif







} // namespace scanners
} // namespace umba




