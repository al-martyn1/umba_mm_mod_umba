/*! \file
    \brief Ничего не делающий insert_iterator
*/

#include "umba.h"

namespace umba {


// UMBA_USED

struct null_insert_iterator
{

    template<typename ValueType> constexpr
    null_insert_iterator& operator=(const ValueType& value)
    {
        UMBA_USED(value);
        return *this;
    }

    template<typename ValueType> constexpr
    null_insert_iterator& operator=(ValueType&& value)
    {
        UMBA_USED(value);
        return *this;
    }

    null_insert_iterator& operator*()
    { return *this; }

    null_insert_iterator& operator++()
    { return *this; }

    null_insert_iterator operator++(int)
    { return *this; }

}; // class null_insert_iterator


template<typename ContainerType> inline
null_insert_iterator null_inserter(const ContainerType &c)
{
    UMBA_USED(c);
    return null_insert_iterator();
}

inline
null_insert_iterator null_inserter()
{
    return null_insert_iterator();
}


} // namespace umba


