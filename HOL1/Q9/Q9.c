/*
============================================================================
Name : 9.c
Author : Jay Rathod
Description : Write a program to print the following information about a given file.    a. inode    b. number of hard links    c. uid    d. gid    e. size    f. block size    g. number of blocks    h. time of last access    i. time of last modification    j. time of last change
Date: 10th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void printFileProperties(struct stat s){
    ino_t inode = s.st_ino;
    nlink_t link = s.st_nlink;
    uid_t uid = s.st_uid;
    gid_t gid = s.st_gid;
    off_t size = s.st_size;
    time_t acctime = s.st_atime;
    time_t modtime = s.st_mtime;
    time_t chgtime = s.st_ctime;
    struct tm *tm;
    char buf[200];
    

    blkcnt_t blksize = s.st_blocks;

    printf("Inode: %ld \n",inode);
    printf("Number of Links: %ld \n",link);
    printf("User ID: %d \n",s.st_uid);
    printf("Group ID: %d \n",s.st_gid);
    printf("Size: %ld \n",s.st_size);
    printf("Block Size: %ld \n",s.st_blksize);
    printf("Number of Blocks: %ld \n",s.st_blocks);
    /* convert time_t to broken-down time representation */
    tm = localtime(&acctime);
    /* format time days.month.year hour:minute:seconds */
    strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
    printf("Last access time: %s \n",buf);
    /* convert time_t to broken-down time representation */
    tm = localtime(&acctime);
    /* format time days.month.year hour:minute:seconds */
    strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
    printf("Last modification time: %s \n",buf);
    /* convert time_t to broken-down time representation */
    tm = localtime(&acctime);
    /* format time days.month.year hour:minute:seconds */
    strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
    printf("Last change time: %s \n",buf);
}

int main(int argc,char* argv[]){
    if(argc < 1){
        perror("Very few arguments were provided\n");
        return -1;    
    }
    struct stat buf;
    if(stat(argv[1],&buf) == 0){
        printFileProperties(buf);
    }
    else{
        perror("Unable to read file meta-data");
        return -1;
    }
    return 1;
}