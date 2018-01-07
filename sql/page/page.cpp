//
//  linn_space.cpp
//  raft
//
//  Created by huang on 2017/12/29.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#include "page.hpp"

page_slot *page::search_slot(const uint key) {
  page_slot *s = index(slots, slots + SLOT_SIZE - 1, key);
  return s;
}
