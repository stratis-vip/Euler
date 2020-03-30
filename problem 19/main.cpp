//
//  main.cpp
//  problem 19
//
//  Created by Στρατής Χριστοδούλου on 25/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "utils.hpp"
#include <iostream>

int main(int argc, const char *argv[]) {
  // insert code here...
  std::cout << "Problem 19 description\n"
               "======================\n"
               "You are given the following information, but you may prefer to "
               "do some research for yourself.\n\n"

               "\t1 Jan 1900 was a Monday.\n"
               "\tThirty days has September,\n"
               "\tApril, June and November.\n"
               "\tAll the rest have thirty-one,\n"
               "\tSaving February alone,\n"
               "\tWhich has twenty-eight, rain or shine.\n"
               "\tAnd on leap years, twenty-nine.\n\n"
               "A leap year occurs on any year evenly divisible by 4, but not "
               "on a century unless it is\n"
               "divisible by 400. How many Sundays fell on the first of the "
               "month during the twentieth\n"
               "century (1 Jan 1901 to 31 Dec "
               "2000)(https://projecteuler.net/problem=18)?\n\nANSWER: ";
  size_t retVal{};
  for (size_t year = 1901; year != 2001; year++) {
    for (size_t month = 1; month != 13; month++) {
      if (isSpecificDay(convertTo(year, month, 01), DayName::sunday)) {
        retVal++;
      }
    }
  }
  std::cout << retVal << std::endl;
  return 0;
}
