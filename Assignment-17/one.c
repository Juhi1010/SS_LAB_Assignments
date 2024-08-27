#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct {
       int tick_no;
    } db; 
    struct flock lock;
    int fd;
    fd = open("db", O_RDWR);
    read(fd, &db, sizeof(db));
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before entering into critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    db.tick_no++;
    printf("Current ticket number: %d\n", db.tick_no);
    lseek(fd, 0L, SEEK_SET);
    printf("Inside the critical section\n");
    printf("Enter to unlock\n");
    write(fd, &db, sizeof(db));
    getchar();
    lock.l_type = F_UNLCK;
    printf("unlocked\n");
    fcntl(fd, F_SETLK, &lock);
    printf("finish\n");
}

// int main() {
//     int fd;
//     struct {
//         int tick_no;
//     } db;
//     db.tick_no = 10;
//     fd = open("db", O_CREAT | O_RDWR, 0744);
//     write(fd, &db, sizeof(db));
//     close(fd);
//     fd = open("db", O_RDONLY);
//     read(fd, &db, sizeof(db));
//     printf("Ticket no: %d\n", db.tick_no);
//     close(fd);
// }