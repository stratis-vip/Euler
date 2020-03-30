//
//  utils.cpp
//  project Euler
//
//  Created by Στρατής Χριστοδούλου on 25/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "utils.hpp"
#include <algorithm>

size_t howManyYears(const ll start, const ll end) {
  return (end - start) / 10000;
}

size_t getYear(const ll date) { return date / 10000; }

size_t getDays(const ll start, const ll end) {
  const size_t years = howManyYears(start, end);
  if (years > 0) {
    size_t days = end - start - years * 10000;
    return years * 365 + days;
  }
  return 0;
}

bool isLeap(size_t year) {
  bool retVal{};
  retVal = year % 4 == 0;
  if (retVal && year % 100 == 0) {
    retVal = year % 400 == 0;
  }
  return retVal;
}

date fromMyDate(const mydate a) {
  size_t local = a;
  const size_t yrsEst = local / 365;

  size_t cYear = yrsEst + startTime.year;
  size_t leapDays = {};
  if (cYear > 1904) {
    leapDays++;
  }
  leapDays += (cYear - 1904) / 4;
  const size_t yrs = (local - leapDays) / 365;
  cYear = yrs + startTime.year;
  size_t mons{};
  size_t day{};

  size_t days = local - yrs * 365 - leapDays;
  std::vector<size_t> sM{monthsAr};
  if (isLeap(yrs)) {
    sM.at(1) = 29;
    days++;
  }
  size_t c{};
  std::for_each(sM.begin(), sM.end(), [&sM, &c](size_t &a) {
    if (c > 0) {
      a += sM.at(c - 1);
    }
    c++;
  });

  if (days < 32) {
    mons = 0;
    if (day == 0) {
      day++;
    } else {
      day = days;
    }
  } else {
    for (auto i = 0; i != 12; i++) {
      if (sM.at(i) >= days) {
        mons = i;
        day = days - sM.at(i - 1) + 1;
        break;
      }
    }
  }
  return date{yrs + startTime.year, mons + 1, day};
}

mydate convertTo(const size_t year, const size_t month, const size_t day) {
  date d{year, month, day};
  ll retVal{};
  const size_t yrs = year - startTime.year;
  const size_t mhs = month - startTime.month;
  // dont count leap year if we are in leap year (offset)
  size_t offset{0};
  if (yrs / 4 > 0 && yrs % 4 == 0) {
    offset = 1;
  }

  retVal += yrs * 365 + yrs / 4 - offset;

  std::vector<size_t> cMonths{monthsAr};
  if (isLeap(year)) {
    cMonths.at(1) = 29;
  }

  if (mhs > 0) {
    size_t sum{};
    std::for_each(cMonths.begin(), cMonths.begin() + mhs,
                  [&sum](size_t a) { sum += a; });
    retVal += sum;
  }

  retVal += day - startTime.day;
  return retVal;
}

bool isSpecificDay(const mydate a, const DayName day) {
  if (a == 0) {
    return day == DayName::monday;
  }
  DayName d = static_cast<DayName>(a % static_cast<size_t>(DayName::monday));
  if (d == DayName::none) {
    return day == DayName::monday;
  } else {
    return d == day;
  }
};

bool operator==(const date &a, const date &b) {
  return a.year == b.year && a.month == b.month && a.day == b.day;
}
