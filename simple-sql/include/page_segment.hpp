//
//  Header.h
//  raft
//
//  Created by huang on 2018/1/1.
//  Copyright © 2018年 peter.huang. All rights reserved.
//

#ifndef Page_segment_h
#define Page_segment_h

#include "aux.h"

#define page_segment_checksum 0
#define page_segment_space_offset 4
#define page_segment_pre_page 8
#define page_segment_next_page 12
#define page_segment_last_lsn 20
#define page_segment_page_type 22
#define page_segment_flush_lsn 30
#define page_segment_space_id 34
#define page_segment_total_len 38

class page_segment {
private:
  byte *ptr;

private:
  uint *checksum;
  uint *space_offset;
  uint *pre_page;
  uint *next_page;
  uint *last_lsn;
  ushort *page_type;
  uint *flust_lsn;
  uint *space_id;

public:
  page_segment(byte *ptr) : ptr(ptr) {}

  void set_checksum(uint checksum) {
    set_field(&checksum, page_segment_checksum, 4);
  }

  void set_space_offset(uint offset) {
    set_field(&offset, page_segment_space_offset, 4);
  }

  void set_pre_page(uint page) { set_field(&page, page_segment_pre_page, 4); }

  void set_next_page(uint page) { set_field(&page, page_segment_next_page, 4); }

  void set_last_lsn(uint lsn) { set_field(&lsn, page_segment_last_lsn, 8); }

  void set_page_type(ushort type) {
    set_field(&type, page_segment_page_type, 2);
  }

  void set_flush_lsn(uint lsn) { set_field(&lsn, page_segment_flush_lsn, 8); }

  void set_space_id(uint space_id) {
    set_field(&space_id, page_segment_space_id, 4);
  }
    
  uint *get_checksum() { return (uint *)(ptr + page_segment_checksum); }

private:
  void set_field(void *value, uint offset, uint len) {
    memcpy(ptr + offset, value, len);
  }
};

#endif /* Page_segment_h */
