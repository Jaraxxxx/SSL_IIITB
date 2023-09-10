/*
============================================================================
Name : 1.c
Author : Jay Rathod
Description : Create the following types of a files using (i) shell command (ii) system call    a. soft link (symlink system call)    b. hard link (link system call)    c. FIFO (mkfifo Library Function or mknod system call) 
Date: 10th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(){
    int v = symlink("./Employe_Record.sh","destSL");
    if(v<0){
        perror("Failed");
        return 1;
    }

    int f = link("./Employe_Record.sh","destHL");
    if(f<0){
        perror("Failed");
        return 1;
    }
    
    int e = mknod("IFIFO",__S_IFIFO,0);
    if(e<0)
        perror("Failed");
    return 0;
}