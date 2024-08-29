#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {

    int fd = open("/tmp/infinite_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        const char *printt = "Infinite loop\n";
        write(fd, printt, strlen(printt));
        sleep(5);
    }

    close(fd);
    return 0;
}
