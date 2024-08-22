#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
   
    const char *srcFile = "sample.txt";
    const char *destFile = "copied.txt";

    int srcFd = open(srcFile, O_RDONLY);
    if (srcFd < 0) {
        perror("Error in source file");
    }

    int destFd = open(destFile, O_WRONLY | O_CREAT, 0644);
    if (destFd < 0) {
        perror("Error in destination file");
        close(srcFd);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(srcFd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(destFd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(srcFd);
            close(destFd);
        }
    }

    if (bytesRead < 0) {
        perror("Error reading from source file");
    }

    close(srcFd);
    close(destFd);

}