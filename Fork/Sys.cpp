#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
int main1()
{
    printf("%d\n",system("ls"));
    return EXIT_SUCCESS;
}
