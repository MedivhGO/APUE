#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FNAME "/tmp/out"
#define BUFSIZE 1024
int main()
{

    FILE* fp = NULL;
    time_t stamp;
    struct tm*   stm;
    int count = 0;
    
    char buf[BUFSIZE];
    fp = fopen(FNAME,"a+");
    if (fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    while (fgets(buf,BUFSIZE,fp) != NULL) {
        count++;
    }

    while (1) {
        time(&stamp);
        stm = localtime(&stamp);
        fprintf(fp,"%-4d%d-%d-%d %d:%d:%d\n",++count,\
            stm->tm_year+1900,stm->tm_mon+1,stm->tm_mday,\
            stm->tm_hour, stm->tm_min,stm->tm_sec);
        fflush(fp);
        sleep(1);
    }

    fclose(fp);
    exit(0);
}