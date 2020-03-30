//
//  tests.cpp
//  pro19Tests
//
//  Created by Στρατής Χριστοδούλου on 25/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "utils.hpp"
#include "gtest/gtest.h"

TEST(Dates, getYears) {
  EXPECT_EQ(howManyYears(19010101, 19020101), 1);
  EXPECT_EQ(howManyYears(19010201, 19020101), 0);
}

TEST(Dates, convertTo) {
  EXPECT_EQ(convertTo(1900, 01, 01), 0);
  EXPECT_EQ(convertTo(1901, 01, 01), 365);
  EXPECT_EQ(convertTo(1904, 01, 01), 1460);
  EXPECT_EQ(convertTo(1905, 01, 01), 1826);
  EXPECT_EQ(convertTo(1906, 01, 01), 2191);
  EXPECT_EQ(convertTo(1907, 01, 01), 2556);
  EXPECT_EQ(convertTo(1908, 01, 01), 2921);
  EXPECT_EQ(convertTo(1918, 01, 01), 6574);
  EXPECT_EQ(convertTo(1900, 01, 02), 1);
  EXPECT_EQ(convertTo(1900, 01, 12), 11);
  EXPECT_EQ(convertTo(1900, 02, 1), 31);
  EXPECT_EQ(convertTo(1900, 02, 12), 42);
  EXPECT_EQ(convertTo(1901, 03, 12), 435);
  EXPECT_EQ(convertTo(1900, 03, 12), 70);
  EXPECT_EQ(convertTo(1918, 04, 21), 6684);
  EXPECT_EQ(convertTo(1928, 12, 31), 10591);
  EXPECT_EQ(convertTo(2020, 3, 25), 43913);
  EXPECT_EQ(convertTo(2000, 1, 1), 36524);

  //  EXPECT_EQ(getDays(19010101, 19020201),396);
}

TEST(Dates, getDays) {
  EXPECT_EQ(getDays(19010101, 19020101), 365);
  //  EXPECT_EQ(getDays(19010101, 19020201),396);
}

TEST(Dates, isLeap) {
  EXPECT_FALSE(isLeap(1901));
  EXPECT_FALSE(isLeap(1900));
  EXPECT_TRUE(isLeap(2020));
  EXPECT_FALSE(isLeap(1700));
  EXPECT_FALSE(isLeap(1800));
  EXPECT_TRUE(isLeap(2000));
}

TEST(Dates, getYear) {
  EXPECT_EQ(getYear(19010201), 1901);
  EXPECT_EQ(getYear(29010201), 2901);
}

TEST(Dates, isMonday) {

  EXPECT_TRUE(isSpecificDay(0, DayName::monday));
  EXPECT_TRUE(isSpecificDay(convertTo(2020, 3, 23), DayName::monday));
  EXPECT_TRUE(isSpecificDay(convertTo(2020, 3, 22), DayName::sunday));
  EXPECT_TRUE(isSpecificDay(convertTo(2020, 3, 24), DayName::tuesday));
  EXPECT_TRUE(
      isSpecificDay(convertTo(2020, 3, 25), DayName::wednesday)); // wednesday
  EXPECT_TRUE(
      isSpecificDay(convertTo(2020, 3, 26), DayName::thursday)); // thursday
  EXPECT_TRUE(isSpecificDay(convertTo(2020, 3, 27), DayName::friday)); // friday
  EXPECT_TRUE(
      isSpecificDay(convertTo(2020, 3, 28), DayName::saturday)); // saturday
}

TEST(dates, fromMyDate) {
  date d{1906, 1, 1};
  EXPECT_EQ(fromMyDate(2191).year, 1906);
  EXPECT_EQ(fromMyDate(2191).month, 1);
  EXPECT_EQ(fromMyDate(2191).day, 1);

  // 1928,12,31), 10591);
  date d1{1928, 12, 31};
  EXPECT_EQ(fromMyDate(10591).year, 1928);
  EXPECT_EQ(fromMyDate(10591).month, 12);
  EXPECT_EQ(fromMyDate(10591).day, 31);
  date d2{2020, 3, 25};
  EXPECT_EQ(fromMyDate(43913), d2);
  date d3{2000, 1, 1};
  EXPECT_EQ(fromMyDate(36524).day, 1);
  EXPECT_EQ(fromMyDate(36524).month, 1);
  EXPECT_EQ(fromMyDate(36524).year, 2000);

  //  EXPECT_EQ(fromMyDate(43913).year, d.year);
}
