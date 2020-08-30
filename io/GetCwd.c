#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int GetCwd()
{
    char buf[100];
    memset(buf,0,sizeof(buf));
    getcwd(buf,sizeof(buf));
    puts(buf);
    return 0;
}
