#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<conio.h>
#include<windows.h> 
#define N "\t\t\t\t\t-----------------------------"
#define S "\t\t\t\t\t"
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void login1();
void login2();
void sign();
char ch[50]; 
typedef struct nba
{
	char name[20];//球员姓名
	char num[10];//球衣号码
	char team[20];//所在球队
	float score;//场均得分
	float rebound;//场均篮板
	float assist;//场均助攻 
	float block;//场均盖帽
	float steal;//场均抢断
	char position[20];//球场位置 
	struct nba *next; 
}nba;
typedef struct Name
{
	char id[50];
	char pwd[50];	
	struct Name *next;
}Name;
typedef struct PWD
{
	char pass[20];
}Pwd;

nba *savei(nba *head)
{
	FILE *fp;
	nba *p;
	fp=fopen("information.txt","w+");
    for(p=head->next;p!=NULL;p=p->next)
    {
	 	fprintf(fp,"\n%s %s %s %.1f %.1f %.1f %.1f %.1f %s",p->name,p->num,p->team,p->score,p->rebound,p->assist,p->block,p->steal,p->position);
    }
    fclose(fp);
}

Name *save(Name *head)
{
	FILE *fp;
	Name *m;
	fp=fopen("name.txt","w+");
	for(m=head->next;m!=NULL;m=m->next)
	{
		fprintf(fp,"%s %s\n",m->id,m->pwd);
	}
	fclose(fp);
}

