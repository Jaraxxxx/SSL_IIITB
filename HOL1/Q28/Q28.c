/*
============================================================================
Name : 28.c
Author : Jay Rathod
Description :   Write a program to get maximum and minimum real time priority. 
Date: 10th Sep, 2023.
============================================================================
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_RR);
    min_priority = sched_get_priority_min(SCHED_RR);

    if (max_priority == -1 || min_priority == -1) {
        perror("Error getting priorities");
        exit(EXIT_FAILURE);
    }

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    
    // Main program logic for the real-time process goes here...

    return 0;
}
