#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>


#define PATHSIZE 1024


static int  path_noloop(const char* path)
{
	
	//找一个字符串中的字符 char* strrchr(const] char *s,int c)
	
	char* pos;
	strrchr(path,'/');
	
	pos = strrchr(path,'/');
	if (pos == NULL)
		exit(1);
	
	if (strcmp(pos+1,".") == 0 || strcmp(pos+1,"..") == 0)
		return 0;
	
	return 1;
	
}

static int64_t mydu(const char* path)
{
	struct stat statres;
	static char nextpath[PATHSIZE];
	glob_t globres;
	int i;
	static int ret;
	int64_t sum = 0;
	if(lstat(path,&statres)<0)
	{
		perror("lstat()");
		exit(1);
	}
	
	if (!S_ISDIR(statres.st_mode)){
		return statres.st_blocks;
	} 
	
	
	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/*",PATHSIZE);
	puts("run this");
	ret = glob(nextpath,0,NULL,&globres);
	if (ret != 0){
		puts("glob error");
		exit(1);
	}

	
	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/.*",PATHSIZE);
	
	ret = glob(nextpath,GLOB_APPEND,NULL,&globres);
	if (ret != 0){
		puts("glob error");
		exit(1);
	}
	
	
	sum+= statres.st_blocks;

	
	for (i = 0; i < globres.gl_pathc; i++)
	{
		if (path_noloop(globres.gl_pathv[i]))
			sum += mydu(globres.gl_pathv[i]);
	}
	
	
	
	
	globfree(&globres);
	
	return sum;
	
	
}

int main(int argc,char** argv)
{
	
	
	if (argc < 2)
	{
		fprintf(stderr,"Usage... \n");
		exit(1);
	}
	
	printf("%lld\n",mydu(argv[1])/2);


    exit(0);

}
