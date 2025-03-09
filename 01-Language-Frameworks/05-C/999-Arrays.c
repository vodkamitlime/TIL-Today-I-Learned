#include <stdio.h>

void funcByArray(int input[]) {
    printf("value of 'input' : %p\n", input); // 0x7ff7bfeff050
    printf("value of 'input' : %d\n", input); // -1074794416
    printf("value of 'input' : %p\n", input[0]); // 0x1
    printf("value of 'input' : %d\n", input[0]); // 1
    printf("value of 'input' : %p\n", input[3]); // 0x4
    printf("value of 'input' : %d\n", input[3]); // 4
}

void funcByPointer(int * input) {
    printf("---funcByPointer\n");
    printf("value of 'input' : %p\n", input[3]); // 0x4
    printf("value of 'input' : %d\n", input[3]); // 4
}

void main(void) {
    int a[5] = { 1, 2, 3, 4, 5 };
    printf("value of 'a' : %p\n", a); // 0x7ff7bfeff050
    printf("-----\n");
    funcByArray(a);
    funcByPointer(a);

    char arr[10];
    arr[2] = 10; // when compiled, this code is translated to *(arr + 2) = 10

    int * pArr = a;
    for (int i = 0; i < 5; i++) {
        printf("%p, %d\n", pArr, *pArr);
        pArr++; // next element in array
    }

    
}
