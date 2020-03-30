//
//  main.cpp
//  problem20
//
//  Created by Στρατής Χριστοδούλου on 26/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "bigIntClass.hpp"
#include <iostream>

BigInt<size_t> factorial(const size_t t) {
  BigInt<size_t> b{t};
  if (t == 1) {
    return b;
  } else {
    return b * factorial(t - 1);
  }
}

int main(int argc, const char *argv[]) {
  // insert code here...
  std::string a{factorial(100).value()};
  //  std::string a{"1234"};
  size_t sum{0};
  std::for_each(a.cbegin(), a.cend(),
                [&sum](char a) { sum += static_cast<size_t>(a - '0'); });
  std::cout << sum << std::endl;
  return 0;
}
