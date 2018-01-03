//
//  aux.h
//  raft
//
//  Created by huang on 2018/1/1.
//  Copyright © 2018年 peter.huang. All rights reserved.
//

#ifndef aux_h
#define aux_h

#include <stdlib.h>

#include <iostream>

typedef unsigned char byte;

ushort checksum(ushort* ptr, uint len) {
    u_long sum = 0;
    while(len>0){
        sum+=*ptr++;
        len -=1;
    }
    while(sum>>16) {
        sum = (sum&0xffff)+(sum>>16);
    }
    return (ushort)(~sum);
}
bool validate_checksum(ushort* ptr, uint len) {
    return 0x00 == checksum(ptr, len);
}

#endif /* aux_h */
