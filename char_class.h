#pragma once

#include <cstdint>
#include <climits>
#include <type_traits>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>

//
#include "string_plus.h"
//
#include "c_char_class.h"



/*

// !!! Do not remove this comment, it is not "dead" code

// CharClass table generator sample

#include "umba/umba.h"
#include "umba/tokeniser.h"

int main(int argc, char* argv[])
{

    umba::tokeniser::CharClass charClasses[128] = { umba::tokeniser::CharClass::none };
    umba::tokeniser::generation::generateCharClassTable(charClasses);

    umba::tokeniser::generation::CommentType  commentType  = umba::tokeniser::generation::CommentType ::cppLike;
    umba::tokeniser::generation::ArrayType    arrayType    = umba::tokeniser::generation::ArrayType   ::stdArray;
    umba::tokeniser::generation::TypeNameType typeNameType = umba::tokeniser::generation::TypeNameType::cppLike;

    if (argc>1)
    {
        commentType  = umba::tokeniser::generation::CommentType ::cLike;
        arrayType    = umba::tokeniser::generation::ArrayType   ::cLike;
        typeNameType = umba::tokeniser::generation::TypeNameType::cLike;
    }

    umba::tokeniser::generation::printCharClassArray( charClasses, commentType, arrayType, typeNameType);  // , const std::string &varName="charClassesTable"

    return 0;
}

*/


#if defined(UMBA_TOKENISER_TYPES_COMPACT)

    #if !defined(UMBA_CHAR_CLASS_UNDERLYING_COMPACT)
        #define UMBA_CHAR_CLASS_UNDERLYING_COMPACT
    #endif

#endif



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
    none             = UMBA_TOKENISER_CHARCLASS_NONE            ,
    nonprintable     = UMBA_TOKENISER_CHARCLASS_NONPRINTABLE    ,
    linefeed         = UMBA_TOKENISER_CHARCLASS_LINEFEED        ,
    space            = UMBA_TOKENISER_CHARCLASS_SPACE           ,
    tab              = UMBA_TOKENISER_CHARCLASS_TAB             ,
    open             = UMBA_TOKENISER_CHARCLASS_OPEN            , // Флаг для парных символов
    close            = UMBA_TOKENISER_CHARCLASS_CLOSE           , // Флаг для парных символов
    brace            = UMBA_TOKENISER_CHARCLASS_BRACE           ,
    quot             = UMBA_TOKENISER_CHARCLASS_QUOT            ,
    opchar           = UMBA_TOKENISER_CHARCLASS_OPCHAR          ,
    operator_char    = UMBA_TOKENISER_CHARCLASS_OPERATOR_CHAR   ,
    punctuation      = UMBA_TOKENISER_CHARCLASS_PUNCTUATION     ,
    digit            = UMBA_TOKENISER_CHARCLASS_DIGIT           ,
    alpha            = UMBA_TOKENISER_CHARCLASS_ALPHA           ,
    identifier       = UMBA_TOKENISER_CHARCLASS_IDENTIFIER      ,
    identifier_first = UMBA_TOKENISER_CHARCLASS_IDENTIFIER_FIRST,
    semialpha        = UMBA_TOKENISER_CHARCLASS_SEMIALPHA       , // Для символов, которые никуда не вошли, такие как @ # $
    escape           = UMBA_TOKENISER_CHARCLASS_ESCAPE            // Для символа '\', который везде используется как escape-символ
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
std::string enum_serialize_single_flag(CharClass f, const std::string &prefix=std::string())
{
    switch(f)
    {
        //case CharClass::none            : return std::string("none");
        case CharClass::nonprintable    : return prefix+std::string("nonprintable");
        case CharClass::linefeed        : return prefix+std::string("linefeed");
        case CharClass::space           : return prefix+std::string("space");
        case CharClass::tab             : return prefix+std::string("tab");
        case CharClass::quot            : return prefix+std::string("quot");
        case CharClass::brace           : return prefix+std::string("brace");
        case CharClass::open            : return prefix+std::string("open");
        case CharClass::close           : return prefix+std::string("close");
        case CharClass::opchar          : return prefix+std::string("opchar");
        //case CharClass::operator_char   : return prefix+std::string("operator_char");
        case CharClass::punctuation     : return prefix+std::string("punctuation");
        case CharClass::digit           : return prefix+std::string("digit");
        case CharClass::alpha           : return prefix+std::string("alpha");
        case CharClass::identifier      : return prefix+std::string("identifier");
        case CharClass::identifier_first: return prefix+std::string("identifier_first");
        case CharClass::semialpha       : return prefix+std::string("semialpha");
        case CharClass::escape          : return prefix+std::string("escape");
        default: return std::string("");
    }
}

