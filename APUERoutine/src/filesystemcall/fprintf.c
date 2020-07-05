#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int arg,char *args[])
{
	FILE *p = fopen(args[1],"w");
	if(p == NULL)
		printf("error is %s\n",strerror(errno));
	else{
		printf("success\n");
		char buf[100];
		memset(buf,0,sizeof(buf));
		strcpy(buf,"hello,world!\n");
		fprintf(p,"%s\n",buf);
		fclose(p);
	}
	return 0;
}
