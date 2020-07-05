#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
int main(int arg,char *args[])
{
	if(arg < 2)
		return 0;
	DIR *dp;
	struct dirent *dirp;
	dp =  opendir(args[1]);
	if(dp == NULL){
		printf("error is %s\n",strerror(errno));
	}
	while((dirp = readdir(dp))){
		printf("%s, %d\n",dirp->d_name,dirp->d_ino);
	}
	closedir(dp);
	return 0;
}
