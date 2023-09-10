/*
============================================================================
Name : 19.c
Author : Jay Rathod
Description :  Write a program to find out time taken to execute getpid system call. Use time stamp counter.   
Date: 10th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
    clock_t start,end;
    struct flock lock;
    // start = clock();
    // lock.l_pid = getpid();
    // end = clock();
    // printf("%ld  %ld\n",start,end);
    if(fork()){
        start = clock();
        int n =100;
        while(n-->0)
        {lock.l_pid = getpid();}
        end = clock();
        printf("%ld  %ld\n",start,end);
        printf("%d took %ld secs ... %ld\n",lock.l_pid,(end-start)/CLOCKS_PER_SEC,CLOCKS_PER_SEC);
    }
    else{
        start = clock();
        lock.l_pid = getpid();
        end = clock();
        printf("%ld  %ld\n",start,end);
        printf("%d took %ld secs\n",lock.l_pid,((end-start)/(CLOCKS_PER_SEC)));
    }
    return 0;
}