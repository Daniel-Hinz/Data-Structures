// Daniel hinz
// test default ctor
// 2/24/2019

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
   String x("c");
   assert(x == "c");
   
   // String y = String("abc");
   //assert(y == "abc");
   
   std::cout << "Done testing char constructor" << std::endl;
   return 0;
}


