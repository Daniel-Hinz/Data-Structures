// Daniel hinz
// test default ctor
// 2/24/2019

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
   String x = String("abcd");
   assert(x == "abcd");
   std::cout << "Done testing char array constructor" << std::endl;
   return 0;
}


