#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv)
{
    char* linebuf;
    size_t linesize;
    FILE *fp = NULL;
    if(argc<2)
    {
        fprintf(stderr,"Usage ...\n");
        exit(1);
    }
    fp = fopen(argv[1],"r");
    if (fp==NULL)
    {
        perror("fopen()");
        exit(1);
    }
    /*
     *important
     * */
    linebuf=NULL;
    linesize=0;
    while(1)
    {
       if(getline(&linebuf,&linesize,fp)<0){
           break;
       } else {
           printf("%d\n",strlen(linebuf));
           printf("%d\n",linesize);
       }
    }
    exit(0);
}
