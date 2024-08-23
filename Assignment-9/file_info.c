#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include<sys/types.h>

int main() {

    struct stat fileInfo;
    const char *path = "sample.txt";

    if(stat(path,&fileInfo)==-1)
    {
    printf("stat error/n");
    exit(0);
    }
    printf("Inode number = %lu\n", (unsigned long)fileInfo.st_ino);
    printf("Number of Hardlink = %lu\n", (unsigned long)fileInfo.st_nlink);
    printf("UID is %u\n", fileInfo.st_uid);
    printf("GID is %u\n", fileInfo.st_gid);
    printf("Size = %ld\n",(long)fileInfo.st_size);
    printf("Block size is %ld bytes\n", (long)fileInfo.st_blksize);
    printf("Number of blocks is %lld\n", (long long)fileInfo.st_blocks);
    printf("Time of last access is %s", ctime(&fileInfo.st_atime));
    printf("Time of last modification is %s", ctime(&fileInfo.st_mtime));
    printf("Time of last change is %s", ctime(&fileInfo.st_ctime));

    return 0;

}