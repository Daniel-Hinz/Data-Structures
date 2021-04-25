// Daniel hinz
// utilities.hpp

#ifndef CS2_UTILITIES_HPP_
#define CS2_UTILITIES_HPP_

#include "stack.hpp"
#include <string>
#include <iostream>

std::string toPostfix(std::string);
std::string toAssembler(std::string, std::ofstream&);
std::string evaluate(std::string, std::string, std::string, int, std::ofstream&);
std::string toString(int); 

#endif
