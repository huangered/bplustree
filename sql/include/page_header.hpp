//
//  page_header.h
//  game
//
//  Created by huang on 2018/1/7.
//  Copyright © 2018年 peter.huang. All rights reserved.
//

#ifndef page_header_h
#define page_header_h

class page_header {
private:
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

public:
  page_header() {}
};

#endif /* page_header_h */
