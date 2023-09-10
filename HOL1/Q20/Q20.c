/*
============================================================================
Name : 20.c
Author : Jay Rathod
Description :  Find out the priority of your running program. Modify the priority with nice command. 
Date: 10th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/errno.h>

int main(){
    int priority = getpriority(PRIO_PROCESS,-1);

    // printf("%d   %d\n",getpid(),0);

    if(priority = -1){
        perror("Error retrieving priority");
        return-1;
    }
    printf("Process id = %d has priority as = %d\n",getpid(),priority);

    if(nice(5) == -1){
        perror("Error nice");
    }

    priority = getpriority(PRIO_PROCESS,0);
    if(priority == -1){
        perror("Error retrieving priority");
        return-1;
    }
    printf("Process id = %d has priority as = %d\n",getpid(),priority);


    return 0;
}