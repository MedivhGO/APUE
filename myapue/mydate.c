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
	FILE* fp = stdout;

	char fmtstr[FMTSTRSIZE];

	fmtstr[0] = '\0';

	stamp = time(NULL);
	tm = localtime(&stamp);

	while(1)
	{
		c =  getopt(argc,argv,"-H:MSy:md"); //-开头，遇到非选项的传参时，返回值为1
		if (c < 0)
			break;

		switch(c)
		{
			case '1' :
				if (fp == stdout) {
						fp = fopen(argv[optind-1],"w"); //optind 当前的argv下标
					if (fp == NULL) {
						perror("fopen()");
						fp = stdout;
					}
				}
				break;
			case 'H' :
				if (strcmp(optarg,"12")==0) {
					strncat(fmtstr,"%I(%P) ",FMTSTRSIZE);
				} else if (strcmp(optarg,"24") == 0) {
					strncat(fmtstr,"%H ",FMTSTRSIZE);
				} else {
					fprintf(stderr,"Invalid argument");	
				}
				break;
			case 'M' :
				strncat(fmtstr,"%M ",FMTSTRSIZE);
				break;
			case 'S' :
				strncat(fmtstr,"%S ",FMTSTRSIZE);
				break;
			case 'y' :
				if (strcmp(optarg,"2")==0) {
					strncat(fmtstr,"%y",FMTSTRSIZE);
				} else if (strcmp(optarg,"4")==0) {
					strncat(fmtstr,"%Y",FMTSTRSIZE);
				} else {
					fprintf(stderr,"Invalid argument");	
				}
				break;
			case 'm' :
				strncat(fmtstr,"%m ",FMTSTRSIZE);
				break;
			case 'd' :
				strncat(fmtstr,"%d ",FMTSTRSIZE);
				break;
			default:
				break;
		}
	}

	//strftime(timestr,TIMESTARSIZE,"Now: %Y-%m-%d",tm);
	strncat(fmtstr,"\n",FMTSTRSIZE);
	strftime(timestr,TIMESTARSIZE,fmtstr,tm); //使用给定格式输出字符串
	fputs(timestr,fp);
	
	if (fp != stdout) 
		fclose(fp);

	//tm->tm_mday += 100;
	//(void)mktime(tm);
	//strftime(timestr,TIMESTARSIZE,"100 days later:%Y-%m-%d",tm);
	//puts(timestr);
	exit(0);
}
