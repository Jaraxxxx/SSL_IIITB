/*
============================================================================
Name : 15.c
Author : Jay Rathod
Description : Write a program to display the environmental variable of the user (use environ).
Date: 10th Sep, 2023.
============================================================================
*/
#include<stdio.h>

extern char **environ;

void main() {
  for(size_t i=0; environ[i]!=NULL; i++)
    printf("%s\n", environ[i]);
}
