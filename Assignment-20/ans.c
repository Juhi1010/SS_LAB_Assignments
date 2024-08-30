#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    pid_t pid = getpid();

    int curr_prty = getpriority(PRIO_PROCESS, pid);

    printf("Current priority of process %d - %d\n", pid, curr_prty);

    // the priority is updated using nice command on the terminal

    return 0;
}
