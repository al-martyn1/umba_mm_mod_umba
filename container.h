/*!
    \file
    \brief ������������� ����������. ����� �� boost (�� ��������� � �������), ��������, ����� ������ �� ���-�� �����������, �� ������, ��������, �� STD, ���� ��������
 */

#pragma once

//-----------------------------------------------------------------------------
#include "boost/container/options.hpp"
//
#include "boost/container/small_vector.hpp"
#include "boost/container/static_vector.hpp"


namespace umba {
namespace container {


#if defined(BOOST_CONTAINER_DOXYGEN_INVOKED) || defined(BOOST_CONTAINER_VARIADIC_TEMPLATES)
template<class ...Options>
using static_vector_options = boost::container::static_vector_options<Options...>;
#else
template<class O1 = void, class O2 = void, class O3 = void, class O4 = void>
using static_vector_options = boost::container::static_vector_options<O1, O2, O3, O4>;
#endif

template<bool OptVal>
using throw_on_overflow = boost::container::throw_on_overflow<OptVal>;

template<std::size_t OptVal>
using inplace_alignment = boost::container::inplace_alignment<OptVal>;

template <typename T, std::size_t Capacity, class Options BOOST_CONTAINER_DOCONLY(= void) >
using static_vector = boost::container::static_vector<T, Capacity, Options>;



#if defined(BOOST_CONTAINER_DOXYGEN_INVOKED) || defined(BOOST_CONTAINER_VARIADIC_TEMPLATES)
template<class ...Options>
using small_vector_options = boost::container::small_vector_options<Options...>;
#else
template<class O1 = void, class O2 = void, class O3 = void, class O4 = void>
using small_vector_options = boost::container::small_vector_options<O1, O2, O3, O4>;
#endif

template<unsigned Minimum, unsigned Numerator, unsigned Denominator>
using grow_factor_ratio = boost::container::dtl::grow_factor_ratio<Minimum, Numerator, Denominator>;

using growth_factor_50  = boost::container::growth_factor_50;
using growth_factor_60  = boost::container::growth_factor_60;
using growth_factor_100 = boost::container::growth_factor_100;

template<typename OptVal>
using growth_factor = boost::container::growth_factor<OptVal>;

using small_vector_option_growth_50_t  = small_vector_options< growth_factor<growth_factor_50> >::type;
using small_vector_option_growth_60_t  = small_vector_options< growth_factor<growth_factor_60> >::type;
using small_vector_option_growth_100_t = small_vector_options< growth_factor<growth_factor_100> >::type;


template<std::size_t Alignment>
using inplace_alignment = boost::container::inplace_alignment<Alignment>;

using small_vector_option_inplace_alignment_16_t = small_vector_options< inplace_alignment<16u> >::type;


template <class T, std::size_t N, class Allocator BOOST_CONTAINER_DOCONLY(= void), class Options BOOST_CONTAINER_DOCONLY(= void) >
using small_vector = boost::container::small_vector<T, N, Allocator, Options>;



// BOOST_INTRUSIVE_OPTION_TYPE(growth_factor, GrowthFactor, GrowthFactor, growth_factor_type)

// #define BOOST_INTRUSIVE_OPTION_TYPE(OPTION_NAME, TYPE, TYPEDEF_EXPR, TYPEDEF_NAME) \
// template< class TYPE> \
// struct OPTION_NAME \
// { \
//    template<class Base> \
//    struct pack : Base \
//    { \
//       typedef TYPEDEF_EXPR TYPEDEF_NAME; \
//    }; \
// }; \
//
//
//    typedef static_vector_opt< packed_options::throw_on_overflow
//                             , packed_options::inplace_alignment> implementation_defined;
//
// BOOST_INTRUSIVE_OPTION_CONSTANT(throw_on_overflow, bool, ThrowOnOverflow, throw_on_overflow)
// BOOST_INTRUSIVE_OPTION_CONSTANT(inplace_alignment, std::size_t, Alignment, inplace_alignment)
//
//
// #define BOOST_INTRUSIVE_OPTION_CONSTANT(OPTION_NAME, TYPE, VALUE, CONSTANT_NAME) \
// template< TYPE VALUE> \
// struct OPTION_NAME \
// { \
//    static const TYPE value = VALUE; \
//  \
//    template<class Base> \
//    struct pack : Base \
//    { \
//       static const TYPE CONSTANT_NAME = VALUE; \
//    }; \
// }; \
//
//


} // namespace container
} // namespace umba



