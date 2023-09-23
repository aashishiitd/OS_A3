#include<stdio.h>
#include<stdlib.h>
#include "my_mmu.h"

int main()
{   
    int *ptr = (int *)my_malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    *ptr = 42;
    printf("Allocated memory contains: %d\n", *ptr);



    int *ptr1 = (int *)my_malloc(sizeof(int));
    int *ptr2 = (int *)my_malloc(sizeof(int));
    
    if (ptr1 == NULL || ptr2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *ptr1 = 42;
    *ptr2 = 100;

    printf("ptr1: %d\n", *ptr1);
    printf("ptr2: %d\n", *ptr2);
    return 0;
}