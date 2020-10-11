#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int fscanfdemo(int arg,char *args[])
{
	FILE *p = fopen(args[1],"r");
	if(p == NULL)
		printf("error is %s\n",strerror(errno));
	else
	{
		printf("success\n");
		char buf[100];
		memset(buf,0,sizeof(buf));
		while(fscanf(p,"%s",buf)!=EOF){
		   	printf("%s\n",buf);
		}
		fclose(p);
	}
	return 0;
}

