#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
    
    if(!fork()) {
        setsid();
        chdir("/");
        umask(0);
        while(1) {
            sleep(4);
            printf("Child pid: %d\n", getpid());
            printf("Daemon process is running\n");
        }
    }
    else 
        exit(0);

}