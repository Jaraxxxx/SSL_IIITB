/*
============================================================================
Name : 15.c
Author : Jay Rathod
Description :  Write a simple program to send some data from parent to the child process.
Date: 5th Oct, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
    int pipefd[2];
    pid_t cpid;
    char buf;
    
    if(argc != 2){
        fprintf(stderr,"Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if(cpid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(cpid == 0){
        close(pipefd[1]);
        
        while(read(pipefd[0], &buf, 1) > 0)
            write(2, &buf,1);
        
        write(2, "\n", 1);
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
    else{
        close(pipefd[0]);
        write(pipefd[1],argv[1], strlen(argv[1]));
        close(pipefd[1]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}