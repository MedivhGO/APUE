#include <stdio.h>
void test(void)
{
     int *i = NULL;
     *i=2;	
}
int main(){
	printf("hello\n");
	test();
	return 0;
}
