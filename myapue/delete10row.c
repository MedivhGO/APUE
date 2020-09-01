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
    fdbefore=open("sourcedata",O_WRONLY);
    if (fdbefore < 0)
    {
        close(fdafter);
        perror("fdbefore");
        exit(1);
    }
    char c;
    int linecount = 0;

    while (1) {
        read(fdafter,&c,1);
        read(fdbefore,&c,1);
        if (c == '\n') {
            linecount++;
            //printf("%d",linecount);
        }
        if (linecount==10)
            break;
    }
    
    size_t linelen = 0;
    int werr;
    while (read(fdafter,&c,1) > 0) {
        buffer[linelen++] = c;
        if (c == '\n'){
            werr = write(fdbefore,buffer,linelen);
            if (werr < 0 ) {
                close(fdafter);
                perror("write file error");
                exit(1);
            }
            printf("%d\n",werr);
          //  memset(buffer,0,linelen);
            linelen = 0;
        }
    }
    close(fdbefore);
    close(fdafter);
    printf("delete 10 row done");
    return 0;

}
