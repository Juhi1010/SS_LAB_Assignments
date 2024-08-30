#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{ 
    pid_t pid = fork(); 
  
    if (pid > 0) { 
        printf("Parent process - PID: %d waiting to create a zombie process once the child process ends\n", getpid());
        sleep(50);
        wait(NULL); 
        printf("Parent process - PID: %d has ended the child process.\n", getpid()); 
    }
  
    else if (pid==0){
        printf("Child process - PID: %d is sleeping for 5 seconds\n", getpid());
        sleep(5); 
        printf("Child process - PID: %d exiting\n", getpid());
        exit(EXIT_SUCCESS); 
    }
  
    return 0; 
} 


