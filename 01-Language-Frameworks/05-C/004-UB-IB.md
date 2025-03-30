## UB and IB

### UB
- Undefined Behavior
- Something that is not defined in C standard 
- It makes a program unpredictable, and leads the compiler to optimize code as it wants
- Program can end up crashing or print strange results 
- Example:
```c
#include <stdio.h>

int main() {
    int x = 10;
    int y = 0;
    int z = x / y;  // divide by 0 in integer division -> UB
    printf("%d\n", z);

    // Some systems end up crashing, others end up printing unexpected value 

    return 0;
}
```
- Cases of UB
    - Accessing out of array bounds
    - Dereferencing a NULL pointer
    - Reading an uninitialized variable (using a variable that hasn't been initialized)
    - Improper type casting (e.g., converting an integer to a pointer and then dereferencing it)
    - Signed integer overflow (e.g., INT_MAX + 1)
    - Accessing memory after it has been freed (use-after-free)
    - Writing to the same variable multiple times in an expression (e.g., i = i++ + i++;)

### IB
- Implementation-defined Behavior
- Behavior that is not defined in C standard, but is defined by the implementation (compiler, OS, architecture)
- It doesn't do strange things like UB, but the result may vary depending on the platform
- Example:
```c
#include <stdio.h>
int main() {
    int x = -5;
    unsigned int y = 3;
    int z = x % y;  // 음수 % 양수의 결과는 구현에 따라 다를 수 있음
    printf("%d\n", z);
    return 0;
}
```
- The result of -5 % 3 can be different depending on the implementation, because it is not defined in the C standard
- Cases of IB
    - The size of the basic data types (int, long, char, etc.)
    - The range of the basic data types (INT_MIN, INT_MAX, etc.)
    - The char type's signedness (signed char or unsigned char)
    - The result of integer division with negative numbers (-5 % 3)
    - The order of bit fields (MSB or LSB)
    - The endianness of the system (Big-endian vs. Little-endian)