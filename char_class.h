#pragma once

#include <cstdint>
#include <type_traits>

namespace umba {

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
identifier       -
identifier-first -
hyphen           -
underscore       -

$ - alpha и operator
@ - alpha и operator

*/

enum class CharClass : std::uint32_t
{
    // unknown       = 1,
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
    hyphen           = 0x4000,
    underscore       = 0x8000
};

using CharClassUnderlyingType = typename std::underlying_type<CharClass>::type;

inline constexpr CharClass operator|(CharClass a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<CharClass>(static_cast<TUnder>(a) | static_cast<TUnder>(b));
}

inline constexpr CharClass operator&(CharClass a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<CharClass>(static_cast<TUnder>(a) & static_cast<TUnder>(b));
}

inline constexpr CharClass operator^(CharClass a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<CharClass>(static_cast<TUnder>(a) ^ static_cast<TUnder>(b));
}

inline constexpr bool operator==(CharClass a, std::underlying_type<CharClass>::type b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<TUnder>(a) == b;
}

inline constexpr bool operator==(std::underlying_type<CharClass>::type a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return a == static_cast<TUnder>(b);
}

inline constexpr bool operator!=(CharClass a, std::underlying_type<CharClass>::type b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return static_cast<TUnder>(a) != b;
}

inline constexpr bool operator!=(std::underlying_type<CharClass>::type a, CharClass b)
{
    using TUnder = typename std::underlying_type<CharClass>::type;
    return a != static_cast<TUnder>(b);
}



} // namespace umba

