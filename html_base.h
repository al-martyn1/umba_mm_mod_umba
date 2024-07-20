#pragma once


#include <iterator>
#include <string>
#include <iostream>
#include <type_traits>
#include <vector>
#include <stack>
#include <exception>
#include <stdexcept>

//
// #include <boost/container/static_vector.hpp>

#include "container.h"
//#include "filename.h"
#include "string_plus.h"


// 

//----------------------------------------------------------------------------

// umba::html::
namespace umba {
namespace html {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
enum class TagType
{
    invalid = -1,
    text    =  0,
    tag         ,  // <tag> open tag
    close       ,  // </tag> close tag
    empty          // <empty-tag/> - не содержит в себе вложенные тэги

};



//----------------------------------------------------------------------------
template<bool UseCaseIndependentNames = true>
struct HtmlTagT
{
    TagType                                       tagType   = TagType::invalid;
    std::string                                   name      ;
    std::string                                   text      ;
    std::unordered_map<std::string, std::string>  attributes;
    std::vector<HtmlTagT>                         childs    ;  // Content 

    constexpr
    static bool isCaseIndependent()
    {
        return UseCaseIndependentNames;
    }

    constexpr // Пусть будет, ведь tolower_copy не всегда вызывается
    static
    std::string prepareName(const std::string &n)
    {
        return isCaseIndependent() ? umba::string_plus::tolower_copy(n) : n;
    }

    constexpr
    static char isNameChar(char ch)
    {
        return (ch>='a' && ch<='z')
            || (ch>='A' && ch<='Z')
            || (ch>='0' && ch<='9')
            || (ch>='_' || ch=='-' || ch=='.' || ch==':')
               ;
    }

    constexpr
    static char isNameFirstChar(char ch)
    {
        return (ch>='a' && ch<='z')
            || (ch>='A' && ch<='Z')
            || (ch>='_' || ch=='-' || ch=='.' || ch==':')
               ;
    }

    void clear()
    {
        tagType = TagType::invalid;
        name      .clear();
        text      .clear();
        attributes.clear();
        childs    .clear();
    }

    void addAttr(const std::string &attrName, const std::string &attrVal)
    {
        if (attrName.empty())
            return;

        attributes[prepareName(attrName)] = attrVal;
    }

    bool isTag() const
    {
        return tagType!=TagType::invalid && tagType!=TagType::text && !name.empty();
    }

    bool isTag(const std::string &nameToCompare) const
    {
        if (!isTag())
            return false;

        return name == prepareName(nameToCompare);
    }

    bool isCloseTag() const
    {
        if (!isTag())
            return false;

        return tagType==TagType::close;
    }

    bool needCloseTag() const
    {
        if (!isTag())
            return false;

        return tagType==TagType::empty;
    }

    bool hasAttr(const std::string &attrName) const
    {
        return attributes.find(prepareName(attrName))!=attributes.end();
    }

