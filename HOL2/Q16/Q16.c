/*
============================================================================
Name : 16.c
Author : Jay Rathod
Description :  Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 5th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include <sys/wait.h>

int main() {
    int ptc[2], ctp[2];
    pipe(ptc);
    pipe(ctp);
    pid_t pid = fork();
    if (!pid) {
        //child
        close(ptc[1]);
        close(ctp[0]);
        char buffer[1024];
        int n = read(ptc[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Child received: %s\n", buffer);
        }
// ------------------------------------------------------------------------
        buffer[0]='\0';
        printf("Parent msg: ");
        fgets(buffer, sizeof(buffer), stdin);
        n=write(ctp[1], buffer, strlen(buffer));
        close(ptc[0]);
        close(ctp[1]);
        exit(EXIT_SUCCESS);
    } else {
        //parent
        close(ptc[0]);
        close(ctp[1]);
        char buffer[1024];
        printf("Child msg: ");
        fgets(buffer, sizeof(buffer), stdin);
        int n = write(ptc[1], buffer, strlen(buffer));
// ------------------------------------------------------------------------
        buffer[0]='\0';
        n=read(ctp[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Parent received: %s\n", buffer);
        }

        close(ptc[1]);
        wait(NULL);
    }

    return 0;
}


// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/types.h>

// #define BUFFER_SIZE 1024

// int main() {
//     int ptc[2], ctp[2];
//     char buf[BUFFER_SIZE];

//     if (pipe(ptc) == -1 || pipe(ctp) == -1) {
//         perror("Pipe creation failed");
//         exit(EXIT_FAILURE);
//     }
  
//     pid_t pid = fork();

//     if (pid == -1) {
//         perror("Fork failed");
//         exit(EXIT_FAILURE);
//     }

//     if (pid == 0) { 
//         close(ptc[1]); 
//         close(ctp[0]);

//         read(ptc[0], buf, BUFFER_SIZE);
//         printf("Child received: %s\n", buf);

//         char reply[] = "Message from child";
//         write(ctp[1], reply, strlen(reply) + 1);

//         close(ptc[0]);
//         close(ctp[1]);

//         exit(EXIT_SUCCESS);
//     } else { 
//         close(ptc[0]); 
//         close(ctp[1]); 

//         char message[] = "Message from parent";
//         write(ptc[1], message, strlen(message) + 1);

//         read(ctp[0], buf, BUFFER_SIZE);
//         printf("Parent received: %s\n", buf);

//         close(ptc[1]);
//         close(ctp[0]);
//     }

//     return 0;
// }
