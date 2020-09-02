#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFSIZE 1024

int main()
{
    int fdbefore = -1;
    int fdafter = -1;
    char buffer[BUFFSIZE];
    off_t after,before;
    fdafter= open("sourcedata",O_RDONLY);
    if (fdafter < 0)
    {
        perror("fdafter()");
        exit(1);
    }
    fdbefore=open("sourcedata",O_RDWR);
    if (fdbefore < 0)
    {
        close(fdafter);
        perror("fdbefore");
        exit(1);
    }
    char cafter;
    char cbefore;
    int afterlinecount = 0;
    int beforelinecount = 0;
    while (1) {
        read(fdafter,&cafter,1);
        printf("%c",cafter);
        if (cafter == '\n') {
            afterlinecount++;
        }
        if (afterlinecount==9)
            break;
    }
    //确认befor被定位到第10行
    off_t afteroffset = lseek(fdafter,0,SEEK_CUR);
    lseek(fdbefore,afteroffset,SEEK_SET);
    //after在向后走一行
    int thislinelen = 0;
     while (1) {
        read(fdafter,&cafter,1);
        buffer[thislinelen++] = cafter;
        if (cafter == '\n') {
           break;
        }
    }
    //显示当前的位置
    off_t beforeoffset = lseek(fdbefore,0,SEEK_CUR);
    afteroffset = lseek(fdafter,0,SEEK_CUR);
    printf("before %lld ------ after %lld\n",beforeoffset,afteroffset);
    /*******/
    //写入文件中
    //TODO:
    int cur = 0;
    while (read(fdafter,&cafter,1) > 0) {
        buffer[cur++] = cafter;
        if (cafter == '\n') {
            //buffer[cur] = '\0';
            fprintf(stdout,"%s\n",buffer);
            write(fdbefore,buffer,cur);
            cur = 0;
        }
    }
    
    
    //关闭文件
    close(fdbefore);
    close(fdafter);
    return 0;
}