    std::string getAttrValue(const std::string &attrName, const std::string &defVal=std::string()) const
    {
        auto it = attributes.find(prepareName(attrName));
        return it==attributes.end() ? defVal : it->second;
    }
    

}; // struct HtmlTag


using HtmlTag              = HtmlTagT<true>;
using HtmlTagCaseSensitive = HtmlTagT<false>;
using HtmlTagCaseSens      = HtmlTagCaseSensitive;


//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//! Разбирает одиночный HTML-тэг. Возвращает итератор, указывающий на конец последовательности, или на символ завершивший сканирование
/*!
   Если указывает на конец последовательности - неожиданное завершение тэга

   Возможные символы остановки:
   '>' - разбор завершен успешно
   '<' - неожиданно начался новый тэг - такое допустимо в маркдауне, например
   '/' - в закрывающем тэге однаружен второй символ '/', который начинает закрывать пустой тэг 
   
   Ничего другого пока вроде не должно появлятся.

   Первый обрабатываемый символ должен быть '<', иначе никакой обработки не начнётся.
   
   На этой базе можно строить какой-то более высокоуровневый разбор.

*/
template<char TagOpenChar='<', char TagCloseChar='>', typename IteratorType, typename HtmlTagType>
IteratorType parseSingleTag(HtmlTagType &parseTo, IteratorType b, IteratorType e)
{
    parseTo.clear();

    auto isWhiteSpace = [](char ch)
    {
        return ch==' ' || ch=='\r' || ch=='\n' || ch=='\t';
    };

    // Переехали в HtmlTag
    auto isNameChar      = [&](char ch) { return parseTo.isNameChar(ch);      };
    auto isNameFirstChar = [&](char ch) { return parseTo.isNameFirstChar(ch); };

    std::string attrName;
    std::string attrVal ;


    auto addAttribute = [&]()
    {
        parseTo.addAttr(attrName, attrVal);
        attrName.clear();
        attrVal .clear();
    };

    auto finalizeTag = [&]()
    {
        if (parseTo.name.empty())
        {
            parseTo.clear();
            return b;
        }

        addAttribute();

        //if (caseIndependent)
        parseTo.name = parseTo.prepareName(parseTo.name);

        return b;
    };

    auto finalizeEmptyTag = [&]()
    {
        if (parseTo.name.empty())
        {
            parseTo.clear();
            return b;
        }

        addAttribute();

        //if (caseIndependent)
        parseTo.name = parseTo.prepareName(parseTo.name);

        if (parseTo.tagType==TagType::close)
            return b; // Обнаружен символ '/', как в empty тэге - но у нас закрывающий тэг, такой символ был перед именем тэга (</tag/>) - это ошибка

        ++b;
        if (b==e)
            return b;

        if (*b==TagCloseChar) // Последовательность "/>" должна идти без пробела - надоело пробелы пропускать
            parseTo.tagType = TagType::empty; // нормальное закрытие empty тэга

        return b; // в любом случае - завершаемся, ошибка или нет, если норм, то тип тэга установлен на empty
    };



    if (b==e)
        return b;

    if (*b!=TagOpenChar)
        return b;

    ++b;

    while(b!=e && isWhiteSpace(*b)) ++b; // пропускаем возможные пробелы перед именем тэга

    if (b==e)
        return b;

    if (*b==TagOpenChar) // Неожиданое открытие другого тэга
        return b;

    if (*b=='/') // Закрывающий тэг
    {
        ++b;
        while(b!=e && isWhiteSpace(*b)) ++b; // пропускаем возможные пробелы перед именем тэга
        if (b==e)
            return b;

        parseTo.tagType = TagType::close;
    }
    else
    {
        parseTo.tagType = TagType::tag;
    }

    // Читаем имя тэга

    if (!isNameFirstChar(*b))
        return finalizeTag();

    parseTo.name.append(1, *b);
    ++b;
    if (b==e)
        return finalizeTag();


    for(; b!=e && isNameChar(*b); ++b)
        parseTo.name.append(1, *b);

    if (b==e)
        return finalizeTag();

    // считали имя тэга
    // тут мы ждём закрытия тэга, закрытия empty тэга, или начало имени атрибута

    while(b!=e)
    {
        while(b!=e && isWhiteSpace(*b)) ++b; // пропускаем возможные пробелы

        if (b==e)
            return finalizeTag();

        if (*b==TagCloseChar)
            return finalizeTag(); // нормальное закрытие - либо открывающего, либо закрывающего тэга. На вызывающей стороне проверят *b==TagCloseChar и убедятся, что всё хорошо

        if (*b==TagOpenChar)
            return finalizeTag(); // Неожиданое открытие другого тэга

        if (*b=='/') // возможно, это empty тэг - <tag/>
            return finalizeEmptyTag();

        if (!isNameFirstChar(*b))
            return finalizeTag(); // Ожидаем первый символ имени атрибута, но получили какую-то фигню

        if (parseTo.tagType==TagType::close) // закрывающий тэг
            return finalizeTag(); //  В закрывающем тэге не должно быть никаких атрибутов

        // Таки атрибут
        attrName.clear();
        attrVal .clear();
        attrName.append(1, *b);
        ++b;

        // Первый символ атрибута уже добавлен
        if (b==e)
            return finalizeTag();

        for(; b!=e && isNameChar(*b); ++b) // собираем имя атрибута
            attrName.append(1, *b);

        if (b==e)
            return finalizeTag();

        // ждём символ равно '=' перед значением атрибута
        while(b!=e && isWhiteSpace(*b)) ++b; // пропускаем возможные пробелы
        if (b==e)
            return finalizeTag(); // символ равно '=' не дождались

        if (*b=='/')
            return finalizeEmptyTag();

        if (*b!='=')
            return finalizeTag();

        ++b;
        while(b!=e && isWhiteSpace(*b)) ++b; // пропускаем возможные пробелы

        // Значения у нас пока без кавычек, ибо лень. Надо будет - прикрутим
        for(; b!=e && !isWhiteSpace(*b) && *b!=TagCloseChar && *b!=TagOpenChar; ++b)
        {
            attrVal.append(1, *b);
        }

        addAttribute();
    }

    return b;

}

//----------------------------------------------------------------------------
template <typename StreamType>
bool testParseSingleTag(StreamType &s, const std::string &str, char expectedEndChar) // 'E' means end, not symbol 'E' itself
{
    HtmlTag parsedTag;

    auto resIt = parseSingleTag<'<', '>'>(parsedTag, str.begin(), str.end());

    char resChar = 'E';
    if (resIt!=str.end())
        resChar = *resIt;

    bool bPassed = resChar==expectedEndChar;

    s << "\n";
    s << (bPassed?"+":"-") << " " << "{" << str << "}, ends with: '" << std::string(1, resChar) << "'";
    if (!bPassed)
    {
        s << ", expected: '" << std::string(1, expectedEndChar);
    }
    s << "\n";

    s << "Tag type: ";
    switch(parsedTag.tagType)
    {
        case TagType::invalid:
            s << "<INVALID>";
            break;

        case TagType::text:
            s << "Text";
            break;

        case TagType::tag:
            s << "Tag (open tag)";
            break;

        case TagType::close:
            s << "End tag (close tag)";
            break;

        case TagType::empty:
            s << "Empty tag (<tag/>)";
            break;
    }
    s << "\n";

    s << "Tag name: " << (parsedTag.name.empty() ? std::string("<EMPTY>") : parsedTag.name) << "\n";
    if (!parsedTag.attributes.empty())
    {
        s << "Attrs:\n";
        for(const auto &akv: parsedTag.attributes)
        {
            s << "    " << akv.first << "=" << (akv.second.empty() ? std::string("<EMPTY>") : akv.second) << "\n";
        }
    }

    return bPassed;
}



//----------------------------------------------------------------------------

} // namespace html
} // namespace umba



