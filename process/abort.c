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
//int abortdemo(int arg,char *args[])
int main(int arg,char *args[])
{
	pid_t pid = 0;
	pid = fork();
	if (pid < 0) {
		perror("fork error");
		exit(1);
	}
	int status;
	if(pid == 0){ //子进程
		printf("child id  %d\n",getpid());
		test();
	} else if(pid > 0){ //父进程
		printf("parent %d\n",getpid());
		wait(&status);
		printf("code = %d\n",WIFEXITED(status)); //由于进程异常退出,所以WIFEXITED返回false
	}
	return 0;
}