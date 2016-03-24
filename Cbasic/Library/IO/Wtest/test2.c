#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *fp = fopen("test.txt","a+");
	struct tm *t1;
	time_t t;
	char buf[100];
	int c;
	int line=1;
	memset(buf,0,sizeof(buf));

	if(fp < 0){
		perror("open test.txt error");
		exit(-1);
	}

	while((c = getc(fp)) != EOF)
		if(c == '\n')
			line++;

	while(1){
		time(&t);
		t1 = localtime(&t);
		sprintf(buf,"%d, %d-%d-%d %d:%d:%d\n",line++,t1->tm_year+1900,t1->tm_mon+1,t1->tm_mday,t1->tm_hour,t1->tm_min,t1->tm_sec);
		printf("%d, %d-%d-%d %d:%d:%d\n",line,t1->tm_year+1900,t1->tm_mon+1,t1->tm_mday,t1->tm_hour,t1->tm_min,t1->tm_sec);

		fwrite(buf,sizeof(char),strlen(buf),fp);
		fflush(fp);

		sleep(1);

	}

	return 0;

}
