//
//  buffer.hpp
//  raft
//
//  Created by huang on 2017/12/31.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef buffer_hpp
#define buffer_hpp

#include "aux.hpp"
#include <new>

// simple buffer class, will enhance in the future
class buffer {
private:
  byte *data;
  u_long len;

public:
  buffer(u_long len) : len(len) { data = (byte *)malloc(len * sizeof(byte)); }
  ~buffer() { free(data); }
  inline byte *getBuffer() const { return data; }

  inline u_long length() const { return len; }

  void *get_offset(u_long offset);
};

#endif /* buffer_hpp */
