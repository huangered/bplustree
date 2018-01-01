//
//  main.cpp
//  raft
//
//  Created by peter.huang on 08/12/2017.
//  Copyright © 2017 peter.huang. All rights reserved.
//

#include <iostream>
#include "aux.h"
#define byte unsigned char
typedef byte page_t;

int main(int argc, const char *argv[]) {
  // insert code here...
  //std::cout << "Hello, World!\n";

    //std::cout<<sizeof(page_t)<<std::endl;
    
    page_t* p = (page_t*)malloc(65535);
    int i=7;
    for(int i =0;i<=10;i++){
        page_t* q = p+i;
        std::cout<<(uint)(*q)<<":"<<std::hex<<(void*)q<<std::endl;
    }
    std::cout<<"------"<<std::endl;
    memcpy(p, &i, size_t(i));
    for(int i =0;i<=10;i++){
        page_t* q = p+i;
        std::cout<<(uint)(*q)<<":"<<std::hex<<(void*)q<<std::endl;
        print_point_addr(q);
    }
    int *qq = (int*)p;
    std::cout<<*qq<<std::endl;
    free(p);
    return 0;
}
