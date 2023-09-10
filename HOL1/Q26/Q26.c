/*
============================================================================
Name : 26.c
Author : Jay Rathod
Description :    Write a program to execute an executable program.    a. use some executable program    b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int c,char* argv[]) {
    if(c < 3){
        perror("few parameters.\n");
        return -1;
    }
    char *args[] = {argv[1],argv[2],NULL};

    // Execute the program
    execl(argv[1], argv[1],argv[2], (char *)NULL);

    execv(argv[1],args);

    // If execl returns, an error occurred
    perror("execl");
    return 1;
}
