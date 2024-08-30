#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"./a.out", "Juhi", NULL};

    execv(args[0], args);

    perror("execv");
    return EXIT_FAILURE;
}
