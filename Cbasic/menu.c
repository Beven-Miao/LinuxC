#include"student.h"
#include"teacher.h"
#if 1
void admin_menu_1()
{
	char u[20]="";
	char u1[20]="admin";
	char p[20]="";
	char p1[20]="admin";
	while (1)
	{
	printf("����Ա�û���\n");
	scanf("%s",u);
              while(getchar()!= '\n');
	printf("����Ա����\n");
	scanf("%s",p);
              while(getchar()!= '\n');
	if (strcmp(u,u1)==0&&strcmp(p,p1)==0)
                      admin_menu_2()   ;
	else 
		printf ("�����û��������벻��ȷ���Ƿ�����y/n\n");
	    char ch ;
		ch=getchar() ;
                while(getchar()!= '\n');
		if ((ch=='y')||(ch=='Y'))
		      admin_menu_1() ;
		  else 
                      menu() ;
           
	}
}
#endif
#if 1
void admin_menu_2()  {
	while(1)
	{ system ("clear");
      printf("\n\n\n");                
      printf("\t\t\t\t******************************\n");
      printf("\t\t\t\t*          1.������ʦ        *\n");
      printf("\t\t\t\t*          2.����ѧ��        *\n");
      printf("\t\t\t\t*          0.����            *\n");
      printf("\t\t\t\t******************************\n");
      printf("\t\t\t\t����������ѡ��\n");
         char ch ;          
         ch=getchar();
         while(getchar()!= '\n');
	  switch(ch)
	  {
		  case '1':
                  admin_menu_2_1() ;
                          break ;
		  case '2':
                   admin_menu_2_2() ;
                           break ;
		  case '0':
		          menu();
		  default:
                         admin_menu_2() ;
                         break;
    }
	}

   }

#endif 
#if 1
void teacher_menu() 
{
 tea_check_passwd();


    char ch;
	while(1)
	{       
       printf("\n\n\n");                
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    1.����ѧ����Ϣ           *\n");
		printf("\t\t\t\t*    2.���ܳɼ�����          *\n");
		printf("\t\t\t\t*    3.�޸���ʦ����          *\n");
		printf("\t\t\t\t*    4.�鿴�ҵ���Ϣ          *\n");
		printf("\t\t\t\t*    5.���հ༶����ѧ��      *\n");
		printf("\t\t\t\t*    0.����                  *\n");
		printf("\t\t\t\t******************************\n");
         printf("\t\t\t\t����������ѡ��\n");                
		ch=getchar();
		while(getchar()!='\n');
		switch(ch)
		{
			case '1':
				//admin_tea_delete();break;
				   stu_llshow();
				   stu_llcheck();
				   break;
			case '2':
			          stu_sort() ;
					  break ;
			case '3':
			          printf ("�޸���ʦ����\n") ;
			           tea_change_passwd() ;
						break ;
			case '4':
						printf("�ҵ���Ϣ\n");
						tea_lookme() ;
						break;
		        case '5':
						printf("���հ༶����\n");
                                                stu_check_class();
						 break ;
			case '0':
				                 menu();
			default :
						printf("�ַ�����\n");
						break;
				}
			  }
                   }		
#endif	
#if 1	
void student_menu()
{
    stu_check_passwd();
	while(1)
	{           
        printf("\n\n\n");                
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    1.��ѯ�ҵ���Ϣ          *\n");
		printf("\t\t\t\t*    2.�޸�ѧ������          *\n");
		printf("\t\t\t\t*    0.����                  *\n");
		printf("\t\t\t\t******************************\n");
        printf("\t\t\t\t����������ѡ��\n");          
                 char ch;      
                ch=getchar();
		while(getchar()!='\n');
		switch(ch)
		{
			case '1':
				printf("��ѯ�ҵ���Ϣ\n");
                                   stu_lookme();
				break;
			case '2':
				printf("�޸�����\n");
				 stu_change_passwd();
				break;
			case '0':
				menu() ;//	break;//exit(0);
			default :
				printf("������\n");
				break;
		}
    }


}
#endif

