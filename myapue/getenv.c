#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    //setenv("")
    puts(getenv("PATH"));

    getchar();
    exit(0);
}