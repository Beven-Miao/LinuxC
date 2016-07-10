#include<stdio.h>
#include<stdlib.h>
#include<string.h>
PSTU head1 = NULL ;
int sq_stu ;
#if 1
	FILE*fp;
int stu_llopen(char* path)//打开文件
{
	fp=fopen(path,"r");
	if(fp==NULL){
		perror("open fail");
		return -1;}
#ifdef _DEBUG_
	     printf ("open susess\n") ;
#endif
	PSTU p;
	int ret;
	while(p)
	{   
#ifdef _DEBUG_
		perror("while -time\n");
#endif
		p=malloc(sizeof(STU));
		if(p==NULL){
			printf("申请空间不够");
			return -1;}
		ret=fscanf(fp,"%d%d%d%d%d%d%s%s",
		 &p->id,&p->age,&p->math,&p->english,
		 &p->chinese,&p->class,p->name,p->passwd);
#ifdef _DEBUG_
		printf("ret is ok\n") ;
#endif
		if(ret<=0) {
#ifdef _DEBUG_
			printf ("list is end \n ") ;
#endif
			break;
		}
		if(head1==NULL){
			p->next=NULL;
			p->pre=NULL;
			head1=p;}
		else{
			p->next=head1;
			p->pre=NULL;
			head1->pre=p;
			head1=p;} 
	}
	return 0;
}
#endif
int stu_llshow()//显示
{
//	FILE *fp;
    if(head1==NULL)
	return -1;
    PSTU p=head1;
	printf("学号\t年龄\t数学\t英语\t语文\t班级\t姓名\n");
	while(p)
	{
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
    p->id,p->age,p->math,p->english,p->chinese,
	p->class,p->name);
	p=p->next;
	}
//      fflush(stdout) ;
   return 0;
}

int stu_llcheck()//查找
{
   printf("\n输入查找学号\n");
	int key;
	scanf("%d",&key);
        while(getchar()!='\n');
         PSTU p;
	 p=head1;
    if(head1==NULL) 
 {
    printf ("打开链表失败") ;
        return -1;
 }
	 while(p)
	 {
		 if(p->id==key)  {
#ifdef _DEBUG_
    printf ("while p ")	;	  
#endif
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
    p->id,p->age,p->math,p->english,p->chinese,
	p->class,p->name);
               break ;
}              
	      	 p=p->next;
			 }

		if (p==NULL) {
	   printf ("未找到该学生");
	   printf ("是否继续查找y/n") ;
	   char ch ;
       ch=getchar();
       while(getchar()!='\n');
	   if((ch='y')||(ch=='Y')) 
	         stu_llcheck()   ;
	      else exit(1) ;

	 }

return 0;
}
int __stu_lladd(PSTU p)//被调用添加
{
	if(p==NULL) return -1;
	if(head1==NULL){
	  p->next=NULL;
	  p->pre=NULL;
	  head1->pre=p;
	  head1=p;}
  else{
	  p->next=head1;
	  p->pre=NULL;
	  head1->pre=p;
	  head1=p;}
  return 0;
}
int stu_lladd()//添加
{
	PSTU p;
  p=malloc(sizeof(STU));
  if(p==NULL) return -1;
   printf("\n输入添加学生信息\n\n");
	printf("学号\t年龄\t数学\t英语\t语文\t班级\t姓名\t密码\n");
	scanf("%d%d%d%d%d%d%s",
		&p->id,&p->age,&p->math,&p->english,
		&p->chinese,&p->class,p->name,p->passwd);
	__stu_lladd(p);
/* fprintf( fp ,
			"%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
			p->id,p->age,p->math,p->english,p->chinese,p->class,p->name	);
	fclose (fp) ;
        fp = fopen ("student.txt","r"  ) ;
*/
  return 0;
}
#if 1
int __stu_lldelete(int id)//被调用的删除
{
     PSTU p;
	 PSTU q=NULL;
	 p=head1;
	 while(p)
	 {
	  if(p->id==id){
		 if(p==head1){
			 if(head1->next){
				 head1=head1->next;
				 head1->pre=NULL;}
			 else{
				 head1=NULL;}
	            	 }
			 else{
				 if(p->next){
					 p->pre->next=p->next;
					 p->next->pre=p->pre;}
				 else{
					 p->pre->next=NULL;}
			 }
		 
		 break;
	 }
		p=p->next;
	 } 
	      if (p==NULL) {
			         printf ("未找到该学生\n");

		  }
	      free(p);
}
int stu_lldelete()//删除
{
        int id;
		PSTU p;
   printf("\n输入删除学号\n");
   scanf("%d",&id);
   while(getchar()!='\n') ;
   return __stu_lldelete(id);
}
#endif
#if 1
int stu_llchange()//修改
{ 
    PSTU p;
    printf("\n输入修改学号");
        int key;
        scanf("%d",&key);
        while(getchar() != '\n');
         p=head1;
         while(p)
         {
                 if(p->id==key){
         printf("学号\t年龄\t数学\t英语\t语文\t班级\t姓名\t密码\n");
	scanf("%d%d%d%d%d%d%s%s",
		&p->id,&p->age,&p->math,&p->english,
	&p->chinese,&p->class,p->name,p->passwd);

             break ;
}
                 p=p->next;}

/* fprintf( fp ,
			"%d\t%d\t%d\t%d\t%d\t%s\t%d\n",
			p->id,p->age,p->math,p->english,p->chinese,p->name,p->class	);
	printf("学号\t年龄\t数学\t英语\t语文\t姓名\t班级");
*/      p = head1 ;
	printf ("修改之后为\n");
        printf("学号\t年龄\t数学\t英语\t语文\t班级\t姓名\n");
        while(p)
        {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
    p->id,p->age,p->math,p->english,p->chinese,
        p->class,p->name);
        p=p->next;
        }



	return 0;
}
#endif
#if 1  //排序
int stu_sort()
{
	PSTU p ;
//  p->sum == (p->math + p->english + p->chinese) ;
PSTU  new_head1=NULL;
PSTU q=NULL,max=head1,prev;
 printf ("按照总成绩排序\n");
while(head1)
{
	//1,找到最大分数的节点地址
	max = head1;
	prev=q=NULL;
	p=head1;
	while(p)
	{
		if( (p->math+p->english+p->chinese) > (max->math+max->english+max->chinese) )
		{
			max = p;
			prev= q;
		}
		q = p;
		p=p->next;
	}
	if(prev){
		prev->next = max->next;
	}else{
		 head1= head1->next;
	}

	//3,把该节点头插到新链表头指针
	max->next = new_head1;
	new_head1 = max;
}
head1 = max;
stu_llshow() ;
 return 0 ;
}
#endif

