#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // const char *fifo = "fifo";

    if (mkfifo("myFifoSysCall", 0666) == -1) {  // providing read and write permission for owner, group and others
        perror("Error in creating pipe");
        return 1;
    } else printf("FIFO created.\n");
    return 0;
}
