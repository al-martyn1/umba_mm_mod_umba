#pragma once

#include "text_position_info.h"
#include "assert.h"

//
#include <iterator>
#include <string>
#include <string_view>


//----------------------------------------------------------------------------
// umba::iterator::
namespace umba {
namespace iterator {

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// SimpleInputIterator - https://en.cppreference.com/w/cpp/iterator/input_iterator
// SimpleForwardIterator - https://en.cppreference.com/w/cpp/iterator/forward_iterator
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename CharType=char>
class TextPositionCountingIterator;

template<typename CharT, typename Traits=std::char_traits<CharT> >
std::basic_string_view<CharT, Traits> makeStringView(const TextPositionCountingIterator<CharT> &b, const TextPositionCountingIterator<CharT> &e);

template<typename CharT, typename Traits=std::char_traits<CharT>, typename Allocator=std::allocator<CharT> >
std::basic_string<CharT, Traits, Allocator> makeString(const TextPositionCountingIterator<CharT> &b, const TextPositionCountingIterator<CharT> &e);

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
/* Поддерживаемые переводы строки
   \r, \n, \r\n
   В последнем варианте инкремент перепрыгнет через \n
 */

template<typename CharType /* =char */ >
class TextPositionCountingIterator
{

    using ThisClass = TextPositionCountingIterator;

public:

    using difference_type = std::ptrdiff_t;
    using value_type = CharType;


protected:


    // Думал сделать возможность использования со скользящим окном, чтобы уметь читать большие файлы порцайками, но потом решил, что пока это не нужно
    // И ещё - string_view нельзя будет из этого делать для фрагментов текста
    // Да и файлы, которые предполагается обрабатывать, будут иметь разумный размер
    // Потом может что-то замучу, но там будет посложнее
    // const char*   viewBase  ;
    // const char*   viewSize  ;
    // std::size_t   baseOffset; // смещение

    const CharType*     m_pData     = 0;
    std::size_t         m_dataSize  = 0;
    std::size_t         m_dataIndex = 0;

    TextPositionInfo    m_positionInfo;


    template<typename CharT, typename Traits /* =std::char_traits<CharT> */ >
    friend std::basic_string_view<CharT, Traits> makeStringView(const TextPositionCountingIterator<CharT> &b, const TextPositionCountingIterator<CharT> &e);

    template<typename CharT, typename Traits /* =std::char_traits<CharT> */, typename Allocator /* =std::allocator<CharT> */ >
    friend std::basic_string<CharT, Traits, Allocator> makeString(const TextPositionCountingIterator<CharT> &b, const TextPositionCountingIterator<CharT> &e);


    const CharType* getRawValueTypePointer() const
    {
        UMBA_ASSERT(!isEndIterator());
        return m_pData + m_dataIndex; // Может выходить за пределы m_dataSize, это нормально.
    }


    bool isEndReached() const
    {
        return m_dataIndex>=m_dataSize;
    }

    bool isEndIterator() const
    {
        return m_pData==0;
    }


    bool equalImpl(const ThisClass &other) const
    {
        if (isEndIterator()==other.isEndIterator()) // Оба итератора либо End, либо не End
        {
            if (isEndIterator())
            {
                return true; // Два end итератора равны
            }
            else
            {
                // Сравниваем почленно
                return m_pData     == other.m_pData    &&
                       m_dataSize  == other.m_dataSize &&
                       m_dataIndex == other.m_dataIndex;
            }
        }

        // У нас один итератор End, другой не End, но мы не знаем какой

        if (isEndIterator())
            return other.equalImpl(*this); // end итератор, если он есть в паре (*this, other), должен быть всегда other

        // this - гарантированно не End итератор, other - гарантированно End итератор

        if (isEndReached()) // Достигли конца входной последовательности, и теперь мы равны End итератору
        {
            return true;
        }

        return false;
    }

    void incrementImpl()
    {
        UMBA_ASSERT(!isEndIterator() && !isEndReached());

        char ch = m_pData[m_dataIndex];
        bool isCr = ch==(CharType)'\r';
        bool isLf = ch==(CharType)'\n';
        if (isCr || isLf)
        {
            ++m_dataIndex;
            if (!isEndReached())
            {
                // До конца не дошли, надо проверить на CRLF
                if (isCr && m_pData[m_dataIndex]==(CharType)'\n')
                    ++m_dataIndex; // Пропускаем LF, который идёт за CR
            }

            m_positionInfo.lineOffset   = m_dataIndex;
            m_positionInfo.symbolOffset = 0;
            ++m_positionInfo.lineNumber;
            return;
        }

        ++m_dataIndex;
    }


public:

