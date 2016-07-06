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
	printf("管理员用户名\n");
	scanf("%s",u);
              while(getchar()!= '\n');
	printf("管理员密码\n");
	scanf("%s",p);
              while(getchar()!= '\n');
	if (strcmp(u,u1)==0&&strcmp(p,p1)==0)
                      admin_menu_2()   ;
	else 
		printf ("输入用户名或密码不正确，是否重试y/n\n");
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
      printf("\t\t\t\t*          1.管理老师        *\n");
      printf("\t\t\t\t*          2.管理学生        *\n");
      printf("\t\t\t\t*          0.返回            *\n");
      printf("\t\t\t\t******************************\n");
      printf("\t\t\t\t请输入数字选择\n");
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
		printf("\t\t\t\t*    1.查找学生信息           *\n");
		printf("\t\t\t\t*    2.按总成绩排名          *\n");
		printf("\t\t\t\t*    3.修改老师密码          *\n");
		printf("\t\t\t\t*    4.查看我的信息          *\n");
		printf("\t\t\t\t*    5.按照班级查找学生      *\n");
		printf("\t\t\t\t*    0.返回                  *\n");
		printf("\t\t\t\t******************************\n");
         printf("\t\t\t\t请输入数字选择\n");                
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
			          printf ("修改老师密码\n") ;
			           tea_change_passwd() ;
						break ;
			case '4':
						printf("我的信息\n");
						tea_lookme() ;
						break;
		        case '5':
						printf("按照班级查找\n");
                                                stu_check_class();
						 break ;
			case '0':
				                 menu();
			default :
						printf("字符不符\n");
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
		printf("\t\t\t\t*    1.查询我的信息          *\n");
		printf("\t\t\t\t*    2.修改学生密码          *\n");
		printf("\t\t\t\t*    0.返回                  *\n");
		printf("\t\t\t\t******************************\n");
        printf("\t\t\t\t请输入数字选择\n");          
                 char ch;      
                ch=getchar();
		while(getchar()!='\n');
		switch(ch)
		{
			case '1':
				printf("查询我的信息\n");
                                   stu_lookme();
				break;
			case '2':
				printf("修改密码\n");
				 stu_change_passwd();
				break;
			case '0':
				menu() ;//	break;//exit(0);
			default :
				printf("请输入\n");
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
	   printf("\t\t\t\t*    欢迎进入学生管理系统    *\n");
	   printf("\t\t\t\t******************************\n");
	   printf("\t\t\t\t*        1.管理员登录        *\n");
	   printf("\t\t\t\t*        2.老师登录          *\n");
	   printf("\t\t\t\t*        3.学生登录          *\n");
	   printf("\t\t\t\t*        0.保存并退出        *\n");
	   printf("\t\t\t\t******************************\n");
       printf("\t\t\t\t请输入数字选择\n");   
                  
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
               printf("输入不存在的字符\n");
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
                printf("\t\t\t\t*         1.删除老师         *\n");
                printf("\t\t\t\t*         2.添加老师         *\n");
                printf("\t\t\t\t*         3.查找老师         *\n");
                printf("\t\t\t\t*         4.修改老师         *\n");
                printf("\t\t\t\t*         5.查看全部老师     *\n");
                printf("\t\t\t\t*         0.返回             *\n");
                printf("\t\t\t\t******************************\n");
                printf("\t\t\t\t请输入数字选择\n");                
				char ch ;
				ch=getchar();
                                while(getchar()!='\n');
				switch(ch)
				{
					case '1':
						//admin_tea_delete();break;
						printf("删除教师\n");
						tea_llshow( ) ;
						tea_lldelete() ;
						break;
					case '2':
						printf("添加教师\n");
						tea_lladd( ) ;
						tea_llshow() ;
						break;
						//admin_tea_add();break;
					case '3':
						printf("查找教师\n");
						tea_llcheck( ) ;
						break;
			            //admin_tea_cheak();break;
					case '4':
						printf("修改老师\n");
                                                tea_llchange() ;
                                                break;
					case '5':
						printf("查看全部老师\n");
                                                tea_llshow() ;
                                                break;
						//		
					case '0':
					     admin_menu_2() ;//	break;//exit(0);
					default :
						printf("字符不符\n");
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
                printf("\t\t\t\t*         1.删除学生         *\n");
                printf("\t\t\t\t*         2.添加学生         *\n");
                printf("\t\t\t\t*         3.查找学生         *\n");
                printf("\t\t\t\t*         4.修改学生         *\n");
		printf("\t\t\t\t*         5.查看全部学生     *\n");
                printf("\t\t\t\t*         0.返回             *\n");
                printf("\t\t\t\t******************************\n");
                printf("\t\t\t\t请输入数字选择\n");  
                                char ch ;              
				ch=getchar();
				while(getchar()!='\n'); 
				switch(ch)
				{
					case '1':
					    printf ("删除学生"); 
						stu_llshow();
						stu_lldelete();  
						stu_llshow();
						break ;
					case '2':
						printf("添加学生\n");
						stu_lladd(); 
						stu_llshow();
						break ;
					case '3':
						printf("查找学生\n");
						stu_llcheck();
						break;
					case '4':
						printf("修改学生\n");
						stu_llchange();
						break;
					case '5':
						printf("查看全部学生\n");
                                                stu_llshow() ;
                                                break;
					case '0':
				                admin_menu_2() ;
					default :
						printf("请选择\n");
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
