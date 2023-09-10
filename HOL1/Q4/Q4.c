/*
============================================================================
Name : 4.c
Author : Jay Rathod
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(){
    int read_only = open("./Q1.c",O_RDONLY);
    int write_only = open("./Q1.c",O_WRONLY|O_EXCL);
    if(read_only == -1 || write_only == -1) return 0;
    return 0;
}