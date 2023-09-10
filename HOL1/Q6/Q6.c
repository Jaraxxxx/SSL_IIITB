/*
============================================================================
Name : 6.c
Author : Jay Rathod
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
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
    char buf[1000];
    int cnt;
    while (1){
        cnt = read(STDIN_FILENO,buf,sizeof(buf));
        buf[cnt] = '\0';
        fflush(0);
        write(STDOUT_FILENO,buf,cnt);
    }
    return 0;
}