#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
	printf("begin\n");
	pid_t child = fork(); //all p begin at this 
	if(child == -1){  //don't have enough mem will return -1
		printf("call fork error\n");
		return -1;
	}
	if(child == 0){ //zai zi jin cheng zhong
		printf("is child\n");
	//	for(;;){
	//		sleep(1);
	//		printf("child pid = %d\n",getpid());
	//	}
	}
	else{
		printf("is parent child pid is %d\n",child);
	//	for(;;){
	//		sleep(1);
	//		printf("parent pid = %d\n",getpid());
	//	}
	}
	printf("end\n");
	return 0;
}
