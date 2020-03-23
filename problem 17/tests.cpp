#include "class17.hpp"
#include "gtest/gtest.h"

TEST(Class17, initialValues) {
  Class17 c{0};
  EXPECT_TRUE(c.sValue() == "zero");
  EXPECT_EQ(c.aValue(), 0);
  EXPECT_EQ(c.size(), 4);
}

TEST(Class17, CheckValuesUnder21) {
  Class17 c{9};
  EXPECT_TRUE(c.sValue() == "nine");
  EXPECT_EQ(c.aValue(), 9);
  EXPECT_EQ(c.size(), 4);
}

TEST(Class17, CheckValues24) {
  Class17 c{24};
  EXPECT_EQ(c.sValue(), "twenty-four");
  EXPECT_EQ(c.aValue(), 24);
  EXPECT_EQ(c.size(), 10);
}

TEST(Class17, CheckValues38) {
  Class17 c{38};
  EXPECT_EQ(c.sValue(), "thirty-eight");
  EXPECT_EQ(c.aValue(), 38);
  EXPECT_EQ(c.size(), 11);
}

TEST(Class17, CheckValues90) {
  Class17 c{90};
  EXPECT_EQ(c.sValue(), "ninety");
  EXPECT_EQ(c.aValue(), 90);
  EXPECT_EQ(c.size(), 6);
}

TEST(Class17, CheckValues100) {
  Class17 c{100};
  EXPECT_EQ(c.sValue(), "one hundred");
  EXPECT_EQ(c.aValue(), 100);
  EXPECT_EQ(c.size(), 10);
}

TEST(Class17, CheckValues111) {
  Class17 c{111};
  EXPECT_EQ(c.sValue(), "one hundred and eleven");
  EXPECT_EQ(c.aValue(), 111);
  EXPECT_EQ(c.size(), 19);
}

TEST(Class17, CheckValues121) {
  Class17 c{121};
  EXPECT_EQ(c.sValue(), "one hundred and twenty-one");
  EXPECT_EQ(c.aValue(), 121);
  EXPECT_EQ(c.size(), 22);
}

TEST(Class17, CheckValues976) {
  Class17 c{976};
  EXPECT_EQ(c.sValue(), "nine hundred and seventy-six");
  EXPECT_EQ(c.aValue(), 976);
  EXPECT_EQ(c.size(), 24);
}

TEST(Class17, CheckValues900) {
  Class17 c{900};
  EXPECT_EQ(c.sValue(), "nine hundred");
  EXPECT_EQ(c.aValue(), 900);
  EXPECT_EQ(c.size(), 11);
}

TEST(Class17, CheckValues1000) {
  Class17 c{1000};
  EXPECT_EQ(c.sValue(), "one thousand");
  EXPECT_EQ(c.aValue(), 1000);
  EXPECT_EQ(c.size(), 11);
}

TEST(Class17, CheckValues342) {
  Class17 c{342};
  EXPECT_EQ(c.sValue(), "three hundred and forty-two");
  EXPECT_EQ(c.aValue(), 342);
  EXPECT_EQ(c.size(), 23);
}

TEST(utilities, getMagnum) {
  //    EXPECT_EQ(getMagnum(10), 1);
  //    EXPECT_EQ(getMagnum(9), 1);
  //    EXPECT_EQ(getMagnum(27), 1);
  //    EXPECT_EQ(getMagnum(129), 1);
}
