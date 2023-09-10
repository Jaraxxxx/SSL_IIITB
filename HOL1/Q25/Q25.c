/*
============================================================================
Name : 25.c
Author : Jay Rathod
Description :   Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call).
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid[3];
    int status;
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        pid[i] = fork();

        if (pid[i] == -1) {
            perror("fork");
            return 1;
        }

        if (pid[i] == 0) {
            printf("Child process %d (PID %d) is running.\n", i+1, getpid());
            sleep(2 + i); 
            printf("Child process %d (PID %d) is exiting.\n", i+1, getpid());
            exit(0);
        }
    }
    int random = rand()%3;
    int specific_child = pid[random];

    printf("Parent process (PID %d) is waiting for Child %d (PID %d).\n", getpid(), random, specific_child);

    pid_t result = waitpid(specific_child, &status, 0);

    if (result == -1) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status)) {
        printf("Child %d (PID %d) exited normally with status %d.\n", random, specific_child, WEXITSTATUS(status));
    }

    return 0;
}
