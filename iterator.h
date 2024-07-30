#pragma once

#include "text_position_info.h"
#include "assert.h"

//
#include <iterator>


// umba::iterator::
namespace umba {
namespace iterator {


// struct SimpleInputIterator - https://en.cppreference.com/w/cpp/iterator/input_iterator

// Example
//
// A minimum input iterator.
//
// #include <cstddef>
// #include <iterator>
//
// struct SimpleInputIterator
// {
//     using difference_type = std::ptrdiff_t;
//     using value_type = int;
//
//     int operator*() const;
//
//     SimpleInputIterator& operator++();
//     void operator++(int) { ++*this; }
// };
//
// static_assert(std::input_iterator<SimpleInputIterator>);

// https://en.cppreference.com/w/cpp/iterator/forward_iterator
// #include <cstddef>
// #include <iterator>
//
// struct SimpleForwardIterator
// {
//     using difference_type = std::ptrdiff_t;
//     using value_type = int;
//
//     int operator*() const;
//
//     SimpleForwardIterator& operator++();
//
//     SimpleForwardIterator operator++(int)
//     {
//         auto tmp = *this;
//         ++*this;
//         return tmp;
//     }
//
//     bool operator==(const SimpleForwardIterator&) const;
// };
//
// static_assert(std::forward_iterator<SimpleForwardIterator>);




/* Поддерживаемые переводы строки
   \r, \n, \r\n
   В последнем варианте инкремент перепрыгнет через \n
 */


class TextPositionCountingIterator
{

    using ThisClass = TextPositionCountingIterator;

public:

    using difference_type = std::ptrdiff_t;
    using value_type = char;


protected:


    // Думал сделать возможность использования со скользящим окном, чтобы уметь читать большие файлы порцайками, но потом решил, что пока это не нужно
    // И ещё - string_view нельзя будет из этого делать для фрагментов текста
    // Да и файлы, которые предполагается обрабатывать, будут иметь разумный размер
    // const char*   viewBase  ;
    // const char*   viewSize  ;
    // std::size_t   baseOffset; // смещение

    const char*       m_pData     = 0;
    std::size_t       m_dataSize  = 0;
    std::size_t       m_dataIndex = 0;

    TextPositionInfo  m_positionInfo;

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
        bool isCr = ch=='\r';
        bool isLf = ch=='\n';
        if (isCr || isLf)
        {
            ++m_dataIndex;
            if (!isEndReached())
            {
                // До конца не дошли, надо проверить на CRLF
                if (isCr && m_pData[m_dataIndex]=='\n')
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
     explicit TextPositionCountingIterator(const char* pData, std::size_t dataSize)
     : m_pData(pData), m_dataSize(dataSize), m_dataIndex(0)
     {
         textPositionInfoInit(m_positionInfo);
     }
     explicit TextPositionCountingIterator(std::string::iterator b, std::string::iterator e)
     : m_pData(0), m_dataSize(0), m_dataIndex(0)
     {
         m_pData = &*b;
         m_dataSize = (std::size_t)std::distance(b, e);
         textPositionInfoInit(m_positionInfo);
     }

     TextPositionCountingIterator(const TextPositionCountingIterator&) = default;
     TextPositionCountingIterator& operator=(const TextPositionCountingIterator&) = default;
     TextPositionCountingIterator(TextPositionCountingIterator&&) = default;
     TextPositionCountingIterator& operator=(TextPositionCountingIterator&&) = default;

     char operator*() const
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

} // namespace iterator
} // namespace umba

