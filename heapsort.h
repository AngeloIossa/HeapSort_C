#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

#define LENGHT 8
#define MAXHEAP 0
#define MINHEAP 1


void swap (int *a, int *b);
void print_array (int *array);
void max_heapify (int *array, int lenght, int i);
void min_heapify (int *array, int lenght, int i);
void build_max_heap (int *array);
void build_min_heap (int *array);
void heap_sort (int *array, int type_heap);


#endif