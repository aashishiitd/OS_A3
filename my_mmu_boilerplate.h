#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 256

//Linked list structure to keep track of the blocks
typedef struct{
    size_t size;
    struct block* next;
}block;

//Global pointer to the start of the list
static void* list_start = NULL;

void* Initialize_list(){
    //Initialize the list with the first block 

    list_start = mmap(NULL, PAGE_SIZE*NUM_PAGES, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (list_start == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    block* first_block = (block*)list_start;
    first_block.size = init_size - sizeof(block);
    first_block.next = NULL;
    return list_start;
}
// You are not allowed to use the function malloc and calloc directly .


// Function to allocate memory using mmap
void* my_malloc(size_t size) {
    // Your implementation of my_malloc goes here
    if (list_start == NULL){
        list_start = Initialize_list();
    }
    block* current = (block*)list_start;
    while (current != NULL){
        if (current.size >= size){
            //Split the block
            if (current.size > size + sizeof(block)){
                block* new_block = (block*)((void*)current + sizeof(block) + size);
                new_block.size = current.size - size - sizeof(block);
                new_block.next = current.next;
                current.size = size;
                current.next = new_block;
            }
            return (void*)current + sizeof(block);
        }
        current = current.next;
    }
    

}

// Function to allocate and initialize memory to zero using mmap
void* my_calloc(size_t nelem, size_t size) {
    // Your implementation of my_calloc goes here
}

// Function to release memory allocated using my_malloc and my_calloc
void my_free(void* ptr) {
    // Your implementation of my_free goes here
}




