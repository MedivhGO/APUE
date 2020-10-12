#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
    printf("begin\n");
    pid_t child = fork(); //all p begin at this 子进程的缓冲区中仍存在"begin\n"
    if(child == -1){  //don't have enough mem will return -1
        printf("call fork error\n");
        return -1;
    }
    if(child == 0){ //child
        printf("is child\n");
    }
    else{ //parent
        printf("is parent child pid is %d\n",child);
    }
    printf("end\n");
    return 0;
}
