#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fdbefore = -1;
    int fdafter = -1;


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
   after =  lseek(fdafter,10,SEEK_SET);
   before = lseek(fdbefore,11,SEEK_SET);








}
