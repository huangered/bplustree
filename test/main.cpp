//
//  main.cpp
//  test
//
//  Created by peter.huang on 22/12/2017.
//  Copyright © 2017 peter.huang. All rights reserved.
//

#include "btree.hpp"
#include "gtest/gtest.h"
#include "page_segment_test.hpp"
#include "buffer_test.hpp"

namespace {
TEST(BtreeTest, Add) {
  linn::tree<int, int> tree;
  int size = 5;
  for (int s = 0; s != size; s++) {
    tree.insert(s, s);
  }
  EXPECT_EQ(size, tree.size());
}
TEST(BtreeTest, Del) {
  linn::tree<int, int> tree;
  int size = 5;
  for (int s = 0; s != size; s++) {
    tree.insert(s, s);
  }
  tree.remove(1);
  tree.remove(2);
  EXPECT_EQ(size - 2, tree.size());
}
} // namespace
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
