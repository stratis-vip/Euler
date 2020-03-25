//
//  tests.cpp
//  project Euler
//
//  Created by Στρατής Χριστοδούλου on 23/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "class18.hpp"
#include "gtest/gtest.h"

TEST(Class18, initialValues) {
  Class18 c{"3 4 5", 1};
  EXPECT_EQ(c.toString(), "3 4 5");
  EXPECT_EQ(c.value(), 5);
  EXPECT_EQ(c.position(), 2);
}

TEST(Class18, oneMember) {
  Class18 c{"3", 0};
  EXPECT_EQ(c.toString(), "3");
  EXPECT_EQ(c.value(), 3);
  EXPECT_EQ(c.position(), 0);
}

TEST(Class18, fromFile) {
  Class18 c{"values"};
  EXPECT_EQ(c.getTable().size(), 15);
  EXPECT_EQ(c.getTable().at(14).size(), 15);
}

TEST(functions, getMaxFromTriangle) {
  vectorTable a{{3}, {7, 4}};
  vectorTable b{{3}, {7, 4}, {2, 4, 6}};
  vectorTable c{{3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}};
  EXPECT_EQ(getMaxFromTriangle(a), 10);
  EXPECT_EQ(getMaxFromTriangle(b), 14);
  EXPECT_EQ(getMaxFromTriangle(c), 23);
  Class18 d{"values"};
  EXPECT_EQ(d.solve(), 1074);
  //  EXPECT_EQ(c.getTable().size(), 15);
  //  EXPECT_EQ(c.getTable().at(14).size(), 15);
}
