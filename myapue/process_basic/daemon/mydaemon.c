
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


#define FNAME "/tmp/out"


static void daemonize()
{
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork error");
        exit(1);
    }

    if (pid > 0) {
        exit(0);
    }



    setsid();

}

int main()
{

    FILE* fp;
    int i;

    daemonize();

    fp = fopen(FNAME,"w");

    if (fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    for (i = 0;;i++) {
        fprintf(fp,"%d\n",i);
        fflush(fp);
        sleep(1);
    }

    fclose(fp);
    closelog();
    exit(0);

}