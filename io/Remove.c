#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int Remove(int arg,char *args[])
{
	if(arg > 1)
		remove(args[1]);
	return 0;

}
