/*
============================================================================
Name : 5.c
Author : Jay Rathod
Description : Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd. 
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
    while(1){
        int fd = open("file",O_CREAT);
        if(fd == -1){
            perror("File not created\n");
        }
        printf("%d\n",fd);
    }
    return 0;
}