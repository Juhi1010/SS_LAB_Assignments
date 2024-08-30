#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>

int main() {

    int policy;
    int maxPriority, minPriority;

    policy = SCHED_FIFO;
    maxPriority = sched_get_priority_max(policy);
    minPriority = sched_get_priority_min(policy);
    if (maxPriority == -1 || minPriority == -1) {
        perror("sched_get_priority_max or sched_get_priority_min");
        exit(EXIT_FAILURE);
    }

    printf("SCHED_FIFO:\n");
    printf("  Max priority - %d\n", maxPriority);
    printf("  Min priority - %d\n", minPriority);

    policy = SCHED_RR;
    maxPriority = sched_get_priority_max(policy);
    minPriority = sched_get_priority_min(policy);
    if (maxPriority == -1 || minPriority == -1) {
        perror("sched_get_priority_max or sched_get_priority_min");
        exit(EXIT_FAILURE);
    }
    printf("SCHED_RR:\n");
    printf("  Max priority -  %d\n", maxPriority);
    printf("  Min priority - %d\n", minPriority);

    return 0;
}
