//
//  buffer_test.h
//  test
//
//  Created by huang on 2017/12/31.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef buffer_test_h
#define buffer_test_h

#include "buffer.hpp"
#include "gtest/gtest.h"

namespace {
TEST(BufferTest, init) {

  buffer *buff = new buffer(10);
  EXPECT_EQ(10, buff->length());
  buff->get_offset(5);
}
} // namespace

#endif /* buffer_test_h */
