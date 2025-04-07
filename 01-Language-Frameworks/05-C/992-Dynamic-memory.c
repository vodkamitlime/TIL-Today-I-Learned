#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define DATASIZE 1024 

int main(void) {
    
    /**
     * ERROR:
     * 
     * int numValues = 0;
     * scanf("%d", &numValues);
     * int values[numValues] = {0};
     * 
     * WHY??
     * - variables declared in scope of main function are auto variables, saved in stack memory
     * - allocated when block (or function) starts, and the size should be decided in compile time
     * 
     * MEMORY
     * Static: managed by OS
     * - Text/Code
     * - Data
     * - Stack
     * 
     * Dynamic: manages by user
     * - Heap
     *   - Decides memory size in run-time
     *   - User has to allocate and free memory 
     *   - void * malloc(size_t size) --> size in bytes
     *     - allocates consecutive memory space of size in heap 
     *     - allocated memory has garbage value in it 
     *     - returns memory address (location: beginning)
     *   - void free(void* ptr)
     *     - frees dynamically allocated memory
     *     - has to pass on beginning memory address of memory, if not error might occur
     */

    int numValues = 0;
    scanf("%d", &numValues);

    int* values = (int*)malloc(sizeof(int)*numValues);
    memset(values, 0, sizeof(int) * numValues);

    for (int i = 0; i < numValues; i++) {
        scanf("%d ", &values[i]);
    }
    for (int i = 0; i < numValues; i++) {
        printf("%d ", values[i]);
    }

    if (values != NULL) {
        free(values);
        values = NULL;
    }

    /**
     * Memory Leak:
     * - happens when allocated memory not freed
     * 
     * Dangling pointer:
     * - pointer that points to freed memory
     * - prevention method: initialize pointer value to NULL after free()
     * 
     * Garbage value
     * - garbage value in malloced space
     * - initialize memory by using 
     *   - void* memset(void *dest, int c, size_t count);
     *      - fills memory with defined value
     *      - dest: beginning memory address 
     *      - c: value to fill (1-byte)
     *      - count: size to fill (bytes)
     *   - void* memcpy(void *dest, const void *src, size_t count);
     *      - copies memory value from src to dest
     *      - dest: beginning memory address of where value will be copied
     *      - src: beginning memory address of where value to copy exists
     *   - void* calloc(size_t number, size_t size);
     *      - number: number of elements
     *      - size: each element's size in bytes
     *      - initializes allocated memory to 0
     */

    int array[DATASIZE] = {0};
    for (int i = 0; i < DATASIZE; i++) {
        array[i] = i;
    }

    int* ptr = (int*)malloc(sizeof(int) * DATASIZE);
    printf("ptr[10] = %d\n", ptr[10]);

    memset(ptr, 0, sizeof(int) * DATASIZE);
    printf("ptr[10] = %d\n", ptr[10]);

    memcpy(ptr, array, sizeof(int) * DATASIZE);
    printf("ptr[10] = %d\n", ptr[10]);

    if (ptr != NULL) {
        free(ptr); 
        ptr = NULL;
    }
    
    return 0;
}