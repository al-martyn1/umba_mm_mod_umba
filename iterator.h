#pragma once

#include "text_position_info.h"
#include "assert.h"
#include "utf.h"

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
template<typename CharType=char, bool UtfIterator=true>
class TextPositionCountingIterator;

template<typename CharT, typename Traits=std::char_traits<CharT>, bool UtfIterator=true >
std::basic_string_view<CharT, Traits> makeStringView(const TextPositionCountingIterator<CharT,UtfIterator> &b, const TextPositionCountingIterator<CharT,UtfIterator> &e);

template<typename CharT, typename Traits=std::char_traits<CharT>, typename Allocator=std::allocator<CharT>, bool UtfIterator=true >
std::basic_string<CharT, Traits, Allocator> makeString(const TextPositionCountingIterator<CharT,UtfIterator> &b, const TextPositionCountingIterator<CharT,UtfIterator> &e);

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
/* Поддерживаемые переводы строки
   \r, \n, \r\n
   В последнем варианте инкремент перепрыгнет через \n
 */

template< typename CharType /* =char */
        , bool UtfIterator
        >
class TextPositionCountingIterator
{

    using ThisClass = TextPositionCountingIterator;

public:

    using difference_type = std::ptrdiff_t;
    using value_type      = CharType;
    using pointer         = CharType*;
    using const_pointer   = const CharType*;

    constexpr const static bool utf_iterator = UtfIterator;


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


    template<typename CharT, typename Traits /* =std::char_traits<CharT> */, bool UtfIteratorT >
    friend std::basic_string_view<CharT, Traits> makeStringView(const TextPositionCountingIterator<CharT,UtfIteratorT> &b, const TextPositionCountingIterator<CharT,UtfIteratorT> &e);

    template<typename CharT, typename Traits /* =std::char_traits<CharT> */, typename Allocator /* =std::allocator<CharT> */, bool UtfIteratorT >
    friend std::basic_string<CharT, Traits, Allocator> makeString(const TextPositionCountingIterator<CharT,UtfIteratorT> &b, const TextPositionCountingIterator<CharT,UtfIteratorT> &e);


    const_pointer getRawValueTypePointer() const
    {
        UMBA_ASSERT(!isEndIterator());
        return m_pData + m_dataIndex; // Может выходить за пределы m_dataSize, это нормально.
    }

    operator const_pointer() const
    {
        return getRawValueTypePointer();
    }

    //!< Допустим, мы что-то парсим, и построчно сохраняем контекст парсинга, для того, чтобы можно был при изменении входных данных парсить только то, что изменилось (после точки/строки изменнения). При этом входной контейнер мог увеличиться и переаллоцироваться, и указатель в итераторе протухает. Надо сделать rebase
    void rebase(const CharType* pData)
    {
        UMBA_ASSERT(!isEndIterator());
        m_pData = pData;
    }


    bool isEndReached(std::size_t idx) const
    {
        return idx>=m_dataSize;
    }

    bool isEndReached() const
    {
        return isEndReached(m_dataIndex);
    }

    bool isEndIterator() const
    {
        return m_pData==0;
    }

    bool isBothEndIterators(const ThisClass &other) const
    {
        return (isEndIterator() && isEndIterator()==other.isEndIterator());
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

        if constexpr (UtfIterator)
        {
            std::size_t numChars = getNumberOfCharsUtf(ch);
            if (!numChars)
                 numChars = 1;
            for(std::size_t i=0; i!=numChars && !isEndReached(); ++i, ++m_dataIndex)
            {
                if (!i)
                    continue;

                if (!isNextCharUtf(ch))
                    break;
            }
        }
        else
        {
            ++m_dataIndex;
        }
    }

    // Возвращает длинну символа в CharType'ах
    std::size_t symbolLength() const
    {
        UMBA_ASSERT(!isEndIterator() && !isEndReached());

        char ch = m_pData[m_dataIndex];
        std::size_t numChars = getNumberOfCharsUtf(ch);
        if (!numChars)
             numChars = 1;

        std::size_t i = 0;

        for(; i!=numChars && !isEndReached(m_dataIndex+i); ++i)
        {
            if (!i)
                continue;

            if (!isNextCharUtf(ch))
                break;
        }

        return i;
    }

