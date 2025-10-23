/*! \file
    \brief Абстрактное полностью квалифицированное имя
 */


#include "umba/rule_of_five.h"

//
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iterator>

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

    using StringType      = StringTypeT;
    using string_type     = StringTypeT;


    using iterator        = typename std::vector<StringType>::iterator       ;
    using const_iterator  = typename std::vector<StringType>::const_iterator ;
    using reference       = typename std::vector<StringType>::reference      ;
    using const_reference = typename std::vector<StringType>::const_reference;


protected: // fields

    // static inline std::string namespaceSeparator = "::"; // Можно переопределять, но только глобально


protected: // fields

    //FullQualifiedNameFlags     flags = FullQualifiedNameFlags::none; // absolute
    std::vector<StringType>   name; 
    Scheme                    scheme = Scheme::relative;

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
    {}

    FullQualifiedName(Scheme sch, std::initializer_list<StringType> pathParts)
    : name(pathParts.begin(), pathParts.end())
    , scheme(sch)
    {}

    FullQualifiedName(std::initializer_list<StringType> pathParts)
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
        name.erase(b, std::next(b, nItems));

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

    void push_back(const StringType &n)     { name.push_back(n); }
    void append(const StringType &n)        { name.push_back(n); }
    void append(const FullQualifiedName &n)
    {
        if (n.isAbsolute())
            throw std::runtime_error("umba::types::FullQualifiedName::append: can't append absolute name");

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

