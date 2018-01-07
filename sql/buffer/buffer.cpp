//
//  buffer.cpp
//  raft
//
//  Created by huang on 2017/12/31.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#include "buffer.hpp"
#include <assert.h>

void *buffer::get_offset(u_long offset) {
  assert(offset < len);
  byte *byte = data + offset;
  return byte;
}