#if 1
void menu()
{
  char ch;
   while(1)
   {   system ("clear");         
      printf("\n\n\n");                
	   printf("\t\t\t\t******************************\n");
	   printf("\t\t\t\t*    ��ӭ����ѧ������ϵͳ    *\n");
	   printf("\t\t\t\t******************************\n");
	   printf("\t\t\t\t*        1.����Ա��¼        *\n");
	   printf("\t\t\t\t*        2.��ʦ��¼          *\n");
	   printf("\t\t\t\t*        3.ѧ����¼          *\n");
	   printf("\t\t\t\t*        0.���沢�˳�        *\n");
	   printf("\t\t\t\t******************************\n");
       printf("\t\t\t\t����������ѡ��\n");   
                  
       ch=getchar(); 
       while(getchar()!= '\n');
	   switch(ch)
	   {
		   case '1':
			   admin_menu_1();break;
		   case '2':
			  teacher_menu(); break;
		   case '3':
                           student_menu();break;
		   case '0': 
                           tea_write() ;
			   stu_write() ;
			  exit(0) ; //break;//exit(0);
		   default :
               printf("���벻���ڵ��ַ�\n");
			   break;
	   }
   }
}
#endif 
#if 1
void admin_menu_2_1() {

while(1) 
			  {    
                printf("\n\n\n");                
                printf("\t\t\t\t******************************\n");
                printf("\t\t\t\t*         1.ɾ����ʦ         *\n");
                printf("\t\t\t\t*         2.�����ʦ         *\n");
                printf("\t\t\t\t*         3.������ʦ         *\n");
                printf("\t\t\t\t*         4.�޸���ʦ         *\n");
                printf("\t\t\t\t*         5.�鿴ȫ����ʦ     *\n");
                printf("\t\t\t\t*         0.����             *\n");
                printf("\t\t\t\t******************************\n");
                printf("\t\t\t\t����������ѡ��\n");                
				char ch ;
				ch=getchar();
                                while(getchar()!='\n');
				switch(ch)
				{
					case '1':
						//admin_tea_delete();break;
						printf("ɾ����ʦ\n");
						tea_llshow( ) ;
						tea_lldelete() ;
						break;
					case '2':
						printf("��ӽ�ʦ\n");
						tea_lladd( ) ;
						tea_llshow() ;
						break;
						//admin_tea_add();break;
					case '3':
						printf("���ҽ�ʦ\n");
						tea_llcheck( ) ;
						break;
			            //admin_tea_cheak();break;
					case '4':
						printf("�޸���ʦ\n");
                                                tea_llchange() ;
                                                break;
					case '5':
						printf("�鿴ȫ����ʦ\n");
                                                tea_llshow() ;
                                                break;
						//		
					case '0':
					     admin_menu_2() ;//	break;//exit(0);
					default :
						printf("�ַ�����\n");
						break;
				}
			  }


}
#endif
#if 1
void admin_menu_2_2() {
                while(1)
	 {     
                printf("\n\n\n");                
                printf("\t\t\t\t******************************\n");
                printf("\t\t\t\t*         1.ɾ��ѧ��         *\n");
                printf("\t\t\t\t*         2.���ѧ��         *\n");
                printf("\t\t\t\t*         3.����ѧ��         *\n");
                printf("\t\t\t\t*         4.�޸�ѧ��         *\n");
		printf("\t\t\t\t*         5.�鿴ȫ��ѧ��     *\n");
                printf("\t\t\t\t*         0.����             *\n");
                printf("\t\t\t\t******************************\n");
                printf("\t\t\t\t����������ѡ��\n");  
                                char ch ;              
				ch=getchar();
				while(getchar()!='\n'); 
				switch(ch)
				{
					case '1':
					    printf ("ɾ��ѧ��"); 
						stu_llshow();
						stu_lldelete();  
						stu_llshow();
						break ;
					case '2':
						printf("���ѧ��\n");
						stu_lladd(); 
						stu_llshow();
						break ;
					case '3':
						printf("����ѧ��\n");
						stu_llcheck();
						break;
					case '4':
						printf("�޸�ѧ��\n");
						stu_llchange();
						break;
					case '5':
						printf("�鿴ȫ��ѧ��\n");
                                                stu_llshow() ;
                                                break;
					case '0':
				                admin_menu_2() ;
					default :
						printf("��ѡ��\n");
						break;
				}
			  }
}
#endif
#if 1
int main()
{      
	stu_llopen(FILENAME1);
        tea_llopen(FILENAME);
#ifdef _DEBUG_
     	stu_llshow();
        tea_llshow();
#endif
        sleep(1);
        system ("clear");
	menu();

}
#endif
