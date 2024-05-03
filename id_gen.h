#pragma once

#include "transliteration.h"

namespace umba {


//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
inline
std::string generateIdFromText_generic(const std::string &t, char replaceChar)
{
    std::string transliterated = transliterate(t);

    std::string resText; resText.reserve(transliterated.size());

    for(char ch: transliterated)
    {
        if (ch>='a' && ch<='z')
        {
            resText.append(1u, ch);
        }
        else if (ch>='A' && ch<='Z')
        {
            resText.append(1u, ch-'A'+'a');
        }
        else if (ch>='0' && ch<='9')
        {
            resText.append(1u, ch);
        }
        else if (ch==' ' || ch=='-')
        {
            resText.append(1u, '-');
        }
        else
        {
            if (replaceChar!=0)
            {
                resText.append(1u, replaceChar); // иначе что-то незнакомое просто пропускаем, без замены
            }
        }
    }

    return resText;
}

//----------------------------------------------------------------------------
inline
std::string generateIdFromText_forDoxygen(const std::string &t, char replaceChar = '-')
{
    return generateIdFromText_generic(t, '-');
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
/*
    GitHub (ПшеРги) правила генерации идентификаторов

    1) Добавляется префикс "user-content-"
    2) Национальные символы переводятся в нижний регистр
    3) Пробел заменяется на минус ('-')
    4) Гитхаб просто пропускает некоторые символы:
       !, ", #, $
       %, &, ' (apos)
       (, ), *, +
       , (запятая)
       минус - это минус, добавляет
       . (точка)
       :, ;, <, =, >, ?
       @, [, \, ], ^
       _ (подчеркивание) - добавляет
       ` (бэктик)
       {|}
       ~

 */
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
inline
std::unordered_map<std::string, std::string> makeGitHubIdTranslationMapUtf8_ascii()
{
    std::unordered_map<std::string, std::string> m;

    m["-"] = "-";
    m[" "] = "-";
    m["_"] = "_";
    m["`"] = "-";

    return m;
}

UMBA_TRANSLITERTION_IMPLEMENT_GET_TRANSLIT_MAP(GitHubIdTranslationMapUtf8_ascii)
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
inline
std::string generateIdFromText_forGitHub(const std::string &t, const std::string &prefix="user-content-")
{
    //return generateIdFromText_generic(t, '-');

    // Никакого алгоритма не используем, тупо заменяем, что знаем, остальное - просто игнорим

    std::string transliterated = transliterateEx( t
                                                , std::vector< std::unordered_map<std::string, std::string> >{ getGitHubIdTranslationMapUtf8_ascii()
                                                                                                             , getLowercaseMapUtf8_ru()
                                                                                                             , getLowercaseMapUtf8_en()
                                                                                                             , getDigitsTranslationMapUtf8()
                                                                                                             //, get
                                                                                                             }
                                                , 0 // replaceChar - игнорим
                                                );
    return prefix+transliterated;
}



// inline
// std::string transliterateEx( const std::string &str, const std::unordered_map<std::string, std::string> &m )








// inline
// std::string generateIdFromTextGeneric(const std::string &t, char replaceChar = '-')
// {
//     std::string transliterated = transliterate(t);
//----------------------------------------------------------------------------





} // namespace umba





