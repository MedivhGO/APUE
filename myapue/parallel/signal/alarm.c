#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    alarm(10);
    //alarm(5); //5s之后进程结束
    alarm(1);//
    alarm(5);
    while (1)
        pause();
    exit(0);
}