#pragma once

#include "utf8.h"

//
#include <unordered_map>


namespace umba {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline
std::unordered_map<std::string, std::string> makeTransliterationMapUtf8()
{
    std::unordered_map<std::string, std::string> m;

    // Транслитерация русского алфавита латиницей - https://ru.wikipedia.org/wiki/%D0%A2%D1%80%D0%B0%D0%BD%D1%81%D0%BB%D0%B8%D1%82%D0%B5%D1%80%D0%B0%D1%86%D0%B8%D1%8F_%D1%80%D1%83%D1%81%D1%81%D0%BA%D0%BE%D0%B3%D0%BE_%D0%B0%D0%BB%D1%84%D0%B0%D0%B2%D0%B8%D1%82%D0%B0_%D0%BB%D0%B0%D1%82%D0%B8%D0%BD%D0%B8%D1%86%D0%B5%D0%B9

    m["А"] = "A";
    m["а"] = "a";
    m["Б"] = "B";
    m["б"] = "b";
    m["В"] = "V";
    m["в"] = "v";
    m["Г"] = "G";
    m["г"] = "g";
    m["Д"] = "D";
    m["д"] = "d";
    m["Е"] = "E";
    m["е"] = "e";
    m["Ё"] = "Yo";
    m["ё"] = "yo";
    m["Ж"] = "Zh";
    m["ж"] = "zh";
    m["З"] = "Z";
    m["з"] = "z";
    m["И"] = "I";
    m["и"] = "i";
    m["Й"] = "Y";
    m["й"] = "y";
    m["К"] = "K";
    m["к"] = "k";
    m["Л"] = "L";
    m["л"] = "l";
    m["М"] = "M";
    m["м"] = "m";
    m["Н"] = "N";
    m["н"] = "n";
    m["О"] = "O";
    m["о"] = "o";
    m["П"] = "P";
    m["п"] = "p";
    m["Р"] = "R";
    m["р"] = "r";
    m["С"] = "S";
    m["с"] = "s";
    m["Т"] = "T";
    m["т"] = "t";
    m["У"] = "U";
    m["у"] = "u";
    m["Ф"] = "F";
    m["ф"] = "f";
    m["Х"] = "Kh";
    m["х"] = "kh";
    m["Ц"] = "Ts";
    m["ц"] = "ts";
    m["Ч"] = "Ch";
    m["ч"] = "ch";
    m["Ш"] = "Sh";
    m["ш"] = "sh";
    m["Щ"] = "Shch";
    m["щ"] = "shch";
    m["Ъ"] = "\"";
    m["ъ"] = "\"";
    m["Ы"] = "Y";
    m["ы"] = "Y";
    m["Ь"] = "'";
    m["ь"] = "'";
    m["Э"] = "E";
    m["э"] = "e";
    m["Ю"] = "Yu";
    m["ю"] = "yu";
    m["Я"] = "Ya";
    m["я"] = "ya";

    // m[""] = "";

    return m;
}

//----------------------------------------------------------------------------
inline
const std::unordered_map<std::string, std::string>& getTransliterationMapUtf8()
{
    static std::unordered_map<std::string, std::string> m = makeTransliterationMapUtf8();
    return m;
}

//----------------------------------------------------------------------------
inline
std::string transliterate( const std::string &str )
{
    const std::unordered_map<std::string, std::string> &m = getTransliterationMapUtf8();

    std::string resStr; resStr.reserve(str.size()/2u);

    std::size_t idx = 0;
    while(idx<str.size())
    {
        std::size_t nCharBytes = getNumberOfBytesUtf8(str[idx]);
        if (nCharBytes==0)
            break;

        std::size_t idxNext = idx+nCharBytes;
        if (idxNext>str.size())
            break;

        std::string curUtfSymbol = std::string(str, idx, idxNext-idx);
        std::unordered_map<std::string, std::string>::const_iterator it = m.find(curUtfSymbol);
        if (it==m.end())
        {
            resStr.append(curUtfSymbol);
        }
        else
        {
            resStr.append(it->second);
        }

        idx = idxNext;
    }

    return resStr;
}

//----------------------------------------------------------------------------
inline
std::string generateIdFromText(const std::string &t, char replaceChar = '-')
{
    std::string transliterated = transliterate(t);

    std::string resText; resText.reserve(transliterated.size());

    for(char ch: transliterated)
    {
        if (ch>='a' && ch<='z')
        {
            resText.append(1u, ch);
        }
        else if (ch>='A' && ch<='z')
        {
            resText.append(1u, ch-'A'+'a');
        }
        else if (ch>='0' && ch<='9')
        {
            resText.append(1u, ch);
        }
        else
        {
            resText.append(1u, replaceChar);
        }
    }

    return resText;
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------

} // namespace umba



