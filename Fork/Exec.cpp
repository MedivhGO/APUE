#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
int main1()
{
	char *args[] = {
		"/bin/ls",
		"-l",
		NULL
	};
	execve("/bin/ls",args,NULL);
	return 0;

}
