// Daniel Hinz
// Tests Assignment 
// 3/19/2019

#include "stack-interface.cpp"
#include <cassert>

int main() {
  
  // Test 1

  stack<String> a1;
  stack<String> a2;

  a1.pushBack("ab");
  a2.pushBack("ab");
   
  assert(a1 == ab);
  
  /////////////////////////////
  
  // Test 2
  
  stack<String> a3;
  stack<String> a4;
 
  a3.pushBack("Thisisatest");
  a4.pushBack("Thisisatest"); 

  assert(a3 == a4);

  //////////////////////////////

  // Test 3
 
  stack<String> a5;
  stack<String> a6;

  a5.pushBack("pleasetestme");
  
  a5 = a6;

  assert(a6 == "pleasetestme");

  //////////////////////////////
  
  // Test 4

  stack<String> a7;
  stack<String> a8;

  a7.pushBack("hello");
  a8.pushBack("hello");
  
  assert(a7 == a8);

  //////////////////////////////

  return 0;
}
