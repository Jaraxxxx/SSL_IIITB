/*
==============================================================================
Name : 30.c
Author : Jay Rathod
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 10th Sep, 2023
==============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

void main() {
  pid_t pid;
  if((pid=fork()) < 0) {
    perror("fork");
    exit(-1);
  } else if(pid > 0) {
    printf("Child's pid = %d\n", getpid());
    exit(0);
  }
  umask(0);
  int sid=setsid();
  if(sid < 0) {
    perror("sid");
    exit(-1);
  }
  chdir("/");
  FILE *fp=fopen("daemon.txt", "w+");
  while(1) {
    sleep(1);
    fprintf(fp, "daemon process...\n");
    fflush(fp);
  }
  fclose(fp);
}