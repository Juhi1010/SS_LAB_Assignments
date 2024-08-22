#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    
    const char *filePath = "sample.txt";

    int fd1 = open(filePath, O_RDWR);

    if (fd1 < 0) {
        perror("error");
    }

    printf("File descriptor fd1: %d\n", fd1);

    int fd2 = open(filePath, O_CREAT | O_EXCL);

    if (fd2 < 0) {
        perror("Error creating file since it already exists");
    }
    else printf("File descriptor fd2: %d\n", fd2);

}