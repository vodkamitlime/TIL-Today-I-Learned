## Void Pointer Casting in C

### What are void pointers?
- Pointers that save memory addresses without specifying the data type of the value to be pointed
- In other words, it can save the memory address of values without having a predefined data type
- Syntax
```c
void * voidPointer;
```

### Size of void pointers 
- Occupies same memory space just like any other pointer
- 4 bytes on 32-bit system
- 8 bytes on 64-but system

### Attributes
- Does not support dereferencing
    - Ex. `*voidPointer = 1; // unsupported` 
- Does not support arithmatic calculation
    - Ex. `voidPointer++; // compiler doesn't know how many bytes to add`
- Can be casted to a pointer that specifies a data type
    - This is a common attribute of all pointers 
    - Ex. `void * -> int * / int * -> float *`
```c
int intVar = 0;
float floatVar = 0.f;
void * vP = NULL;

vP = &intVar;  // ok
vP = &floatVar;// ok

printf("%d", *vP); // Error, does not allow dereferencing
printf("%d", *((int*)vP)); // ok, explicit type cast
```

### Other attributes 
- Void pointers have a powerful effect when combined with functions
    
    ```c
    // instead of this,
    sumInt(int*, int*)
    sumFloat(float*, float*)
    sumDouble(double*, double*)
    
    // Use void pointers to increase efficiency
    sum(void*, void*) // -> pass on type together and cast the void pointer according to the type
    ```
    
### How does type casting work with void pointers in function parameters?
```c
// the function
sum (void*, void*);

// the code
int a = 1, b = 2;
sum(&a, &b);

// At which point is &a casted to a void pointer?
```
- implicit type casting occurs
- not automatic: void * -> specific pointer type
- automatic: specific pointer type (int *) -> void *