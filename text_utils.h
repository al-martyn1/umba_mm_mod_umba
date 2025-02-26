/*!
    \file
    \brief Шляпы с текстом
 */

#pragma once

// #include "isa.h"
// #include "splits.h"
// #include "case.h"

#include "string_plus.h"
#include "utf.h"
#include "debug_helpers.h"
//
#include <string>
#include <algorithm>
#include <exception>
#include <stdexcept>

// umba::text_utils::
namespace umba{
namespace text_utils{


//bool isSpace( char ch, const std::string& spaceChars = "\t\n\v\f\r ");
// bool isDigit( char ch);
// bool isUpper( char ch );
// bool isLower( char ch );
// void strAlphaStat( const std::string &s, size_t &nUppers, size_t &nLowers, size_t &nDigits, size_t &nOthers );
// bool isUpperAlphasOnly( const std::string &s );
// bool isLowerAlphasOnly( const std::string &s );
//
// char toUpper( char ch );
// char toLower( char ch );
// std::string toUpper( std::string s );
// std::string toLower( std::string s );
// std::vector<std::string> toUpper( std::vector<std::string> v );
// std::vector<std::string> toLower( std::vector<std::string> v );
// std::set<std::string> toUpper( const std::set<std::string> &s );
// std::set<std::string> toLower( const std::set<std::string> &s );

enum class TextAlignment
{
    width  = 0,
    left      ,
    center    ,
    right

};



//-----------------------------------------------------------------------------
template<typename StringType, typename SpacePredType> inline
std::size_t textLineGetIndentSize(const StringType &s, SpacePredType pred)
{
    std::size_t i = 0;
    for(auto ch : s)
    {
        if (!pred(ch))
            break;
        ++i;
    }

    return i;
}

//-----------------------------------------------------------------------------
template<typename StringType, typename SpacePredType> inline
void textStripCommonIndent(std::vector<StringType> &v, SpacePredType pred)
{
    std::size_t minIndentLen = (std::size_t)-1;
    for(auto && s : v)
        minIndentLen = std::min(minIndentLen, textLineGetIndentSize(s, pred));
    for(auto & s : v)
        s.erase(0, minIndentLen);
}

//-----------------------------------------------------------------------------
template<typename StringType, typename SpacePredType> inline
std::vector<StringType> textStripCommonIndentCopy(const std::vector<StringType> &v, SpacePredType pred)
{
    std::vector<StringType> res = v;
    textStripCommonIndent(res, pred);
    return res;
}

//-----------------------------------------------------------------------------
inline
std::string textAddIndent(const std::string &text, const std::string &indent)
{
    std::string res;

    // (text.size()/40) - кол-во строк навскидку
    res.reserve( text.size() + (text.size()/40) * indent.size());

    if (!text.empty())
        res = indent;

    for( char ch : text)
    {
        res.append(1,ch);
        if (ch=='\n')
            res.append(indent);
    }

    return res;
}

//-----------------------------------------------------------------------------
inline
std::string textAddIndent(const std::string &text, const std::string &indent, const std::string &firstIndent)
{
    std::string res;

    // (text.size()/40) - кол-во строк навскидку
    res.reserve( text.size() + (text.size()/40) * indent.size());

    if (!text.empty())
        res = firstIndent;

    for( char ch : text)
    {
        res.append(1,ch);
        if (ch=='\n')
            res.append(indent);
    }

    return res;
}

//-----------------------------------------------------------------------------
inline
std::string compareStringsCasePrepare( const std::string &s, bool ci )
{
    if (ci)
    {
        std::string res = s;
        umba::string_plus::tolower(res);
        return res;
    }

    return s;
}

//-----------------------------------------------------------------------------
//inline
//int compareStringsCaseNoCase( const std::string &s1, const std::string &s2, bool ci )

//-----------------------------------------------------------------------------
struct StringsLess
{
    bool bCaseIgnore;
    StringsLess( bool bCI = true ) : bCaseIgnore(bCI) {}
    bool operator()( const std::string &s1, const std::string &s2 ) const
    {
        return compareStringsCasePrepare(s1,bCaseIgnore) < compareStringsCasePrepare(s2,bCaseIgnore);
    }
};

struct StringsGreater
{
    bool bCaseIgnore;
    StringsGreater( bool bCI = true ) : bCaseIgnore(bCI) {}
    bool operator()( const std::string &s1, const std::string &s2 ) const
    {
        return compareStringsCasePrepare(s1,bCaseIgnore) > compareStringsCasePrepare(s2,bCaseIgnore);
    }
};

//-----------------------------------------------------------------------------
struct StringsLessFirstBySize
{
    bool bCaseIgnore;
    StringsLessFirstBySize( bool bCI = true ) : bCaseIgnore(bCI) {}
    bool operator()( const std::string &s1, const std::string &s2 ) const
    {
        if (s1.size()<s2.size())
            return true;
        if (s1.size()>s2.size())
            return false;
        return compareStringsCasePrepare(s1,bCaseIgnore) < compareStringsCasePrepare(s2,bCaseIgnore);
    }
};

struct StringsGreaterFirstBySize
{
    bool bCaseIgnore;
    StringsGreaterFirstBySize( bool bCI = true ) : bCaseIgnore(bCI) {}
    bool operator()( const std::string &s1, const std::string &s2 ) const
    {
        if (s1.size()>s2.size())
            return true;
        if (s1.size()<s2.size())
            return false;
        return compareStringsCasePrepare(s1,bCaseIgnore) > compareStringsCasePrepare(s2,bCaseIgnore);
    }
};

//-----------------------------------------------------------------------------
#include "umba/warnings/push_disable_spectre_mitigation.h"
//! Расширяет строку до заданной длины, вставляя дополнительные пробелы
inline
std::string expandStringWidth( std::string str, std::string::size_type width )
{

    while(str.size() < width)
    {
        std::string::size_type i = 0;
        for( ; i!=str.size() && str.size()<width; ++i)
        {
            if (str[i]==' ')
            {
                str.insert( i, 1, ' ');
                while( i!=str.size() && str[i]==' ') ++i;
                --i;
            }
        }
    }

    return str;
}
#include "umba/warnings/pop.h"

//-----------------------------------------------------------------------------
//! Расширяет строку до заданной длины, вставляя дополнительные пробелы
inline
std::string alignStringWithWidth( std::string str, std::string::size_type width, TextAlignment textAlignment = TextAlignment::width )
{
    if (str.empty() || str.size()>=width)
        return str;

    switch(textAlignment)
    {
        case TextAlignment::left   : return str;

        case TextAlignment::center :
                                     {
                                         std::string::size_type widthToAddTotal = str.size() - width;
                                         std::string::size_type widthToAddLeft  = widthToAddTotal/2;
                                         std::string::size_type widthToAddRight = widthToAddTotal - widthToAddLeft;
                                         return std::string(widthToAddLeft, ' ') + str + std::string(widthToAddRight,' ');
                                     }

        case TextAlignment::right  :
                                     {
                                         std::string::size_type widthToAddRight = str.size() - width;
                                         return str + std::string(widthToAddRight,' ');
                                     }

        case TextAlignment::width  : return expandStringWidth(str,width);

        default                    : return str;
    }

}

//-----------------------------------------------------------------------------
//! Вычисляет длину символа в char'ах для однобайтных кодировок
struct SymbolLenCalculatorEncodingSingleByte
{
    std::size_t operator()(const char *pCh) const
    {
        UMBA_USED(pCh);
        return 1;
    }
};

//-----------------------------------------------------------------------------
#include "umba/warnings/push_disable_spectre_mitigation.h"
//! Вычисляет длину строки в символах
template<typename SymbolLenCalculator> inline
std::size_t getStringLen(const std::string &str, const SymbolLenCalculator &symbolLenCalculator)
{
    //using marty_utf::utf8_char_t;

    std::size_t numSymbols = 0;

    std::size_t curPos = 0;

    while(curPos<str.size())
    {
        //auto uch = (utf8_char_t)str[curPos];
        //auto symbolNumBytes = getNumberOfCharsUtf8(uch);
        auto symbolNumBytes = symbolLenCalculator(&str[curPos]);
        if (symbolNumBytes==0)
        {
            #ifdef UMBA_DEBUGBREAK
                UMBA_DEBUGBREAK();
            #endif
            throw std::runtime_error("Invalid symbol lenght: not a UTF-8 string?");
        }

        std::size_t nextPos = curPos + symbolNumBytes;

        if (nextPos<=str.size())
        {
            ++numSymbols;
        }

        curPos = nextPos;
    }

    return numSymbols;
}
#include "umba/warnings/pop.h"

//-----------------------------------------------------------------------------
//! Форматирует абзац (параграф). На входе - строка текста абзаца, на выходе - разбито на строки, и строки выровнены с учетом textAlignment
template<typename SymbolLenCalculator> inline
std::vector<std::string> prepareTextParaMakeLines( const std::string &para, std::string::size_type paraWidth
                                                 , TextAlignment textAlignment // = TextAlignment::width
                                                 , const SymbolLenCalculator &symbolLenCalculator // = SymbolLenCalculatorEncodingSingleByte()
                                                 )
{
    std::vector<std::string> words = umba::string_plus::split(para, ' ', false);
    //splitToVector( para, words, ' ' );
    umba::string_plus::cont_trim(words);

    std::vector< std::vector<std::string> > paraLinesWords;
    std::vector<std::string> curLineWords;
    std::string::size_type   curLineLen = 0;

    for( const auto &w : words )
    {
        std::size_t wordLenInSymbols = getStringLen(w, symbolLenCalculator);
        if ( (curLineLen+1+wordLenInSymbols) > paraWidth)
        {
            paraLinesWords.push_back(curLineWords);
            curLineLen = 0;
            curLineWords.clear();
        }

        curLineLen += 1 + wordLenInSymbols; // w.size(); // 1 - space len
        curLineWords.push_back( w );
    }

    if (!curLineWords.empty())
    {
        paraLinesWords.push_back(curLineWords);
    }

    std::vector<std::string> res;

    //std::vector< std::vector<std::string> >::size_type lineIdx = 0;

    std::vector< std::vector<std::string> >::const_iterator lineWordsIt = paraLinesWords.begin();
    std::vector< std::vector<std::string> >::const_iterator lastLineIt  = paraLinesWords.end();
    --lastLineIt;

    for(; lineWordsIt != paraLinesWords.end(); ++lineWordsIt)
    {
        const auto &lw = *lineWordsIt;

        if (lineWordsIt==lastLineIt && textAlignment==TextAlignment::width)
            res.push_back(umba::string_plus::merge(lw, ' ')); // если строка последняя и выравнивание по ширине, то не ничего не делаем, просто мержим слова
        else // Иначе (left/center/right или не последняя строка) - можно выравнивать
            res.push_back(umba::text_utils::alignStringWithWidth( umba::string_plus::merge(lw, ' '), paraWidth, textAlignment ));
    }

/*
    std::vector< std::vector<std::string> >::size_type lineIdx = 0;

    for( const auto &lw : paraLinesWords )
    {
        if (lineIdx!=(paraLinesWords.size()-1))
            res.push_back(umba::text_utils::expandStringWidth(umba::string_plus::merge(lw, ' '), paraWidth ));
        else
            res.push_back(umba::string_plus::merge(lw, ' '));
        lineIdx++;
    }
*/
    return res;
}

//-----------------------------------------------------------------------------
//! Форматирует абзац (параграф). Разбивает входную строку на строки по длине, форматирует их по alignment, и затем склеивает с переводом строки
template<typename SymbolLenCalculator> inline
std::string prepareTextParaMakeString( const std::string &para, std::string::size_type paraWidth
                                     , TextAlignment textAlignment // = TextAlignment::width
                                     , const SymbolLenCalculator &symbolLenCalculator // = SymbolLenCalculatorEncodingSingleByte()
                                     , bool bAppendMissingComma=true
                                     )
{
    std::vector<std::string> v = prepareTextParaMakeLines( para, paraWidth, textAlignment, symbolLenCalculator );
    auto res = umba::string_plus::merge( v, '\n'); // umba::string_plus::merge
    if (bAppendMissingComma)
    {
        if (!res.empty() && res.back()!='.' && res.back()!='!' && res.back()!='?' && res.back()!=':' && res.back()!=';')
            res.push_back('.');
    }
    return res;
}

//-----------------------------------------------------------------------------
// enum class TextAlignment
// {
//     left   ,
//     center ,
//     right  ,
//     width
//
// };

//! Форматирует параграфы. Разбивает текст по символу LF, форматирует, склеивает обратно
template<typename SymbolLenCalculator> inline
std::string formatTextParas( std::string text, std::string::size_type paraWidth
                           , TextAlignment textAlignment // = TextAlignment::width
                           , const SymbolLenCalculator &symbolLenCalculator // = SymbolLenCalculatorEncodingSingleByte()
                           , bool bAppendMissingComma=true
                           )
{
    std::vector<std::string> paras = umba::string_plus::split(text, '\n', true /* skipEmpty */);
    //splitToVector( text, paras, '\n' );

    text.clear();
    //trim(paras);
    for( auto &p : paras )
    {
        if (!p.empty() && p[0]==' ')
        {
            if (!text.empty())
                text.append("\n");
            umba::string_plus::trim(p);
            text.append("  ");
            text.append(p);
        }
        else
        {
            if (!text.empty())
                text.append("\n\n");
            text.append(prepareTextParaMakeString(p, paraWidth, textAlignment, symbolLenCalculator, bAppendMissingComma));
        }
    }

    return text;
    //return mergeStrings( paras, "\n\n", true /* skipEmpty */ );
}

//-----------------------------------------------------------------------------
//! Форматирует параграфы. Разбивает текст по символу LF, форматирует, склеивает обратно. Дефолтная реализация для однобайтной кодировки.
inline
std::string formatTextParas( std::string text, std::string::size_type paraWidth
                           , TextAlignment textAlignment // = TextAlignment::width
                           , bool bAppendMissingComma=true
                           )
{
    return formatTextParas<SymbolLenCalculatorEncodingSingleByte>(text, paraWidth, textAlignment, SymbolLenCalculatorEncodingSingleByte(), bAppendMissingComma);
}

//-----------------------------------------------------------------------------
//! Разбор строки с базовыми C-escape последовательностями - \\, \r, \n, \t, \', \"
inline
std::string parseEscapes( const std::string &text )
{
    std::string res;
    res.reserve( text.size() );

    bool prevEscape = false;

    for( char ch : text)
    {
        if (!prevEscape)
        {
            if (ch=='\\')
            {
                prevEscape = true;
            }
            else
            {
                res.append(1,ch);
            }
        }
        else
        {
            switch(ch)
            {
                case '\\':
                     res.append(1,'\\');
                     break;
                case 'r':
                     res.append(1,'\r');
                     break;
                case 'n':
                     res.append(1,'\n');
                     break;
                case 't':
                     res.append(1,'\t');
                     break;
                case '\'':
                     res.append(1,'\'');
                     break;
                case '\"':
                     res.append(1,'\"');
                     break;
                default:
                     res.append(1,ch);
            }

            prevEscape = false;
        }
    }

    return res;
}

//-----------------------------------------------------------------------------
//! Просто добавляет точку в конце текста, если её там нет
inline
std::string textAppendDot( std::string text )
{
    umba::string_plus::rtrim(text);
    if (!text.empty() && text.back()!='.')
        text.append(1, '.');
    return text;
}

//-----------------------------------------------------------------------------
//! Производит "сжатие" последовательностей из повторяющихся символов в один. Символы для "сжатия" задаются параметром compressChars
inline
std::string textCompress( const std::string &text, const std::string &compressChars )
{
    std::string res;

    std::string::size_type i = 0, sz = text.size();

    char prevWs = 0;

    for(; i!=sz; ++i)
    {
        char ch = text[i];
        std::string::size_type chPos = compressChars.find(ch);
        //if (ch==' ' || ch=='\t')
        if (chPos!=compressChars.npos)
        {
            if (ch==prevWs)
            {
                // simple skip
            }
            else
            {
                prevWs = ch;
                res.append(1,ch);
            }
        }
        else
        {
            prevWs = 0;
            res.append(1,ch);
        }
    }

    return res;

}

inline
std::string textDetectLinefeed( const std::string &text )
{
    // CRLF most used
    std::string::size_type pos = text.find('\n');
    if (pos == text.npos)
    {
        pos = text.find('\r');
        if (pos != text.npos)
            return "\r";
        // no linefeeds found at all
        return "\r\n";
    }

    if (pos==0)
    {
        if ((pos+1) != text.size() && text[pos+1]=='\r')
            return "\n\r"; // MAC style
        return "\n";
    }

    if (text[pos-1]=='\r')
        return "\r\n";

    if ((pos+1) != text.size() && text[pos+1]=='\r')
        return "\n\r"; // MAC style

    return "\n";
}

inline
std::string detectLinefeed( const std::string &text )
{
    return textDetectLinefeed(text);
}



inline
void textSplitToLines( const std::string &text, std::vector<std::string> &lines, std::string &detectedLinefeed )
{
    detectedLinefeed = textDetectLinefeed(text);
    if (detectedLinefeed.empty())
    {
        detectedLinefeed = "\n";
        //throw std::runtime_error("BEBEBEBEBE");
    }

    lines = umba::string_plus::split( text, detectedLinefeed.back(), false );
    umba::string_plus::cont_trim(lines, umba::string_plus::linefeed_pred<std::string::value_type>() );
}



} // namespace text_utils
} // namespace umba
