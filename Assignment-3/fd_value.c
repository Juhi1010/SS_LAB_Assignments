#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    
    int fd1, fd2, fd3;

    fd1 = creat("file1", 0766);
    printf("File decsriptor fd1 = %d\n", fd1);

    fd2 = open("file2", O_CREAT|O_RDWR, 0766);
    perror("fd2: ");
    printf("File descriptor fd2 = %d\n", fd2);

    close(fd1);
    close(fd2);

}
