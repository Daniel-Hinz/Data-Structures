// Daniel hinz
// test default ctor
// 2/24/2019

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {   
   String x = String();
   assert(x == '\0');
   
   String z; 
   assert(z == ""); 
    
   String y = String("abc");
   assert(y == "abc");

   std::cout<< "Done testing default constructor" << std::endl;      
   return 0;
} 
