#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numOfEntries = 3;
    int fd = open("sample.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    } 

     char *entries[3] = {
        "Line 1..Name - Juhi\n",
        "Line 2..Roll No. - MT2024071\n",
        "Line 3..Batch - 2024-26\n"
    };

    for (int i = 0; i < numOfEntries; i++) {
        if (write(fd, entries[i], strlen(entries[i])) < 0) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    close(fd);

    return 0;
}


