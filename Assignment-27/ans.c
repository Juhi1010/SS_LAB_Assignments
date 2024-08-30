#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    printf("Executing ls -Rl using different system calls");

    if (pid == 0) {
        printf("execl - \n");
        execl("/bin/ls", "ls", "-Rl", (char *) NULL);
        
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL); 
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("execlp - \n");
        execlp("ls", "ls", "-Rl", (char *) NULL);
        
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL); 
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("execle - \n");
        char *envp[] = { NULL }; 
        execle("/bin/ls", "ls", "-Rl", (char *) NULL, envp);
        
        perror("execle");
        exit(EXIT_FAILURE);

    } else {
        wait(NULL); 
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("execv - \n");
        char *args[] = { "ls", "-Rl", NULL };
        execv("/bin/ls", args);
        
        perror("execv");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL); 
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("execvp - \n");
        char *args[] = { "ls", "-Rl", NULL };
        execvp("ls", args);
        
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL); 
    }

    return 0;
}
