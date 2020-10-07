#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TIMESTRSIZE 1024

int main()
{
    time_t stamp;
    char timestr[TIMESTRSIZE];
    struct tm *tm;
    stamp = time(NULL);
    tm = localtime(&stamp);
    strftime(timestr,TIMESTRSIZE,"Now: %Y-%m-%d",tm);
    puts(timestr);
    tm->tm_mday += 100;
    mktime(tm);
    strftime(timestr,TIMESTRSIZE,"100day: %Y-%m-%d",tm);
    puts(timestr);
    exit(0);
}