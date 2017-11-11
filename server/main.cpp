//
//  main.cpp
//  kkkk
//
//  Created by peter.huang on 12/11/2017.
//  Copyright © 2017 peter.huang. All rights reserved.
//
#include <assert.h>
#include "btree.hpp"
#include "server.hpp"
#include <iostream>
#include <list>
//#include <memory>

using namespace std;

int find1(std::vector<int> data, int key);

int main(int argc, const char *argv[]) {
   
    linn::tree<int, int> root ;
  for (int i = 1; i <= 30000; i++) {
      
      root.insert(30000-i, 30000-i);
  }
    int t=123;
    linn::tree<int,int>::iterator i = root.find(t);
    if(i != root.end()){
    assert(*i==t);
    }
    linn::tree<int,int>::iterator first = root.begin();

    while(first!=root.end()) {
        std::cout<<*first<< " "<<std::endl;;
        first++;
    }
  return 0;
}

int find1(std::vector<int> data, int key) {
  int low = 0, high = (int)data.size();
  while (low != high) {
    int mid = (high + low) / 2;
    cout << "high " << high << " mid " << mid << " low " << low << " value "
         << data[mid] << endl;
    if (data[mid] < key) {
      low = mid + 1;
    } else if (data[mid] == key) {
      low = high = mid;
      break;
    } else {
      high = mid;
    }
  }
  return low;
}
