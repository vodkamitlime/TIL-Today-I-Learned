## Call by Reference in C
- Main topic: Does call by reference exist in C?

### Call by value, call by reference
- call by value
    - is a way of transferring the original value of a data in a function's parameter
    - value is copied, thus changes made to it inside a function's scope does not effect the original value of the variable
    - what does it mean for a value to be copied? a new stack variable is created in the stack frame
```c
    // C

    void cbv(int a) {
        a = 3;
    }

    int main(void) {
        int a = 0;
        cbv(a);

        // value of a is still 0
        return 0;
    }
```
- call by reference
    - is a way of transferring not the original value of the data, but a reference to it in a function's parameter
    - value is aliased, meaning the parameter is directly bound to the original variable to be referenced 
    - there is no separate memory allocated, it does not have its own memory. 
    - works similarly to implicit constant pointers (in which its memory address cannot be reassigned after initialization)
```c++
    // Cpp

    void cbr(int & a) {
        a = 3;
    }

    int main(void) {
        int a = 0;
        cbr(a);

        // value of a 3
        return 0;
    }
```

### Call by reference in C?
- Explicitly speaking, call by reference doesn't exist in C
- Everthing is copied when parameters are passed on
- However, passing pointers as a parameter implements a similar behavior
- Parameter is copied and is allocated an independent memory block, however it contains the memory address of the original value
```c
    // C

    void pointerParam(int * b) {
        *b = 3;
    }

    int main(void) {
        int a = 0;          // a's memory address (example): 0xFF 
        pointerParam(&a);   // a's memory address is copied 
        // parameter int * b 's memory address (example): 0xEE
        // value of b = 0xFF 

        // value of a 3
        return 0;
    }
```