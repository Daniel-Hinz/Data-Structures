// Daniel Hinz
// Milestone 3
// 2/17/2019

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
        std::ifstream in("data1-2.txt");
        bigint fNum;
        bigint sNum;    
        if(!in) {                           
             std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
             exit(1);
    }
    if (in.is_open()){
         in >> fNum;
         in >> sNum;
         while (!in.eof()){
              std::cout << fNum << std::endl;
              std::cout << std::endl;
              if (!in.eof()){
                   std::cout << fNum << std::endl;
                   std::cout << std::endl;
                   bigint bi = fNum*sNum;
                   std::cout << bi << std::endl;
                   std::cout << std::endl;
                   in >> fNum;
                   in >> sNum; 
              }
         }
    }
    in.close();
    return 0;
}
