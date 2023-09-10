#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe_fd[2];
    pid_t pid;

    if (pipe(pipe_fd) == -1) {
        write(3,"Pipe Failed",12);
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        write(3,"Fork Failed",12);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  
        close(pipe_fd[0]);  

        char message[1];
        int fd = open("shared.txt",O_CREAT|O_WRONLY|O_TRUNC,0777);


        if (fd == -1) {
            write(3,"File open Failed",12);
            exit(EXIT_FAILURE);
        }

        while (1) {
            write(2,"\nChild: Enter Message: ",23);
            read(1,message,1);
            write(fd,message,1);
            write(pipe_fd[1], "1", 1);
        }

        close(fd);
    } else {  
        close(pipe_fd[1]); 

        char buffer;
        int fd = open("shared.txt",O_RDONLY,0777);

        if (fd == -1) {
            write(3,"File open Failed",12);
            exit(EXIT_FAILURE);
        }

        while (1) {
            read(pipe_fd[0], &buffer, 1);
            char message[1];
            write(2,"\nParent: Message Received: ",26);
            read(fd, message,SEEK_CUR);
            write(2,message,sizeof(message));
        }

        close(fd);
    }

    return 0;
}
