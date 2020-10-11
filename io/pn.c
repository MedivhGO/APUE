#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
int pndemo()
{
	char *login = getlogin();
	struct passwd *ps = getpwnam(login);
	printf("user name = %s\n",ps->pw_name);
	printf("uid = %d\n",ps->pw_uid);
	printf("home dir = %s\n",ps->pw_dir);
	return EXIT_SUCCESS;
}

