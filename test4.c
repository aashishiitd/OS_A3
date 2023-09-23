#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_mmu_boilerplate.h"


int main() {
    int* arr1 = (int*)my_calloc(5, sizeof(int));
    if (arr1 != NULL) {
        // Test case 1: Basic Test
        for (int i = 0; i < 5; i++) {
            arr1[i] = i;
        }
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr1[i]); // Should print 0 1 2 3 4
        }
        //free(arr1);
    } else {
        printf("Test case 1 failed: Allocation failed.\n");
    }

    int* arr2 = (int*)my_calloc(0, sizeof(int));
    if (arr2 != NULL) {
        // Test case 2: Zero Elements
        printf("Test case 2 failed: Did not return NULL for zero elements.\n");
        //free(arr2);
    }

    int* arr3 = (int*)my_calloc(5, 0);
    if (arr3 != NULL) {
        // Test case 3: Zero Element Size
        printf("Test case 3 failed: Did not return NULL for zero element size.\n");
        //free(arr3);
    }

    // Additional test cases can be added here

    // Check for memory leaks using Valgrind
    printf("Checking for memory leaks using Valgrind...\n");
    fflush(stdout);
    system("valgrind --leak-check=full ./your_program_name");

    return 0;
}
