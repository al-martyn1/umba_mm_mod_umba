#pragma once

#include <cstdint>
#include <climits>
#include <type_traits>
#include <string>



// umba::tokeniser::
namespace umba {
namespace tokeniser {


// #define UMBA_CHAR_CLASS_UNDERLYING_COMPACT

#if defined(UMBA_CHAR_CLASS_UNDERLYING_COMPACT)

    using char_class_underlying_uint_t = std::uint_least16_t;

#else

    using char_class_underlying_uint_t = std::uint_fast32_t;

#endif


constexpr
std::size_t charToCharClassTableIndex(char ch)
{
    return (((std::size_t)(std::uint_least8_t)ch) < 0x80) ? (std::size_t)(std::uint_least8_t)ch : 0x7Fu; // Всё, что больше или равно 0x80, превращаем в непечатный символ DEL (0x7Fu)
}

constexpr
std::size_t charToCharClassTableIndex(std::uint8_t ch)
{
    return (((std::size_t)(std::uint_least8_t)ch) < 0x80) ? (std::size_t)(std::uint_least8_t)ch : 0x7Fu; // Всё, что больше или равно 0x80, превращаем в непечатный символ DEL (0x7Fu)
}


/*

Классы символов
Символ может входить в несколько классов, например '<'/'>' - скобка и операторный символ

nonprintable     - all less to space
space            - all less or eq to space
quot             - ` ' " (backtik apos quot)
brace            - {}()[]<>
open             - {([<
close            - })]>
operator         - ! $ % & * + , - . / : ; < = > ? @ \ ^ | ~
digit            - 0-9
alpha            - A-Za-z
identifier       - _A-Za-z0-9
identifier-first - _A-Za-z
hyphen           - -
underscore       - _

$ - alpha и operator
@ - alpha и operator

*/

//----------------------------------------------------------------------------
enum class CharClass : char_class_underlying_uint_t
{
    // unknown       = 1,
    none             = 0x0000,
    nonprintable     = 0x0001,
    linefeed         = 0x0002,
    space            = 0x0004,
    tab              = 0x0008,
    quot             = 0x0010,
    brace            = 0x0020,
    open             = 0x0040, // Для парных символов
    close            = 0x0080, // Для парных символов
    opchar           = 0x0100,
    operator_char    = 0x0100,
    punctuation      = 0x0200,
    digit            = 0x0400,
    alpha            = 0x0800,
    identifier       = 0x1000,
    identifier_first = 0x2000,
    semialpha        = 0x4000,
    escape           = 0x8000
};

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
using CharClassUnderlyingType = typename std::underlying_type<CharClass>::type;

inline constexpr CharClass operator|(CharClass a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<CharClass>(static_cast<TUnder>(a) | static_cast<TUnder>(b));
}

//----------------------------------------------------------------------------
inline constexpr CharClass operator&(CharClass a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<CharClass>(static_cast<TUnder>(a) & static_cast<TUnder>(b));
}

//----------------------------------------------------------------------------
inline constexpr CharClass operator^(CharClass a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<CharClass>(static_cast<TUnder>(a) ^ static_cast<TUnder>(b));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline constexpr CharClass& operator|=(CharClass& a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    a = static_cast<CharClass>(static_cast<TUnder>(a) | static_cast<TUnder>(b));
    return a;
}

//----------------------------------------------------------------------------
inline constexpr CharClass& operator&=(CharClass& a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    a = static_cast<CharClass>(static_cast<TUnder>(a) & static_cast<TUnder>(b));
    return a;
}

//----------------------------------------------------------------------------
inline constexpr CharClass& operator^=(CharClass& a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    a = static_cast<CharClass>(static_cast<TUnder>(a) ^ static_cast<TUnder>(b));
    return a;
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline constexpr bool operator==(CharClass a, std::underlying_type<CharClass>::type b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<TUnder>(a) == b;
}

//----------------------------------------------------------------------------
inline constexpr bool operator==(std::underlying_type<CharClass>::type a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return a == static_cast<TUnder>(b);
}

//----------------------------------------------------------------------------
inline constexpr bool operator!=(CharClass a, std::underlying_type<CharClass>::type b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<TUnder>(a) != b;
}

//----------------------------------------------------------------------------
inline constexpr bool operator!=(std::underlying_type<CharClass>::type a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return a != static_cast<TUnder>(b);
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline
std::string enum_serialize_single_flag(CharClass f)
{
    switch(f)
    {
        //case CharClass::none            : return std::string("none");
        case CharClass::nonprintable    : return std::string("nonprintable");
        case CharClass::linefeed        : return std::string("linefeed");
        case CharClass::space           : return std::string("space");
        case CharClass::tab             : return std::string("tab");
        case CharClass::quot            : return std::string("quot");
        case CharClass::brace           : return std::string("brace");
        case CharClass::open            : return std::string("open");
        case CharClass::close           : return std::string("close");
        case CharClass::opchar          : return std::string("opchar");
        //case CharClass::operator_char   : return std::string("operator_char");
        case CharClass::punctuation     : return std::string("punctuation");
        case CharClass::digit           : return std::string("digit");
        case CharClass::alpha           : return std::string("alpha");
        case CharClass::identifier      : return std::string("identifier");
        case CharClass::identifier_first: return std::string("identifier_first");
        case CharClass::semialpha       : return std::string("semialpha");
        case CharClass::escape          : return std::string("escape");
        default: return std::string("");
    }
}

//----------------------------------------------------------------------------
inline
std::string enum_serialize_flags(CharClass f)
{
    char_class_underlying_uint_t fu = (char_class_underlying_uint_t)f;

    std::string res;

    char_class_underlying_uint_t flagBit = 1;
    for(; flagBit!=0; flagBit<<=1)
    {
        if (fu&flagBit)
        {
            std::string flagStr = enum_serialize_single_flag((CharClass)flagBit);
            if (!flagStr.empty())
            {
                if (!res.empty())
                {
                    res.append(1,'|');
                }

                res.append(flagStr);
            }
        }
    }

    if (res.empty())
    {
        res = "0";
    }

    return res;
}

//----------------------------------------------------------------------------
inline
std::string enum_serialize(CharClass f)
{
    return enum_serialize_flags(f);
}

} // namespace tokeniser
} // namespace umba

