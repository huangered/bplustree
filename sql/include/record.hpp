//
//  record.h
//  raft
//
//  Created by huang on 2018/1/1.
//  Copyright © 2018年 peter.huang. All rights reserved.
//

#ifndef record_h
#define record_h

struct record {
  char *name;
  int len;
  int owned;

  uint type;

  int key;
  int value;
  record *next;
  record() : key(0), value(0), next(nullptr) {}
  record(int key, int value) : key(key), value(value), next(nullptr) {}
};

#endif /* record_h */
