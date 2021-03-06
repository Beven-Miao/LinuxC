#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    FILE *ini,*xml;            //声明两个文件流
    //声明两个缓冲区
    char buf[100];            //存放父节点，即http,database
    char dbuf[100];            //存放子节点和子节点的值，即doamin=www.mysite.com```````
    char ch;                        //定义一个变量用来获取文件的当前位置字符
    int i = 0;
    char *kay,*value;        //用来分割子节点和子节点的值用到的指针

    if((ini = fopen("inifile.txt","r")) == NULL){        //打开源文件
        perror("open inifile.txt");
        exit(1);
    }

    if((xml = fopen("xml","aw+")) == NULL){            //打开目标文件
        perror("open xml");
        exit(1);
    }

    while((ch = fgetc(ini)) != EOF){                        //一直读到文件的末尾
        if(ch == ';'){                                                        //根据源文件特性进行判断
            i = 0;
            memset(buf,0,sizeof(buf));                            //初始化缓存区
            while((ch = fgetc(ini)) != '\r')                //windows下的文件一行的结束符用‘\r’'\n'来表示
                buf[i++] = ch;
            fseek(ini,1,SEEK_CUR);                                    //把文件指针偏移到下一行
            fprintf(xml,"<!--%s-->\n",buf);                    //把缓冲区的数据写入文件
            continue;
        }

        if(ch == '['){
            i = 0;
            memset(buf,0,sizeof(buf));
            while((ch = fgetc(ini)) != ']')
                buf[i++] = ch;
            fseek(ini,2,SEEK_CUR);
            fprintf(xml,"<%s>\n",buf);
            continue;
        }
        if(ch != '\n' && ch != '\r' && ch != ' '){
            memset(dbuf,0,sizeof(buf));
            i = 0;
            while((ch = fgetc(ini)) != '\r')
                dbuf[i++] = ch;
            kay = strtok(dbuf,"=");                                    //分割字符串
            value = strtok(NULL,"=");
            fprintf(xml,"\t<%s>%s</%s>\n",kay,value,kay);
            fseek(ini,1,SEEK_CUR);
            continue;    
        }
        if(ch == '\n')                                                //当子节点和其值全部写入文件后，即把父节点的结尾补全
            fprintf(xml,"</%s>\n",buf);
            
    }
    fprintf(xml,"</%s>\n",buf);                    //把最后一个父节点结尾写入到文件
    
    //关闭文件
    fcolse(xml);
    fcolse(ini);
return 0;
}
