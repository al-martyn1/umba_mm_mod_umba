#pragma once

// requires vars deckared/defined before
//   appVersion defined before
//   appFullName defined before
//   appCommitHash std::string compatible defined before
//   appBuildDate and appBuildTime


// umba::app_helpers::
namespace umba {
namespace app_helpers {


// https://stackoverflow.com/questions/11697820/how-to-use-date-and-time-predefined-macros-in-as-two-integers-then-stri

template<typename StreamType> inline
StreamType& printOnlyVersion(StreamType &os)
{
    os << appVersion << "\n";
    return os;
}

template<typename StreamType> inline
StreamType& printNameVersion( StreamType &os, const std::string &indent = "" )
{
    os << indent << appFullName << " version ";
    printOnlyVersion(os);
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





} // namespace app_helpers
} // namespace umba

