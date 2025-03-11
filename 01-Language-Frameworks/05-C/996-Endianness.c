#include <stdio.h>

int main(void) {
    unsigned int a = 0x00ABCDEF;
    printf("a : %x\n", a);

    unsigned char * pA = &a; // reads the first byte of a
    printf("pA, %s\n", pA);
    printf("*pA, %x\n", *pA);

    /**
     * little endian: 
     * 00ABCDEF -> saved as EF CD AB 00 
     * 
     * big endian: 
     * 00ABCDEF -> saved as 00 AB CD EF
     * 
     * if pA prints EF, the system uses little endian
     * if pA prints 00, the system uses big endian
     */
    
    return 0;
}