//
//  main.cpp
//  allSorts
//
//  Created by apple on 2020/7/6.
//  Copyright © 2020 apple. All rights reserved.
//

#include <iostream>
#include "allSorts.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int array[] ={1000,200,120,2000,1,0,1300,15};
    sortArray arrayObj (array, 8);
    arrayObj.countSort();
    arrayObj.printArray();
}
