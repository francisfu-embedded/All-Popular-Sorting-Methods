//
//  allSorts.hpp
//  allSorts
//
//  Created by Francis Fu
//

#ifndef allSorts_hpp
#define allSorts_hpp

#include <stdio.h>
#include <iostream>

class sortArray
{
private:
    int array [50];
    int len;
    const int de_bruijn_lookup[32] = {0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
        31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9};
    void merge(int front, int end); //sorted array merging
    void swap(int index1, int index2); //element swapt method
    int partition(int part_array[], int front, int end);
    int findMax(void);
    int getBitIndex (uint32_t bitHolder);

    
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
    void improvedCountSort(void); 
    
};

typedef struct
{
    
}listNode;

#endif /* allSorts_hpp */
