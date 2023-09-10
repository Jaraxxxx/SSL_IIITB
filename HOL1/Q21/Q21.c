/*
============================================================================
Name : 21.c
Author : Jay Rathod
Description :   Write a program, call fork and print the parent and child process id.
Date: 10th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/errno.h>

int main(){
    if(fork()){
        printf("Parent Process pid = %d.\n",getpid());
    }
    else{
        printf("Child Process pid = %d.\n",getpid());
    }
    return 0;
}