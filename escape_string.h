#pragma once

#include <utility>
#include <algorithm>
#include <iterator>


//----------------------------------------------------------------------------
namespace umba {



//----------------------------------------------------------------------------
template<typename CharType, typename OutputIterator> inline
OutputIterator appendToOutputEscapeHelper(OutputIterator outIt, const char* ccStr)
{
    for(; *ccStr; ++ccStr)
        *outIt++ = (CharType)*ccStr;
    return outIt;
}

//----------------------------------------------------------------------------
template<typename CharType, typename OutputIterator> inline
OutputIterator appendOctalEscapeSequence(OutputIterator outIt, unsigned uch)
{
    char buf[4] = { 0 };
    for(auto i=0u; i!=3; ++i)
    {
        buf[i] = '0'+(char)(uch%8);
        uch /= 8;
    }

    std::swap(buf[0], buf[2]);
    *outIt++ = (CharType)'\\';
    return appendToOutputEscapeHelper<CharType>(outIt, &buf[0]);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename InputIterator, typename OutputIterator> inline
OutputIterator escapeStringC(OutputIterator outIt, InputIterator b, InputIterator e)
{
    using CharType = typename InputIterator::value_type;

    for(; b!=e; ++b)
    {
        auto ch = *b;

        switch(ch)
        {
            case (CharType)'\'': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\'" ); break;
            case (CharType)'\"': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\\""); break;
            case (CharType)'\\': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\\\"); break;
            case (CharType)'\a': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\a" ); break;
            case (CharType)'\b': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\b" ); break;
            case (CharType)'\f': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\f" ); break;
            case (CharType)'\n': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\n" ); break;
            case (CharType)'\r': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\r" ); break;
            case (CharType)'\t': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\t" ); break;
            case (CharType)'\v': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\v" ); break;
            default:
                if (ch>=(CharType)' ')
                    *outIt++ = ch;
                else
                    outIt = appendOctalEscapeSequence<CharType>(outIt, (unsigned)ch);
        }
    }

    return outIt;
}

//----------------------------------------------------------------------------
template<typename StringType> inline
StringType escapeStringC(const StringType &str)
{
    StringType res; res.reserve(str.size());
    escapeStringC(std::back_inserter(res), str.begin(), str.end());
    return res;
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename InputIterator, typename OutputIterator> inline
OutputIterator escapeStringGraphViz(OutputIterator outIt, InputIterator b, InputIterator e)
{
    using CharType = typename InputIterator::value_type;

    for(; b!=e; ++b)
    {
        auto ch = *b;

        switch(ch)
        {
            case (CharType)'<' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\<" ); break;
            case (CharType)'>' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\>" ); break;
            case (CharType)'|' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\|" ); break;
            case (CharType)'{' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\{" ); break;
            case (CharType)'}' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\}" ); break;

            case (CharType)'\'': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\'" ); break;
            case (CharType)'\"': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\\""); break;
            case (CharType)'\\': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\\\"); break;
            case (CharType)'\a': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\a" ); break;
            case (CharType)'\b': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\b" ); break;
            case (CharType)'\f': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\f" ); break;
            case (CharType)'\n': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\n" ); break;
            case (CharType)'\r': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\r" ); break;
            case (CharType)'\t': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\t" ); break;
            case (CharType)'\v': outIt = appendToOutputEscapeHelper<CharType>(outIt, "\\v" ); break;
            default:
                if (ch>=(CharType)' ')
                    *outIt++ = ch;
                else
                    outIt = appendOctalEscapeSequence<CharType>(outIt, (unsigned)ch);
        }
    }

    return outIt;
}

//----------------------------------------------------------------------------
template<typename StringType> inline
StringType escapeStringGraphViz(const StringType &str)
{
    StringType res; res.reserve(str.size());
    escapeStringGraphViz(std::back_inserter(res), str.begin(), str.end());
    return res;
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename InputIterator, typename OutputIterator> inline
OutputIterator escapeStringXmlHtml(OutputIterator outIt, InputIterator b, InputIterator e)
{
    using CharType = typename InputIterator::value_type;

    for(; b!=e; ++b)
    {
        auto ch = *b;

        switch(ch)
        {
            // https://en.wikipedia.org/w/index.php?title=List_of_XML_and_HTML_character_entity_references&mobile-app=true&theme=dark
            case (CharType)'&' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "&amp;" ); break;
            case (CharType)'<' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "&lt;"  ); break;
            case (CharType)'>' : outIt = appendToOutputEscapeHelper<CharType>(outIt, "&gt;"  ); break;
            case (CharType)'\'': outIt = appendToOutputEscapeHelper<CharType>(outIt, "&apos;"); break;
            case (CharType)'\"': outIt = appendToOutputEscapeHelper<CharType>(outIt, "&quot;"); break;
            default:
                                *outIt++ = ch;
        }
    }

    return outIt;
}

//----------------------------------------------------------------------------
template<typename StringType> inline
StringType escapeStringXmlHtml(const StringType &str)
{
    StringType res; res.reserve(str.size());
    escapeStringXmlHtml(std::back_inserter(res), str.begin(), str.end());
    return res;
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

} // namespace umba


