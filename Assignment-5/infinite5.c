#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {

    int fds[5];
    char name[40];
    
    while (1) {

        for (int i = 0; i < 5; i++) {
            snprintf(name, sizeof(name), "%s%d.txt", "/tmp/infinite_file_", i);
  
            fds[i] = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
            if (fds[i] < 0) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            
            const char *data = "Hi, this file is created using an infinite loop\n";
            write(fds[i], data, strlen(data));
        }

        for (int i = 0; i < 5; i++) {
            close(fds[i]);
        }

        sleep(5);
    }
    return 0;
}
