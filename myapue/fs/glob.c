#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <glob.h>

#if 0
static int errfunc(const char* epth,const int errono)
{
    puts(epth);
    fprintf(stderr,"ERROR MSG: %s\n",strerror(errno));

    return 0;

}

#endif
//#define PAT "/etc/a*.conf"
#define PAT "/etc/*" //不包括隐藏文件

int main(int argc,char** argv)
{


    glob_t globres;
    int err,i;
    err = glob(PAT,0,NULL,&globres);

    if (err) {

        printf("Error code = %d\n",err);
        exit(1);

    }

    for (i = 0; i < globres.gl_pathc;i++)
    {
        puts(globres.gl_pathv[i]);
    }

	globfree(&globres);


    exit(0);

}
