/*
============================================================================
Name : 12.c
Author : Jay Rathod
Description : Write a program to find out the opening mode of a file. Use fcntl. 
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main() {
    int fd = open("file", O_CREAT | O_RDWR, 0666);
    int mode = fcntl(fd, F_GETFL);
    printf("%d\n", mode & O_ACCMODE);
}
