#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = NULL;
    fp = fopen("abc","a");
    fputc('a',fp);
    fseek(fp,0,SEEK_END);
    printf("%ld\n",ftell(fp));


    return 0;

}
