/*! 
    \file
    \brief Помощяки для плюсовых регулярок. В тч (простая_маска_*_?) -> ECMA Regex
 */

#pragma once

#include "string_plus.h"

#include <exception>
#include <map>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

//----------------------------------------------------------------------------



// umba::regex_helpers::
namespace umba{
namespace regex_helpers{

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
//! Возвращает префикс, который можно использовать, если нужно передать "сырой" regexp
template< typename StringType > inline
StringType getRawEcmaRegexPrefix( )
{
    return umba::string_plus::make_string<StringType>("{*?regex?*}");
}

//----------------------------------------------------------------------------
//! Легким движением руки простая маска превращается в регэксп
/*! Символ ^ (крышечка, XOR) - если первый символ маски - привязывает маску к началу текста
                             - если последний символ маски - привязывает маску к концу текста
 */
template< typename StringType > inline
StringType expandSimpleMaskToEcmaRegex( StringType s, bool useAnchoring = false, bool allowRawRegexes = true )
{
    if (allowRawRegexes)
    {
        if (umba::string_plus::starts_with_and_strip<StringType>(s,getRawEcmaRegexPrefix<StringType>()))
            return s;
    }

    StringType res; res.reserve(s.size());

    typedef typename StringType::value_type    CharType;


    // https://docs.microsoft.com/en-us/previous-versions/windows/desktop/indexsrv/ms-dos-and-windows-wildcard-characters
    // https://en.cppreference.com/w/cpp/regex/ecmascript
    // https://developer.mozilla.org/ru/docs/Web/JavaScript/Guide/Regular_Expressions

    // The assertion ^ (beginning of line) matches
    //  
    // 1) The position that immediately follows a LineTerminator character (this may not be supported) 
    //    (until C++17) (this is only guaranteed if std::regex_constants::multiline(C++ only) is enabled) (since C++17)
    // 2) The beginning of the input (unless std::regex_constants::match_not_bol(C++ only) is enabled)


    // The assertion $ (end of line) matches
    //  
    // 1) The position of a LineTerminator character (this may not be supported) (until C++17)(this is only guaranteed 
    //    if std::regex_constants::multiline(C++ only) is enabled) (since C++17)
    // 2) The end of the input (unless std::regex_constants::match_not_eol(C++ only) is enabled)


    // characters ^ $ \ . * + ? ( ) [ ] { } |

    // Single character matches The Atom '.' matches and consumes any one character 
    // from the input string except for LineTerminator (U+000D, U+000A, U+2029, or U+2028)
    // Quantifiers
    // { DecimalDigits } exact DecimalDigits
    // { DecimalDigits , } from value of DecimalDigits to inf

    bool anchorBeginning = (!useAnchoring || s.empty() ) ? false : s.front()=='^';
    bool anchorEnding    = (!useAnchoring || s.empty() ) ? false : s.back ()=='^';

    if (anchorEnding)
        s.erase(s.size()-1,1);

    if (anchorBeginning)
        s.erase(0,1);

    using namespace umba::string_plus;

    for(auto ch: s)
    {
        switch(ch)
        {
            // case '*' : res.append(".{1,}");
            case (CharType)'*' : res.append(make_string<StringType>(".*"));
                                 break;
            case (CharType)'?' : res.append(make_string<StringType>(".{1}"));
                                 break;
            case (CharType)'^' : res.append(make_string<StringType>("\\^"));
                                 break;
            case (CharType)'$' : res.append(make_string<StringType>("\\$"));
                                 break;
            case (CharType)'\\': res.append(make_string<StringType>("\\\\"));
                                 break;
            case (CharType)'.' : res.append(make_string<StringType>("\\."));
                                 break;
            // case (CharType)'*' : res.append(make_string<StringType>("\\*"));
            //                      break;
            // case (CharType)'?' : res.append(make_string<StringType>("\\?"));
            //                      break;
            case (CharType)'+' : res.append(make_string<StringType>("\\+"));
                                 break;
            case (CharType)'(' : res.append(make_string<StringType>("\\("));
                                 break;
            case (CharType)')' : res.append(make_string<StringType>("\\)"));
                                 break;
            case (CharType)'[' : res.append(make_string<StringType>("\\["));
                                 break;
            case (CharType)']' : res.append(make_string<StringType>("\\]"));
                                 break;
            case (CharType)'{' : res.append(make_string<StringType>("\\{"));
                                 break;
            case (CharType)'}' : res.append(make_string<StringType>("\\}"));
                                 break;
            case (CharType)'|' : res.append(make_string<StringType>("\\|"));
                                 break;
            default:
                       res.append(1, ch);
        }

    }

    return ( anchorBeginning ? make_string<StringType>("^") : StringType() )
         + res
         + ( anchorEnding    ? make_string<StringType>("$") : StringType() )
         ;
}

//----------------------------------------------------------------------------
//! Легким движением руки простая маска превращается в регэксп - версия для сырого char*
inline
std::string expandSimpleMaskToEcmaRegex( const char* s, bool useAnchoring = false, bool allowRawRegexes = true )
{
    return expandSimpleMaskToEcmaRegex<std::string>( std::string(s), useAnchoring, allowRawRegexes );
}

//----------------------------------------------------------------------------
//! Легким движением руки простая маска превращается в регэксп - версия для сырого wchar_t*
inline
std::wstring expandSimpleMaskToEcmaRegex( const wchar_t* s, bool useAnchoring = false, bool allowRawRegexes = true )
{
    return expandSimpleMaskToEcmaRegex<std::wstring>( std::wstring(s), useAnchoring, allowRawRegexes );
}

//----------------------------------------------------------------------------
// https://en.cppreference.com/w/cpp/regex/match_results
// Хз, что быстрее, match_results или regex_match

#if 0
template< typename StringType > inline
bool regexMatch(const StringType &text, const std::basic_regex<typename StringType::value_type> &r)
{
    // https://en.cppreference.com/w/cpp/regex/match_results
    
    // std::smatch m;
    std::match_results< typename StringType::const_iterator > m;

    if ( !regex_search(text, m, r ) )
        return false;

    return true;
}
#endif

//! Просто завернули std::regex_match в try/catch, версия для строки
template< typename CharType > inline
bool regexMatch( const std::basic_string<CharType> &text, const std::basic_regex<CharType> &r
               , std::regex_constants::match_flag_type flags = std::regex_constants::match_default
               )
{
    try
    {
        return std::regex_match( text, r, flags );
    }
    catch(...)
    {}

    return false;
}

//----------------------------------------------------------------------------
//! Просто завернули std::regex_match в try/catch, версия для вектора CharType'ов
template< typename CharType > inline
bool regexMatch( const std::vector<CharType> &text, const std::basic_regex<CharType> &r
               , std::regex_constants::match_flag_type flags = std::regex_constants::match_default
               )
{
    try
    {
        return std::regex_match( text.begin(), text.end(), r, flags );
    }
    catch(...)
    {}

    return false;
}


//----------------------------------------------------------------------------
//! На входе вместо regex строка с regex-выражением, версия для строки
template< typename CharType > inline
bool regexMatch( const std::basic_string<CharType>     &text
               , const std::basic_string<CharType>     &r
               , std::regex_constants::match_flag_type flags = std::regex_constants::match_default
               )
{
    return regexMatch(text, std::basic_regex<CharType>(r));
}

//----------------------------------------------------------------------------
//! На входе вместо regex строка с regex-выражением, версия для вектора CharType'ов
template< typename CharType > inline
bool regexMatch( const std::vector<CharType>           &text
               , const std::basic_string<CharType>     &r
               , std::regex_constants::match_flag_type flags = std::regex_constants::match_default
               )
{
    return regexMatch(text, std::basic_regex<CharType>(r));
}

//----------------------------------------------------------------------------
//! На входе - map, ключ - трока с выражением, значение - regex, чтобы прогонять regex'ы пачками и уметь получать исходную строку regex-выражения
template< typename StringType > inline
bool regexMatch( const StringType                                                                &text
               , const std::map< StringType, std::basic_regex<typename StringType::value_type> > &regexes
               , StringType                                                                      *pMatchedRegexText = 0
               , std::regex_constants::match_flag_type                                           flags = std::regex_constants::match_default
               )
{
    for( const auto& [key,val] : regexes)
    {
        if (regexMatch(text, val, flags))
        {
            if (pMatchedRegexText)
               *pMatchedRegexText = key;
            return true;
        }
    }

    return false;
}

//----------------------------------------------------------------------------
//! Прогоняет по выражению вектор regex'ов, возвращает true, если хоть один сработал
template< typename StringType > inline
bool regexMatch( const StringType                                                          &text
               , const std::vector< std::basic_regex<typename StringType::value_type> >    &regexes
               , std::size_t                                                               *pMatchIndex = 0
               , std::regex_constants::match_flag_type                                      flags = std::regex_constants::match_default
               )
{
    std::size_t idx = 0;
    for(const auto& r : regexes)
    {
        if (regexMatch(text, r, flags))
        {
            if (pMatchIndex)
                *pMatchIndex = idx;

            return true;
        }

        ++idx;
    }

    return false;
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------


} // namespace regex_helpers
} // namespace umba

// umba::regex_helpers::


