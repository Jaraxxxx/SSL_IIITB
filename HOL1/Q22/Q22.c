/*
============================================================================
Name : 22.c
Author : Jay Rathod
Description :   Write a program, open a file, call fork, and then write to the file by both the child as well as the 
parent processes. Check output of the file. 
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;
    char buf[100];

    fd = open("Q22.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        printf("Child process: ");
        fgets(buf, sizeof(buf), stdin);
    } else {
        wait(NULL); // Wait for the child process to finish

        printf("Parent process: ");
        fgets(buf, sizeof(buf), stdin);
    }

    dprintf(fd, "Process %d: %s", getpid(), buf);

    close(fd);

    return 0;
}
