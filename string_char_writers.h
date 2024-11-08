#pragma once


#pragma once


#include "i_char_writer.h"

#if !defined(UMBA_MCU_USED)
    #include <string>
#endif


namespace umba
{

//-----------------------------------------------------------------------------
#if !defined(UMBA_MCU_USED)

//-----------------------------------------------------------------------------
//! Реализация CharWriter, производящая вывод в строку std::string по заданной ссылке
struct StringRefCharWriter : UMBA_IMPLEMENTS ICharWriter
{

    //UMBA_NON_COPYABLE_STRUCT(StringRefCharWriter)

    //! Конструктор, принимающий ссылку на строку-буфер
    StringRefCharWriter(std::string &buf) : m_buf(buf) {}

    //! Запись одного символа
    virtual
    void writeChar( char ch  //!< Символ для записи
                  ) override
    {
        m_buf.append(1,ch);
    }

    //! Запись заданного буфера
    virtual
    void writeBuf( const uint8_t* pBuf //!< Указатель на записываемый буфер
                 , size_t len          //!< Количество символов для записи
                 ) override
    {
        m_buf.append( (const std::string::value_type*)pBuf, len );
    }

    //! Запись ASCII-Z строки
    virtual
    void writeString( const char* str //!< Указатель на ASCII-Z строку
                    ) override
    {
        m_buf.append( (const std::string::value_type*)str );
    }

    //! Реализация flush - сброс кешированных данных
    virtual
    void flush() override {}

    //-------

    //! Совместимый по интерфейсу с std::stringstream  метод, возвращающий строку
    const std::string& str() const
    {
        return m_buf;
    }

    //! Возвращает ASCII-Z указатель на строку. Совместимый по интерфейсу с std::string метод
    const std::string::value_type* c_str() const
    {
        return m_buf.c_str();
    }

    //! Возвращает указатель на данные строки (без гарантии замершающего нуля). Совместимый по интерфейсу с std::string метод
    const std::string::value_type* data() const
    {
        return m_buf.data();
    }

    //! Возвращает размер строки. Совместимый по интерфейсу с std::string метод
    std::string::size_type size() const
    {
        return m_buf.size();
    }

    //! Возвращает true для пустой строки. Совместимый по интерфейсу с std::string метод
    bool empty() const
    {
        return m_buf.empty();
    }


protected:

    std::string &m_buf;  //!< Ссылка на строку, в которую производится фактическая запись

}; // class StringRefCharWriter

//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
//! Реализация CharWriter, производящая вывод в собственный строковый std::string буфер
struct StringCharWriter : UMBA_IMPLEMENTS ICharWriter
{

    //UMBA_NON_COPYABLE_STRUCT(StringCharWriter)

    //! Конструктор
    StringCharWriter() : m_buf() {}

    //-------

    //! Запись одного символа
    virtual
    void writeChar( char ch  //!< Символ для записи
                  ) override
    {
        m_buf.append(1,ch);
    }

    //! Запись заданного буфера
    virtual
    void writeBuf( const uint8_t* pBuf  //!< Указатель на записываемый буфер
                 , size_t len           //!< Количество символов для записи
                 ) override
    {
        m_buf.append( (const std::string::value_type*)pBuf, len );
    }

    //! Запись ASCII-Z строки
    virtual
    void writeString( const char* str ) override
    {
        m_buf.append( (const std::string::value_type*)str );
    }

    //! Реализация flush - сброс кешированных данных
    virtual
    void flush() override {}

    //-------

    //! Совместимый по интерфейсу с std::stringstream метод, возвращающий строку
    const std::string& str() const
    {
        return m_buf;
    }

    //! Возвращает ASCII-Z указатель на строку. Совместимый по интерфейсу с std::string метод
    const std::string::value_type* c_str() const
    {
        return m_buf.c_str();
    }

    //! Возвращает указатель на данные строки (без гарантии замершающего нуля). Совместимый по интерфейсу с std::string метод
    const std::string::value_type* data() const
    {
        return m_buf.data();
    }

    //! Возвращает размер строки. Совместимый по интерфейсу с std::string метод
    std::string::size_type size() const
    {
        return m_buf.size();
    }

    //! Возвращает true для пустой строки. Совместимый по интерфейсу с std::string метод
    bool empty() const
    {
        return m_buf.empty();
    }

protected:

    std::string m_buf; //!< Строка-буфер

}; // class StringCharWriter

#endif // UMBA_MCU_USED

} // namespace umba

