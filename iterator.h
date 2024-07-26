#pragma once

// #include <iterator>


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



struct TextPositionCountingIteratorWrapper
{

};


//----------------------------------------------------------------------------

} // namespace iterator
} // namespace umba

