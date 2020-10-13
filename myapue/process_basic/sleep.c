#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    puts("Begin!");
    fflush(NULL);

    pid_t pid;
    pid = fork();

    if (pid < 0) {

    }
    if (pid == 0) {

        execle("/bin/sleep","sleep","100",NULL); //第二个参数给此程序起了一个新名字
        perror("execl()");
        exit(1);

    }
    wait(NULL);
    puts("End!");
    exit(0);
}