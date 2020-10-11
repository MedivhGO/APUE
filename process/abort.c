#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int test()
{
	abort();
	return 0;
}
int abortdemo(int arg,char *args[])
{
	pid_t pid = 0;
	pid = fork();
	int status;
	if(pid == 0){
		test();
	}
	if(pid > 0){
		wait(&status);
		printf("code = %d\n",WEXITSTATUS(status));
	}
	return 0;
}
