//
//  main.cpp
//  problem 17
//
//  Created by Στρατής Χριστοδούλου on 22/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "class17.hpp"
#include <iostream>

int main(int argc, const char *argv[]) {
  std::cout << "Problem 17 description\n"
               "======================\n"
               "If the numbers 1 to 5 are written out in words: one, two, "
               "three, four, five, then there are\n\n"
               "\t3 + 3 + 5 + 4 + 4 = 19 letters used in total.\n\n"

               "If all the numbers from 1 to 1000 (one thousand) inclusive "
               "were written out in words, how many letters\n"
               "would be used?\n\n"

               "NOTE: Do not count spaces or hyphens. For example, 342 (three "
               "hundred and forty-two) contains 23 letters \n"
               "and 115 (one hundred and fifteen) contains 20 letters. The use "
               "of \"and\" when writing out numbers is in \n"
               "compliance with British usage "
               "(https://projecteuler.net/problem=17).\n\nANSWER: ";

  long long ret{0};
  for (size_t i = 1; i != 1001; i++) {
    Class17 c{i};
    ret += c.size();
  }
  std::cout << ret << std::endl;
  return 0;
}
