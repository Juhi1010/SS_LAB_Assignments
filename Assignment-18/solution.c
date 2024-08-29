#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define numOfEntries 3
#define entrySize 30

void acquire_lock(int fd, int lock_type) {
    struct flock fl;
    fl.l_type = lock_type;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0; 

    if (fcntl(fd, F_SETLKW, &fl) < 0) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

void release_lock(int fd) {
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0; 

    if (fcntl(fd, F_SETLK, &fl) < 0) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

void read_record(int record_number) {
    if (record_number < 0 || record_number >= numOfEntries) {
        fprintf(stderr, "Record number out of range\n");
        return;
    }

    int fd = open("sample.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    acquire_lock(fd, F_RDLCK); 

    lseek(fd, record_number * entrySize, SEEK_SET);

    char buffer[entrySize];
    if (read(fd, buffer, entrySize) < 0) {
        perror("read");
        release_lock(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Reading Record %d: %s\n", record_number + 1, buffer);

    release_lock(fd);
    close(fd);
}

void update_record(int record_number, const char *data) {
    if (record_number < 0 || record_number >= numOfEntries) {
        fprintf(stderr, "Record number out of range\n");
        return;
    }

    int fd = open("sample.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    acquire_lock(fd, F_WRLCK); 

    lseek(fd, record_number * entrySize, SEEK_SET);

    if (write(fd, data, entrySize) < 0) {
        perror("write");
        release_lock(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Record %d update success\n", record_number + 1);

    release_lock(fd);
    close(fd);
}

int main() {
    for (int i = 0; i < numOfEntries; i++) {
        read_record(i);
    }

    update_record(0, "Line 1..updated data\n");
    update_record(1, "Line 2..updated data\n");
    update_record(2, "Line 3..updated data\n");

    for (int i = 0; i < numOfEntries; i++) {
        read_record(i);
    }

    return 0;
}