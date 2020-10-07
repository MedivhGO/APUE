#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    printf("argc = %d\n",argc);

    int i;
    for (i = 0 ; i < argc ; i++)
    {
        puts(argv[i]);
    }
    exit(0);

}
