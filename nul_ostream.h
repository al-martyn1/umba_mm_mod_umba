/*! \file
    \author Alexander Martynov (Marty AKA al-martyn1) <amart@mail.ru>
    \copyright (c) 2018-2026 Alexander Martynov
    \brief Пустопорожний Ostream, никуда ничего не выводит

    Repository: https://github.com/al-martyn1/umba
*/

#pragma once

// umba::
namespace umba{


class NulOstream
{

public:

    template<typename T>
    NulOstream& operator<<( const T & /* t */ ) { return *this; }

}; // class NulOstream


} // namespace umba
