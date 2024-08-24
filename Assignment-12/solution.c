#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void openingMode(int flags) {
    if (flags & O_RDONLY) {
        printf("File is opened in read-only mode.\n");
    }
    if (flags & O_WRONLY) {
        printf("File is opened in write-only mode.\n");
    }
    if (flags & O_RDWR) {
        printf("File is opened in read-write mode.\n");
    }
    if (flags & O_APPEND) {
        printf("File is opened in append mode.\n");
    }
    if (flags & O_CREAT) {
        printf("File is opened with O_CREAT flag (create file if it does not exist).\n");
    }
}

int main() {
    
    const char *destFile = "sample.txt";

    int fd = open(destFile, O_RDWR , 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Value of flag in decimal is %d\n", flags);

    openingMode(flags);

    close(fd);
    return 0;

}