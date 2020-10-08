#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    puts(getenv("PATH"));
    exit(0);
}