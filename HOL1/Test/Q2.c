#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Log{
    int LogID;
    time_t timestamp;
    enum status;
    char log_message[]; 
};

int main(){
    struct Log *log = (struct Log*) malloc (sizeof(struct Log));
    log->LogID = ""
}