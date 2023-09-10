/*
============================================================================
Name : 27.c
Author : Jay Rathod
Description :   Write a program to execute ls -Rl by the following system calls    a. execl    b. execlp    c. execle 
   d. execv    e. execvp 
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int pipe_fd[2]; // Pipe for capturing output
    char buffer[1024];

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            close(pipe_fd[0]);

            dup2(pipe_fd[1], STDOUT_FILENO);

            close(pipe_fd[1]);

            switch (i) {
                case 0:
                    printf("Child %d: Using execl:\n", i);
                    execl("/bin/ls", "ls", "-Rl", NULL);
                    break;
                case 1:
                    printf("Child %d: Using execlp:\n", i);
                    execlp("ls", "ls", "-Rl", NULL);
                    break;
                case 2:
                    printf("Child %d: Using execle:\n", i);
                    char *envp[] = {NULL}; // Empty environment
                    execle("/bin/ls", "ls", "-Rl", NULL, envp);
                    break;
                case 3:
                    printf("Child %d: Using execv:\n", i);
                    char *argv[] = {"ls", "-Rl", NULL};
                    execv("/bin/ls", argv);
                    break;
                case 4:
                    printf("Child %d: Using execvp:\n", i);
                    char *argvp[] = {"ls", "-Rl", NULL};
                    execvp("ls", argvp);
                    break;
                default:
                    break;
            }
            
            perror("exec");
            return 1;
        }
        
        close(pipe_fd[1]);

        printf("\n\nParent reading output from Child %d:\n", i);
        ssize_t n;
        while ((n = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, n);
        }

        close(pipe_fd[0]);

        wait(NULL);
    }

    return 0;
}
