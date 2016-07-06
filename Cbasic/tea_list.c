#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"teacher.h"
int sq_tea ;
PTEA head = NULL ;
FILE *fp ;
int tea_llopen(const char* path)//打开文件
{
	fp=fopen(path,"r");
	if(fp==NULL){
		perror("open fail");
		return -1;}
#ifdef DEBUG
	printf ("debug--001") ;
#endif
	PTEA p;
	int ret;
	while(p)
	{
		p=malloc(sizeof(TEA));
		if(p==NULL){
			perror("申请空间不够");
			return -1;}
		ret=fscanf(fp,"%d%d%d%s%s",
		 &p->id,&p->age,&p->wages,p->name,p->passwd);
		if(ret<=0) break;
		if(head==NULL){
			p->next=NULL;
			p->pre=NULL;
			head=p;}
		else{
			p->next=head;
			p->pre=NULL;
			head->pre=p;
			head=p;}
	}
	return 0;
}
#if 1
int tea_llshow( )//显示
{
    if(head==NULL)
	return -1;
    PTEA p=head;
	printf("工号\t年龄\t工资\t姓名\n");
	while(p)
	{
    printf("%d\t%d\t%d\t%s\n",
    p->id,p->age,p->wages,p->name);
	p=p->next;
	}
   return 0;
}

PTEA tea_llcheck(PTEA a)//查找
{
   printf("输入查找教师工号\n");
	int id;
	scanf("%d",&id);
           while(getchar()!='\n');
     PTEA p;
	 p=head;
	 while(p)
	 {
		 if(p->id==id){
 printf ("工号\t年龄\t薪水\t姓名\n " );
 printf ("%d\t%d\t%d\t%s\n",p->id,p->age,p->wages,p->name);
		break ;
                 	                }
	 p=p->next;
  }
	 if (p==NULL) {
		        printf ("未找到该教师\n");
				printf ("是否继续查找y/n\n") ;
			char ch ;
			getchar();
			ch=getchar();
			if((ch=='y')||(ch=='Y')) 
			tea_llcheck (p )   ;   
			else 
				return NULL  ;
	 }      
	 
return 0;

}
#endif
#if 1
int tea_lladd(PTEA b )//增加老师信息
{
#ifdef _DEBUG_	
	printf ("debug-001\n") ;
#endif
        PTEA p ;
		char ch ;
		p=malloc(sizeof(TEA));
		if(p==NULL){
			perror("申请空间不够\n");
			return -1;}
		printf ("请输入添加老师的信息\n工号\t年龄\t薪水\t姓名\t密码\n") ;
		scanf("%d%d%d%s",&p->id,&p->age,&p->wages,p->name,p->passwd) ;
                while(getchar()!='\n');
		if ( p == NULL )
			return -1 ;
		if ( head == NULL ) //说明链表为空，加入成第一个
		{ p->next = NULL ;
			p->pre = NULL ;
			head->pre = p ;
			head = p ; 
		}
		 else {
		 p->next=head ;
		 p->pre=NULL ;
         head->pre = p ;
		 head=p ;
		 }
/*		 fprintf ( fp , "%d\t%d\t%d\t%s\n",p->id,p->age,p->wages,p->name ) ;
		 	 fclose ( fp ) ;
                 fopen ("teacher.txt" , "a+");
*/		


		return 0 ;
}

#endif 
#if 1
int tea_lldelete( PTEA a   )  //删除老师
{   int key ;
   printf ("请输入要删除的老师的工号\n") ;
   scanf ("%d",&key);
           while(getchar()!='\n');
   PTEA p ;
   PTEA q ;
   p = head ;
   while (p)
   {   if (p->id == key )
	   {
	if( (p == head)&&(head->next!=NULL) )
	   { head = head->next ;
	     head->pre = NULL ;   
#ifdef _DEBUG_
	    printf ("case 1\n") ;
#endif
	   }
	   else  if ((p==head) && ( head->next==NULL))
	   {  head = NULL ;
#ifdef _DEBUG_
	   printf ("case 2\n") ; 
#endif	   
	   } 
      else  if( (p!=head )&&(p->next!=NULL) )
		   {p->pre->next=p->next  ;
			   p->next->pre = p->pre ;
#ifdef _DEBUG_
		       printf ("case 3\n ") ;  I
#endif 
		   }
	   else { p->pre->next = NULL ;
#ifdef _DEBUG_ 
	         printf ("case 4\n") ; 
#endif 
	   }
                 break ;
   }   
          p = p->next ;
		  
   }
              free (p) ;
		if (p==NULL)
			printf ("未找到该教师") ;
/*		fp = fopen("teacher.txt","r+");
	while(p){
	fprintf (fp ," %d\t%d\t%d\t%s\n" , p->id , p->age ,p->wages , p->name );
	    p=p->next ;
	}
	 fclose (fp) ;
        tea_llopen ;
*/ }
#endif 
#if 1   
int tea_llchange()//修改老师信息
{ 
    PTEA p;
    printf("\n输入工号");
        int key;
        scanf("%d",&key);
           while(getchar()!='\n');
         p=head;
         while(p)
         {
                 if(p->id==key){
         printf("工号\t年龄\t薪水\t姓名\n");
	scanf("%d%d%d%s%s",
		&p->id,&p->age,&p->wages,p->name,p->passwd);
           while(getchar()!='\n');
             break ;
}
                 p=p->next;}

                   p = head ;
	printf ("修改之后为\n");
        printf("学号\t年龄\t数学\t英语\t语文\t班级\t姓名\t密码\n");
        while(p)
        {
    printf("%d\t%d\t%d\t%s\t%s\n",
    p->id,p->age,p->wages,p->name,p->passwd);
        p=p->next;
        }



	return 0;
}


