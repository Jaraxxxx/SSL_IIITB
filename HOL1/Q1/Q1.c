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