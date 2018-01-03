//
//  buffer.hpp
//  raft
//
//  Created by huang on 2017/12/31.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef buffer_hpp
#define buffer_hpp

#include <new>
#include "aux.h"

// simple buffer class, will enhance in the future
class buffer {
private:
  byte *data;
  uint len;

public:
    buffer(uint len):len(len) {
    data = (byte *)malloc(len * sizeof(byte));
  }
  ~buffer() { free(data); }
  inline byte *getBuffer() const { return data; }

  inline uint length() const { return len; }
};

#endif /* buffer_hpp */
