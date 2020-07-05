#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
struct abc{
	char name[5];
	int i;
};
int main(int arg,char *args[]){

	FILE *p = fopen(args[1],"r+");
	if(p == NULL)
	{
		printf("error is %s\n",strerror(errno));
	}
	else
	{
		struct abc a[100];
		printf("success\n");
		char buf[100];
		size_t rc = 0;
		while(1){
		size_t tmp = fread(buf,1,1,p); //principle the second multiply the first arugment can't beyond the buff
		rc +=tmp;
		if(tmp == 0)
			break;
		}
		// fread(a,sizeof(struct abc),1,p);
		printf("%d\n",rc);
		printf("%s\n",buf);
		fclose(p);

		
	}

}
