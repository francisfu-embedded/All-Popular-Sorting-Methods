//
//  allSorts.cpp
//  allSorts
//
//  Created by Francis Fu on 2020/8/28.
//  Copyright © 2020 apple. All rights reserved.
//

#include "allSorts.hpp"
#include <iostream>
using namespace std;

sortArray :: sortArray(int array[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        this->array[i] = array[i];
    }
    this->array[len] = INT_MAX;
    this->len = len;
}

void sortArray :: printArray (void)
{
    int i;
    for(i=0; i<len; i++)
    {
        cout<<this->array[i]<<"  ";
    }
    
    cout<<endl;
}

void sortArray :: merge (int front, int end)
{
    int* arr = new int[50];
    int mid = (front + end)/2;  //get the mid point
    int i = front;
    int j = mid + 1;
    int k = front;
    
    while ((i <= mid) && (j<= end))
    {
        //find the smaller element between two sorted lists, copy & increment index
        if(this->array[i] < this->array[j])
        {
            arr[k++] = this->array[i++];
        }
        else
        {
            arr[k++] = this->array[j++];
        }
    }
    
    // copy the rest that are not compared to the temporary array
    for(; i<= mid;i++)
        arr[k++] = this->array[i];
    
    for(; j<= end;j++)
        arr[k++] = this->array[j];
    
    for(k = front; k <= end; k++)
        this->array[k] = arr[k];
    
    delete[] arr;
}

//swap the value of the array elements corresponding to the two input index
void sortArray :: swap (int index1, int index2)
{
    int temp = this->array[index1];
    this->array[index1] = this->array[index2];
    this->array[index2] = temp;
}

//partition, used as part of quick sort
int sortArray :: partition (int part_array[], int front, int end)
{
    int pivot = part_array[front];
    int i = front;
    int j = end;
    
    do
    {
        do {i++;} while(part_array[i] <= pivot);
        do {j--;} while(part_array[j] > pivot);
        if(i<j)
            swap(i, j);
    }   while (i<j);
    
    //create new pivot value
    swap(front, j);
    
    //return the centre of the array
    return j;
}

void sortArray :: bubbleSort (void)
{
    
    int swapFlag = 0;
    //a bubble sort's outer loop takes array_length - 1 times
    for ( int i = 0; i < this->len-1; i++ )
    {
        //the inner loop takes array_length - 1 - outer_loop_index times
        //since each cycle of the outer loop sorts one largest elements
        for (int j = 0 ; j< this->len-1 - i; j++)
        {
            if(this->array[j] > this->array[j+1])
            {
                this->swap(j,j+1);
                swapFlag = 1;
            }
        }
        
        //acount for scenario where the array is already in a sorted order
        if(swapFlag == 0)
            break;
    }
}

void sortArray :: insertionSort(void)
{
    // the outer loop continues to "swallow" new elements into the sorted list on the left
    // as long as the new elements is larger than the "frontier" of the sorted list
    for (int i = 1; i < this->len; i++)
    {
        // when a smaller element is encountered by the "frontier", do multiple swaps
        // till this element is situated at a place that it is smaller than one before it
        if(this->array[i] < this->array[i-1])
        {
            for(int j = i; j > 0; j--)
            {
                if(this->array[j] < this->array[j-1])
                {
                    this->swap(j, j-1);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void sortArray :: selectionSort(void)
{
    
    for (int i = 0; i < this->len - 1 ; i++)
    {
        int k = i;
        
        for(int j = i+1 ; j < this->len; j++)
        {
            if(this->array[j] < this->array[k])
            {
                k = j;
            }
        }
        this->swap(i, k);
    }
}

void sortArray :: quickSort(int front, int end)
{
    int center;
    if(front < end)
    {
        center = partition(this->array, front, end);
        quickSort(front,center);
        quickSort(center+1,end);
    }
}

void sortArray:: rmergeSort(int front, int end)
{
    int mid = (front + end)/2;
    if(mid != front)
    {
        rmergeSort(front, mid);
        rmergeSort(mid+1, end);
    }
    merge(front,end);
}

void sortArray:: imergeSort(int front, int end)
{
    int p;
    for( p = 2; p <= this->len; p*=2)
    {
        for(int i = 0; i < (this->len); i+=p)
        {
            merge(i, (i + p - 1));
        }
    }
}



