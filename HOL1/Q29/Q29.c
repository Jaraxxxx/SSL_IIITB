/*
============================================================================
Name : 29.c
Author : Jay Rathod
Description :   Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  
SCHED_RR).
Date: 10th Sep, 2023.
============================================================================
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(){
    struct sched_param param;
    int max_priority;
    max_priority = sched_get_priority_max(SCHED_FIFO);

    param.sched_priority = max_priority; 

    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("Error setting scheduler");
        exit(EXIT_FAILURE);
    }

    int policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("Error getting scheduler");
        exit(EXIT_FAILURE);
    }
    printf("Scheduling policy is set to SCHED_FIFO\n");
    
    
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("Error setting scheduler");
        exit(EXIT_FAILURE);
    }

    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("Error getting scheduler");
        exit(EXIT_FAILURE);
    }
    printf("Scheduling policy is set to SCHED_RR\n");
    
}