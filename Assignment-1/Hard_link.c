#include <stdio.h>
#include <unistd.h>

int main() {
    const char *source_file = "sample.txt";
    const char *hard_link = "hardlink";

    if (link(source_file, hard_link) == -1) {
        perror("Error in creating Hard link");
        return 1;
    }

    printf("Hard link created.\n");
    return 0;
}
