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

        execle("/bin/date","date","+%s",NULL);
        perror("execl()");
        exit(1);

    }
    wait(NULL);
    puts("End!");
    exit(0);
}