    std::size_t findNearestLinefeedIndex() const
    {
        for(std::size_t i=m_dataIndex; i!=m_dataSize; ++i)
        {
            char ch = m_pData[i];
            if (ch=='\n' || ch=='\r')
                return i;
        }

        return m_dataSize;
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

    difference_type distanceTo(const ThisClass &other) const
    {
        if (isEndIterator() && isEndIterator()==other.isEndIterator())
            return 0;

        UMBA_ASSERT(!isEndIterator());

        if (other.isEndIterator())
        {
            //return std::distance(*this, other);
            return m_dataSize-m_dataIndex;
        }

        return std::distance(getRawValueTypePointer(), other.getRawValueTypePointer());
    }

    // auto pb   = b.getRawValueTypePointer();
    // auto pe   = e.getRawValueTypePointer();
    // auto dist = (std::size_t)std::distance(pb, pe);
    // return std::basic_string_view<CharT, Traits>(pb, dist);



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



    TextPositionInfo getPosition(bool findLineLen=false) const // длина строки не всегда нужна, а только чтобы, например, вывести ошибочную строку при возникновении ошибки
    {
        // Положение в строке мы не вычисляем каждый раз при инкременте итератора, а только тогда, когда у нас запрашивают позиции
        TextPositionInfo resPos = m_positionInfo;
        resPos.symbolOffset = (TextPositionInfo::symbol_offset_type)(m_dataIndex - m_positionInfo.lineOffset);
        resPos.lineLen      = findLineLen ? (TextPositionInfo::symbol_offset_type)(findNearestLinefeedIndex() - m_positionInfo.lineOffset) : 0;
        return resPos;
    }

    TextPositionCountingIterator getLineStartIterator() const
    {
        TextPositionCountingIterator res = *this;
        res.m_dataIndex = m_positionInfo.lineOffset; // перемотали на начало строки
        return res;
    }

    TextPositionCountingIterator getLineEndIterator() const
    {
        TextPositionCountingIterator res = getLineStartIterator();
        res.m_dataIndex = res.findNearestLinefeedIndex(); // перемотали на конец строки
        return res;
    }

}; // class TextPositionCountingIterator

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename CharType, bool UtfIterator>
TextPositionCountingIterator<CharType> operator+( const TextPositionCountingIterator<CharType,UtfIterator> &it
                                                , typename TextPositionCountingIterator<CharType,UtfIterator>::difference_type diff
                                                )
{
    UMBA_ASSERT(diff>=0);
    auto itCopy = it;
    while(diff--)
        ++itCopy;
    return itCopy;
}

//----------------------------------------------------------------------------
template<typename CharType, bool UtfIterator>
TextPositionCountingIterator<CharType> operator+( typename TextPositionCountingIterator<CharType,UtfIterator>::difference_type diff
                                                , const TextPositionCountingIterator<CharType,UtfIterator> &it
                                                )
{
    UMBA_ASSERT(diff>=0);
    auto itCopy = it;
    while(diff--)
        ++itCopy;
    return itCopy;
}

//----------------------------------------------------------------------------
template<typename CharType, bool UtfIterator>
TextPositionCountingIterator<CharType>& operator+=( TextPositionCountingIterator<CharType,UtfIterator> &it
                                                  , typename TextPositionCountingIterator<CharType,UtfIterator>::difference_type diff
                                                  )
{
    UMBA_ASSERT(diff>=0);
    while(diff--)
        ++it;
    return it;
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
template<typename CharT, typename Traits /* =std::char_traits<CharT> */, bool UtfIterator >
std::basic_string_view<CharT, Traits> makeStringView(const TextPositionCountingIterator<CharT,UtfIterator> &b, const TextPositionCountingIterator<CharT,UtfIterator> &e)
{
    if (b.isBothEndIterators(e))
        return std::basic_string_view<CharT, Traits>();

    return std::basic_string_view<CharT, Traits>(b.getRawValueTypePointer(), b.distanceTo(e));
}

template<typename CharT, typename Traits /* =std::char_traits<CharT> */, typename Allocator /* =std::allocator<CharT> */, bool UtfIterator >
std::basic_string<CharT, Traits, Allocator> makeString(const TextPositionCountingIterator<CharT,UtfIterator> &b, const TextPositionCountingIterator<CharT,UtfIterator> &e)
{
    if (b.isBothEndIterators(e))
        return std::basic_string<CharT, Traits, Allocator>();

    return std::basic_string<CharT, Traits, Allocator>(b.getRawValueTypePointer(), b.distanceTo(e));
}

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

} // namespace iterator
} // namespace umba
// umba::iterator::

