#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
    int f_rw = open("Q10.txt",O_CREAT|O_RDWR,0777);
    int cnt = 10,ptr = 0;
    char buf1[10] = "lseek back";
    char buf[10] = "lseek test";
    if(f_rw < 0){
        perror("Error to read file\n");
        return 0;
    }
    int count = 0;
    printf("Loc: %ld\n",lseek(f_rw, 0, SEEK_SET));
    write(1,buf,sizeof(buf));
    write(f_rw, buf, sizeof(buf));
    printf("\nLoc: %ld\n",lseek(f_rw,0,SEEK_CUR));
    printf("Loc: %ld\n",lseek(f_rw, 0, SEEK_SET));
    write(f_rw,buf1,sizeof(buf1));
    write(1,buf1,sizeof(buf1));
    return 0;
}