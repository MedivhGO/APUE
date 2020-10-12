#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
int main(int arg,char *args[]){
    FILE *p  = fopen(args[1],"r+");
    if(p == NULL)
        //printf("error is %s\n",strerror(errno));
        perror("error is");
    else{
        printf("success\n");
        char buf[100];
        memset(buf,0,sizeof(buf));
        int count = 0;
        while(fgets(buf,sizeof(buf),p)){
            printf("%s",buf);
            count++;
        }
        printf("read time %d",count);
        fclose(p);
    }
    return 0;

}
