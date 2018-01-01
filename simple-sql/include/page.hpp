//
//  linn_space.hpp
//  raft
//
//  Created by huang on 2017/12/29.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef linn_space_hpp
#define linn_space_hpp

#include "aux.h"
#include "buffer.hpp"
#include <iostream>
#include "page_segment.hpp"

struct page_header {
  uint slot;
  uint free_space_ptr;
  uint record_sum;
  uint free_rec_ptr;
  uint delete_space;
  uint page_last_insert_ptr;
  uint page_last_insert_orient;
  uint same_orient_insert_count;
  uint page_user_record_count;
  uint transit_id;
  uint level;
  uint index_id;
  uint index_leaf_page_segment_header;
  uint index_no_leaf_page_segment_header;
};
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
struct page_slot {
  uint offset;
};

class page {
private:
  // raw data;
  buffer *buffer;

  page_segment *segment;
  page_header *header_info;

  record *infimum, *supremum;
  record *data;
  uint free_space;
  page_slot *slots;

  uint page_checksum;

public:
  page(class ::buffer *buff) {
    buffer = buff;
    init();
  }
  ~page() {
    delete infimum;
    delete supremum;
  }
  void insert(int key, int value) {
    record *roc = new record(key, value);
    interal_insert(roc);
  }

  record *get_first_record() { return infimum; }

  record *get_last_record() { return supremum; }

private:
  void init() {
    init_record(&infimum, "infimum", 8);
    std::cout << infimum->key << std::endl;
    std::cout << std::numeric_limits<int>::min() << std::endl;
    infimum->key = std::numeric_limits<int>::min();
    infimum->owned = 1;
    init_record(&supremum, "supremum", 9);
    supremum->key = std::numeric_limits<int>::max();
    supremum->owned = 1;
    infimum->next = supremum;
    supremum->next = nullptr;
  }
  void init_record(record **rec, char *name, int len) {
    *rec = new record();
    (*rec)->name = name;
    (*rec)->len = len;
  }

  void interal_insert(record *rec) {
    record *temp = infimum;
    while (temp != supremum) {
      if (rec->key < temp->next->key) {
        rec->next = temp->next;
        temp->next = rec;
        break;
      }
      temp = temp->next;
    }
  }
};

#endif /* linn_space_hpp */
