#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
struct min{
	int a;
	int b;
	int c;
	int d;
};
int sfwritedemo(int arg,char *args[])
{
	FILE *p = fopen(args[1],"r");
	if(p == NULL)
		printf("error is %s\n",strerror(errno));
	else
	{
		printf("success\n");
		struct min temp;
		while(fread(&temp,sizeof(struct min),1,p))
		{
			printf("%d,%d,%d,%d\n",temp.a,temp.b,temp.c,temp.d);
		}
		fclose(p);
	}
	return 0;
}
