#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"teacher.h"
int sq_tea ;
PTEA head = NULL ;
FILE *fp ;
int tea_llopen(const char* path)//���ļ�
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
			perror("����ռ䲻��");
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
int tea_llshow( )//��ʾ
{
    if(head==NULL)
	return -1;
    PTEA p=head;
	printf("����\t����\t����\t����\n");
	while(p)
	{
    printf("%d\t%d\t%d\t%s\n",
    p->id,p->age,p->wages,p->name);
	p=p->next;
	}
   return 0;
}

PTEA tea_llcheck(PTEA a)//����
{
   printf("������ҽ�ʦ����\n");
	int id;
	scanf("%d",&id);
           while(getchar()!='\n');
     PTEA p;
	 p=head;
	 while(p)
	 {
		 if(p->id==id){
 printf ("����\t����\tнˮ\t����\n " );
 printf ("%d\t%d\t%d\t%s\n",p->id,p->age,p->wages,p->name);
		break ;
                 	                }
	 p=p->next;
  }
	 if (p==NULL) {
		        printf ("δ�ҵ��ý�ʦ\n");
				printf ("�Ƿ��������y/n\n") ;
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
int tea_lladd(PTEA b )//������ʦ��Ϣ
{
#ifdef _DEBUG_	
	printf ("debug-001\n") ;
#endif
        PTEA p ;
		char ch ;
		p=malloc(sizeof(TEA));
		if(p==NULL){
			perror("����ռ䲻��\n");
			return -1;}
		printf ("�����������ʦ����Ϣ\n����\t����\tнˮ\t����\t����\n") ;
		scanf("%d%d%d%s",&p->id,&p->age,&p->wages,p->name,p->passwd) ;
                while(getchar()!='\n');
		if ( p == NULL )
			return -1 ;
		if ( head == NULL ) //˵������Ϊ�գ�����ɵ�һ��
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
int tea_lldelete( PTEA a   )  //ɾ����ʦ
{   int key ;
   printf ("������Ҫɾ������ʦ�Ĺ���\n") ;
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
			printf ("δ�ҵ��ý�ʦ") ;
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
int tea_llchange()//�޸���ʦ��Ϣ
{ 
    PTEA p;
    printf("\n���빤��");
        int key;
        scanf("%d",&key);
           while(getchar()!='\n');
         p=head;
         while(p)
         {
                 if(p->id==key){
         printf("����\t����\tнˮ\t����\n");
	scanf("%d%d%d%s%s",
		&p->id,&p->age,&p->wages,p->name,p->passwd);
           while(getchar()!='\n');
             break ;
}
                 p=p->next;}

                   p = head ;
	printf ("�޸�֮��Ϊ\n");
        printf("ѧ��\t����\t��ѧ\tӢ��\t����\t�༶\t����\t����\n");
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

PTEA tea_check_id() //У����ʦ�û���
{
	PTEA p;
	p = head;
	int id;
	char ch;
	printf("���������Ĺ���:");
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
	printf("�Ҳ������û�\n");
	printf("�Ƿ�����?[y/n]\n");
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
PTEA tea_check_passwd() //У����ʦ����
{
    PTEA p;
    p =tea_check_id();
    char passwd[20];
    char ch;
    printf("����������:");
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
	printf("���벻��ȷ\n");
	printf("�Ƿ���������[y/n]\n");
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
    printf("������������:");
    scanf("%s",new_passwd);
        while(getchar() != '\n');
    printf("���ٴ�����������:");
    scanf("%s",new);
        while(getchar() != '\n');
    if(strcmp(new_passwd,new)==0)
	{
        strcpy(p->passwd,new_passwd) ;
         printf("�����޸ĳɹ�!\n");


   //   tea_write() ;
    }
    else
    {
	printf("�����������\n");
	printf("�Ƿ�����[y/n]\n");
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
	printf("����\t����\tнˮ\t����\t����\n");
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
