//
//  aux.h
//  raft
//
//  Created by huang on 2018/1/1.
//  Copyright © 2018年 peter.huang. All rights reserved.
//

#ifndef aux_h
#define aux_h

#include <stdlib.h>

#include <iostream>

#include "page_slot.h"

typedef unsigned char byte;

ushort checksum(ushort *ptr, uint len);

bool validate_checksum(ushort *ptr, uint len);

page_slot *index(page_slot *start, page_slot *end, const uint key);

#endif /* aux_h */
