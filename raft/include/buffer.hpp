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

namespace linn {
typedef unsigned char byte;

class buffer {
private:
  byte *data;
  unsigned int size;

public:
  buffer(unsigned int size) : size(size) {
    data = (byte *)malloc(size * sizeof(byte));
  }
  ~buffer() { free(data); }
  inline byte *getBuffer() const { return data; }

  inline unsigned int getSize() const { return size; }
};
} // namespace linn

#endif /* buffer_hpp */
