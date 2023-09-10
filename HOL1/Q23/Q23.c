/*
============================================================================
Name : 23.c
Author : Jay Rathod
Description :   Write a program to create a Zombie state of the running program. 
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process exited. \n");
        printf("Child Process zombied. \n");
    } else {
        printf("Parent process is running.\n");
        sleep(10);
        printf("Parent process Exited.\n");

    }
    return 0;
}
