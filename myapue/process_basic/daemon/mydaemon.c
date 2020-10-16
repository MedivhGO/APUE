
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>

#define FNAME "/tmp/out"

static int daemonize()
{
    pid_t pid;
    int fd;
    pid = fork();

    if (pid < 0)
    {
        return -1;
    }

    if (pid > 0)
    {
        exit(0);
    }

    fd = open("/dev/null", O_RDWR);

    if (fd < 0)
    {
        return -1;
    }

    //对0,1,2进行重定向

    dup2(fd, 0);
    dup2(fd, 1);
    dup2(fd, 2);

    if (fd > 2)
    {
        close(fd);
    }

    chdir("/"); //当前的工作路径到根目录的位置.

    umask(0); //不会再产生文件.关掉

    setsid();
    return 0;
}

int main()
{

    FILE *fp;
    int i;

    daemonize();
    if (daemonize())
    {
        syslog(LOG_ERR, "daemonize() failed!");
        exit(1);
    }
    else
    {
        syslog(LOG_INFO, "daemonize() successed!"); //syslogd自己会处理格式
    }

    fp = fopen(FNAME, "w");

    if (fp == NULL)
    {
        syslog(LOG_ERR,"fopen:%s",strerror(errno));
        exit(1);
    }

    syslog(LOG_INFO,"%s was opened.",FNAME);

    for (i = 0;; i++)
    {
        fprintf(fp, "%d\n", i);
        fflush(fp);
        syslog(LOG_DEBUG,"%d is printed.",i);
        sleep(1);
    }

    fclose(fp);
    closelog();
    exit(0);
}