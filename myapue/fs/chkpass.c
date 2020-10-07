#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>
#include <string.h>

int main(int argc,char** argv)
{
    char* input_pass;
    char* crypted_pass;
    struct spwd *shadowline;
    if (argc < 2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    //注意关闭回显功能

    input_pass = getpass("Password: ");

    shadowline = getspnam(argv[1]);

    crypted_pass = crypt(input_pass,shadowline->sp_pwdp);

    if (strcmp(crypted_pass,shadowline->sp_pwdp) == 0 )
        puts("OK");
    else
        puts("failed");




    exit(0);
}