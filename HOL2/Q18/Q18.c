/*
============================================================================
Name : 18.c
Author : Jay Rathod
Description :  Write a program to find out total number of directories on the pwd.    execute ls -l | grep ^d | wc ? Use only dup2.
Date: 5th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main(void)
{
    int firstpart[2], secondpart[2];
    pid_t pid1, pid2;
    if(pipe(firstpart) < 0 || pipe(secondpart) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid1=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if (!pid1) {
        dup2(firstpart[1], 1);
        close(secondpart[0]);
        close(secondpart[1]);
        close(firstpart[0]);
        char *args[]={"ls", "-l", NULL};
        execv("/bin/ls", args);
    } else {
        if((pid2=fork()) < 0) {
            perror("Fork");
            exit(EXIT_FAILURE);
        }
        if (!pid2) {
            dup2(firstpart[0], 0);
            dup2(secondpart[1], 1);
            close(firstpart[1]);
            close(secondpart[0]);
            char *args[]={"grep", "^d", NULL};
            execv("/bin/grep", args);
            // execlp("grep", "grep", "^-", NULL);
        } else {
            sleep(2);
            dup2(secondpart[0], 0);
            close(secondpart[1]);
            close(firstpart[0]);
            close(firstpart[1]);
            char *args[]={"wc", "-l", NULL};
            execv("/bin/wc", args);
            // execlp("wc", "wc", "-l", NULL);
        }
    }
}