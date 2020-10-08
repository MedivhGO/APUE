#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char** environ;
int main()
{
    int i = 0;
    for (i = 0; environ[i] != NULL; i++)
    {
        puts(environ);

    }
    exit(0);
}