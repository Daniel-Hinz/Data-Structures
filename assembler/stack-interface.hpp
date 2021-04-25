#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer: Daniel Hinz
// Updated:    3/2019
//
//
//
//

#include <new>

////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class Node {
  
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T>
class stack {
public:
              stack     () {};
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>){swap(rhs); return *this;};
    bool      empty     () const;
    bool      full      () const;
    T         top       () const;
    T         pop       ();
    void      push      (const T&);

private:
	Node<T>   *tos;
};

#endif

