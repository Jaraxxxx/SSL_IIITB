/*
============================================================================
Name : 24.c
Author : Jay Rathod
Description :   Write a program to create an orphan process. 
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child process (PID %d) is running.\n", getpid());
        sleep(10);
        printf("Child process (PID %d) is exiting.\n", getpid());
    } else {
        printf("Parent process (PID %d) is exiting immediately.\n", getpid());
    }

    return 0;
}
