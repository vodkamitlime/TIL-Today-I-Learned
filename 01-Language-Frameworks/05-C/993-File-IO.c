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

    return 0;
}