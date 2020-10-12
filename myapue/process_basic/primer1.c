#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


#define LEFT  30000000
#define RIGHT 30000200

int main()
{
    int i,j;
    for (i = LEFT; i <= RIGHT; i++) {
        pid_t pid;
        pid = fork();
        if (pid < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0 ) {
            int mark = 1;
            for (j = 2; j < i / 2; j++) {
                if (i%j == 0)
                {
                    mark = 0;
                    break;
                }
            }
            if (mark)
                printf("%d is a primer\n",i);
           // sleep(1000); //等待父进程结束 会产生孤儿进程
            exit(0);
        }
    }
    sleep(1000); //子进程结束 没有收回子进程资源,会产生僵尸进程
    exit(0);
}