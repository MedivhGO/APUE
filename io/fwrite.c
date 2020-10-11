#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
struct min{
    int a;
    int b;
    int c;
    int d;
};
int fwritedemo(int arg,char *args[])
{
    FILE *p = fopen(args[1],"w");
    if(p == NULL)
        printf("error is %s\n",strerror(errno));
    else{
        printf("success\n");
        struct min exp[100];
        memset(&exp,0,sizeof(exp));
        exp[0].a=0;
        exp[0].b=0;
        exp[0].c=0;
        exp[0].d=0;
        exp[1].a=1;
        exp[1].b=1;
        exp[1].c=1;
        exp[1].d=1;
        fwrite(exp,sizeof(struct min),2,p);
        fclose(p);
    }
    return 0;

}
