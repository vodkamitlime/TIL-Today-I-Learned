#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 255

int main(void) {

    /**
     * fopen() mode:
     * - r: read
     * - w: write, overwrites existing file or creates new file
     * - a: append
     */

    char * filename = "test.txt";
    FILE * fp = fopen(filename, "w");

    if (fp == NULL) { 
        printf("Failed to open file\n");
        return 1;
    }
    printf("File opened successfully\n");

    fclose(fp);
    printf("File closed successfully\n"); 


    /**
     * FILE I/O functions
     *                  READ  | WRITE
     * Character I/O    fgetc | fputc
     * String I/O       fgets | fputs
     * Formatted I/O    fscanf | fprintf
     * Binary I/O       fread | fwrite
     */

    // Character I/O
    fp = fopen(filename, "w");
    fputc('a', fp);
    fputc('b', fp);
    fputc('1', fp);
    fclose(fp);

    fp = fopen(filename, "r");
    char c = 0;
    while((c = fgetc(fp)) != EOF) {
        printf("%c\n", c);
    }
    fclose(fp);

    // String I/O
    char srcName[BUFFER_SIZE] = "test.txt";
    char dstName[BUFFER_SIZE] = "test1.txt";
    FILE * fpSrc = NULL, *fpDst = NULL;
    if ((fpSrc = fopen(srcName, "r")) == NULL) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(-1);
    }

    if((fpDst = fopen(dstName, "w")) == NULL) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(-1);
    }

    char buffer[BUFFER_SIZE] = { 0 };
    while(fgets(buffer, BUFFER_SIZE, fpSrc) != NULL) {
        fputs(buffer, fpDst);
    }

    fclose(fpSrc);
    fclose(fpDst);

    // Formatted I/O
    int ID;
    char name[8];
    float score;

    fp = fopen("test2.txt", "r");
    fscanf(fp, "%d %s %f\n", &ID, name, &score);
    fprintf(fp, "%d %s %f\n", ID, name, score);
    fclose(fp);

    // Binary File - read and write memory as it is
    /**
     * - rb, read binary
     * - wb, write binary
     * - ab, append binary
     */
    int data[5] = { 10, 20, 30, 40, 50 };
    FILE * binFp = NULL;

    if (!(binFp = fopen("binary.bin", "wb"))) {
        fprintf(stderr, "Fail to open the file - %s,\n", "binary.bin");
        exit(1);
    }

    int i = fwrite(data, sizeof(int), 5, binFp);
    printf("Success to write %d object(s).\n", i);

    fclose(binFp);

    int buf[5] = { 0 };
    binFp = fopen("binary.bin", "rb");
    i = fread(buf, sizeof(int), 5, binFp);
    for (int i = 0; i < 5; i++) {
        printf("%d ", buf[i]);
        prtinf("\n");
    }

    /**
     * ascii file vs binary file
     * - if same data is saved, binary file uses less space 
     * - ascii file takes up more space because it needs conversion from binary data to readable characters
     * - ascii file needs read/write logic line by line 
     * - whereas binary file saves/reads raw data directly
     */

    /**
     * File sequential access
     * - the access logic above was sequential access
     * - fopen(), fread(), fwrite()...
     * - fopen() creates a file pointer pointing to the beginning of file ("a" mode points to end of file)
     * - when I/O is processed, the file pointer moves sequentially
     * 
     * File random access
     * - moving file pointer and processing I/O in random areas 
     * - fseek(FILE* fp, long offset, int origin) 
     *   - offset: bytes to move from origin
     *   - origin: where to start
     * - rewind(FILE* fp)
     *   - ininitalizes file pointer location to 0
     * - ftell(FILE* fp)
     *   - returns current file pointer location
     */

    FILE * randFp = fopen("test.txt", "w");
    fputs("1234567890", randFp);
    fclose(fp);

    randFp = fopen("test.txt", "r");
    fseek(randFp, 3, SEEK_SET); // start of file
    printf("fseek(randFp, 3, SEEK_SET) = %d \n", fgetc(randFp));
    fseek(randFp, -2, SEEK_END); // end of file
    printf(" fseek(randFp, -2, SEEK_END) = %d \n", fgetc(randFp));
    

    return 0;
}