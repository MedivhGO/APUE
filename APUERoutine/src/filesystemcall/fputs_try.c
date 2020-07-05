#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int main(int arg,char *args[])
{
 	FILE *p  = fopen(args[1],"r+");
	if(p == NULL)
		printf("error is %s\n",strerror(errno));
	else{
		printf("success\n");
		char buf[100];
		int i = 0;
		for(;i<100;i++){
			sprintf(buf,"i =\t%d\n",i);
			fputs(buf,p);
		}
	//	char buf2[100];
	//	memset(buf2,0,sizeof(buf2));
	//	memset(buf,'a',sizeof(buf));
//		 fgets(buf2,p);
		fclose(p);
	}
	return 0;
}
