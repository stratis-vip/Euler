//
//  utils.hpp
//  project Euler
//
//  Created by Στρατής Χριστοδούλου on 25/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <cstdio>
#include <vector>

enum class DayName : unsigned char {

  monday = 7,
  sunday = 6,
  saturday = 5,
  friday = 4,
  thursday = 3,
  wednesday = 2,
  tuesday = 1,
  none = 0
};

const std::vector<size_t> monthsAr{31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};

struct date {
  size_t year;
  size_t month;
  size_t day;
  date(const size_t year, const size_t month, const size_t day)
      : year(year), month(month), day(day){};
};

const date startTime = {1900, 1, 1};

using ll = long long;
using mydate = ll;

const ll startOfTime = 19000101;

const ll startRange = 19010101;
const ll endRange = 20001231;

bool isLeap(size_t);
size_t getYear(const ll);
size_t getDays(const ll, const ll);
size_t howManyYears(const ll, const ll);
mydate convertTo(const size_t, const size_t, const size_t);
bool isSpecificDay(const mydate, const DayName);
date fromMyDate(const mydate);
bool operator==(const date &a, const date &b);
#endif /* utils_hpp */
