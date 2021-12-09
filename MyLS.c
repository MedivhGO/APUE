#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static const char Description[] = 
{

   "Usage: ls long-option\n"
   "       ls [-lain] [file ...]\n"
   "Print a list of files.\n"
   "\n"
   "  -l         Long listings\n"
   "  -a         All, Do not hide entries starting with .\n"
   "  -i         Print index number of each file\n"
   "  -n         List numeric user and group ID's instead of names\n"
   "\n"
   "Long Options:\n"
   "  --help     Print this help message\n"
   "  --version  Print the program version\n"
   "\n"
};

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc == 1) {
        puts("too few arguments");
        return 0;
    }

    char *ptr;

    ptr = argv[1];

    if (!strcmp(ptr, "--help")) {
        puts(Description);
        return 0;
    } else if (!strcmp(ptr, "--version")) {
        puts("ls: version 1.0");
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        ptr = argv[i];
        if (*ptr == '-') {
            while(*++ptr) {
                switch(*ptr) {
                    case 'a':
                        puts("parameter -a exsit");
                        break;
                    default :
                        puts("to do");
                }
            }
        }
    }
    
    puts("***********************");

    //TODO: 不支持参数情况, 命令后需要直接给出

    if ((dp = opendir(ptr)) == NULL) {
	    printf("can't open %s",ptr);
    }

    while ((dirp = readdir(dp)) != NULL) {
	    printf("%s\n",dirp->d_name); 
    }
    
    closedir(dp);

    return 0;
}
