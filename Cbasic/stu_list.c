#include<stdio.h>
#include<stdlib.h>
#include<string.h>
PSTU head1 = NULL ;
int sq_stu ;
#if 1
	FILE*fp;
int stu_llopen(char* path)//���ļ�
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
			printf("����ռ䲻��");
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
int stu_llshow()//��ʾ
{
//	FILE *fp;
    if(head1==NULL)
	return -1;
    PSTU p=head1;
	printf("ѧ��\t����\t��ѧ\tӢ��\t����\t�༶\t����\n");
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

int stu_llcheck()//����
{
   printf("\n�������ѧ��\n");
	int key;
	scanf("%d",&key);
        while(getchar()!='\n');
         PSTU p;
	 p=head1;
    if(head1==NULL) 
 {
    printf ("������ʧ��") ;
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
	   printf ("δ�ҵ���ѧ��");
	   printf ("�Ƿ��������y/n") ;
	   char ch ;
       ch=getchar();
       while(getchar()!='\n');
	   if((ch='y')||(ch=='Y')) 
	         stu_llcheck()   ;
	      else exit(1) ;

	 }

return 0;
}
int __stu_lladd(PSTU p)//���������
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
int stu_lladd()//���
{
	PSTU p;
  p=malloc(sizeof(STU));
  if(p==NULL) return -1;
   printf("\n�������ѧ����Ϣ\n\n");
	printf("ѧ��\t����\t��ѧ\tӢ��\t����\t�༶\t����\t����\n");
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
int __stu_lldelete(int id)//�����õ�ɾ��
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
			         printf ("δ�ҵ���ѧ��\n");

		  }
	      free(p);
}
int stu_lldelete()//ɾ��
{
        int id;
		PSTU p;
   printf("\n����ɾ��ѧ��\n");
   scanf("%d",&id);
   while(getchar()!='\n') ;
   return __stu_lldelete(id);
}
#endif
#if 1
int stu_llchange()//�޸�
{ 
    PSTU p;
    printf("\n�����޸�ѧ��");
        int key;
        scanf("%d",&key);
        while(getchar() != '\n');
         p=head1;
         while(p)
         {
                 if(p->id==key){
         printf("ѧ��\t����\t��ѧ\tӢ��\t����\t�༶\t����\t����\n");
	scanf("%d%d%d%d%d%d%s%s",
		&p->id,&p->age,&p->math,&p->english,
	&p->chinese,&p->class,p->name,p->passwd);

             break ;
}
                 p=p->next;}

/* fprintf( fp ,
			"%d\t%d\t%d\t%d\t%d\t%s\t%d\n",
			p->id,p->age,p->math,p->english,p->chinese,p->name,p->class	);
	printf("ѧ��\t����\t��ѧ\tӢ��\t����\t����\t�༶");
*/      p = head1 ;
	printf ("�޸�֮��Ϊ\n");
        printf("ѧ��\t����\t��ѧ\tӢ��\t����\t�༶\t����\n");
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
#if 1  //����
int stu_sort()
{
	PSTU p ;
//  p->sum == (p->math + p->english + p->chinese) ;
PSTU  new_head1=NULL;
PSTU q=NULL,max=head1,prev;
 printf ("�����ܳɼ�����\n");
while(head1)
{
	//1,�ҵ��������Ľڵ��ַ
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

	//3,�Ѹýڵ�ͷ�嵽������ͷָ��
	max->next = new_head1;
	new_head1 = max;
}
head1 = max;
stu_llshow() ;
 return 0 ;
}
#endif

#if 1
PSTU stu_check_id() //У��ѧ���û���
{
	PSTU p;
	p = head1;
	int id;
	char ch;
	printf("����������ѧ��:");
	scanf("%d",&id);
        while(getchar() != '\n');
	while(p)
	{
		if(p->id==id){
			return p;
		}
		p = p->next;
	}
	    printf ("�ҵ����û�\n") ;
	if(p==NULL){
	printf("�Ҳ������û�\n");
	printf("�Ƿ�����?[y/n]\n");
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
PSTU stu_check_passwd() //У��ѧ������
{
    PSTU p;
    p =stu_check_id();
    char passwd[20];
    char ch;
    printf("����������:");
    scanf("%s",passwd);
     while(getchar()!='\n') ;
    if(strcmp (p->passwd , passwd)==0)
      {
	   sq_stu = p->id ;
		return p;
    }else{
	printf("���벻��ȷ\n");
	printf("�Ƿ���������[y/n]\n");
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
    printf("������������:");
    scanf("%s",new_passwd);
    while(getchar() != '\n');
    printf("���ٴ�����������:");
    scanf("%s",new);
     while(getchar()!='\n') ;
    if(strcmp(new_passwd,new)==0)
	{
        strcpy(p->passwd,new_passwd) ;
         printf("�����޸ĳɹ�!\n");
    }
    else
    {
	printf("�����������\n");
	printf("�Ƿ�����[y/n]\n");
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
			  printf("ѧ��\t����\t��ѧ\tӢ��\t����\t�༶\t����\t����\n");
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
printf ("��������Ҫ���ҵİ༶:\n");
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
	printf("δ�ҵ��ð༶\n");
   
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
			printf("����ʧ��\n");
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
