#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
   
    const char *fileToRead = "sample.txt";

    int Fd = open(fileToRead, O_RDONLY);
    
    if (Fd < 0) {
        perror("Error in source file");
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(Fd, buffer, BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
    }

    printf("\n");
    if (bytesRead < 0) {
        perror("Error reading from source file\n");
    } else printf("Read success");

    close(Fd);
}