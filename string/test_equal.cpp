// Daniel hinz
// test default ctor
// 2/24/2019

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
  String x("a");
  String y("a");
  assert(x == y);

  std::cout << "Done testing equal" << std::endl;
  return 0;
}

