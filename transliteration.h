#pragma once

#include "utf8.h"

//
#include <unordered_map>


#define UMBA_TRANSLITERTION_IMPLEMENT_GET_TRANSLIT_MAP(whichMap)                            \
                                                                                            \
            inline                                                                          \
            const std::unordered_map<std::string, std::string>& get##whichMap()             \
            {                                                                               \
                static std::unordered_map<std::string, std::string> m = make##whichMap();   \
                return m;                                                                   \
            }


namespace umba {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline
void mergeTransliterationMaps(std::unordered_map<std::string, std::string> &mergeTo, const std::unordered_map<std::string, std::string> &mergeFrom)
{
    std::unordered_map<std::string, std::string>::const_iterator it = mergeFrom.begin();
    for(; it!=mergeFrom.end(); ++it)
    {
        mergeTo[it->first] = it->second;
    }
}

//----------------------------------------------------------------------------
inline
std::unordered_map<std::string, std::string> mergeTransliterationMaps(const std::vector< std::unordered_map<std::string, std::string> > &maps)
{
    std::unordered_map<std::string, std::string> resMap;

    if (maps.empty())
        return resMap;

    std::vector< std::unordered_map<std::string, std::string> >::const_iterator it = maps.begin();
    resMap = *it;

    for(++it; it!=maps.end(); ++it)
    {
        mergeTransliterationMaps(resMap, *it);
    }

    return resMap;
}

//----------------------------------------------------------------------------
//! Транслитерация руссского абы как, из вики, что показалось более привычным, не по каким-то стандартам
inline
std::unordered_map<std::string, std::string> makeTransliterationMapUtf8_ru()
{
    std::unordered_map<std::string, std::string> m;

    // Транслитерация русского алфавита латиницей - https://ru.wikipedia.org/wiki/%D0%A2%D1%80%D0%B0%D0%BD%D1%81%D0%BB%D0%B8%D1%82%D0%B5%D1%80%D0%B0%D1%86%D0%B8%D1%8F_%D1%80%D1%83%D1%81%D1%81%D0%BA%D0%BE%D0%B3%D0%BE_%D0%B0%D0%BB%D1%84%D0%B0%D0%B2%D0%B8%D1%82%D0%B0_%D0%BB%D0%B0%D1%82%D0%B8%D0%BD%D0%B8%D1%86%D0%B5%D0%B9

    m["А"] = "A";    m["а"] = "a";        m["З"] = "Z";    m["з"] = "z";
    m["Б"] = "B";    m["б"] = "b";        m["И"] = "I";    m["и"] = "i";
    m["В"] = "V";    m["в"] = "v";        m["Й"] = "Y";    m["й"] = "y";
    m["Г"] = "G";    m["г"] = "g";        m["К"] = "K";    m["к"] = "k";
    m["Д"] = "D";    m["д"] = "d";        m["Л"] = "L";    m["л"] = "l";
    m["Е"] = "E";    m["е"] = "e";        m["М"] = "M";    m["м"] = "m";
    m["Ё"] = "Yo";   m["ё"] = "yo";       m["Н"] = "N";    m["н"] = "n";
    m["Ж"] = "Zh";   m["ж"] = "zh";       m["О"] = "O";    m["о"] = "o";

    m["П"] = "P";    m["п"] = "p";        m["Ч"] = "Ch";   m["ч"] = "ch";  
    m["Р"] = "R";    m["р"] = "r";        m["Ш"] = "Sh";   m["ш"] = "sh";  
    m["С"] = "S";    m["с"] = "s";        m["Щ"] = "Shch"; m["щ"] = "shch";
    m["Т"] = "T";    m["т"] = "t";        m["Ъ"] = "\"";   m["ъ"] = "\"";  
    m["У"] = "U";    m["у"] = "u";        m["Ы"] = "Y";    m["ы"] = "Y";   
    m["Ф"] = "F";    m["ф"] = "f";        m["Ь"] = "'";    m["ь"] = "'";   
    m["Х"] = "Kh";   m["х"] = "kh";       m["Э"] = "E";    m["э"] = "e";   
    m["Ц"] = "Ts";   m["ц"] = "ts";       m["Ю"] = "Yu";   m["ю"] = "yu";  

    m["Я"] = "Ya";   m["я"] = "ya";

    // m[""] = "";

    return m;
}

//----------------------------------------------------------------------------
//! Для генерации ID для гитхаба
inline
std::unordered_map<std::string, std::string> makeLowercaseMapUtf8_ru()
{
    std::unordered_map<std::string, std::string> m;

    m["А"] = "а";    m["З"] = "з";    m["П"] = "п";    m["Ч"] = "ч";
    m["Б"] = "б";    m["И"] = "и";    m["Р"] = "р";    m["Ш"] = "ш";
    m["В"] = "в";    m["Й"] = "й";    m["С"] = "с";    m["Щ"] = "щ";
    m["Г"] = "г";    m["К"] = "к";    m["Т"] = "т";    m["Ъ"] = "ъ";
    m["Д"] = "д";    m["Л"] = "л";    m["У"] = "у";    m["Ы"] = "ы";
    m["Е"] = "е";    m["М"] = "м";    m["Ф"] = "ф";    m["Ь"] = "ь";
    m["Ё"] = "ё";    m["Н"] = "н";    m["Х"] = "х";    m["Э"] = "э";
    m["Ж"] = "ж";    m["О"] = "о";    m["Ц"] = "ц";    m["Ю"] = "ю";    m["Я"] = "я";

    return m;
}

//----------------------------------------------------------------------------
UMBA_TRANSLITERTION_IMPLEMENT_GET_TRANSLIT_MAP(TransliterationMapUtf8_ru)
UMBA_TRANSLITERTION_IMPLEMENT_GET_TRANSLIT_MAP(LowercaseMapUtf8_ru)

//----------------------------------------------------------------------------
inline
std::string transliterateEx( const std::string &str
                           , const std::unordered_map<std::string, std::string> &m
                           , char replaceChar = 0
                           )
{
    //const std::unordered_map<std::string, std::string> &m = getTransliterationMapUtf8();

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
            if (replaceChar!=0) // либо заменяем, либо пропускаем
            {
                resStr.append(curUtfSymbol);
            }
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
std::string transliterateEx( const std::string &str
                           , const std::vector< std::unordered_map<std::string, std::string> > &mv
                           , char replaceChar = 0
                           )
{
    return transliterateEx(str, mergeTransliterationMaps(mv), replaceChar );
}

//----------------------------------------------------------------------------
inline
std::string transliterate( const std::string &str )
{
    return transliterateEx( str
                          , std::vector< std::unordered_map<std::string, std::string> >{ getTransliterationMapUtf8_ru()
                                                                                       }
                          );
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------

} // namespace umba



