//
//  allSorts.hpp
//  allSorts
//
//  Created by apple on 2020/8/28.
//  Copyright © 2020 apple. All rights reserved.
//

#ifndef allSorts_hpp
#define allSorts_hpp

#include <stdio.h>


class sortArray
{
private:
    int array [50];
    int len;
    void merge(int front, int end); //sorted array merging
    void swap(int index1, int index2); //element swapt method
    int partition(int part_array[], int front, int end);
    int findMax(void);
    
public:
    sortArray(int array[], int len);    //constructor
    void printArray(void);              //array printer function
    
    //sort methods
    void rmergeSort(int front, int end);//recursive merge sort
    void imergeSort(int front, int end);//iterative merge sort
    void bubbleSort(void);
    void insertionSort(void);
    void selectionSort(void);
    void quickSort(int front, int end);
    void countSort(void);
};

typedef struct
{
    
}listNode;

#endif /* allSorts_hpp */
