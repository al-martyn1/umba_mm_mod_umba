/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief Утилиты для парсинга

    Repository: https://github.com/al-martyn1/umba
*/

#pragma once

//----------------------------------------------------------------------------

#include "string.h"
#include "basic_enums.h"

//
#include <algorithm>
#include <cstring>
#include <stdint.h>
#include <string.h>
#include <type_traits>

// #include "const_string.h"



#if defined(UMBA_QT_USED)

    #include <QString>

#endif

// umba::parse_utils::

namespace umba
{



//! Утилиты для парсинга
namespace parse_utils
{

//! Проверка на нижнерегистровую букву
inline
bool isAlphaLower( char ch )
{
    if (ch>='a' && ch<='z')
        return true;
    return false;
}

//! Проверка на нижнерегистровую букву
inline
bool isAlphaLower( uint8_t ch )
{
    return isAlphaLower( (char)ch );
}

//! Проверка на верхнерегистровую букву
inline
bool isAlphaUpper( char ch )
{
    if (ch>='A' && ch<='Z')
        return true;
    return false;
}

//! Проверка на верхнерегистровую букву
inline
bool isAlphaUpper( uint8_t ch )
{
    return isAlphaUpper( (char)ch );
}

//! Проверка на букву
inline
bool isAlpha( char ch )
{
    return isAlphaLower(ch) || isAlphaUpper(ch);
}

//! Проверка на букву
inline
bool isAlpha( uint8_t ch )
{
    return isAlphaLower(ch) || isAlphaUpper(ch);
}

//! Пробел?
inline
bool isSpace( char ch )
{
    return ch==' ';
}

//! Пробельный символ?
inline
bool isWhitespace( char ch )
{
    return ch==' ' || ch=='\r' || ch=='\n' || ch=='\t';
}

//! Пробел?
inline
bool isSpace( uint8_t ch )
{
    return isSpace((char)ch);
}

//! Пробельный символ?
inline
bool isWhitespace( uint8_t ch )
{
    return isWhitespace((char)ch);
}


#include "warnings/push_disable_spectre_mitigation.h"
//! Преобразование из цифрового сивола
inline
int toDigit( char ch )
{
    if (ch>='0' && ch<='9')
        return (int)(ch-'0');
    if (ch>='a' && ch<='z')
        return (int)(ch-'a'+10);
    if (ch>='A' && ch<='Z')
        return (int)(ch-'A'+10);
    return -1;
}
#include "warnings/pop.h"

//! Преобразование из цифрового сивола
inline
int toDigit( uint8_t ch )
{
    return toDigit( (char)ch );
}

//! Цифра?
inline
bool isDigit( char ch, int ss = 10)
{
    int d = toDigit( ch );
    if (d<0 || d>=ss)
        return false;
    return true;
}

//! Цифра?
inline
bool isDigit( uint8_t ch, int ss = 10)
{
    return isDigit( (char)ch, ss );
}

//! Пропустить пробелы
inline
size_t skipSpaces( const char* pBuf )
{
    for( size_t i=0; ; ++i )
    {
        if ( isSpace(pBuf[i]) ) // isSpace detects zero by itself
            continue;
        return i;
    }

    //return (size_t)-1;
}

//! Пропустить пробелы
inline
size_t skipSpaces( const uint8_t* pBuf )
{
    return skipSpaces( (const char*)pBuf );
}

//! Пропустить пробелы
inline
size_t skipSpaces( const char* pBuf, size_t bufSize )
{
    for( size_t i=0; i!=bufSize; ++i )
    {
        if ( isSpace(pBuf[i]) ) // isSpace detects zero by itself
            continue;
        return i;
    }

    return bufSize;
}

//! Пропустить пробелы
inline
size_t skipSpaces( const uint8_t* pBuf, size_t bufSize )
{
    return skipSpaces( (const char*)pBuf, bufSize );
}

//! Пропустить пробельные символы
inline
size_t skipWhitespaces( const char* pBuf )
{
    for( size_t i=0; ; ++i )
    {
        if ( isWhitespace(pBuf[i]) ) // isSpace detects zero by itself
            continue;
        return i;
    }

    //return (size_t)-1;
}

//! Пропустить пробельные символы
inline
size_t skipWhitespaces( const uint8_t* pBuf )
{
    return skipWhitespaces( (const char*)pBuf );
}

//! Пропустить пробельные символы
inline
size_t skipWhitespaces( const char* pBuf, size_t bufSize )
{
    for( size_t i=0; i!=bufSize; ++i )
    {
        if ( isWhitespace(pBuf[i]) )
            continue;
        return i;
    }

    return bufSize;
}

//! Пропустить пробельные символы
inline
size_t skipWhitespaces( const uint8_t* pBuf, size_t bufSize )
{
    return skipWhitespaces( (const char*)pBuf, bufSize );
}


//! Преобразование строки в число, без затей. *pReadedCount - инкрементируется, а не присваивается
inline
int64_t toNumberSimple( const char* pBuf, size_t bufSize, int ss, size_t *pReadedCount = 0 )
{
    //size_t  readedCount = 0;
    int64_t res = 0;
    size_t    i = 0;

    for( ; i!=bufSize && pBuf[i]; ++i )
    {
        int d = toDigit( pBuf[i] );
        if (d<0 || d>=ss)
            break;
        res *= (int64_t)ss;
        res += (int64_t)d;
    }

    if (pReadedCount)
       *pReadedCount += i;

    return res;
}

//! Преобразование строки в число, без затей. *pReadedCount - инкрементируется, а не присваивается
inline
int64_t toNumberSimple( const uint8_t* pBuf, size_t bufSize, int ss, size_t *pReadedCount = 0 )
{
    return toNumberSimple( (const char*)pBuf, bufSize, ss, pReadedCount );
}

#include "warnings/push_disable_spectre_mitigation.h"
//! Преобразование строки в число. *pReadedCount - инкрементируется, а не присваивается
/*! Пропускаются пробельные символы, определяется знак
 */
inline
bool toNumberEx( const char* pBuf, size_t bufSize, int ss, int64_t *pRes, size_t *pReadedCount = 0 )
{
    size_t offs = skipWhitespaces( pBuf, bufSize );
    if (offs>=bufSize)
    {
        if (pReadedCount)
           *pReadedCount += offs;
        return false;
    }

    int64_t neg = 1;
    if (pBuf[offs]=='-')
    {
        ++offs;
        neg = -1;
    }
    else if (pBuf[offs]=='+')
    {
        ++offs;
    }

    if (offs>=bufSize)
    {
        if (pReadedCount)
           *pReadedCount += offs;
        return false;
    }

    size_t tmpReaded = 0;
    int64_t num = toNumberSimple( &pBuf[offs], bufSize-offs, ss, &tmpReaded );
    if (!tmpReaded)
    {
        if (pReadedCount)
           *pReadedCount += offs;
        return false;
    }

    if (pRes)
        *pRes = neg*num;

    if (pReadedCount)
       *pReadedCount += offs+tmpReaded;

    return true;
}
#include "warnings/pop.h"

//! \copydoc toNumberEx
inline
bool toNumberEx( const uint8_t* pBuf, size_t bufSize, int ss, int64_t *pRes, size_t *pReadedCount = 0 )
{
    return toNumberEx( (const char*)pBuf, bufSize, ss, pRes, pReadedCount );
}

//! Вычисляет 10 в степени N
inline
int64_t pow10( int powN )
{
    if (powN<0)
        powN = -powN;

    int64_t res = 1;

    for( int i=0; i!=powN; ++i)
    {
        res *= 10;
    }

    return res;
}

//! Умножает/делит на 10 в степени N, в зависимости от знака N
inline
int64_t mulPow10( int64_t val, int powN )
{
    return powN < 0 ? val/pow10(powN) : val*pow10(powN);
}

//! Производит разбор десятичечного числа. *pReadedCount - инкрементируется, а не присваивается
/*! Возвращает число, умноженное на 10 в степени prec.
    Вычитывает всё число целиком, но используется только сколько задано
 */
inline
bool toDecimalFixedPoint( const char* pBuf, size_t bufSize, size_t prec, int64_t *pRes, size_t *pReadedCount = 0 )
{
    size_t orgBufSize = bufSize;
    size_t pos = skipWhitespaces( pBuf, bufSize );
    pBuf    += pos;
    bufSize -= pos;

    if (*pBuf==0 || !bufSize)
        return false;

    bool bNeg = false;

    if (*pBuf=='+' || *pBuf=='-')
    {
        if (*pBuf=='-')
            bNeg = true;

        ++pBuf;
        --bufSize;
    }

    pos = skipWhitespaces( pBuf, bufSize );
    pBuf    += pos;
    bufSize -= pos;

    if (*pBuf==0 || !bufSize)
        return false;

    size_t readedDigits = 0;
    int64_t res = toNumberSimple( pBuf, bufSize, 10, &readedDigits );

    //++readedDigits; // skip dot or comma
    pBuf    += readedDigits;
    bufSize -= readedDigits;

    if (!readedDigits && (*pBuf!='.' && *pBuf!=','))
        return false;

    res = mulPow10( res, (int)prec );

    if (*pBuf==0 || !bufSize || (*pBuf!='.' && *pBuf!=',') )
    {
        if (pRes)
           *pRes = bNeg ? -res : res;
        if (pReadedCount)
           *pReadedCount += orgBufSize - bufSize;
        return true;
    }

    ++pBuf;
    --bufSize;

    pos = 0;
    int64_t fractional = toNumberSimple( pBuf, bufSize, 10, &pos );
    pBuf    += pos;
    bufSize -= pos;

    readedDigits += pos;
    if (!readedDigits)
    {
        return false;
    }

    int readedPwr10 = (int)pos;
    int takenPwr10  = (int)prec;
    int deltaPwr    = takenPwr10 - readedPwr10;

    fractional = mulPow10( fractional, (int)deltaPwr );
    res += fractional;

    if (pRes)
       *pRes = bNeg ? -res : res;
    if (pReadedCount)
       *pReadedCount += orgBufSize - bufSize;
    return true;
}

//! \copydoc toDecimalFixedPoint
inline
bool toDecimalFixedPoint( const uint8_t* pBuf, size_t bufSize, size_t prec, int64_t *pRes, size_t *pReadedCount = 0 )
{
    return toDecimalFixedPoint( (const char*)pBuf, bufSize, prec, pRes, pReadedCount );
}



inline
const char* getNumberAllowedSymbols( bool allowAposAsSeparator = true )
{
    static char symbolsA[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
                             , '+', '-', ' ', ',', '.', '`', '\'' // decimal dot and possible separators
                             , 0
                             };
    static char symbolsN[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
                             , '+', '-', ' ', ',', '.', '`' // decimal dot and possible separators
                             , 0
                             };
    return allowAposAsSeparator ? &symbolsA[0] : &symbolsN[0];
}


inline
bool isAllowedNumberChar( char ch, bool allowAposAsSeparator = true )
{
    return std::strchr( getNumberAllowedSymbols(allowAposAsSeparator), ch )!=0;
}

inline
std::size_t findNumberUnits( const char* numStr, bool allowAposAsSeparator = true )
{
    std::size_t i = 0;
    for(; *numStr; ++numStr, ++i )
    {
        if (!isAllowedNumberChar(*numStr, allowAposAsSeparator))
            return i;
    }

    return (std::size_t)-1;
}

inline
bool removeNumberUnits( char* numStr, char* pUnitsBuf, std::size_t unitsBufSize, bool allowAposAsSeparator = true )
{
    std::size_t unitsStartPos = findNumberUnits( numStr, allowAposAsSeparator );

    if (unitsStartPos==(std::size_t)-1)
        return false;

    if (unitsBufSize && pUnitsBuf)
    {
        using namespace std;

        #if defined(UMBA_MSVC_COMPILER_USED)

            strncpy_s( pUnitsBuf, unitsBufSize, &numStr[unitsStartPos], _TRUNCATE );
            // https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l?view=msvc-160

        #else

            strncpy( pUnitsBuf, &numStr[unitsStartPos], unitsBufSize );

        #endif

        numStr[unitsStartPos] = 0;
        pUnitsBuf[unitsBufSize-1] = 0;
    }

    return true;
}

#if defined(UMBA_QT_USED)

inline
int findNumberUnits( const QString &numStr, bool allowAposAsSeparator = true )
{
    int i = 0;
    for(; i<numStr.size(); ++i )
    {
        if (!isAllowedNumberChar( numStr[i].toLatin1(), allowAposAsSeparator))
            return i;
    }

    return -1;
}

inline
bool removeNumberUnits( QString &numStr, QString &unitsStr, bool allowAposAsSeparator = true )
{
    int unitsStartPos = findNumberUnits( numStr, allowAposAsSeparator );

    if (unitsStartPos==(std::size_t)-1)
        return false;

    unitsStr = numStr;

    unitsStr.remove( 0, unitsStartPos ); // remove number from units
    numStr.remove( unitsStartPos, numStr.size()-unitsStartPos );

    return true;
}

#endif

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// Разбирает список по разделителям, убирает окружающие пробелы
inline
std::vector<std::string> optionStringSplitToVector(const std::string &str, const std::string &seps=",;")
{
    std::vector<std::string> resVec;
    std::string buf;

    for(auto ch : str)
    {
        if (seps.find(ch)!=seps.npos) // Найден разделитель
        {
            umba::string::trim(buf);
            if (!buf.empty())
                resVec.push_back(buf);
            buf.clear();
        }
        else
        {
            buf.append(1, ch);
        }
    }

    umba::string::trim(buf);
    if (!buf.empty())
        resVec.push_back(buf);

    return resVec;
}

//----------------------------------------------------------------------------
// Возвращает true, если разделитель найден
inline
bool optionStringSplitToPair(const std::string &str, std::string &first, std::string &second, const std::string &seps=":=")
{
    first.clear();
    second.clear();

    auto pos = str.find_first_of(seps);
    if (pos==str.npos)
    {
        first = str;
        umba::string::trim(first);
        return false;
    }

    first.assign(str, 0, pos); umba::string::trim(first);
    second.assign(str, pos+1); umba::string::trim(second);

    return true;
}

//----------------------------------------------------------------------------
inline
std::string optionStringExtractUpdateMarker(std::string optStr, bool &bRemove, bool defaultAdd=true)
{
    umba::string::trim(optStr);

    if (optStr.empty())
        return optStr;

    if (optStr.front()=='-' || optStr.front()=='+')
    {
        if (optStr.front()=='-')
            bRemove = true;
        else
            bRemove = false;

        optStr.erase(0, 1);
        umba::string::trim(optStr);
    }
    else
    {
        if (defaultAdd)
            bRemove = false;
        else // default - remove
            bRemove = true;
    }

    return optStr;
}

//----------------------------------------------------------------------------
// Трейт: является ли тип ассоциативным контейнером (имеет key_type)
template<typename, typename = void>
struct is_associative : std::false_type {};

template<typename T>
struct is_associative<T, std::void_t<typename T::key_type>> : std::true_type {};

//----------------------------------------------------------------------------
struct OptionPrepareDefault
{
    std::string operator()(const std::string &s) const
    {
        return s;
    }
};

//----------------------------------------------------------------------------
template<typename SetType, typename OptPrepareHandler=OptionPrepareDefault> inline
std::enable_if_t<is_associative<SetType>::value, bool>
optionStringUpdateSet(std::string opt, SetType &s, OptPrepareHandler optPrepareHandler=OptionPrepareDefault(), CaseOption caseOption=CaseOption::toLower, bool defaultAdd=true)
{
    umba::string::trim(opt);

    if (opt=="-") // 'remove all' marker
    {
        s.clear();
        return true;
    }

    bool bRemove = false;
    opt = optionStringExtractUpdateMarker(opt, bRemove, defaultAdd);
    opt = optPrepareHandler(opt);

    if (opt.empty())
        return false;

    umba::string::case_convert(opt, caseOption);

    if (bRemove)
        s.erase(opt);
    else
        s.insert(opt);

    return true;
}

//----------------------------------------------------------------------------
// Версия для векторов, списков, и тп
template<typename SetType, typename OptPrepareHandler=OptionPrepareDefault> inline
std::enable_if_t<!is_associative<SetType>::value, bool>
optionStringUpdateSet(std::string opt, SetType &s, OptPrepareHandler optPrepareHandler=OptionPrepareDefault(), CaseOption caseOption=CaseOption::toLower, bool defaultAdd=true)
{
    umba::string::trim(opt);

    if (opt=="-") // 'remove all' marker
    {
        s.clear();
        return true;
    }

    bool bRemove = false;
    opt = optionStringExtractUpdateMarker(opt, bRemove, defaultAdd);
    
    if (opt.empty())
        return false;

    umba::string::case_convert(opt, caseOption);
    opt = optPrepareHandler(opt);

    auto existingValIt = std::find(s.begin(), s.end(), opt);
    
    if (bRemove)
    {
        if (existingValIt!=s.end()) // Элемент существует - удаляем
            s.erase(existingValIt);
    }
    else
    {
        if (existingValIt==s.end()) // Элемент не существует - добавляем
            s.push_back(opt);
    }

    return true;
}

//----------------------------------------------------------------------------
template<typename SetType, typename OptPrepareHandler=OptionPrepareDefault> inline
bool optionVectorUpdateSet(const std::vector<std::string> &optVec, SetType &s, OptPrepareHandler optPrepareHandler=OptionPrepareDefault(), CaseOption caseOption=CaseOption::toLower, bool defaultAdd=true)
{
    for(const auto &opt : optVec)
    {
        if (!optionStringUpdateSet(opt, s, optPrepareHandler, caseOption, defaultAdd))
            return false;
    }

    return true;
}

//----------------------------------------------------------------------------
template<typename SetType, typename OptPrepareHandler=OptionPrepareDefault> inline
bool optionStringListUpdateSet(const std::string &optStr, SetType &s, OptPrepareHandler optPrepareHandler=OptionPrepareDefault(), CaseOption caseOption=CaseOption::toLower, const std::string &seps=",;", bool defaultAdd=true)
{
    auto optVec = optionStringSplitToVector(optStr, seps);
    return optionVectorUpdateSet(optVec, s, optPrepareHandler, caseOption, defaultAdd);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

} // namespace parse_utils
} // namespace umba


