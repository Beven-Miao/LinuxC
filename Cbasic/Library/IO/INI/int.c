#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *fIni = fopen("Ini","r");
	FILE *fXml = fopen("Xml","w");
	char buf[100];
	char dbuf[100];
	char  ch;
	int i = 0;
	char *key,*value;

	if((fIni = fopen("Ini","r")) == NULL){
		perror("open Ini error");
		exit(-1);
	}

	if((fXml = fopen("Xml","w")) == NULL ){
		perror("open Xml error");
		exit(-1);
	}

	while((ch = fgetc(fIni)) !=EOF){
		if(ch == ';'){
			i = 0;
			memset(buf,0,sizeof(buf));
			while((ch = fgetc(fIni)) != '\n')
				buf[i++] = ch;
			fprintf(fXml,"<!--%s-->\n",buf);
			continue;
		}

		if(ch == '['){
			i=0;
			memset(buf,0,sizeof(buf));
			while((ch = fgetc(fIni)) != ']')
				buf[i++] = ch;
			fseek(fIni,1,SEEK_CUR);
			fprintf(fXml,"<%s>\n",buf);
			continue;
		}

		//该条件判断放在最后，最低优先级
		if(ch != '\n' && ch != ' '){
			i = 0;
			memset(dbuf,0,sizeof(dbuf));
			dbuf[i++] = ch;//先取第一个字符
			while((ch = fgetc(fIni)) != '\n')
				dbuf[i++] = ch;
			key = strtok(dbuf,"=");
			value = strtok(NULL, "=");
			fprintf(fXml, "<%s>%s</%s>\n",key,value,key);
			continue;
		}

		if(ch == '\n')
			fprintf(fXml,"</%s>\n",buf);
	}
	fprintf(fXml,"</%s>\n",buf);

	fclose(fXml);
	fclose(fIni);
	
	return 0;
}
