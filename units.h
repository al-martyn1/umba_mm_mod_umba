#pragma once

#include <cstddef>
#include <exception>
#include <stdexcept>
#include <string>
#include <limits>
#include <type_traits>
#include <unordered_map>

//
#include "string_plus.h"


// umba::units::

//----------------------------------------------------------------------------
namespace umba {
namespace units {





//----------------------------------------------------------------------------

// 6. The String library
// http://squirrel-lang.org/squirreldoc/stdlib/stdstringlib.html#the-string-library

// Вместо l/r/trim - lstrip(str)/rstrip(str)/strip(str)

// Есть startswith(str, cmp)/endswith(str, cmp)

// Есть format(formatstr, ...)

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
template<typename StringType> inline
void splitValueAndUnits( const StringType     &valWithUnits
                       , StringType           &valStr 
                       , StringType           &unitsStr
                       , const StringType     &valAllowedChars
                       , const StringType     &ignoreValChars
                       , const StringType     &dotAliasChars
                       , bool                 allowDot
                       , bool                 eatSpaces
                       , bool                 eatIgnored
                       )
{
    typedef typename StringType::value_type CharType;

    valStr.clear();
    unitsStr.clear();

    auto isSpaceChar = [](CharType ch) -> bool
        {
            if (ch==(CharType)' ' || ch==(CharType)'\t' || ch==(CharType)'\r' || ch==(CharType)'\n')
            {
                return true;
            }

            return false;
        };

    auto skipThisChar = [&](CharType ch) -> bool
        {
            // Просто съедаем все пробелы
            // Или не съедаем все пробелы?
            // Не съедаем, чтобы потом можно было восстановить исходную строку
            // Или съедаем опционально
            if (eatSpaces && isSpaceChar(ch))
            {
                return true;
            }

            std::size_t foundPos = ignoreValChars.find(ch);
            if (foundPos!=ignoreValChars.npos)
            {
                return true;
            }

            return false;
        };


    std::size_t i = 0;

    std::size_t dotCount = allowDot ? 0u : 1u;

    for(; i!=valWithUnits.size(); ++i)
    {
        auto ch = valWithUnits[i];

        if (skipThisChar(ch))
        {
            continue;
        }

        if (isSpaceChar(ch))
        {
            // Если пробелы не съедаются, они просто копируются в результат
            valStr.append(1,ch);
        }

        if (allowDot && ch==(CharType)'.') // Точку проверяем безусловно, не надо, чтобы она входила явно в список алиасов или в список разрешенных для числа символов
        {
            if (dotCount)
            {
                break; // Точка уже есть, или запрещена для данного типа
            }

            ++dotCount;
            valStr.append(1,(CharType)'.');
        }


        // Замена запятой и прочего на точку
        std::size_t
        foundPos = dotAliasChars.find(ch);
        if (foundPos!=dotAliasChars.npos)
        {
            if (dotCount)
            {
                break; // Точка уже есть, или запрещена для данного типа
            }

            ++dotCount;
            valStr.append(1,(CharType)'.');
        }

        // Символы, которые просто игнорируем в строке значения
        // Или как тут быть? Мы же хотим, чтобы строка осталась нужной длины со всеми символами, не?
        foundPos = ignoreValChars.find(ch);
        if (foundPos!=ignoreValChars.npos) // Найдено в игноре
        {
            if (!eatIgnored) // Копируем или пропускаем, главное - не выйдем по !valAllowedChars
            {
                valStr.append(1,ch);
            }

            continue;
        }

        // Не найдено в разрешенных
        foundPos = valAllowedChars.find(ch);
        if (foundPos==valAllowedChars.npos)
        {
            break;
        }

        valStr.append(1,ch);

    }

    if (!eatSpaces)
    {
        unitsStr = StringType(valWithUnits, i);
        return;
    }


    for(; i!=valWithUnits.size(); ++i)
    {
        auto ch = valWithUnits[i];

        if (isSpaceChar(ch))
        {
            continue;
        }

        unitsStr.append(1,ch);
    }

}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// integral signed
template<typename T> inline
std::enable_if_t<std::is_integral<T>::value && std::is_signed<T>::value, void>
getValueAllowedCharsImpl(std::string &allowedChars)
{
    allowedChars = "0123456789+-"; // +/- - в конце, они реже всего появляются
}

template<typename T> inline
std::enable_if_t<std::is_integral<T>::value && std::is_signed<T>::value, void>
getValueAllowedCharsImpl(std::wstring &allowedChars)
{
    allowedChars = L"0123456789+-";
}

// integral unsigned
template<typename T> inline
std::enable_if_t<std::is_integral<T>::value && std::is_unsigned<T>::value, void>
getValueAllowedCharsImpl(std::string &allowedChars)
{
    allowedChars = "0123456789+";
}

template<typename T> inline
std::enable_if_t<std::is_integral<T>::value && std::is_unsigned<T>::value, void>
getValueAllowedCharsImpl(std::wstring &allowedChars)
{
    allowedChars = L"0123456789+";
}

// floating point
template<typename T> inline
std::enable_if_t<std::is_floating_point<T>::value, void>
getValueAllowedCharsImpl(std::string &allowedChars)
{
    allowedChars = "0123456789+-";
}

template<typename T> inline
std::enable_if_t<std::is_floating_point<T>::value, void>
getValueAllowedCharsImpl(std::wstring &allowedChars)
{
    allowedChars = L"0123456789+-";
}


template<typename T> inline
std::enable_if_t<std::is_integral<T>::value, bool>
getValueDotAllowedImpl()
{
    return false;
}

template<typename T> inline
std::enable_if_t<std::is_floating_point<T>::value, bool>
getValueDotAllowedImpl()
{
    return true;
}



template<typename StringType, typename T>
StringType getValueAllowedChars()
{
    StringType allowedChars;
    getValueAllowedCharsImpl<T>(allowedChars);
    return allowedChars;
}

template<typename T> inline
bool getValueDotAllowed()
{
    return getValueDotAllowedImpl<T>();
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------

template<typename ValueType, typename StringType> inline
ValueType valueFromStringImpl( const StringType &str )
{
    throw std::runtime_error("umba::units::valueFromStringImpl: not implemented for this type");
}


//----------------------------------------------------------------------------
// https://en.cppreference.com/w/cpp/string/basic_string/stoul

template<> inline
unsigned valueFromStringImpl<unsigned, std::string>( const std::string &str )
{
    unsigned long ul = std::stoul(str);
    if (ul<std::numeric_limits<unsigned>::min() || ul>std::numeric_limits<unsigned>::max())
    {
        std::out_of_range("umba::units::valueFromStringImpl<unsigned>: value is out of range");
    }

    return (unsigned)ul;
}

template<> inline
unsigned valueFromStringImpl<unsigned, std::wstring>( const std::wstring &str )
{
    unsigned long ul = std::stoul(str);
    if (ul<std::numeric_limits<unsigned>::min() || ul>std::numeric_limits<unsigned>::max())
    {
        std::out_of_range("umba::units::valueFromStringImpl<unsigned>: value is out of range");
    }

    return (unsigned)ul;
}

//------------------------------
template<> inline
unsigned long valueFromStringImpl<unsigned long, std::string>( const std::string &str )
{
    return std::stoul(str);
}

template<> inline
unsigned long valueFromStringImpl<unsigned long, std::wstring>( const std::wstring &str )
{
    return std::stoul(str);
}

//------------------------------
template<> inline
unsigned long long valueFromStringImpl<unsigned long long, std::string>( const std::string &str )
{
    return std::stoull(str);
}

template<> inline
unsigned long long valueFromStringImpl<unsigned long long, std::wstring>( const std::wstring &str )
{
    return std::stoull(str);
}

//----------------------------------------------------------------------------
// https://en.cppreference.com/w/cpp/string/basic_string/stol

template<> inline
int valueFromStringImpl<int, std::string>( const std::string &str )
{
    return std::stoi(str);
}

template<> inline
int valueFromStringImpl<int, std::wstring>( const std::wstring &str )
{
    return std::stoi(str);
}

//------------------------------
template<> inline
long valueFromStringImpl<long, std::string>( const std::string &str )
{
    return std::stol(str);
}

template<> inline
long valueFromStringImpl<long, std::wstring>( const std::wstring &str )
{
    return std::stol(str);
}

//------------------------------
template<> inline
long long valueFromStringImpl<long long, std::string>( const std::string &str )
{
    return std::stoll(str);
}

template<> inline
long long valueFromStringImpl<long long, std::wstring>( const std::wstring &str )
{
    return std::stoll(str);
}

//----------------------------------------------------------------------------
// https://en.cppreference.com/w/cpp/string/basic_string/stof

template<> inline
float valueFromStringImpl<float, std::string>( const std::string &str )
{
    return std::stof(str);
}

template<> inline
float valueFromStringImpl<float, std::wstring>( const std::wstring &str )
{
    return std::stof(str);
}

//------------------------------
template<> inline
double valueFromStringImpl<double, std::string>( const std::string &str )
{
    return std::stod(str);
}

template<> inline
double valueFromStringImpl<double, std::wstring>( const std::wstring &str )
{
    return std::stod(str);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename ValueType> inline
ValueType valueFromString( const std::string &str )
{
    return valueFromStringImpl<ValueType, std::string>(str);
}

template<typename ValueType> inline
ValueType valueFromString( const std::wstring &str )
{
    return valueFromStringImpl<ValueType, std::wstring>(str);
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
template<typename ValueType, typename UnitsType>
struct ValWithUnits
{
    ValueType  value;
    UnitsType  units;


protected:

    // ErrorCode::ok

    // std::domain_error        - ErrorCode::unknownUnits
    // std::invalid_argument    - ErrorCode::invalidArgument
    // std::out_of_range        - ErrorCode::outOfRange
    // std::bad_alloc           - ErrorCode::noMemory
    //                            ErrorCode::genericError

    template<StringType>
    static
    ValWithUnits fromStringImpl( const StringType &str
                           , std::unordered_map<StringType, UnitsType> unitsMap
                           , UnitsType defaultUnits
                           , bool      iCase // true if case independed
                           , const StringType &ignoreValChars // разделители разрядов, например
                           , const StringType &dotAliasChars
                           )
    {
        if (iCase)
        {
            std::unordered_map<StringType, UnitsType> unitsMapTmp;
            std::unordered_map<StringType, UnitsType>::const_iterator it = unitsMap.begin();
            for(; it!=unitsMap.end(); ++it)
            {
                unitsMapTmp[umba::string_plus::toupper_copy(it->first)] = it->second;
            }

            unitsMapTmp.swap(unitsMap);
        }

        StringType valStr  ;
        StringType unitsStr;

        splitValueAndUnits( str, valStr, unitsStr
                          , getValueAllowedChars<StringType, ValueType>()
                          , ignoreValChars
                          , dotAliasChars
                          , getValueDotAllowed<ValueType>()
                          , true // eatSpaces
                          , true // eatIgnored
                          );

        if (valStr.empty())
        {
            throw std::invalid_argument("umba::units::ValWithUnits::fromStringImpl: invalid argument" );
        }

        if (iCase)
        {
            unitsStr = umba::string_plus::toupper_copy(unitsStr);
        }


        ValWithUnits res;

        res.value = valueFromString<ValueType>(valStr);


        if (unitsStr.empty())
        {
            res.units = defaultUnits;
        }
        else
        {
            std::unordered_map<StringType, UnitsType>::const_iterator it = unitsMap.find(unitsStr);
            if (it==unitsMap.end())
            {
                throw std::domain_error("umba::units::ValWithUnits::fromStringImpl: unknown units");
            }

            res.units = it->second;
        }

        return res;

    }


public:

    static
    ValWithUnits fromString( const std::string &str
                           , const std::unordered_map<std::string, UnitsType> &unitsMap
                           , UnitsType defaultUnits
                           , bool      iCase = true // true if case independed
                           , const std::string &ignoreValChars = "`' " // разделители разрядов, например
                           , const std::string &dotAliasChars  = ","
                           )
    {
        return fromStringImpl(str, unitsMap, defaultUnits, iCase, ignoreValChars, dotAliasChars)
    }

    static
    ValWithUnits fromString( const std::wstring &str
                           , const std::unordered_map<std::wstring, UnitsType> &unitsMap
                           , UnitsType defaultUnits
                           , bool      iCase = true // true if case independed
                           , const std::wstring &ignoreValChars = L"`' " // разделители разрядов, например
                           , const std::wstring &dotAliasChars  = L","
                           )
    {
        return fromStringImpl(str, unitsMap, defaultUnits, iCase, ignoreValChars, dotAliasChars)
    }


};

//----------------------------------------------------------------------------




} // namespace units
} // namespace umba