//----------------------------------------------------------------------------
inline
std::string enum_serialize_flags(CharClass f, const std::string &prefix=std::string())
{
    char_class_underlying_uint_t fu = (char_class_underlying_uint_t)f;

    std::string res;

    char_class_underlying_uint_t flagBit = 1;
    for(; flagBit!=0; flagBit<<=1)
    {
        if (fu&flagBit)
        {
            std::string flagStr = enum_serialize_single_flag((CharClass)flagBit, prefix);
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

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// umba::tokeniser::generation::
namespace generation {

template< std::size_t N >
void setCharClassFlags( umba::tokeniser::CharClass (&charClasses)[N], char ch, umba::tokeniser::CharClass setClasses)
{
    std::size_t idx = umba::tokeniser::charToCharClassTableIndex(ch);
    if (idx>=N)
    {
        std::cerr << "Bad index" << std::endl;
        throw std::runtime_error("Bad index");
    }

    charClasses[idx] |= setClasses;
}

template< std::size_t N >
void setCharClassFlags( umba::tokeniser::CharClass (&charClasses)[N], const std::string &chars, umba::tokeniser::CharClass setClasses)
{
    for(auto ch : chars)
    {
        setCharClassFlags(charClasses, ch, setClasses);
    }
}

template< std::size_t N >
void setCharClassFlags( umba::tokeniser::CharClass (&charClasses)[N], char ch1, char ch2, umba::tokeniser::CharClass setClasses)
{
    for(auto ch=ch1; ch<=ch2; ++ch)
    {
        setCharClassFlags(charClasses, ch, setClasses);
    }
}

template< std::size_t N >
void setCharClassFlagsForBracePair( umba::tokeniser::CharClass (&charClasses)[N], const std::string &braceChars)
{
    if (braceChars.size()!=2)
    {
        std::cerr << "Braces def invalid size" << std::endl;
        throw std::runtime_error("Braces def invalid size");
    }

    setCharClassFlags(charClasses, braceChars[0], umba::tokeniser::CharClass::brace | umba::tokeniser::CharClass::open );
    setCharClassFlags(charClasses, braceChars[1], umba::tokeniser::CharClass::brace | umba::tokeniser::CharClass::close);
}


/*
Делаем таблицу, из которой получаем класс символа
Таблица - это 128 позиций на базоые ASCII-символы
Делаем это не вручную.
Таблица генерируется не константная, надо уметь менять её в рантайме - например,
чтобы управлять поведением символов $/@ в зависимости от контекста - то ли они могутт быть в идентификаторе, то ли нет

а) Имеем список операторов с названиями - "!==" -> "STRICT_NEQ"
   Все операторы разбираем посимвольно, для каждого символа ставим флаг CharClass::opchar

Всё, что меньше пробела - флаг nonprintable, а также 0x7F
[X] \r, \n - linefeed
[X] \t     - tab
[X] \r, \n, \t, ' ' - space

[X] в) кавычка, двойная кавычка, бэктик - quot
[X] г) Для {}()<>[] - расставляем флаги brace, open, close
[X] д) ! ? , . ( ) - punctuation (что ещё?) - можно добавлять/менять в рантайме
[X] е) A-Za-z - alpha, identifier, identifier_first
[X] ж) 0-9    - digit, identifier

*/

template< std::size_t N >
void generateCharClassTable( umba::tokeniser::CharClass (&charClasses)[N])
{
    for(std::size_t i=0; i!=N; ++i)
    {
        charClasses[i] = CharClass::none;
    }

    // pairs
    setCharClassFlagsForBracePair( charClasses, "{}");
    setCharClassFlagsForBracePair( charClasses, "()");
    setCharClassFlagsForBracePair( charClasses, "[]");
    setCharClassFlagsForBracePair( charClasses, "<>");

    // ranges
    setCharClassFlags( charClasses,   0,  31, umba::tokeniser::CharClass::nonprintable);
    setCharClassFlags( charClasses, '0', '9', umba::tokeniser::CharClass::digit | umba::tokeniser::CharClass::identifier );
    setCharClassFlags( charClasses, 'A', 'Z', umba::tokeniser::CharClass::alpha | umba::tokeniser::CharClass::identifier | umba::tokeniser::CharClass::identifier_first);
    setCharClassFlags( charClasses, 'a', 'z', umba::tokeniser::CharClass::alpha | umba::tokeniser::CharClass::identifier | umba::tokeniser::CharClass::identifier_first);

    // sets
    setCharClassFlags( charClasses, "!%&*+,-./:;<=>?^|~", umba::tokeniser::CharClass::operator_char);
    setCharClassFlags( charClasses, "\r\n"              , umba::tokeniser::CharClass::linefeed);
    setCharClassFlags( charClasses, "\t"                , umba::tokeniser::CharClass::tab);
    setCharClassFlags( charClasses, "\r\n\t "           , umba::tokeniser::CharClass::space);
    setCharClassFlags( charClasses, ".,!?()\"\'"        , umba::tokeniser::CharClass::punctuation);
    setCharClassFlags( charClasses, "\"\'`"             , umba::tokeniser::CharClass::quot);
    setCharClassFlags( charClasses, "@#$"               , umba::tokeniser::CharClass::semialpha);

    // setCharClassFlags( charClasses, "", umba::tokeniser::CharClass::);
    // setCharClassFlags( charClasses, "", umba::tokeniser::CharClass::);

    // single chars
    setCharClassFlags( charClasses,   0x7F, umba::tokeniser::CharClass::nonprintable); // DEL
    setCharClassFlags( charClasses,   '\\', umba::tokeniser::CharClass::escape);
    setCharClassFlags( charClasses,   '_' , umba::tokeniser::CharClass::identifier | umba::tokeniser::CharClass::identifier_first); // underscore

}


enum class CommentType
{
    cLike, cppLike
};


struct CommentPrinter
{
    CommentType commentType;

    CommentPrinter(CommentType ct) : commentType(ct)
    {
        std::cout << (commentType==CommentType::cLike ? "/*" : "//") << " ";
    }

    ~CommentPrinter()
    {
        if (commentType==CommentType::cLike)
             std::cout<<" */";
    }

    template<typename T>
    CommentPrinter& operator<<(const T &t)
    {
        std::cout << t;
    }
};


inline
std::string nsToPath(const std::string &ns)
{
    std::string res; res.reserve(ns.size());

    for(auto ch : ns)
    {
        if (ch==':')
        {
            if (res.empty() || res.back()!='/')
                res.append(1, '/');
        }
        else
        {
            res.append(1, ch);
        }
    }

    return res;
}

inline
std::string pathToNs(const std::string &p)
{
    std::string res; res.reserve(p.size());

    for(auto ch : p)
    {
        if (ch=='/' || ch=='\\')
            res.append(2, ':');
        else
            res.append(1, ch);
    }

    return res;
}

inline
std::string nameToDefine(std::string name)
{
    name = nsToPath(name);
    umba::string_plus::toupper(name);

    for(auto &ch : name)
    {
        if (umba::string_plus::is_alpha_upper(ch) || umba::string_plus::is_digit(ch))
            continue;
        if (ch=='|' || ch==' ')
            continue;
        ch = '_';
    }

    return name;
}


enum class ArrayType
{
    cLike, stdArray
};

enum class TypeNameType
{
    cLike, cppLike
};

inline
std::string transformName(const std::string &name, TypeNameType typeNameType)
{
    if (typeNameType==TypeNameType::cLike)
        return nameToDefine(name);
    return name;
}

// Можно напечатать, как массив, можно - как template<class T, std::size_t N> struct array;
// int varName[N] =
// std::array<int, N> varName = {1, 2, 3};.

template< std::size_t N >
void printCharClassArray( umba::tokeniser::CharClass (&charClasses)[N], CommentType commentType, ArrayType arrayType, TypeNameType typeNameType, const std::string &varName="charClassesTable")
{
    static const std::string charClassType = "umba::tokeniser::CharClass";

    if (arrayType==ArrayType::cLike)
    {
        std::cout << transformName(charClassType, typeNameType) << " " << varName << "[" << N << "] =\n";
    }
    else if (arrayType==ArrayType::stdArray)
    {
        std::cout << "std::array<" << transformName(charClassType, typeNameType) << ", " << N << "> " << varName << " =\n";
    }

    for(std::size_t idx=0; idx!=N; ++idx)
    {
        std::cout << (idx==0 ? "{ " : ", ") << transformName(enum_serialize_flags(charClasses[idx], charClassType+"::"), typeNameType) << "  ";
        if (idx>=32)
           CommentPrinter(commentType) << " '" << (char)idx << "'";
        else
           CommentPrinter(commentType) << " " << idx;

        std::cout << "\n";
    }

    std::cout << "};\n";

}




} // namespace generation



inline
umba::tokeniser::CharClass getCharClass(char ch)
{
    static
    #include "char_class_table.h.inc"

    std::size_t idx = (std::size_t)(unsigned char)ch;
    if (idx>=0x80u)
        idx = 0x7Fu;

    return charClassesTable[idx];
}




} // namespace tokeniser
} // namespace umba

