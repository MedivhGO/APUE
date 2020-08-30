#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int NonaPipe(int arg,char *args[])
{
    int fd[2];
    char buf[100];
    int len;
    pipe(fd);
    memset(buf,0,sizeof(buf));
    int pid = fork();
    if(pid == 0)
    {
        close(fd[1]);
        while((len = read(fd[0],buf,sizeof(buf))) > 0)
        {
            write(STDOUT_FILENO,buf,len);
        }
        close(fd[0]);
    }
    else
    {
        close(fd[0]);
        strcpy(buf,"hello world\n");
        write(fd[1],buf,sizeof(buf));
        close(fd[1]);
        waitpid(pid,NULL,0);
    }
    return 0;
}
