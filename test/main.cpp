//
//  main.cpp
//  test
//
//  Created by peter.huang on 22/12/2017.
//  Copyright © 2017 peter.huang. All rights reserved.
//

#include "gtest/gtest.h"

namespace  {
    TEST(HelloTest, Hello) {
        EXPECT_EQ(1, 1);
    }
    TEST(GG, G) {
        EXPECT_EQ(1, 2);
    }
}
int main(int argc, char** argv) {
       testing::InitGoogleTest(&argc, argv);
       return RUN_ALL_TESTS();
     }