    TextPositionCountingIterator() = default;
    explicit TextPositionCountingIterator(const CharType* pData, std::size_t dataSize, TextPositionInfo::file_id_type fileId=0u)
    : m_pData(pData), m_dataSize(dataSize), m_dataIndex(0)
    {
        textPositionInfoInit(m_positionInfo, fileId);
    }


    template<typename CharT, typename Traits=std::char_traits<CharT>, class Allocator=std::allocator<CharT> >
    explicit TextPositionCountingIterator( typename std::basic_string<CharT, Traits, Allocator>::const_iterator b
                                         , typename std::basic_string<CharT, Traits, Allocator>::const_iterator e
                                         , TextPositionInfo::file_id_type fileId=0u
                                         )
    : m_pData(0), m_dataSize(0), m_dataIndex(0)
    {
        m_pData = &*b;
        m_dataSize = (std::size_t)std::distance(b, e);
        textPositionInfoInit(m_positionInfo, fileId);
    }

    TextPositionCountingIterator(const TextPositionCountingIterator&) = default;
    TextPositionCountingIterator& operator=(const TextPositionCountingIterator&) = default;
    TextPositionCountingIterator(TextPositionCountingIterator&&) = default;
    TextPositionCountingIterator& operator=(TextPositionCountingIterator&&) = default;

    CharType operator*() const
    {
       UMBA_ASSERT(!isEndIterator() && !isEndReached());
       return m_pData[m_dataIndex];
    }

    bool operator==(const ThisClass &other) const
    {
        return equalImpl(other);
    }

    bool operator!=(const ThisClass &other) const
    {
        return !equalImpl(other);
    }

    TextPositionCountingIterator& operator++()
    {
        incrementImpl();
        return *this;
    }

    TextPositionCountingIterator operator++(int)
    {
        auto res = *this;
        incrementImpl();
        return res;
    }

    TextPositionInfo getPosition() const
    {
        // Положение в строке мы не вычисляем каждый раз при инкременте итератора, а только тогда, когда у нас запрашивают позиции
        TextPositionInfo resPos = m_positionInfo;
        resPos.symbolOffset = (TextPositionInfo::symbol_offset_type)(m_dataIndex - m_positionInfo.lineOffset);
        return resPos;
    }

};

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename CharType>
TextPositionCountingIterator<CharType> operator+( const TextPositionCountingIterator<CharType> &it
                                                , typename TextPositionCountingIterator<CharType>::difference_type diff
                                                )
{
    UMBA_ASSERT(diff>=0);
    auto itCopy = it;
    while(diff--)
        ++itCopy;
    return itCopy;
}

//----------------------------------------------------------------------------
template<typename CharType>
TextPositionCountingIterator<CharType> operator+( typename TextPositionCountingIterator<CharType>::difference_type diff
                                                , const TextPositionCountingIterator<CharType> &it
                                                )
{
    UMBA_ASSERT(diff>=0);
    auto itCopy = it;
    while(diff--)
        ++itCopy;
    return itCopy;
}

//----------------------------------------------------------------------------
template<typename CharType>
TextPositionCountingIterator<CharType>& operator+=( TextPositionCountingIterator<CharType> &it
                                                  , typename TextPositionCountingIterator<CharType>::difference_type diff
                                                  )
{
    UMBA_ASSERT(diff>=0);
    while(diff--)
        ++it;
    return it;
}

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
template<typename CharT, typename Traits /* =std::char_traits<CharT> */ >
std::basic_string_view<CharT, Traits> makeStringView(const TextPositionCountingIterator<CharT> &b, const TextPositionCountingIterator<CharT> &e)
{
    auto pb   = b.getRawValueTypePointer();
    auto pe   = e.getRawValueTypePointer();
    auto dist = (std::size_t)std::distance(pb, pe);
    return std::basic_string_view<CharT, Traits>(pb, dist);
}

template<typename CharT, typename Traits /* =std::char_traits<CharT> */, typename Allocator /* =std::allocator<CharT> */ >
std::basic_string<CharT, Traits, Allocator> makeString(const TextPositionCountingIterator<CharT> &b, const TextPositionCountingIterator<CharT> &e)
{
    auto pb   = b.getRawValueTypePointer();
    auto pe   = e.getRawValueTypePointer();
    auto dist = (std::size_t)std::distance(pb, pe);
    return std::basic_string<CharT, Traits, Allocator>(pb, dist);
}




//----------------------------------------------------------------------------

} // namespace iterator
} // namespace umba
// umba::iterator::

