//
//  linn_space.hpp
//  raft
//
//  Created by huang on 2017/12/29.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef linn_space_hpp
#define linn_space_hpp

#include <iostream>

#include "aux.hpp"
#include "buffer.hpp"
#include "page_header.hpp"
#include "page_segment.hpp"
#include "page_slot.h"
#include "record.hpp"

#define SLOT_SIZE 8

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

  page_slot *search_slot(const uint key);
};

#endif /* linn_space_hpp */
