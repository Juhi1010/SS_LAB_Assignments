#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {

    const char *destFile = "sample.txt";
    
    int fd, fd1, fd2, fd3;
    char data[50] = "Appending data using dup, dup2, and fcntl\n";
 
    fd = open(destFile, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    fd1 = dup(fd);  // using dup
    if (fd1 == -1) {
        perror("dup");
        close(fd);
        return 1;
    }

    fd2 = dup2(fd, fd + 1);  // using dup2
    if (fd2 == -1) {
        perror("dup2");
        close(fd);
        close(fd1);
        return 1;
    }

    fd3 = fcntl(fd, F_DUPFD, fd + 2);  // using fcntl
    if (fd3 == -1) {
        perror("fcntl");
        close(fd);
        close(fd1);
        close(fd2);
        return 1;
    }

    printf("Appending data using original file descriptor\n");
    if (write(fd, data, strlen(data)) == -1) {
        perror("write");
    }

    printf("Appending data using dup\n");
    if (write(fd1, data, strlen(data)) == -1) {
        perror("write");
    }

    printf("Appending data using dup2\n");
    if (write(fd2, data, strlen(data)) == -1) {
        perror("write");
    }

    printf("Appending data using fcntl\n");
    if (write(fd3, data, strlen(data)) == -1) {
        perror("write");
    }

  
    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
