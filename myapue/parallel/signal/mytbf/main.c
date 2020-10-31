#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

#include "mytbf.h"

#define CPS 10
#define BUFFSIZE 1024
#define BURST 100



int main(int argc, char **argv)
{
    int sfd, dfd = 1;
    char buf[BUFFSIZE];
    int len = 0;
    int ret = 0;
    int size = 0;
    int pos;
    mytbf_t *tbf;
    if (argc < 2)
    {
        fprintf(stderr, "Usage..\n");
        exit(1);
    }

    tbf = mytbf_init(CPS,BURST);

    if (tbf == NULL) {
        fprintf(stderr,"mytbf_init() failed!\n");
        exit(1);
    }


    do
    {
        sfd = open(argv[1], O_RDONLY);
        if (sfd < 0)
        {
            if (errno != EINTR)
            {
                perror("open()");
                exit(1);
            }
        }
    } while (sfd < 0);



    while (1)
    {

        size = mytbf_fetchtoken(tbf,BUFFSIZE);

        if (size < 0){
            fprintf(stderr,"mytbf_fetchtoken():%s\n",strerror(-size));
        }

        while((len = read(sfd, buf, size)) < 0)
        {
            if (errno == EINTR)
                continue;
            perror("read()");
            break;
        }
        if (len == 0)
            break;

        if (size-len > 0)
            mytbf_returntoken(tbf,size-len);

        pos = 0;
        while (len > 0)
        {
            ret = write(dfd, buf + pos, len);
            if (ret < 0)
            {
                if (errno ==EINTR)
                    continue;
                perror("write()");
                exit(1);
            }
            len -= ret;
            pos += ret;
        }

        sleep(1);
    }


    mytbf_destory(tbf);
    close(sfd);
    exit(0);
}
