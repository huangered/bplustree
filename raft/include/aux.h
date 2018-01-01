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

uint checksum(const void* ptr, uint len) {
    return 1;
}

void print_point_addr(const void* ptr) {
    std::cout<<"addr: "<<std::hex<<ptr<<std::endl;
}


void set_value(void *dest, const void *src, size_t size) {
    memcpy(dest, src, size);
}

#endif /* aux_h */
