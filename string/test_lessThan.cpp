// Daniel hinz
// test less than
// 2/24/2019

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
   String x = String("b");
   String y = String("cde");
   assert(x < y);

   std::cout<< "Done testing less than" << std::endl;
   return 0;
}

