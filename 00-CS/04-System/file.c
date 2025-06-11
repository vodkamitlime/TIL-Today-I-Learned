#include <sys/types.h>
#include <sys.stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd;
    mode_t mode;

    mode = S_IRUSR | S_IWUSR;

    // fd = open("hello.txt", O_CREAT, mode);       // O_CREAT creates file if doesn't exist
    fd = open("hello.txt", O_CREAT | O_EXCL, mode); // O_EXCL, when used together with O_CREAT, creates file if doesn't exist but prints error if file already exists
    if (fd == -1) {
        perror("Creat");
        exit(1);
    }
    close(fd);

    int rfd, wfd, n;
    char but[10];

    rfd = open("hello.txt", O_RDONLY);
    if (rfd == -1) {
        perror("Open hello.txt");
        exit(1);
    }

    wfd = open("hello.bak", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if (wfd = -1) {
        perror("Open hello.bak");
        exit(1);
    }

    while((n = read(rfd, buf, 6)) > 0)
        if (write(wfd, buf, n) !=n) perror("write");

    if (n == -1) perror("Read");
    close(rfd);
    close(wfd);

    return 0;
}