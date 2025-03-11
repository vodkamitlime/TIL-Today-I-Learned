#include <stdio.h>

void swapArray1(int ** _arrA, int ** _arrB) {
    int * tmpArr = *_arrA;
    *_arrA = *_arrB;
    *_arrB = tmpArr;
}

void printArray(int * _arr) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", _arr[i]);
    }
    printf("\n");
}

int main(void) {

    int a = 10;
    int * p = &a;
    int ** dP = &p;

    printf("value of a, %d\n", a);
    printf("value of *a, %p\n", &a);
    printf("value of p, %p\n", p);
    printf("value of *p, %p\n", &p);
    printf("value of dP, %p\n", dP);
    printf("value of *dP, %p\n", *dP);
    printf("value of **dP, %d\n", **dP);

    int arrA[5] = { 1, 2, 3, 4, 5 };
    int arrB[5] = { 6, 7, 8, 9, 10 };

    printf("sizeof: %d\n", (int)sizeof(arrA));

    int * pA = arrA;
    int * pB = arrB;
    swapArray1(&pA, &pB);

    printArray(arrA);
    printArray(arrB);
    printf("--------\n");
    printArray(pA);
    printArray(pB);

    /**
     * TIP:
     * - because arrA, arrB are variable names of arrays, you may thing swapArray(&arrA, &arrB) might work
     * - But this throws the error : incompatible pointer types passing 'int (*)[5]' to parameter of type 'int **' [-Wincompatile-pointer-types]
     * - Why??
     *      - Type of &arrA is NOT int **, but is int (*)[5], meaning it is a pointer pointing to an array that consists of 5 int elements
     *      - This results in type mismatch
     * - Reference: 
     * - https://stackoverflow.com/questions/4607128/in-c-are-arrays-pointers-or-used-as-pointers
     * - "Arrays are not pointers, though in most expressions an array name evaluates to a pointer to the first element of the array. 
     *    So it is very, very easy to use an array name as a pointer. You will often see the term 'decay' used to describe this, as in "the array decayed to a pointer"."
     */

    int c[2] = { 2, 4 };
    int * tC = c;
    int (*pC)[2] = &c;

    printf("c %p\n", c);    // 0x7ff7bfeff018
    printf("tC %p\n", tC);  // 0x7ff7bfeff018
    printf("pC %p\n", *pC); // 0x7ff7bfeff018

    printf("tC++ %p\n", ++tC);      // 0x7ff7bfeff01c  --> 4 bytes added (one int element)
    printf("pC++ %p\n", *(++pC));   // 0x7ff7bfeff020  --> 8 bytes added (sizeof(c))

    // Multiple Pointers and Arrays
    char nameA[3] = { 'A', 'B', 'C'};
    char nameB[3] = { 'D', 'E', 'F'};
    int levelA[3] = { 1, 2, 3 };
    int levelB[3] = { 4, 5, 6 };

    void * ppA[2] = { nameA, levelB };
    void * ppB[2] = { nameB, levelA };

    void ** pppA = ppA;
    void ** pppB = ppB;

    return 0;
}