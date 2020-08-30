#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
int Read(int arg,char *args[])
{
	if(arg < 2)
		return 0;
	int fd = open(args[1],O_RDONLY);
	if(fd==-1)
	{
		printf("error is %s\n",strerror(errno));
	}
	else
	{
		printf("success fd=%d\n",fd);
		char buf[100];
		memset(buf,0,sizeof(buf));
		while( read(fd,buf,sizeof(buf))>0){
			printf("%s\n",buf);
			memset(buf,0,sizeof(buf));
		}
		close(fd);
	}
	return 0;

}
