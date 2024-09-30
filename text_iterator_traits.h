#pragma once

#include "iterator.h"


//----------------------------------------------------------------------------
// umba::iterator::
namespace umba {
namespace iterator {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template< typename IteratorType >
struct TextIteratorTraits
{
    using iterator_type = IteratorType;

    static std::size_t symbolLength(iterator_type it)
    {
        return 1;
    }

}; // template< typename IteratorType > struct TextIteratorTraits

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template< typename CharType /* =char */
        , bool UtfIterator
        >
struct TextIteratorTraits< TextPositionCountingIterator<CharType, UtfIterator> >
{
    using iterator_type = TextPositionCountingIterator<CharType, UtfIterator>;

    static std::size_t symbolLength(const iterator_type &it)
    {
        return it.symbolLength();
    }
};



    // std::size_t symbolLength() const
    // {
    //     UMBA_ASSERT(!isEndIterator() && !isEndReached());
    //  
    //     char ch = m_pData[m_dataIndex];
    //     std::size_t numChars = getNumberOfCharsUtf(ch);
    //     if (!numChars)
    //          numChars = 1;
    //  
    //     for(std::size_t i=0; i!=numChars && !isEndReached(m_dataIndex+i); ++i)
    //     {
    //         if (!i)
    //             continue;
    //  
    //         if (!isNextCharUtf(ch))
    //             break;
    //     }
    //  
    //     return i;
    // }



//----------------------------------------------------------------------------

} // namespace iterator
} // namespace umba
// umba::iterator::

