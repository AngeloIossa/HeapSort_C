#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

int main(int argc, char const *argv[])
{
    int array[LENGHT]={10,45,3,4,5,90,89,900};
    int choice;
    print_array(&array[0]);

    printf("Make your choice:\n");
    printf("1. Run max-heapify\n");
    printf("2. Run min-heapify\n");
    printf("3. Run BuildMaxheap\n");
    printf("4. Run BuildMinheap\n");
    printf("5. Run HeapSort (max-heap)\n");
    printf("6. Run HeapSort (min-heap)\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\nMaxHeap:\n");
        max_heapify(array, LENGHT, 0);
        print_array(&array[0]);
        break;
    case 2:
        printf("\nMinHeap:\n");
        min_heapify(array, LENGHT, 0);
        print_array(&array[0]);        
        break;
    case 3:
        printf("\nBuild max heap:\n");
        build_max_heap(&array[0]);
        print_array(&array[0]);
        break;
    case 4:
        printf("\nBuild min heap:\n");
        build_min_heap(&array[0]);
        print_array(&array[0]);
        break;
    case 5:
        printf("\nSort with heap-sort:\n");
        heap_sort(&array[0], MAXHEAP);
        print_array(&array[0]);
        break;
    case 6: 
        printf("\nSort with heap-sort:\n");
        heap_sort(&array[0], MINHEAP);
        print_array(&array[0]);
        break;
    default:
        break;
    }
    return 0;
}


