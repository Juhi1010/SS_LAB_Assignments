#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

    int fd;
    ssize_t result;
    off_t offset;
    char* line_1 = "MT2024071x";
    char* line_2 = "1234567890";

    const char *destFile = "sample.txt";

    fd = open(destFile, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    result = write(fd, line_1, strlen(line_1));
    if (result != strlen(line_1)) {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("lseek");
        close(fd);
        return EXIT_FAILURE;
    }

    result = write(fd, line_2, strlen(line_2));
    if (result != strlen(line_2)) {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    printf("Data written successfully.\n");

    return EXIT_SUCCESS;
}
