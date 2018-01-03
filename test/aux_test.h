//
//  aux_test.h
//  game
//
//  Created by peter.huang on 03/01/2018.
//  Copyright © 2018 peter.huang. All rights reserved.
//

#ifndef aux_test_h
#define aux_test_h

#include "gtest/gtest.h"
#include "aux.h"
#include <iostream>
namespace {
       TEST(AuxTest, checksum) {
           ushort *ptr = (ushort*)malloc(sizeof(ushort)*10);
           bzero(ptr, 10);
           for(int i=0;i<9;i++) {
               *(ptr+i)=0xff;
           }
           ushort checksum1 = checksum(ptr, 9);
           *(ptr+9)=checksum1;
        
           bool checksum_equal = validate_checksum(ptr,10);
           EXPECT_EQ(true, checksum_equal);
        }
}


#endif /* aux_test_h */
