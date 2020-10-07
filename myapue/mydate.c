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
int main()
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
			
				break;
			case 'M' :
				
				strcat(fmtstr,"%M",FMTSTRSIZE);
			
				break;
			
			case 'S' :
			
				break;
			
			case 'y' :
			
				break;
			
			case 'm' :
			
				break;
			
			case 'd' :
			
				break;
			
			default:
				break;
			
		}
		
		
		
	}
	
	//strftime(timestr,TIMESTARSIZE,"Now: %Y-%m-%d",tm);
	strftime(timestr,TIMESTARSIZE,fmtstr,tm);
	puts(timestr);

	//tm->tm_mday += 100;
	//(void)mktime(tm);
	//strftime(timestr,TIMESTARSIZE,"100 days later:%Y-%m-%d",tm);
	//puts(timestr);
	exit(0);
}