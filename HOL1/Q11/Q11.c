/*
============================================================================
Name : 11.c
Author : Jay Rathod
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not.    a. use dup    b. use dup2    c. use fcntl 
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    char buf1[11] = "1234567890\n"; 
    char buf2[11] = "0987654321\n"; 
    int f_dup = open("dup.txt",O_CREAT|O_RDWR|O_APPEND,0777);
    if(f_dup < 0){
        perror("dup.txt was not opened properly\n");
    }

    int copy_fdup = dup(f_dup);

    write(f_dup,buf1,sizeof(buf1));
    write(copy_fdup,buf2,sizeof(buf2));

    int f_dup2 = open("dup2.txt",O_CREAT|O_RDWR|O_APPEND,0777);
    if(f_dup2 < 0){
        perror("dup2.txt was not opened properly\n");
    }

    copy_fdup = dup2(f_dup2,1);

    write(f_dup2,buf1,sizeof(buf1));
    write(copy_fdup,buf2,sizeof(buf2));


    int f_fcntl = open("fcntl.txt",O_CREAT|O_RDWR|O_APPEND,0777);
    if(f_fcntl < 0){
        perror("fcntl.txt was not opened properly\n");
    }

    copy_fdup = fcntl(f_fcntl,F_DUPFD);

    write(f_fcntl,buf1,sizeof(buf1));
    write(copy_fdup,buf2,sizeof(buf2));

    return 0;
}