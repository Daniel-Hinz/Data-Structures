// Daniel hinz
// test default ctor
// 2/24/2019

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
   String x = String("a");
   String y = String("b");
   std::cout << x; 
   //String z = x+y;
   // std::cout << z;
   //std::cout << x << " " << y << std::endl;
   assert((x+y) == "ab");
   std::cout << "Done testing concat" << std::endl;
   return 0;
}

