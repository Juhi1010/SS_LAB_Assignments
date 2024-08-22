#include <stdio.h>
#include <unistd.h>

int main() {
    const char *source_file = "sample.txt";
    const char *soft_link = "softlink";

    if (symlink(source_file, soft_link) == -1) {
        perror("Error in creating soft link");
        return 1;
    }

    printf("Soft link created");
    return 0;
}