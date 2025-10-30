/*! \file
    \brief Абстрактное полностью квалифицированное имя
 */


#include "umba/rule_of_five.h"

//
#include <algorithm>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iterator>
#include <utility>

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// umba::types::
namespace umba {
namespace types {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename StringTypeT>
struct FullQualifiedName
{

public: // types

    enum class Scheme // Addressing Scheme
    {
        relative,
        absolute
    };

    using StringType           = StringTypeT;
    using string_type          = StringTypeT;


    using iterator             = typename std::vector<StringType>::iterator       ;
    using const_iterator       = typename std::vector<StringType>::const_iterator ;
    using reference            = typename std::vector<StringType>::reference      ;
    using const_reference      = typename std::vector<StringType>::const_reference;

    using string_size_type     = typename StringType::size_type;
    using string_pos_len_type  = std::pair<string_size_type, string_size_type>;


protected: // fields

    // static inline std::string namespaceSeparator = "::"; // Можно переопределять, но только глобально


protected: // fields

    //FullQualifiedNameFlags     flags = FullQualifiedNameFlags::none; // absolute
    std::vector<StringType>   name; 
    Scheme                    scheme = Scheme::relative;

    static
    string_pos_len_type findPosLen( const StringType &str, const StringType &substr, string_size_type fromPos)
    {
        return string_pos_len_type{ str.find(substr, fromPos), substr.size() };
    }

    static
    string_pos_len_type findPosLen( const StringType &str, const std::vector<StringType> &substrs, string_size_type fromPos)
    {
        string_size_type foundPos = StringType::npos;
        string_size_type foundLen = StringType::npos;

        for(const auto substr : substrs)
        {
            string_size_type pos = str.find(substr, fromPos);
            if (pos==StringType::npos)
                continue;

            if (foundPos==StringType::npos)
            {
                foundPos = pos;
                foundLen = substr.size();
                continue;
            }

            if (pos<foundPos) // какой-то разделитель найден раньше, чем предыдущий найдёныш
            {
                foundPos = pos;
                foundLen = substr.size();
            }
        }

        return string_pos_len_type{foundPos, foundLen};
    }

    static
    std::vector<StringType> sortPathSeparators(std::vector<StringType> &&seps)
    {
        std::stable_sort( seps.begin(), seps.end()
                        , [](const auto& s1, const auto& s2)
                          {
                              return s1.size() > s2.size();
                          }
                        );
        return seps;
    }

    void assignBySplitPath(const StringType &p, const StringType &sep)
    {
        name.clear();
        scheme = Scheme::relative;

        string_pos_len_type posLenPrev = {0,0};
        while(true)
        {
            string_pos_len_type posLenNext = findPosLen( p, sep, posLenPrev.first+posLenPrev.second);

            if (posLenNext.first==0)
                scheme = Scheme::absolute;

            if (posLenNext.first==StringType::npos)
            {
                auto startPos = posLenPrev.first+posLenPrev.second;
                if (startPos<=p.size())
                {
                    name.emplace_back(p, startPos, p.size()-startPos);
                }
                return;
            }
            else
            {
                auto startPos = posLenPrev.first+posLenPrev.second;
                if (startPos!=posLenNext.first)
                    name.emplace_back(p, startPos, posLenNext.first-startPos);
                posLenPrev = posLenNext;
            }
        }
    }

    void assignBySplitPath(const StringType &p, std::vector<StringType> seps)
    {
        name.clear();
        scheme = Scheme::relative;

        seps = sortPathSeparators(std::move(seps));

        string_pos_len_type posLenPrev = {0,0};
        while(true)
        {
            string_pos_len_type posLenNext = findPosLen( p, seps, posLenPrev.first+posLenPrev.second);

            if (posLenNext.first==0)
                scheme = Scheme::absolute;

            if (posLenNext.first==StringType::npos)
            {
                auto startPos = posLenPrev.first+posLenPrev.second;
                if (startPos<=p.size())
                {
                    name.emplace_back(p, startPos, p.size()-startPos);
                }
                return;
            }
            else
            {
                auto startPos = posLenPrev.first+posLenPrev.second;
                if (startPos!=posLenNext.first)
                    name.emplace_back(p, startPos, posLenNext.first-startPos);
                posLenPrev = posLenNext;
            }
        }
    }

    void checkRemoveLasteEmptyPart()
    {
        if (!name.empty() && name.back().empty())
            name.pop_back();
    }


public: // ctors

    UMBA_RULE_OF_FIVE(FullQualifiedName, default, default, default, default, default);

    FullQualifiedName(Scheme sch)
    : name()
    , scheme(sch)
    {}

    FullQualifiedName(Scheme sch, const StringType &p1)
    : name(1, p1)
    , scheme(sch)
    {}

    FullQualifiedName(const StringType &p1)
    : name(1, p1)
    , scheme(Scheme::relative)
    {}

    FullQualifiedName(const StringType &p, const StringType &sep)
    {
        assignBySplitPath(p, sep);
    }

    FullQualifiedName(const StringType &p, const std::vector<StringType> &seps)
    {
        assignBySplitPath(p, seps);
    }

    // FullQualifiedName(const StringType &p, const typename StringType::value_type *sep)
    // {
    //     assignBySplitPath(p, sep);
    // }
    //  
    // FullQualifiedName(const typename StringType::value_type *p, const typename StringType::value_type *sep)
    // {
    //     assignBySplitPath(p, sep);
    // }
    //  
    // FullQualifiedName(const typename StringType::value_type *p, const StringType &sep)
    // {
    //     assignBySplitPath(p, sep);
    // }


