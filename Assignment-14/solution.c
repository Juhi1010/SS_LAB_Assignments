#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void file_type(const char *filee) {

    struct stat fileStat;

    if (stat(filee, &fileStat) != 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    if (S_ISREG(fileStat.st_mode)) {
        printf("%s is a regular file\n", filee);
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s is a directory\n", filee);
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("%s is a symbolic link\n", filee);
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("%s is a character device file\n", filee);
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("%s is a block device file\n", filee);
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("%s is a FIFO (named pipe)\n", filee);
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("%s is a socket\n", filee);
    } else {
        printf("%s is of an unknown type\n", filee);
    }

    const char *dot = strrchr(filee, '.');
    if (dot) {
        if (strcmp(dot, ".txt") == 0) {
            printf("%s is a text file\n", filee);
        } else if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0) {
            printf("%s is a JPEG image file\n", filee);
        } else if (strcmp(dot, ".png") == 0) {
            printf("%s is a PNG image file\n", filee);
        } else if (strcmp(dot, ".pdf") == 0) {
            printf("%s is a PDF doc\n", filee);
        } else {
            printf("File extension %s is not recognized\n", dot);
        }
    } else {
        printf("File  extension not recognized\n");
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Error %s \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file_type(argv[1]);

    return 0;
}