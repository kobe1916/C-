#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"



void login()
{
	name log;
	FILE *fp1;
	int i;
	int flag=0;
	char ch[50],p[50];
	fp1 = fopen("name.txt", "rt");
	printf("\t请输入用户名：");
	getchar();
	gets(ch);
	printf("\t请输入密码：");
	for (i = 0;; i++)
	{
		//arr[i]--> *(arr+i)
		p[i] = getch();
		switch (p[i])
		{
		case '\b':
			p[--i] = '\0';
			i--;
			printf("\b \b");
			break;
		case '\r':
			p[i] = '\0';
			putchar('\n');
			break;
		default:
			putchar('*');
			break;
		}
		if (p[i] == '\0') 
			break;
	}
	while(fscanf(fp1,"%s %s",log.name,log.pwd)!=EOF)
	{	
		if( strcmp(ch,log.name)==0&&strcmp(p,log.pwd)==0 )
		{	
				flag=1;
				break;
        }
			else if(strcmp(ch,log.name)==0&&strcmp(p,log.pwd)!=0)
			{	
				flag=0;
				break;
			}
		else if(strcmp(ch,log.name)!=0)
		{
             flag=2;	
			continue;
		}
	}
		if(flag==1)
		{
			
			menu();
		}
		else if(flag ==0)
		{
			printf("\t密码出错！");
			getch();
			sys_menu();
		}
		else if(flag ==2)
		{
			printf("\t您输入用户名不存在！");
			getch();
			sys_menu();
		}
	
}

void sys_menu()
{
	int choice;
	system("cls");
	printf("\n\n");
	printf("\t\t|------------------------------|\n");
	printf("\t\t|--欢迎来到NBA球员管理系统^-^--|\n");
	printf("\t\t|---Basketball Never Stop!-----|\n");
	printf("\t\t|------------------------------|\n");
	printf("\t\t|------管理员登陆-请按1--------|\n");
	printf("\t\t|-------用户登陆-请按2---------|\n");
	printf("\t\t|---------退出-请按0-----------|\n");
	printf("\t\t|------------------------------|\n");
	printf("\t请输入您的选择: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 0:printf("\t\t您已成功退出！欢迎下次再来！\n"); exit(0);
	
	case 1:Admin(); break;
	case 2:login(); break;
	default:
		printf("\t\t您输入有误哟~请重新选择^o^ \n");
		getch();
		sys_menu();
	}

}


void Admin()
{
	char ad_name[20] = "admin";
	char ad_pwd[20] = "admin";
	int time = 0;
	int i;
	int flag = 0;
	char p[50];
	char ch[50];

	


	printf("\t请输入用户名：");
	getchar();
	gets(ch);
	printf("\t请输入密码：");
	for (i = 0;; i++)
	{
		p[i] = getch();
		switch (p[i])
		{
		case '\b':
			p[--i] = '\0';
			i--;
			printf("\b \b");
			break;
		case '\r':
			p[i] = '\0';
			putchar('\n');
			break;
		default:
			putchar('*');
			break;
		}
		if (p[i] == '\0') break;
	}
	while (time<3)
	{
		if (strcmp(ch, ad_name) == 0 && strcmp(p, ad_pwd) == 0)
		{
			//对的
			flag = 1;
			break;
		}
		else if (strcmp(ch, ad_name) == 0 && strcmp(p, ad_pwd) != 0)
		{
			//密码错误
			time++;
			flag = 0;
			break;
		}
		else if (strcmp(ch, ad_name) != 0)
		{
			//用户名不存在
			flag = 2;
			continue;
		}
	}
	if (flag == 1)
	{
		//对的
		printf("登陆成功进入管理员界面：>");
		guanli();
	}
	else if (flag == 0)
	{
		//错误
		printf("\t密码出错！");
		printf("你还有%d次机会",3 - time);
		getch();
		sys_menu();
	}
	else if (flag == 2)
	{
		printf("\t您输入用户名不存在！");
	}
}

void guanli()
{
	int choice;
	do {
		system("cls");
		printf("\n\n");

		printf("\t\t|------------------------------|\n");
		printf("\t\t|-----欢迎来到管理员系统^-^----|\n");
		printf("\t\t|----Basketball Never Stop!----|\n");
		printf("\t\t|------------------------------|\n");
		printf("\t\t|-------用户注册-请按1---------|\n");
		//printf("\t\t|-------用户删除-请按2---------|\n");
		printf("\t\t|---------退出-请按0-----------|\n");
		printf("\t\t|------------------------------|\n");
		printf("\t请输入您的选择: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:zhuce(); break;
		//case 2:shanchu(); break;
			/*case 0:sys_menu(); break;
			default:
				printf("\t\t您输入有误哟~请重新选择^o^ \n");
				getch();
				guanli();*/
		}
		if (choice == 0)
			sys_menu();
	} while (choice);

} 


//对注册名比较看有无重复
int pd(name signin)
{
	FILE *fp1;
	name member;
	int flag = 2;
	fp1 = fopen("name.txt", "rt");
	if (fp1 == NULL)
	{
		printf("\t输入无效，按任意键返回注册！\n");
		getch();
		exit(1);
	}
	while (fscanf(fp1, "%s", member.name) != EOF)
	{
		if (strcmp(signin.name, member.name) == 0)
		{
			flag = 0;
			break;
		}
		else if (strcmp(signin.name, member.name) != 0)
		{
			flag = 1;
			continue;
		}
	}
	if (flag == 0)
	{
		return 0;
	}
	else if (flag == 1)
	{
		return 1;
	}
	else if (flag == 2)
	{
		return 1;
	}
}


void zhuce()
{
	name signin;
	FILE  *fp1;
	fp1 = fopen("name.txt", "a+");
	if (fp1 == NULL)
	{
		printf("打开失败,按任意键退出！\n");
		exit(1);
	}
	printf("\t请输入用户名：");
	getchar();
	gets(signin.name);
	printf("\n");
	if (pd(signin) == 0)
	{
		printf("\t对不起，您注册的用户名重复，返回重新想一个名字吧");
		getch();
		guanli();
	}
	else if (pd(signin) == 1)
	{
		printf("\t请设置密码：");
		gets(signin.pwd);
		fputs(signin.name, fp1);
		fputs(" ", fp1);
		fputs(signin.pwd, fp1);
		fputs("\n", fp1);
		fclose(fp1);
		printf("\t*****注册成功，按任意键返回*****");
		getch();
		guanli();
	}
}