#if 1
PSTU stu_check_id() //校验学生用户名
{
	PSTU p;
	p = head1;
	int id;
	char ch;
	printf("请输入您的学号:");
	scanf("%d",&id);
        while(getchar() != '\n');
	while(p)
	{
		if(p->id==id){
			return p;
		}
		p = p->next;
	}
	    printf ("找到该用户\n") ;
	if(p==NULL){
	printf("找不到该用户\n");
	printf("是否重试?[y/n]\n");
    ch = getchar () ;
      while(getchar()!='\0');
	if ((ch=='y')||(ch=='Y'))
			stu_check_id();
	else
	    menu();
}
}
#endif
#if 1
PSTU stu_check_passwd() //校验学生密码
{
    PSTU p;
    p =stu_check_id();
    char passwd[20];
    char ch;
    printf("请输入密码:");
    scanf("%s",passwd);
     while(getchar()!='\n') ;
    if(strcmp (p->passwd , passwd)==0)
      {
	   sq_stu = p->id ;
		return p;
    }else{
	printf("密码不正确\n");
	printf("是否重新输入[y/n]\n");
	ch = getchar () ;
       while(getchar()!='\n');
	if((ch=='y')||(ch=='Y'))
	   stu_check_passwd();
	else
	    menu();
    }
    return NULL;
}
#endif
#if 1
int stu_change_passwd()
{
    PSTU p;
    p=stu_check_passwd();
//    p->passwd=1234;
    char new_passwd[20];
    char new[20];
    char ch;
    printf("请输入新密码:");
    scanf("%s",new_passwd);
    while(getchar() != '\n');
    printf("请再次输入新密码:");
    scanf("%s",new);
     while(getchar()!='\n') ;
    if(strcmp(new_passwd,new)==0)
	{
        strcpy(p->passwd,new_passwd) ;
         printf("密码修改成功!\n");
    }
    else
    {
	printf("密码输入错误\n");
	printf("是否重试[y/n]\n");
	ch=getchar();
	while (getchar()!='\n') ;
	if((ch=='y')||(ch=='Y'))
	   stu_change_passwd();
	else
	    student_menu();
    }
    return 0;
}
#endif

#if 1
int stu_lookme()
{
    PSTU p;
	p = head1 ;
#ifdef _DEBUG_
        printf ("%d\n",sq_stu) ;
#endif
	while (p) {
              if (p->id==sq_stu){ 
			  printf("学号\t年龄\t数学\t英语\t语文\t班级\t姓名\t密码\n");
		      printf("%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n",
			 p->id,p->age,p->math,p->english,p->chinese, p->class,p->name,p->passwd);
	}		               p = p->next ;
	                       
   } 
   return 0 ; 
}

#endif
#if 1

int stu_write()
{
    PSTU p;
    FILE *fp;
//	PSTU head1 ;
    p=head1;
    fp=fopen("student.txt","w");
    while(p)
    {
    fprintf( fp,
			"%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n",
	          p->id,p->age,p->math,p->english,p->chinese,p->class,p->name,p->passwd);
	             p=p->next;
    }
    return 0;
}
#endif
#if 1  
void stu_check_class() 
{
int class ;
PSTU p ;
int i=0 ;
p = head1 ;
printf ("请输入您要查找的班级:\n");
scanf ("%d",&class);
     while(getchar()!='\n') ;
while (p){ 
	if (p->class==class ) {
	   printf("%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
			   p->id,p->age,p->math,p->english,p->chinese,
			   p->class,p->name); 
	                  i++ ; }
	                p=p->next;	
	
}
        if((p==NULL)&&(i==0))
	printf("未找到该班级\n");
   
}

#endif

#if 0
int main(int argc,char * argv[])
{
 /*   if(argc<2){
		printf("execult error");
		return -1;}
*/	int ret;
	PSTU p;
	ret=stu_llopen("student.txt");
		if(ret<0){
			printf("创建失败\n");
			return -1;}

	printf ("debug-000\n") ;

//	int id;
        stu_llshow();
//	stu_lldelete();
//         stu_llcheck() ;
//	stu_llshow();
    stu_check_class() ; 
//	stu_llchange();
//	sleep (1) ;
//	stu_llshow();
//	stu_sort();
//	stu_llshow();
return 0;
}
#endif
