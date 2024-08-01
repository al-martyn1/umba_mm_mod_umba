/*! \file
    \brief Ничего не делающий insert_iterator
*/

#include "umba.h"

namespace umba {


// UMBA_USED
template<typename ValueType>
struct null_insert_iterator
{

    using difference_type = std::ptrdiff_t;
    using value_type = ValueType;

    //template<typename ValueType>
    constexpr
    null_insert_iterator& operator=(const ValueType& value)
    {
        UMBA_USED(value);
        return *this;
    }

    template<typename OtherValueType>
    constexpr
    null_insert_iterator& operator=(OtherValueType&& value)
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
null_insert_iterator<typename ContainerType::value_type> null_inserter(const ContainerType &c)
{
    UMBA_USED(c);
    return null_insert_iterator<typename ContainerType::value_type>();
}

inline
null_insert_iterator<char> null_inserter()
{
    return null_insert_iterator<char>(); // нехай будет char, всё равно operator= шаблонный и нифига не делает
}


} // namespace umba


