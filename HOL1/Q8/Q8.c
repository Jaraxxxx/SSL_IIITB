#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_MAX 10 

int main(int argc, char* argv[]){
    int fd_read = open(argv[1],O_RDONLY);
    printf("%s\n",argv[1]);
    if(fd_read == -1){
        perror("File not opened succesfully");
    }
    char buffer[BUFF_MAX+1];
    int count;
    fflush(0);
    while (1){
        count = read(fd_read,buffer,sizeof(buffer));
        buffer[count] = '\0';
        if(count == 0) break;
        fflush(0);
        write(STDOUT_FILENO,buffer,count);
    }
    return 0;
}