#endif

#if 1

PTEA tea_check_id() //校验老师用户名
{
	PTEA p;
	p = head;
	int id;
	char ch;
	printf("请输入您的工号:");
	scanf("%d",&id);
           while(getchar()!='\n');
	while(p)
	{
		if(p->id==id){
			return p;

		}
		p = p->next;
	}
	if(p==NULL){
	printf("找不到该用户\n");
	printf("是否重试?[y/n]\n");
//	scanf("%c",&ch) ;
 //   getchar () ;
    ch = getchar () ;
	if ((ch=='y')||(ch=='Y'))
			tea_check_id();
	else
	    menu();
}
}
#endif
#if 1
PTEA tea_check_passwd() //校验老师密码
{
    PTEA p;
    p =tea_check_id();
    char passwd[20];
    char ch;
    printf("请输入密码:");
    scanf("%s",passwd); 
           while(getchar()!='\n');
    if(strcmp (p->passwd , passwd)==0)
    { 
		sq_tea = p->id ;
#ifdef _DEBUG_
		printf("================%d\n",p->id) ;
		printf("================%d\n",sq_tea) ;
		getchar();
		getchar();
#endif
		return p;
    }else{
	printf("密码不正确\n");
	printf("是否重新输入[y/n]\n");
//	getchar() ;
	ch = getchar () ;
           while(getchar()!='\n');
	if((ch=='y')||(ch=='Y'))
	   tea_check_passwd();
	else
	    menu();
    }
    return NULL;
}
#endif
#if 1
int tea_change_passwd()
{
    PTEA p;
    p=tea_check_passwd();
    char new_passwd[20];
    char new[20];
    char ch;
    printf("请输入新密码:");
    scanf("%s",new_passwd);
        while(getchar() != '\n');
    printf("请再次输入新密码:");
    scanf("%s",new);
        while(getchar() != '\n');
    if(strcmp(new_passwd,new)==0)
	{
        strcpy(p->passwd,new_passwd) ;
         printf("密码修改成功!\n");


   //   tea_write() ;
    }
    else
    {
	printf("密码输入错误\n");
	printf("是否重试[y/n]\n");
//	getchar();
	ch=getchar() ;
           while(getchar()!='\n');
	if((ch=='y')||(ch=='Y'))
	   tea_change_passwd();
	else
	    exit(1);
    }
    return 0;
}
#endif

#if 1
int tea_lookme()
{
    PTEA p;
	p = head ;
   while (p) { 
	  if( p->id == sq_tea ) {
	printf("工号\t年龄\t薪水\t姓名\t密码\n");
	    printf("%d\t%d\t%d\t%s\n%s\n",
			p->id,p->age,p->wages,p->name,p->passwd);
	  }
    p = p->next ;
} 
 return 0 ;
}
#endif


#if 1

int tea_write()
{
      PTEA p;
   //   PTEA head ;
      FILE *fp;
       p=head;
      fp=fopen("teacher.txt","w+");
	  while(p)
	   {   
		fprintf( fp, 
			      "%d\t%d\t%d\t%s\t%s\n",
				  p->id,p->age,p->wages,p->name,p->passwd);
				  p=p->next;
															     }   
							    return 0;
}


#endif


#if 0
int main(int argc,char * argv[])
{
    if(argc<2){
		printf("execult error");
		return -1;}
	int ret;
	PTEA p;
	ret=tea_llopen(argv[1]);
		if(ret<0){
			printf("list is end\n");
			return -1;}
//	tea_llshow(head);
//	int id;
/*	p=tea_llcheck();
    printf("%d\t%d\t%d\t%s\n",
    p->id,p->age,p->wages,p->name);
*/	//tea_llshow();
//	tea_lladd(head) ;
//	tea_llshow(head) ;
//    tea_lldelete( head ) ;	
 //   tea_llshow(head) ;
	tea_llcheck(head) ;
     return 0;
  }
#endif
