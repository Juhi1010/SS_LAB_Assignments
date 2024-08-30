#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {

        printf("Child process - PID: %d created and it's parent's PID is %d\n", getpid(), getppid());
        sleep(10);

        printf("Child process - PID: %d is orphaned and it's current parent PID is %d\n", getpid(), getppid());
        
        while (1) {
            sleep(5); 
        }

    } else {

        printf("Parent process PID - %d terminating\n", getpid());

        exit(EXIT_SUCCESS);
    }

    return 0;

}