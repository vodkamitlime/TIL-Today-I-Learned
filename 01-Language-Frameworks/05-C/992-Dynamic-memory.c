#include <stdio.h>

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
     * Static:
     * - Text/Code
     * - Data
     * - Stack
     * 
     * Dynamic:
     * - Heap
     */

    return 0;
}