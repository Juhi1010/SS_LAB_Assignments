#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t childProcesses[4];
    pid_t wpid;
    int status;
    int i;

    for (i = 0; i < 4; i++) {
        childProcesses[i] = fork();
        if (childProcesses[i] < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (childProcesses[i] == 0) {
            printf("Child %d pid - %d running\n", i + 1, getpid());
            sleep(2 + i); 
            printf("Child %d pid - %d exiting\n", i + 1, getpid());
            exit(i + 1); 
        }
    }

    printf("Parent pid - %d created 4 child processes\n", getpid());

    wpid = waitpid(childProcesses[1], &status, 0);
    if (wpid == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status)) {
        printf("Child process with PID %d exited with status %d.\n", wpid, WEXITSTATUS(status));
    } 
    
    return 0;
}
