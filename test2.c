#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "my_mmu_boilerplate.h"

#define NUM_ALLOCS 1000 // Number of allocations to test

int main() {
    void *pointers[NUM_ALLOCS];
    size_t sizes[NUM_ALLOCS];
    int i;

    // Allocate memory blocks of various sizes
    for (i = 0; i < NUM_ALLOCS; i++) {
        sizes[i] = rand() % 1024 + 1; // Random sizes from 1 to 1024 bytes
        pointers[i] = my_malloc(sizes[i]);
        
        if (pointers[i] == NULL) {
            printf("Memory allocation failed for allocation #%d (size %lu bytes).\n", i, sizes[i]);
            return 1;
        }

        // Fill the allocated memory with a known pattern (e.g., 0xAA)
        memset(pointers[i], 0xAA, sizes[i]);
    }

    // Check if the allocated memory contains the expected pattern
    for (i = 0; i < NUM_ALLOCS; i++) {
        for (size_t j = 0; j < sizes[i]; j++) {
            if (*((unsigned char *)pointers[i] + j) != 0xAA) {
                printf("Memory corruption detected in allocation #%d (size %lu bytes).\n", i, sizes[i]);
                return 1;
            }
        }
    }

    printf("Memory allocation and deallocation tests passed.\n");

    return 0;
}
