#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int waitdemo(int arg, char *args[])
{
	pid_t pid = fork();//调用fork之后会有两个进程
	int status;
	if (pid == 0)
	{
		printf("child begin\n");
		sleep(5);
		printf("child end\n");
		return -1;
	}

	if (pid > 0)
	{
		printf("parent begin\n");
		wait(&status);//阻塞调用,直到子进程退出，wait才返回
		printf("child return = %d\n", WEXITSTATUS(status));
		printf("parent end\n");
	}

	return 0;
}

