#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
    char s[]="abc.txt";
	int i = 1;
	close(STDOUT_FILENO);
	int fd1 = open("/dev/pts/1",O_WRONLY);//can be read and writed
	int fd = open(s,O_RDONLY); //only be read
	if(fd==-1){
		printf("%s\n",strerror(errno));
	}
	else{
	  	while(i--){
			printf("fd1 = %d,fd = %d:%d\n",fd1,fd);
			sleep(1);
		}
		close(fd);
		close(fd1);
	}
	return EXIT_SUCCESS;
}
