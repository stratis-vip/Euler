//
//  tests.cpp
//  treeTests
//
//  Created by Στρατής Χριστοδούλου on 24/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "btree.hpp"
#include "gtest/gtest.h"

TEST(BinaryTree, initialValues) {
  Node<int> a{};
  a.data = 0;
  EXPECT_EQ(a.left,  nullptr);
  EXPECT_EQ(a.right, nullptr);
  EXPECT_EQ(a.data, 0);
}
