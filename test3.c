#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_mmu.h"

#define NUM_ALLOCS 1000 // Number of allocations to test
#define MAX_SIZE    1024 // Maximum allocation size (bytes)

int main() {
    void *pointers[NUM_ALLOCS];
    size_t sizes[NUM_ALLOCS];
    int i;

    // Initialize random number generator
    srand(time(NULL));

    // Allocate memory blocks of various sizes
    for (i = 0; i < NUM_ALLOCS; i++) {
        sizes[i] = rand() % MAX_SIZE + 1; // Random sizes from 1 to MAX_SIZE bytes
        
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

    // Check for memory leaks using a memory debugging tool like Valgrind or AddressSanitizer
    // Optionally, add a call to these tools here

    printf("Memory allocation and deallocation tests passed.\n");
    info();
    return 0;
}
