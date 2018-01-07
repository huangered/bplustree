//
//  aux.cpp
//  sql
//
//  Created by huang on 2018/1/7.
//  Copyright © 2018年 peter.huang. All rights reserved.
//
#include "aux.hpp"
#include <stdlib.h>

#include <iostream>

ushort checksum(ushort *ptr, uint len) {
  u_long sum = 0;
  while (len > 0) {
    sum += *ptr++;
    len -= 1;
  }
  while (sum >> 16) {

    sum = (sum & 0xffff) + (sum >> 16);
  }
  return (ushort)(~sum);
}
bool validate_checksum(ushort *ptr, uint len) {
  return 0x00 == checksum(ptr, len);
}

// 1 3 5 7 9;

page_slot *index(page_slot *begin, page_slot *end, const uint key) {
  long low = 0, high = end - begin;
  int p = 0;
  while (low != high) {
    int mid = (high + low) >> 1;
    page_slot *t = begin + mid;
    if (t->key < key) {
      low = mid + 1;
      p = mid;
    } else if (t->key == key) {
      low = high = mid;
      p = low;
      break;
    } else {
      high = mid;
    }
  }
  return begin + p;
}
