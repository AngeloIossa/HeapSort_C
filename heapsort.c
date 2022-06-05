#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"


/*
 *  Swap function 
*/
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 *  Print array function 
*/
void print_array (int *array)
{
    int i;
    printf("Array: ");
    for (i = 0; i < LENGHT; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*
 *  Max Heapify function
 *  Maintains the property of heap 
*/
void max_heapify (int *array, int lenght, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left_child = (2*i)+1;
    int right_child = left_child+1;

    if(left_child < lenght && array[left_child] > array[largest]) {
        largest = left_child;
    }

    if(right_child < lenght && array[right_child] > array[largest]) {
        largest = right_child;
    }

    // Swap and continue heapifying if root is not largest
    if(largest != i) {
        swap(&array[i], &array[largest]);
        max_heapify(array, lenght, largest);
    }

}

/*
 *  Min Heapify function
 *  Maintains the property of heap 
*/
void min_heapify (int *array, int lenght, int i)
{
    // Find largest among root, left child and right child
    int smallest = i;
    int left_child = (2*i)+1;
    int right_child = left_child+1;

    if(left_child < lenght && array[left_child] < array[smallest]) {
        smallest = left_child;
    }

    if(right_child < lenght && array[right_child] < array[smallest]) {
        smallest = right_child;
    }

    // Swap and continue heapifying if root is not largest
    if(smallest != i) {
        swap(&array[i], &array[smallest]);
        min_heapify(array, lenght, smallest);
    }

}

/*
 *  Build max heap function
 *  Maintains the property of heap 
*/
void build_max_heap (int *array)
{
    int i;
    // The first index of a non-leaf node is given by n/2 - 1
    // Run max-heapify for all subtrees
    for (i = (LENGHT/2)+1; i >= 0; i--)
    {
        max_heapify(&array[0], LENGHT, i);
        //print_array(&array[0]);   debug
    }
}


/*
 *  Build min heap function
 *  Maintains the property of heap 
*/
void build_min_heap (int *array)
{
    int i;
    // The first index of a non-leaf node is given by n/2 - 1
    // Run max-heapify for all subtrees
    for (i = (LENGHT/2)+1; i >= 0; i--)
    {
        min_heapify(&array[0], LENGHT, i);
        //print_array(&array[0]);   debug
    }
}

/*
 *  HeapSort function
 *  Algorithm to sort an array 
 *  type_heap: choice if you want to sort width max or min heap
*/
void heap_sort (int *array, int type_heap)
{
    int i, lenght;
    lenght = LENGHT;
    if(type_heap == MAXHEAP){
        build_max_heap(&array[0]);
        for (i = (LENGHT-1); i >= 0; i--)
        {
            swap(&array[0], &array[i]);
            lenght--;
            max_heapify(&array[0], lenght, 0);
        }    
    }
    if(type_heap == MINHEAP){
        build_min_heap(&array[0]);
        for (i = (LENGHT-1); i >= 0; i--)
        {
            swap(&array[0], &array[i]);
            lenght--;
            min_heapify(&array[0], lenght, 0);
        }    
    }

}