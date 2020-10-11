#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
void writelog(const char *log)
{
	time_t tDate;
	struct tm *evenTime;
	time(&tDate); //get sys time now
	evenTime = localtime(&tDate); //let time_t transfer to struct tm
	int iYear = evenTime->tm_year + 1900;
	int iMon = evenTime->tm_mon + 1;
	int iDay = evenTime->tm_mday;
	int iHour = evenTime->tm_hour;
	int iMin = evenTime->tm_min;
	int iSecond = evenTime->tm_sec;

	char sDate[16];
	sprintf(sDate,"%04d-%02d-%02d",iYear,iMon,iDay);
	char sTime[16];
	sprintf(sTime,"%02d:%02d:%02d",iHour,iMin,iSecond);
	char s[1024];
	sprintf(s,"%s %s %s\n",sDate,sTime,log);

	FILE *p = fopen("my.log","a+");
	if(p == NULL){
		printf("write log my.log error:%s\n",strerror(errno));
	}
	else{
 		fputs(s,p);
		fclose(p);
	}
	return ;
}
int logdemo(int arg,char *args[])
{
	writelog("proccess begin");
	printf("hello world\n");
	writelog("proccess end");
	return 0;
}