int pd(Name signin)
{
	FILE *fp1;
	Name member;
	int flag = 2;
	fp1 = fopen("name.txt", "rt");
	if (fp1 == NULL)
	{
		printf("\t输入无效，按任意键返回注册！\n");
		getch();
		exit(1);
	}
	while (fscanf(fp1, "%s", member.id) != EOF)
	{
		if (strcmp(signin.id, member.id) == 0)
		{
			flag = 0;
			break;
		}
		else if (strcmp(signin.id, member.id) != 0)
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
void sign()
{
	Name signin;
	FILE *fp1;
	fp1=fopen("name.txt","a+");
	if(fp1==NULL)
	{
		printf("打开失败，按任意键退出\n");
		getch();
		exit(1);
	}
	printf("%s请输入用户名：",S);
	getchar();
	gets(signin.id);
	printf("\n");
	if(pd(signin)==0)
	{
		printf("%s对不起，用户名重复，按任意键返回",S);
		getch();
		menu1();
	}
	else if(pd(signin)==1)
	{
		printf("%s请设置密码",S);
		gets(signin.pwd);
		fputs(signin.id,fp1);
		fputs(" ",fp1);
		fputs(signin.pwd,fp1);
		fputs("\n",fp1);
		fclose(fp1);
		printf("%s注册成功，按任意键返回",S);
		getch();
		menu1();
	}
}
void login1()
{
	Name log;
	FILE *fp1;
	int i;
	int flag=0;
	char p[50];
	fp1=fopen("name.txt","rt");
	printf("%s输入用户名:",S);
	getchar();
	gets(ch);
	printf("%s输入密码:",S);
	for(i=0;;i++)
	{
		p[i]=getch();
		switch(p[i])
		{
			case '\b':
				p[--i]='\0';
				i--;
				printf("\b \b");
				break;
			case '\r':
				p[i]='\0';
				putchar('\n');
				break;
			default:
				putchar('*');
				break;
		}
		if(p[i]=='\0') break;
	}
	while(fscanf(fp1,"%s %s",log.id,log.pwd)!=EOF)
	{
		if(strcmp(ch,log.id)==0&&strcmp(p,log.pwd)==0)
		{
			flag=1;
			break;
		}
		else if(strcmp(ch,log.id)==0&&strcmp(p,log.pwd)!=0)
		{
			flag=0;
			break;
		}
		else if(strcmp(ch,log.id)!=0)
		{
			flag=2;
			continue;
		}
	}
	if(flag==1)
	{
		printf("%s登陆成功",S);
		getch();
		menu2();
	}
	else if(flag==0)
	{
		printf("%s密码出错！\n",S);
		printf("%s按任意键返回",S);
		getch();
		menu1();
	}
	else if(flag==2)
	{
		printf("%s您输入的用户名不存在！\n",S);
		printf("%s按任意键返回",S);
		getch();
		menu1(); 
	 } 
 } 
void login2()
{
	Pwd mima;
	FILE *fp2;
	int i;
	char p[20];
	fp2=fopen("pwd.txt","rt");	
	printf("%s输入管理员密码：",S);
	for(i=0;;i++)
	{
		p[i]=getch();
		switch(p[i])
		{
			case '\b':
				p[--i]='\0';
				i--;
				printf("\b \b");
				break;
			case '\r':
				p[i]='\0';
				putchar('\n');
				break;
			default:
				putchar('*');
				break;
		}
		if(p[i]=='\0') break;
	}
	while(fread(mima.pass,sizeof(Pwd),1,fp2)!=EOF)
	{
		if(strcmp(p,mima.pass)==0)
		{
			menu3();
	    }
	    else if(strcmp(p,mima.pass)!=0)
	    {
		    printf("%s密码错误\n%s按任意键返回上一级",S,S);
		    getch();
		    menu1();
	    }
	}
}
void xiugai()
{
	Name *head,*m,*q,*v;
	FILE *fp;
	int i;
	char p[50]={'\0'};
	fp=fopen("name.txt","rt"); 
	head=(Name*)malloc(sizeof(Name));
	q=head;
	q->next=NULL;
	while (!feof(fp)) 
	{
		m= (Name*)malloc(sizeof(Name));
	    fscanf(fp,"%s %s",m->id,m->pwd);
		if(feof(fp))
			break;
		m->next=NULL;
	    q->next=m;
	    q=m;
	}
	v=head->next;
	while(strcmp(ch,v->id)!=0)
	{
		v=v->next;
	}
	if(v)
	{
		printf("%s输入原密码:",S);
		for(i=0;;i++)
	    {
	    	p[i]=getch();
	    	switch(p[i])
	    	{
		    	case '\b':
			    	p[--i]='\0';
			    	i--;
			    	printf("\b \b");
				    break;
		    	case '\r':
			    	p[i]='\0';
			    	putchar('\n');
			    	break;
		    	default:
			    	putchar('*');
			    	break;
	    	}
		    if(p[i]=='\0') break;
	    }
	    if(strcmp(p,v->pwd)==0)
	    {
	    	printf("%s输入新密码:",S);
			scanf("%s",v->pwd);
			printf("\n%s修改成功",S);
			save(head);
			printf("\n%s按任意键返回上一级",S);
			getch();
			menu1();		
		}
		else
		{
			printf("%s密码错误！\n",S);
			printf("%s按任意键返回上一级",S);
			getch();
			menu2();			
		}
	    
	}
		
	fclose(fp);    	
}

	
void menu1()
{
	system("cls");
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t|\t1.用户登录\t    |\n");
	printf("\t\t\t\t\t|\t2.用户注册\t    |\n");
	printf("\t\t\t\t\t|\t3.管理员登陆\t    |\n");
	printf("\t\t\t\t\t|\t4.退出管理系统\t    |\n");
	puts(N);
	printf("%s输入选择的功能：\n",S);
	int n;
	printf("%s",S);
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			login1();
			break;
		case 2:
			sign();
			break; 
		case 3:
		    login2();
		    break;
		case 4:
			exit(1);
			break;
		default:
            printf("%s您输入有错误，请重新选择\n",S);     	
	    	menu1();	

	}
}
void input()
{
	FILE *fp;
	nba *p;
	nba *q,*s;
	int x,i=0;
	system("cls");
	fp=fopen("information.txt","a");
	p=(nba*)malloc(sizeof(nba));
	p->next=NULL;
	q=p;
	printf("%s输入球员数量：",S);
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		s=(nba*)malloc(sizeof(nba));
		printf("%s输入球员信息：\n",S);
		printf("%s第%d个球员信息：\n",S,i+1);
		printf("%s球员姓名：",S);
		scanf("%s",s->name);
		printf("%s号码：",S);
		scanf("%s",s->num);
		printf("%s所在球队：",S);
		scanf("%s",s->team);
		printf("%s生涯场均得分：",S);
		scanf("%f",&s->score);
		printf("%s生涯场均篮板：",S);
		scanf("%f",&s->rebound);
		printf("%s生涯场均助攻：",S);
		scanf("%f",&s->assist);
		printf("%s生涯场均盖帽：",S);
		scanf("%f",&s->block);
		printf("%s生涯场均抢断：",S);
		scanf("%f",&s->steal);
		printf("%s球场位置：",S);
		scanf("%s",s->position);
		q->next=s;
		q=s;
		s->next=NULL;
	}
	printf("\n%s录入完毕。",S);
	getch();
	//return p;
	p=p->next;
	while(p)
	{
		fprintf(fp,"\n%s %s %s %f %f %f %f %f %s",p->name,p->num,p->team,p->score,p->rebound,p->assist,p->block,p->steal,p->position);
		p=p->next;
	}
	fclose(fp); 
	 
}
nba *print1(nba *head)
{
	nba *p = head->next;
	system("cls");
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t|\t  球员信息\t    |\n");
	printf("%s\n",S);
	printf("\t\t\t姓名     号码     球队     得分     篮板     助攻     盖帽     抢断      位置\n");
	while (p)
	{
		printf("\t\t\t%s      %s      %s     %.1f     %.1f      %.1f      %.1f      %.1f       %s\n", p->name, p->num, p->team, p->score, p->rebound, p->assist,p->block,p->steal,p->position);
		p = p->next;
	}
	menu5();

	
	
}
nba *print2(nba *head)
{
	system("cls");
	nba *p = head->next;
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t\t--得分榜排名--\n\n");
	printf("\t\t\t\t\t   -----------------------\n");
	printf("\t\t\t\t\t    姓名-------------得分\n");
	while (p)
	{
		printf("\t\t\t\t\t    %-17s%-16.1f\n", p->name, p->score);
		p = p->next;
	}
	printf("\n\t\t\t\t\t    按任意键返回！");
	getch();
	menu2();
	
}
nba *print3(nba *head)
{
	system("cls");
	nba *p = head->next;
    printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t\t--篮板榜排名--\n\n");
	printf("\t\t\t\t\t   -----------------------\n");
	printf("\t\t\t\t\t    姓名-------------篮板\n");
	while (p)
	{
		printf("\t\t\t\t\t    %-17s%-16.1f\n", p->name, p->rebound);
		p = p->next;
	}
	printf("\n\t\t\t\t\t    按任意键返回！");
	getch();
	menu2();

}
nba *print4(nba *head)
{
	system("cls");
	nba *p = head->next;
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t\t--助攻榜排名--\n\n");
	printf("\t\t\t\t\t   -----------------------\n");
	printf("\t\t\t\t\t    姓名-------------助攻\n");
	while (p)
	{
		printf("\t\t\t\t\t    %-17s%-16.1f\n", p->name, p->assist);
		p = p->next;
	}
	printf("\n\t\t\t\t\t    按任意键返回！");
	getch();
	menu2();
}
nba *print5(nba *head)
{
	system("cls");
	nba *p = head->next;
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t\t--盖帽榜排名--\n\n");
	printf("\t\t\t\t\t   -----------------------\n");
	printf("\t\t\t\t\t    姓名-------------盖帽\n");
	while (p)
	{
		printf("\t\t\t\t\t    %-17s%-16.1f\n", p->name, p->block);
		p = p->next;
	}
	printf("\n\t\t\t\t\t    按任意键返回！");
	getch();
	menu2();
} 
nba *print6(nba *head)
{
	system("cls");
	nba *p = head->next;
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t\t--抢断榜排名--\n\n");
	printf("\t\t\t\t\t   -----------------------\n");
	printf("\t\t\t\t\t    姓名-------------抢断\n");
	while (p)
	{
		printf("\t\t\t\t\t    %-17s%-16.1f\n", p->name, p->steal);
		p = p->next;
	}
	printf("\n\t\t\t\t\t    按任意键返回！");
	getch();
	menu2();
}
nba *del(nba *head)
{
	nba *q;
	nba *p = head;
	q = head->next;
	char id[20];
	printf("\n%s请输入要删除的球员姓名：",S);
	scanf("%s", &id);
	while (q)
	{
		if (strcmp(q->name, id) == 0)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	printf("\n%s删除完成!!",S);
	savei(head);
	getch();
	menu3();

}
nba *search1(nba *head)
{
	system("cls");
	nba *p;
	p = head;
	char id[20];
	printf("\t\t\t\t\t**    *    ******       *\n");
    printf("\t\t\t\t\t* *   *    *     *     * *\n");
  	printf("\t\t\t\t\t*  *  *    ******     *****\n");
   	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
   	printf("\t\t\t\t\t*    **    ******   *       *\n");
   	puts(N);
	printf("%s请输入要查询的球星名字: ",S);
	scanf("%s", &id);
	while (strcmp(p->name, id) && p!=0)
	{
		p = p->next;
		if(p==NULL)
		{
			printf("\n%s未查询到该球员的信息，请检查是否输入正确。",S);
			printf("\n\n%s按任意键返回！",S);
        	getch();
        	search1(head);
			
		}
	}
	if (p)
	{
    	printf("\t\t\t\t\t|\t  球员信息\t    |\n");
    	printf("%s\n",S);
    	printf("\t\t\t姓名     号码     球队     得分     篮板     助攻     盖帽     抢断      位置\n");
		printf("\t\t\t%s      %s      %s     %.1f     %.1f      %.1f      %.1f      %.1f       %s\n", p->name, p->num, p->team, p->score, p->rebound, p->assist,p->block,p->steal,p->position);
	} 	
	printf("\n%s按任意键返回！",S);
	getch();
	menu4();
}
nba *search2(nba *head)
{
	system("cls");
	nba *p;
	p = head;
	char id[20];
	printf("\t\t\t\t\t**    *    ******       *\n");
    printf("\t\t\t\t\t* *   *    *     *     * *\n");
    printf("\t\t\t\t\t*  *  *    ******     *****\n");
    printf("\t\t\t\t\t*   * *    *     *   *     *\n");
    printf("\t\t\t\t\t*    **    ******   *       *\n");
    puts(N);
    printf("%s请输入要查询的球队: ",S);
	scanf("%s", &id);
	printf("\t\t\t\t\t|\t  球员信息\t    |\n");
	printf("\t\t\t姓名     号码     球队     得分     篮板     助攻     盖帽     抢断      位置\n");
	for(p=head->next;p!=NULL;p=p->next)
	{
		if(strcmp(p->team,id)==0)
		{
			
    	    printf("%s\n",S);
    	    
		    printf("\t\t\t%s      %s      %s     %.1f     %.1f      %.1f      %.1f      %.1f       %s\n", p->name, p->num, p->team, p->score, p->rebound, p->assist,p->block,p->steal,p->position); 
		}
		
		
	}
	printf("\n%s按任意键返回！",S);
	getch();
	menu4();
}
nba *search3(nba *head)
{
	system("cls");
	nba *p;
	p = head;
	char id[20];
	printf("\t\t\t\t\t**    *    ******       *\n");
    printf("\t\t\t\t\t* *   *    *     *     * *\n");
    printf("\t\t\t\t\t*  *  *    ******     *****\n");
    printf("\t\t\t\t\t*   * *    *     *   *     *\n");
    printf("\t\t\t\t\t*    **    ******   *       *\n");
    puts(N);
    printf("%s请输入要查询的位置: ",S);
	scanf("%s", &id);
	printf("\t\t\t\t\t|\t  球员信息\t    |\n");
	printf("\t\t\t姓名     号码     球队     得分     篮板     助攻     盖帽     抢断      位置\n");
	for(p=head->next;p!=NULL;p=p->next)
	{
		if(strcmp(p->position,id)==0)
		{
			
    	    printf("%s\n",S);
    	    
		    printf("\t\t\t%s      %s      %s     %.1f     %.1f      %.1f      %.1f      %.1f       %s\n", p->name, p->num, p->team, p->score, p->rebound, p->assist,p->block,p->steal,p->position); 
		}
		
		
	}
	
	printf("\n%s按任意键返回！",S);
	getch();
	menu4();
}
nba *rank1(nba *head)
{
	nba *p, *q, *t;
	t = NULL;
	FILE *fp;
	while (t != head->next)
	{
		p = head;
		q = p->next;
		while (q->next != t)
		{
			if (p->next->score<q->next->score)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
		t = q;
	}
//	print2(head);
//	return head;

}
nba *rank2(nba *head)
{
	nba *p, *q, *t;
	t = NULL;
	while (t != head->next)
	{
		p = head;
		q = p->next;
		while (q->next != t)
		{
			if (p->next->rebound<q->next->rebound)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
		t = q;
	}
//	print3(head);
//	return head;
}
nba *rank3(nba *head)
{
	nba *p, *q, *t;
	t = NULL;
	while (t != head->next)
	{
		p = head;
		q = p->next;
		while (q->next != t)
		{
			if (p->next->assist<q->next->assist)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
		t = q;
	}
//	print4(head);
//	return head;
}
nba *rank4(nba *head)
{
	nba *p, *q, *t;
	t = NULL;
	while (t != head->next)
	{
		p = head;
		q = p->next;
		while (q->next != t)
		{
			if (p->next->block<q->next->block)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
		t = q;
	}
//	print5(head);
//	return head;
}
nba *rank5(nba *head)
{
	nba *p, *q, *t;
	t = NULL;
	while (t != head->next)
	{
		p = head;
		q = p->next;
		while (q->next != t)
		{
			if (p->next->steal<q->next->steal)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
		t = q;
	}
//	print6(head);
//	return head;
}
void change(nba *head)
{
	system("cls");
	nba *p = head;
	int choice;
	char id[20];
	printf("\n%s请输入要修改的球员姓名：",S);
	scanf("%s", &id);
	while (p&&strcmp(p->name, id) != 0)
	{
		p = p->next;
	}
	if (p)
	{
		printf("\t\t\t\t\t**    *    ******       *\n");
    	printf("\t\t\t\t\t* *   *    *     *     * *\n");
    	printf("\t\t\t\t\t*  *  *    ******     *****\n");
    	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
    	printf("\t\t\t\t\t*    **    ******   *       *\n");
    	puts(N);
    	printf("\t\t\t\t\t|\t  球员信息\t    |\n");
    	printf("%s\n",S);
    	printf("\t\t\t姓名     号码     球队     得分     篮板     助攻     盖帽     抢断     位置\n");
		printf("\t\t\t%s      %s      %s     %.1f     %.1f      %.1f      %.1f      %.1f       %s\n", p->name, p->num, p->team, p->score, p->rebound, p->assist,p->block,p->steal,p->position);
		printf("\n\n");
		printf("\t\t\t\t\t ┏━━━━━━━━请选择修改的选项━━━━━━━━┓\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄  1.球员名称 ┄┄┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄  2.球员号码 ┄┄┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄  3.球员位置 ┄┄┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄4.球员所在球队 ┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄5.球员场均得分 ┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄6.球员场均篮板 ┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄7.球员场均助攻 ┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄8.球员场均盖帽 ┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┃┄┄┄┄┄┄┄┄┄9.球员场均抢断 ┄┄┄┄┄┄┄┄┃\n");
		printf("\t\t\t\t\t ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n%s请选则您要进行的修改项：",S);
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:printf("\n%s请输入修改后的姓名:",S);
			scanf("%s", p->name); break;
		case 2:printf("\n%s请输入修改后的号码:",S);
			scanf("%s", p->num); break;
		case 3:printf("\n%s请输入修改后的位置:",S);
		    scanf("%s",p->position);break; 
		case 4:printf("\n%s请输入修改后的队伍:",S);
			scanf("%s", p->team); break;
		case 5:printf("\n%s请输入修改后的得分:",S);
			scanf("%f", &p->score); break;
		case 6:printf("\n%s请输入修改后的篮板:",S);
			scanf("%f", &p->rebound); break;
		case 7:printf("\n%s请输入修改后的助攻:",S);
			scanf("%f", &p->assist); break;
	    case 8:printf("\n%s请输入修改后的盖帽:",S);
			scanf("%f", &p->block); break;
		case 9:printf("\n%s请输入修改后的抢断:",S);
			scanf("%f", &p->steal); break;
		}
		printf("\n\n%s恭喜你，修改成功\n",S);
    	puts(N);
    	printf("\t\t\t\t\t|\t  球员信息\t    |\n");
    	printf("%s\n",S);
    	printf("\t\t\t姓名     号码     球队     得分     篮板     助攻     盖帽     抢断      位置\n");
		printf("\t\t\t%s      %s      %s     %.1f     %.1f      %.1f      %.1f      %.1f       %s\n", p->name, p->num, p->team, p->score, p->rebound, p->assist,p->block,p->steal,p->position );
	}
	printf("\n%s按任意键返回！",S);
	savei(head);
	getch();
	menu3();
}
nba *readi()
{
	nba  *head,*q, *p;
	FILE *fp;
	if ((fp = fopen("information.txt", "r+")) == NULL)
	{
		printf("\t打开文件有错，按任意键返回上一级！");
		getch();
		menu2();
	}
	head = (nba *)malloc(sizeof(nba));
	head->next = NULL;
	q = head;
	while (!feof(fp)) 
	{	p = (nba *)malloc(sizeof(nba));
		fscanf(fp, "%s %s %s %f %f %f %f %f %s", p->name, p->num, p->team, &p->score, &p->rebound, &p->assist,&p->block,&p->steal,p->position);
	//	if(feof(fp))
		//	break;
		q->next = p;
		q = p;
	}
	q->next = NULL;
	fclose(fp);
	return head;
}
void read()
{
	int i=0;
	FILE *fp1;
	Name xianshi[10];
	fp1=fopen("name.txt","rt");
	
	printf("%s用户名      密码\n",S);
	while(!feof(fp1))
	{
	
		fscanf(fp1,"%s %s",xianshi[i].id,xianshi[i].pwd);
		if(feof(fp1))
		{
			break;
		}
        printf("%s%s        %s\n",S,xianshi[i].id,xianshi[i].pwd);
   		i++;
    	
	}
	
	printf("%s按任意键返回上一级",S);
	getch();
	menu3(); 
}
void menu2()
{
	nba *head = NULL;
	system("cls");
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t|\t1.查询信息\t    |\n");
	printf("\t\t\t\t\t|\t2.得分排行榜\t    |\n");
	printf("\t\t\t\t\t|\t3.篮板排行榜\t    |\n");
	printf("\t\t\t\t\t|\t4.助攻排行榜\t    |\n");
	printf("\t\t\t\t\t|\t5.盖帽排行榜\t    |\n");
	printf("\t\t\t\t\t|\t6.抢断排行榜\t    |\n");
	printf("\t\t\t\t\t|\t7.修改密码\t    |\n");
	printf("\t\t\t\t\t|\t8.返回上一级\t    |\n");
	puts(N);
	printf("%s输入选择的功能：\n",S);
	int n;
	printf("%s",S);
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			menu4();
			break;
		case 2:
			head=readi();
			rank1(head);
			print2(head);
			break;
		case 3:
			head=readi();
			rank2(head);
			print3(head);
			break;
		case 4:
			head=readi();
			rank3(head);
			print4(head);
			break;
		case 5:
			head=readi();
		    rank4(head);
		    print5(head);
			break;
		case 6:
			head=readi();
			rank5(head);
			print6(head);
			break;
		case 7:
		     xiugai();
		case 8:
		    menu1();
			break; 
	}
}
void menu3()
{
	nba *head=NULL;
	system("cls");
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t|\t1.录入数据\t    |\n");
	printf("\t\t\t\t\t|\t2.修改数据\t    |\n");
	printf("\t\t\t\t\t|\t3.删除数据\t    |\n");
	printf("\t\t\t\t\t|\t4.查看数据\t    |\n");
	printf("\t\t\t\t\t|\t5.查看用户\t    |\n");
	printf("\t\t\t\t\t|\t6.返回上一级\t    |\n");
	puts(N);
	printf("%s输入选择的功能：\n",S);
	int n;
	printf("%s",S);
	scanf("%d",&n);
	switch(n)	 
	{
		case 1:
			input();
			break;
		case 2:
			head=readi();
			change(head);
			break;
		case 3:
			head=readi();
			del(head);
			break;
		case 4:
			head=readi();
			print1(head);
			menu3();
		case 5:
			read();
		case 6:
			menu1();
	}
}
void menu4()
{
	nba *head=NULL;
	system("cls");
	printf("\t\t\t\t\t**    *    ******       *\n");
	printf("\t\t\t\t\t* *   *    *     *     * *\n");
	printf("\t\t\t\t\t*  *  *    ******     *****\n");
	printf("\t\t\t\t\t*   * *    *     *   *     *\n");
	printf("\t\t\t\t\t*    **    ******   *       *\n");
	puts(N);
	printf("\t\t\t\t\t|\t1.球员信息\t    |\n");
	printf("\t\t\t\t\t|\t2.球队信息\t    |\n");
	printf("\t\t\t\t\t|\t3.位置信息\t    |\n");
	printf("\t\t\t\t\t|\t4.返回上一级\t    |\n");
	puts(N);
	printf("%s输入选择的功能：\n",S);
	int n;
	printf("%s",S);
	scanf("%d",&n);
	switch(n)	 
	{
		case 1:
		    head=readi();
		    search1(head);
		case 2:
		    head=readi();
			search2(head);
		case 3:
			head=readi();
			search3(head);
		case 4:
			menu2();
    }			 
}
void menu5()
{
	nba *head=NULL;
	puts(N);
	printf("\t\t\t\t\t1.根据得分大小显示数据\t    \n");
	printf("\t\t\t\t\t2.根据篮板大小显示数据\t    \n");
	printf("\t\t\t\t\t3.根据助攻大小显示数据\t    \n");
	printf("\t\t\t\t\t4.根据盖帽大小显示数据\t    \n");
	printf("\t\t\t\t\t5.根据抢断大小显示数据\t    \n");
	printf("\t\t\t\t\t6.返回上一级\t            \n");
	puts(N);
	printf("%s输入选择的功能：\n",S);
	int n;
	printf("%s",S);
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			head=readi();
			rank1(head);
			print1(head);
		case 2:
			head=readi();
			rank2(head);
			print1(head);
		case 3:
			head=readi();
			rank3(head);
			print1(head);
		case 4:
			head=readi();
			rank4(head);
			print1(head);
		case 5:
			head=readi();
			rank5(head);
			print1(head);
		case 6:
			menu3();
			
    	 }	 	
}
main()
{
	nba *head=NULL;
    system("color F0");
	menu1();
}
