#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main1(int arg,char *args[])
{
	if(arg >= 2)
		rename(args[1],args[2]);
	return 0;

}
