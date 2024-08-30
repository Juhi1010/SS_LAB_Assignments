#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int currPriority, newPriority;

    currPriority = getpriority(PRIO_PROCESS, 0);
    if (currPriority == -1 && errno != 0) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Current priority -  %d\n", currPriority);

    newPriority = atoi(argv[1]);

    if (setpriority(PRIO_PROCESS, 0, newPriority) == -1) {
        perror("setpriority");
        exit(EXIT_FAILURE);
    }

    currPriority = getpriority(PRIO_PROCESS, 0);
    if (currPriority == -1 && errno != 0) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("New priority - %d\n", currPriority);

    return 0;
}
