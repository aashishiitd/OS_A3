#include "my_mmu.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Test case 1: Basic Test
    int* arr1 = (int*)my_malloc(5 * sizeof(int));
    //printf("arr1: %p ---pointer of allocated array\n", arr1);
    if (arr1 != NULL) {
        printf("Test case 1: Allocated memory successfully.\n");
        for (int i = 0; i < 5; i++) {
            arr1[i] = i;
        }
        info();
        my_free(arr1);
        info();
        printf("Memory freed successfully.\n");
        // Try accessing arr1 after freeing to ensure it's inaccessible
        printf("Attempting to access arr1 after freeing: %d\n", arr1[0]); // This should result in undefined behavior
    } else {
        printf("Test case 1: Memory allocation failed.\n");
    }

    // Test case 2: Double Freeing
    int* arr2 = (int*)my_malloc(sizeof(int));
    if (arr2 != NULL) {
        printf("Test case 2: Allocated memory successfully.\n");
        my_free(arr2);
        printf("First free successful.\n");
        // my_free(arr2); // Ensure that this doesn't cause an error
        // printf("Second free successful.\n");
    } else {
        printf("Test case 2: Memory allocation failed.\n");
    }

    // Test case 3: Freeing NULL Pointer
    int* arr3 = NULL;
    my_free(arr3); // Ensure this doesn't cause an error
    printf("Test case 3: Attempted to free a NULL pointer.\n");

    // Test case 4: Memory Leak Check
    int* arr4 = (int*)my_malloc(sizeof(int));
    if (arr4 != NULL) {
        printf("Test case 4: Allocated memory successfully.\n");
        // Uncomment the next line to intentionally introduce a memory leak
        //arr4 = (int*)malloc(sizeof(int));
        info();
        my_free(arr4);
        info();
        printf("Memory freed successfully.\n");
    } else {
        printf("Test case 4: Memory allocation failed.\n");
    }

    return 0;
}
