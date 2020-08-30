#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int Kill(int arg,char *args[])
{
    if(arg > 1){
        int pid = atoi(args[1]);
        kill(pid,SIGKILL);
    }
    else{
        printf("pid = %u\n",getpid());
        sleep(60);
    }
    return 0;

}
