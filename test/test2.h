//
//  test2.h
//  game
//
//  Created by huang on 2017/12/29.
//  Copyright © 2017年 peter.huang. All rights reserved.
//

#ifndef test2_h
#define test2_h

#include "gtest/gtest.h"
#include "page.hpp"
#include <iostream>
#include "buffer.hpp"

namespace {
    TEST(PageTest, Insert) {
        linn::buffer* buffer = new linn::buffer(10000);
        linn::page *page = new linn::page(buffer);
        for(int i =0;i<=10;i++){
            page->insert(i,i);
        }
        
        linn::record* temp = page->get_first_record();
        linn::record* end = page->get_last_record();
        while(temp!=nullptr) {
            std::cout<<temp->key<<":"<<temp->value<<std::endl;
            temp=temp->next;
    }
    }
}

#endif /* test2_h */
