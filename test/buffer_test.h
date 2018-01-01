//
//  buffer_test.h
//  test
//
//  Created by huang on 2017/12/31.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef buffer_test_h
#define buffer_test_h

#include "gtest/gtest.h"
#include "buffer.hpp"

namespace {
    TEST(BufferTest, init) {
        
        linn::buffer *buffer = new linn::buffer(10);
        EXPECT_EQ(10, buffer->getSize());
    }
}


#endif /* buffer_test_h */
