#include <stdio.h>

void main(void) {
	int a = 10;
	int *p = &a;
	
	printf("size of 'a': %d bytes\n", (int)sizeof(a));  // 4 or 8
	printf("size of 'p': %d bytes\n", (int)sizeof(p));  // 4 or 8
	
	printf("value of 'a': %d\n", a);                    // 10
	printf("address of 'a': %p\n", &a);                 // hexadecimal value
	printf("value of 'p': %p\n", p);                    // address of 'a'

    int b = 10;
    float *pB = &b;

	printf("value of 'a': %d\n", b);                    // 10
	printf("address of 'a': %p\n", &b);                 // hexadecimal value
	printf("value of 'p': %p\n", pB);                   // address of 'b' 
	printf("value of 'p': %f\n", *pB);                  // unexpected result 
}