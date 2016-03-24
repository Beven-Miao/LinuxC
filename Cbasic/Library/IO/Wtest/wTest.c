#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	FILE *fp = fopen("test.txt","a+");
	struct tm *t1;
	time_t t;
	char buf[100];
	int line = 1;
	int c;
	
	memset(buf,0,sizeof(buf));

	//文件不存在
	if(fp < 0){
		perror("failed to open test.txt");
		exit(1);
	}
	
	while((c = getc(fp)) != EOF)
		if(c == '\n')
			line++;
	while(1){
		time(&t);
		t1 = localtime(&t); //获取当前时间
		
		sprintf(buf,"%d, %d-%d-%d %d:%d:%d\n",line++,t1->tm_year + 1900, t1->tm_mon+1,t1->tm_mday, t1->tm_hour, t1->tm_min, t1->tm_sec);
		printf(buf,"%d, %d-%d-%d %d:%d:%d\n",line,t1->tm_year + 1900, t1->tm_mon+1,t1->tm_mday, t1->tm_hour, t1->tm_min, t1->tm_sec);
		fwrite(buf,sizeof(char),strlen(buf),fp);
		fflush(fp);

		sleep(1);
	}
	return 0;
}
