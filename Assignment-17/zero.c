#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    struct {
        int tick_no;
    } db;
    db.tick_no = 12;
    fd = open("db", O_CREAT | O_RDWR, 0744);
    write(fd, &db, sizeof(db));
    close(fd);
    fd = open("db", O_RDONLY);
    read(fd, &db, sizeof(db));
    printf("Ticket no: %d\n", db.tick_no);
    close(fd);
}