//
//  aux_test.h
//  game
//
//  Created by peter.huang on 03/01/2018.
//  Copyright © 2018 peter.huang. All rights reserved.
//

#ifndef aux_test_h
#define aux_test_h

#include "aux.hpp"
#include "page_slot.h"
#include "gtest/gtest.h"
#include <iostream>
namespace {
TEST(AuxTest, checksum) {
  ushort *ptr = (ushort *)malloc(sizeof(ushort) * 10);
  bzero(ptr, 10);
  for (int i = 0; i < 9; i++) {
    *(ptr + i) = 0xff;
  }
  ushort checksum1 = checksum(ptr, 9);
  *(ptr + 9) = checksum1;

  bool checksum_equal = validate_checksum(ptr, 10);
  EXPECT_EQ(true, checksum_equal);
}

TEST(AuxTest, index) {
  page_slot *slots = new page_slot[8];
  for (int i = 0; i < 8; i++) {
    (slots + i)->key = 10 * i;
  }
  page_slot *index1 = index(slots, slots + 7, 51);
  EXPECT_EQ(index1->key, 50);

  page_slot *index2 = index(slots, slots + 7, 45);
  EXPECT_EQ(index2->key, 40);

  page_slot *index3 = index(slots, slots + 7, 40);
  EXPECT_EQ(index3->key, 40);
}
} // namespace

#endif /* aux_test_h */
