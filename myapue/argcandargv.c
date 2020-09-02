#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	puts("*********************");
	printf("argc = %d\n",argc);
	int i;
	puts("*********************");
	for (i=0;i < argc;i++) {
		puts(argv[i]);
	}
	
	puts("*********************");
	
	for (i = 0; argv[i]!=NULL;i++) {
		puts(argv[i]);
	}
	exit(0);	
}