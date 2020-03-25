//
//  main.cpp
//  problem 18
//
//  Created by Στρατής Χριστοδούλου on 23/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "class18.hpp"
#include <fstream>
#include <iostream>

int main(int argc, const char *argv[]) {
  std::cout
      << "Problem 18 description\n"
         "======================\n"
         "By starting at the top of the triangle below and moving to adjacent "
         "numbers\n"
         "on the row below, the maximum total from top to bottom is 23.\n\n"

         "\t    3\n"
         "\t   7 4\n"
         "\t  2 4 6\n"
         "\t 8 5 9 3\n\n"

         "That is, 3 + 7 + 4 + 9 = 23.\n\n"

         "Find the maximum total from top to bottom of the triangle below:\n\n"

         "\t                    75\n"
         "\t                   95 64\n"
         "\t                 17 47 82\n"
         "\t                18 35 87 10\n"
         "\t               20 04 82 47 65\n"
         "\t             19 01 23 75 03 34\n"
         "\t            88 02 77 73 07 63 67\n"
         "\t           99 65 04 28 06 16 70 92\n"
         "\t          41 41 26 56 83 40 80 70 33\n"
         "\t        41 48 72 33 47 32 37 16 94 29\n"
         "\t       53 71 44 65 25 43 91 52 97 51 14\n"
         "\t      70 11 33 28 77 73 17 78 39 68 17 57\n"
         "\t     91 71 52 38 17 14 91 43 58 50 27 29 48\n"
         "\t   63 66 04 68 89 53 67 30 73 16 69 87 40 31\n"
         "\t 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23\n\n"

         "NOTE: As there are only 16384 routes, it is possible to solve this "
         "problem\n"
         "by trying every route. However, Problem 67, is the same challenge "
         "with a triangle\n"
         "containing one-hundred rows; it cannot be solved by brute force, and "
         "requires a clever\n"
         "method! ;o) (https://projecteuler.net/problem=18).\n\nANSWER: ";
  if (argc != 2) {
    std::cout << "\n\tUSAGE:\n\t\tproblem18 [filename]\n";
  } else {
    Class18 c{argv[1]};
    std::cout << c.solve() << std::endl;
  }

  return 0;
}
