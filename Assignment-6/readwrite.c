#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buffer[32];
    int read_buffer = read(0, buffer, 30);
    printf("%d", read_buffer);
    fflush(stdout);
    write(1, buffer, read_buffer);
}