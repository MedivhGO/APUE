#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
int main(int arg,char *args[]){
 		FILE *p  = fopen(args[1],"r+");
		if(p == NULL)
			printf("error is %s\n",strerror(errno));
		else{
			printf("success\n");
			char buf[100];
			memset(buf,0,sizeof(buf));
			while(fgets(buf,sizeof(buf),p)){
				printf("%s",buf);
			}
			fclose(p);
			}
		return 0;

}
