#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
    date +%s

*/

int main()
{
    puts("Begin!");
    fflush(NULL);
    execl("/bin/date","date","+%s",NULL); //replace,新的进程映像
    perror("execl()");
    exit(1);
    puts("End!");
    exit(0);
}