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
    int array[] ={100,200,120,50,60,1,3,2,78,0,32,15};
    sortArray arrayObj (array,12);
    arrayObj.improvedCountSort();
    arrayObj.printArray();
}
