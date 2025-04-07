## Stack vs Heap

### Stack
- Memory space managed by OS, saves auto variables needed to run code
- Allocated in block, freed when execution finished (auto managed)
- Only accessed inside block
- Limited size (Ex. 1MB)
```c
#define DATASIZE_S (1024 * 1024) // about 1M

int main(void) {
    int stackMem[DATASIZE_S] = { 0 }; // STACK OVERFLOW

    return 0;
}
```

### Heap
- Memory space managed by user
- Allocated/freed whenever requested
- Can be accesssed in the scope of entire program (before memory is freed)
- Has largest size in system memory (or virtual memory) size (Ex. Hundreds of MB ~ Hundreds of GB)
```c
#define DATASIZE_H (1024 * 1024 ) // about 1M

int main(void) {
    int* heapMem[DATASIZE_H] = (int *)malloc(sizeof(int) * DATASIZE_H); // No error

    return 0;
}
```