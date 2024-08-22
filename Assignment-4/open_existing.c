#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    
    const char *filePath = "sample.txt";

    int fd1 = open(filePath, O_RDWR);

    if (fd1 < 0) {
        perror("error");
        // exit(1);
    }

    printf("File descriptor fd1: %d\n", fd1);

    // const char *filePath2 = "example.txt";

    int fd2 = open(filePath, O_CREAT | O_EXCL);

    if (fd2 < 0) {
        perror("Error creating file since it already exists");
        // exit(1);
    }
    else printf("File descriptor fd2: %d\n", fd2);

}