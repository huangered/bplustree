//
//  test2.h
//  game
//
//  Created by huang on 2017/12/29.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef test2_h
#define test2_h

#include "gtest/gtest.h"
#include "page_segment.hpp"
#include <iostream>
#include "buffer.hpp"

namespace {
    TEST(PageSegmentTest, Checksum) {
        byte* buffer = (byte*)malloc(page_segment_total_len);
        
        page_segment* seg = new page_segment(buffer);
        seg->set_checksum(255);
        uint* value = seg->get_checksum();
        EXPECT_EQ(*value, 255);
        free(buffer);
    }
}

#endif /* test2_h */
