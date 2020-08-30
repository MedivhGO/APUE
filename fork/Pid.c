#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int Pid()
{
    printf("pid=%d\n",getpid());
    printf("ppid=%d\n",getppid());
    return EXIT_SUCCESS;
}
