/*
============================================================================
Name : 2.c
Author : Jay Rathod
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and 
identify all the process related information in the corresponding proc directory.  
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
    while(1);
    return 0;
}
/*bg
jobs
ps
check pid of process 
search in proc for the same pid
ls -l*/