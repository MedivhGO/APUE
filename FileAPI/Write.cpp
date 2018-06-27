#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int Write(int arg,char *args[])
{
	int fd = open(args[1],O_RDWR|O_APPEND);
	if(fd == -1)
		printf("error is %s\n",strerror(errno));
	else
	{
		printf("success fd = %d\n",fd);
		char buf[100];
		memset(buf,0,sizeof(buf));
		strcpy(buf,"hello,world\n");
		int i = write(fd,buf,strlen(buf));
		close(fd);
	}
	return 0;
}