    FullQualifiedName(Scheme sch, std::initializer_list<StringType> pathParts)
    : name(pathParts.begin(), pathParts.end())
    , scheme(sch)
    {}

    FullQualifiedName(std::initializer_list<StringType> pathParts)
    : name(pathParts.begin(), pathParts.end())
    {}

    FullQualifiedName(Scheme sch, const std::vector<StringType> &pathParts)
    : name(pathParts.begin(), pathParts.end())
    , scheme(sch)
    {}

    FullQualifiedName(const std::vector<StringType> &pathParts)
    : name(pathParts.begin(), pathParts.end())
    {}


public: // methods

    std::size_t size() const  { return name.size(); }
    bool empty() const { return name.empty(); }

    // Не меняет scheme
    void clear() { name.clear(); }

    reference       front()       { return name.front(); }
    const_reference front() const { return name.front(); }
    reference       back()        { return name.back() ; }
    const_reference back() const  { return name.back() ; }

    iterator        begin()       { return name.begin (); }
    iterator        end  ()       { return name.end   (); }
    const_iterator  begin() const { return name.begin (); }
    const_iterator  end  () const { return name.end   (); }
    const_iterator cbegin() const { return name.cbegin(); }
    const_iterator cend  () const { return name.cend  (); }

    bool isAbsolute() const { return scheme == Scheme::absolute; }
    bool isRelative() const { return scheme == Scheme::relative; }

    FullQualifiedName& makeRelative() { scheme = Scheme::relative; return *this; }
    FullQualifiedName& makeAbsolute() { scheme = Scheme::absolute; return *this; }

    FullQualifiedName toRelative() const { auto res = *this; return res.makeRelative(); }
    FullQualifiedName toAbsolute() const { auto res = *this; return res.makeAbsolute(); }

    // Не меняет scheme
    FullQualifiedName& removeTail(std::size_t nItems=1u)
    {
        if (nItems==std::size_t(-1))
        {
            clear();
            return *this;
        }
    
        if (nItems>name.size())
            throw std::runtime_error("umba::types::FullQualifiedName::tailRemove: too many items to remove");
    
        for(std::size_t i=0; i!=nItems; ++i)
            name.pop_back();

        return *this;
    }

    // Также меняет схему на relative
    FullQualifiedName& removeHead(std::size_t nItems=1u)
    {
        if (nItems==std::size_t(-1))
        {
            clear();
            return makeRelative();
        }
    
        if (nItems>name.size())
            throw std::runtime_error("umba::types::FullQualifiedName::tailRemove: too many items to remove");

        auto b = name.begin();
        name.erase(b, std::next(b, std::ptrdiff_t(nItems)));

        return makeRelative();
    }

    // Возвращает хвост, удаляя голову. Также меняет схему на relative
    FullQualifiedName getTail() const
    {
        if (empty())
            throw std::runtime_error("umba::types::FullQualifiedName::getTail: can't get tail from empty name");

        auto res = *this;
        return res.removeHead(1);
    }

    // Возвращает голову (всё оставшееся), удаляя хвост (последний элемент). Не меняет scheme
    FullQualifiedName getHead   () const
    {
        if (empty())
            throw std::runtime_error("umba::types::FullQualifiedName::getHead: can't get head from empty name");
    
        auto res = *this;
        return res.removeTail(1);
    }

    void push_back(const StringType &n)     { checkRemoveLasteEmptyPart(); name.push_back(n); }
    void append(const StringType &n)        { checkRemoveLasteEmptyPart(); name.push_back(n); }
    void append(const FullQualifiedName &n)
    {
        if (n.isAbsolute())
            throw std::runtime_error("umba::types::FullQualifiedName::append: can't append absolute name");

        checkRemoveLasteEmptyPart();
        name.insert(name.end(), n.name.begin(), n.name.end());
    }

    StringType toString(const StringType &sep = StringType(1, typename StringType::value_type('/'))) const
    {
        if (empty())
            return StringType();

        if (sep.empty())
            throw std::runtime_error("umba::types::FullQualifiedName::toString: can't convert to string with empty name separator");

        std::size_t nameSummarySize = 0;
        for(const auto &n: name) nameSummarySize += n.size();

        StringType resStr;

        if (isAbsolute())
            resStr = sep;

        resStr.reserve(nameSummarySize + resStr.size() + (name.size()-1)*sep.size());

        auto it = name.begin();

        resStr.append(*it);

        for(++it; it!=name.end(); ++it)
        {
            resStr.append(sep);
            resStr.append(*it);
        }

        return resStr;
    }

    FullQualifiedName& operator+=(const StringType &n)        { append(n); return *this; }
    FullQualifiedName& operator/=(const StringType &n)        { append(n); return *this; }
    FullQualifiedName& operator+=(const FullQualifiedName &n) { append(n); return *this; }
    FullQualifiedName& operator/=(const FullQualifiedName &n) { append(n); return *this; }

    FullQualifiedName  operator+(const StringType &n)        { FullQualifiedName res = *this; res.append(n); return res; }
    FullQualifiedName  operator/(const StringType &n)        { FullQualifiedName res = *this; res.append(n); return res; }
    FullQualifiedName  operator+(const FullQualifiedName &n) { FullQualifiedName res = *this; res.append(n); return res; }
    FullQualifiedName  operator/(const FullQualifiedName &n) { FullQualifiedName res = *this; res.append(n); return res; }


}; // struct FullQualifiedName

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
} // namespace types
} // namespace umba
// umba::types::

