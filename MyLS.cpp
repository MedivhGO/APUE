#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int
main(int argc,char *argv[])
{

	DIR *dp;
	struct dirent *dirp;
	if(argc != 2)
		puts("a single argument(the directory name) is required");
	if((dp = opendir(argv[1])) == NULL)
		printf("can't open %s",argv[1]);
	while((dirp = readdir(dp))!= NULL)
		printf("%s\n",dirp->d_name);
	closedir(dp);
	exit(0);
}
