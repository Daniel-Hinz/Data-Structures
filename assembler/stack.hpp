// Daniel Hinz
// Project 3
// milestone 1

#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>

//////////////////////////////////////////////
template<typename T>
class Node
{
 public:
  Node()           : next(0)          {};
  Node(const T& x) : data(x), next(0) {};
  
  T data;
  Node<T>  *next;
};


//////////////////////////////////////////////
template<typename T>
class stack {
 public:
       stack() :tos(0) {};
       stack(const stack<T>&);
       ~stack();
  void swap(stack<T>&);
  stack<T>& operator=(stack<T> rhs) { swap(rhs); return this*; };
  bool empty() const { return tos == 0; };
  bool full() const;
  T    top() const {return tos->data;};
  T    pop();
  void push(const T&);

 private:
  Node<T> *tos;
};

template<typename T>
stack<T>::stack(const stack<T>& actual) {
  Node<T> *temp = actual.tos,*bottom;
  tos = 0;

  while (temp != 0) {
    if (tos == 0){
      tos = new Node<T> (temp -> data);
      bottom = tos;
    }
    else {
      bottom->next = new Node<T>(temp->data);
      bottom = bottom -> next;
    }
    temp = temp->next;
  }
}

template <typename T>
stack<T>::~stack(){
  Node<T> *temp;
  while(tos != 0){
    temp = tos;
    tos = tos->next;
    delete temp;
  }
}

template <typename T>
void stack<T>::swap(stack<T>& rhs){
  Node<T> *temp = tos;
  tos = rhs.tos;
  rhs.tos = temp;
}

template <typename T>
bool stack<T>::full() const {
  Node<T> *ptr = new(std::nothrow) Node<T>();
  if (ptr == 0)
    return true;
  delete ptr;
  return false;
}

template <typename T>
void stack<T>::push(const T& item) {
  if (!full()){
    Node<T> *temp = new Node<T> (item);
    temp ->next = tos;
    tos = temp;
  }
}

template <typename T>
T stack<T>::pop(){
  if(!empty()){
    T result = tos->data;
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
  }
}

#endif
