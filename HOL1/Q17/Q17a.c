#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main() {
  int fd;
  int i = 10;
  fd = open("file.txt", O_CREAT|O_RDWR,0777);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  write(fd, &i, sizeof(int));
  close(fd);
}
