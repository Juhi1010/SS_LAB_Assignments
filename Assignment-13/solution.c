#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {

    fd_set readfds;
    FD_ZERO(&readfds);          
    FD_SET(STDIN_FILENO, &readfds); 

    struct timeval time;
    time.tv_sec = 10;        
    time.tv_usec = 0;

    int data = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &time);

    if (data == -1) {
        perror("select"); 
        return 1;
    } else if (data == 0) {
        printf("No data available within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Data entered\n");

            char buffer[256];
            ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
            if (bytesRead > 0) {
                buffer[bytesRead] = '\0'; 
                printf("Read data: %s\n", buffer);
            }
        }
    }

    return 0;
}
