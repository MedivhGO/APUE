#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/*
	-y: year
	-m: month
	-d: day
	-H: hour
	-M: minute
	-S: second

*/


#define TIMESTARSIZE 1024
#define FMTSTRSIZE 1024
int main(int argc,char** argv)
{
	time_t stamp;
	struct tm *tm;
	char timestr[TIMESTARSIZE];
	int c;

	char fmtstr[FMTSTRSIZE];

	fmtstr[0] = '\0';

	stamp = time(NULL);
	tm = localtime(&stamp);

	while(1)
	{

		c =  getopt(argc,argv,"HMSymd");
		if (c < 0)
			break;

		switch(c)
		{
			case 'H' :
				strncat(fmtstr,"%H",FMTSTRSIZE);
				break;
			case 'M' :
				strncat(fmtstr,"%M",FMTSTRSIZE);
				break;
			case 'S' :
				strncat(fmtstr,"%S",FMTSTRSIZE);
				break;
			case 'y' :
				strncat(fmtstr,"%y",FMTSTRSIZE);
				break;
			case 'm' :
				strncat(fmtstr,"%m",FMTSTRSIZE);
				break;
			case 'd' :
				strncat(fmtstr,"%d",FMTSTRSIZE);
				break;
			default:
				break;

		}



	}

	//strftime(timestr,TIMESTARSIZE,"Now: %Y-%m-%d",tm);
	strftime(timestr,TIMESTARSIZE,fmtstr,tm); //使用给定格式输出字符串
	puts(timestr);

	//tm->tm_mday += 100;
	//(void)mktime(tm);
	//strftime(timestr,TIMESTARSIZE,"100 days later:%Y-%m-%d",tm);
	//puts(timestr);
	exit(0);
}
