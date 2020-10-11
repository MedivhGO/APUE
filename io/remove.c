#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int removedemo(int arg,char *args[])
{
	if(arg > 1)
		remove(args[1]);
	return 0;

}
