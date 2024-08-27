#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct flock lock;
    int fd;
    fd = open("sample.txt", O_CREAT | O_RDWR);
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before entering into critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section\n");
    printf("Enter to unlock\n");
    getchar();
    printf("unlocked\n");
    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("finish\n");
}

