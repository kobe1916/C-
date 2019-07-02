#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

nba* input()		//录入信息
{
	system("cls");            //跳转入函数后清屏

	nba* head;
	nba* tail;
	nba* p;
	head = (nba*)malloc(sizeof(nba));
	head->next = NULL;
	p = head;      //p为中间变量--串联链表
	int x = 0;
	int i = 0;

	printf("请输入要录入球员信息个数：>");
	scanf("%d", &i);
	do
	{
		tail = (nba *)malloc(sizeof(nba));
		//开辟空间需要大小    sizeof。。。
		printf("\t*****************请输入第%d个球员信息*******************\n", x + 1);
		printf("请输入球员姓名：>");
		scanf("%s", tail->name);
		printf("请输入球员所在球队名：>");
		scanf("%s", tail->team);
		printf("请输入球员球衣号码：>");
		//scanf("%d", p->num);   录入数字需要取值符
		scanf("%d", &tail->num);
		printf("请输入球员得分：>");
		scanf("%f", &tail->score);
		printf("请输入球员篮板：>");
		scanf("%f", &tail->block);
		printf("请输入球员助攻：>");
		scanf("%f", &tail->assist);
		p->next = tail;
		p = tail;
		tail->next = NULL;
		//p = tail;
		x++;
	} while (x < i);
	printf("恭喜你，录入信息成功！");
	return head;
}

nba* mod(nba *head)		//修改信息
{
	system("cls");
	nba* p = head;		//用p接收头结点，从头结点开始找起


	int choice;
	char id[20];           //存储要查找的球员姓名
	printf("\n\t请输入要修改的球员姓名：>\n");
	scanf("%s", &id);
	//while (strcmp(p->name, id));	//对比查找
	while (p&&strcmp(p->name, id) != 0)//要信息存在且相同才能修改    
		//strcmp   --相同返回0
	{
		//比较不相同则下移，比较下一个
		p = p->next;
	}
	if (p)
	{

		printf("\n\n                              --球员信息--                                            \n\n");
		printf("\t******************************************************************************************\n");
		printf("\t姓名------------号码-------------球队-----------得分------------篮板-------------助攻-----\n");
		printf("\t%-17s%-16d%-15s%-16.1f%-17.1f%-17.1f\n", p->name, p->num, p->team, p->score, p->block, p->assist);
		printf("\n\n");
		printf("\t\t******************修改选项*******************\n");
		printf("\t\t*                 1.球员姓名                *\n");
		printf("\t\t*                 2.球员号码                *\n");
		printf("\t\t*                 3.球员球队                *\n");
		printf("\t\t*                 4.球员得分                *\n");
		printf("\t\t*                 5.球员篮板                *\n");
		printf("\t\t*                 6.球员助攻                *\n");
		printf("\t\t*********************************************\n");
		printf("请输入你要修改的选项：>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n                   请输入修改后的姓名:");
			scanf("%s", p->name);
			break;
		case 2:printf("\n                   请输入修改后的号码:");
			scanf("%d", &p->num);
			break;
		case 3:
			printf("\n                   请输入修改后的队伍:");
			scanf("%s", p->team);
			break;
		case 4:
			printf("\n                   请输入修改后的得分:");
			scanf("%f", &p->score);
			break;
		case 5:
			printf("\n                   请输入修改后的篮板:");
			scanf("%f", &p->block);
			break;
		case 6:
			printf("\n                   请输入修改后的助攻:");
			scanf("%f", &p->assist);
			break;
		default:
			printf("\t输入错误，请重新输入！");
			break;
		}
		system("cls");
		printf("\n\n\t恭喜你，修改成功");
		Sleep(100);
		//展示修改后结果
		printf("\n\n                              --球员信息--                                            \n\n");
		printf("\t------------------------------------------------------------------------------------------\n");
		printf("\t姓名------------号码-------------球队-----------得分------------篮板-------------助攻-----\n");
		printf("\t%-17s%-16d%-15s%-16.1f%-17.1f%-17.1f\n", p->name, p->num, p->team, p->score, p->block, p->assist);
	}

	printf("\t修改成功，按任意键返回上一界面");
	getch();

	return head;
	//return  p;  p的节点位置已经改变不能应该返回头结点
}

nba* del(nba *head)		//删除信息
{

	char id[20];
	system("cls");
	nba* p = head;		//接收头结点
	nba* q;
	q = p->next;
	printf("请输入要删除球员的姓名：>\n");
	scanf("%s", &id);
	while (q)
	{
		//同修改，先找到然后改变指向关系
		if (strcmp(q->name, id) == 0)
		{
			//情况一：要删除的就是头结点的下一个
			p->next = q->next;
			free(q);
			//!!!
			q = p->next;
		}
		else
		{
			//情况二：要删除的不是头结点的下一个，两个节点依次后移
			p = p->next;
			q = q->next;

		}

	}
	printf("删除成功！\n");
	printf("按任意键返回操作界面：>\n");
	getch();

	return head;

}

nba* search(nba* head)		//查询球员信息
{
	system("cls");
	nba* p = head;
	char id[20];
	printf("请输入你要查找的球员姓名：>");
	scanf("%s", &id);
	//while (p)
	//{
	//	if (strcmp(p->name, id) == 0)
	//	{

	//	}
	//	
	//}
	//while (strcmp(p->name, id) != 0 && p)	//循环查找

	while (strcmp(p->name, id) != 0 && p)
	{
		p = p->next;
	}
	if (p)			//找到后展示
	{
		printf("\n\n                              --球员信息--                                            \n\n");
		printf("\t------------------------------------------------------------------------------------------\n");
		printf("\t姓名------------号码-------------球队-----------得分------------篮板-------------助攻-----\n");
		printf("\t%-17s%-16d%-15s%-16.1f%-17.1f%-17.1f\n", p->name, p->num, p->team, p->score, p->block, p->assist);
	}
	else
	{
		printf("\n\t未查询到该球员的信息，请检查是否输入正确。");
	}

	printf("\n\t按任意键返回！");
	getch();
	return head;


}

nba* show(nba* head)			//展示所有球员信息
{
	system("cls");
	nba* p;
	p = head->next;
	printf("\n\n                              --球员信息--                                            \n\n");
	printf("\t------------------------------------------------------------------------------------------\n");
	printf("\t姓名------------号码-------------球队-----------得分------------篮板-------------助攻-----\n");
	while (p)
	{
		printf("\t%-17s%-16d%-15s%-16.1f%-17.1f%-17.1f\n", p->name, p->num, p->team, p->score, p->block, p->assist);
		p = p->next;

	}
	printf("\n          按任意键返回！");
	getch();
	return head;
}


nba* score(nba* head)		//得分排序
{
	system("cls");
	nba *p;
	nba *q;
	nba *t;
	t = NULL;
	while (t != head->next)
	{
		p = head;		//接收头结点
		q = p->next;
		while (q->next != t)
		{
			//由大到小排列
			if (p->next->score < q->next->score)
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

	system("cls");

	p = head->next;
	printf("\n\n \t--得分榜排名--\n\n");
	printf("\t-------------------\n");
	printf("\t姓名-----------得分\n");
	while (p)
	{
		printf("\t%-17s%-16.1f\n", p->name, p->score);
		p = p->next;
	}
	printf("\n          按任意键返回！");
	getch();
	return head;
}

nba* block(nba *head)		//篮板排序
{
	system("cls");
	system("cls");
	nba *p;
	nba *q;
	nba *t;
	t = NULL;
	while (t != head->next)
	{
		p = head;		//接收头结点
		q = p->next;
		while (q->next != t)
		{
			//由小到大排列
			if (p->next->block > q->next->block)
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

	system("cls");

	p = head->next;
	printf("\n\n \t--篮板榜排名--\n\n");
	printf("\t-------------------\n");
	printf("\t姓名-----------得分\n");
	while (p)
	{
		printf("\t%-17s%-16.1f\n", p->name, p->block);
		p = p->next;
	}
	printf("\n          按任意键返回！");
	getch();
	return head;

}

nba* assist(nba *head)		//助攻排序
{
	system("cls");
	system("cls");
	nba *p;
	nba *q;
	nba *t;
	t = NULL;
	while (t != head->next)
	{
		p = head;		//接收头结点
		q = p->next;
		while (q->next != t)
		{
			if (p->next->assist < q->next->assist)
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

	system("cls");

	p = head->next;
	printf("\n\n \t--助攻榜排名--\n\n");
	printf("\t-------------------\n");
	printf("\t姓名-----------得分\n");
	while (p)
	{
		printf("\t%-17s%-16.1f\n", p->name, p->assist);
		p = p->next;
	}
	printf("\n          按任意键返回！");
	getch();
	return head;
}

nba* DisFil()		//展示已存球员信息
{
	system("cls");
	FILE *fp;
	nba *head;
	nba *q;
	nba *p;
	char filename[20];
	printf("\t请输入要打开的文件名：>");
	scanf("%s", &filename);
	if ((fp = fopen(filename, "rt")) == NULL)
	{
		printf("\t打开文件有错，按任意键退出！");
		getch();
		exit(1);
	}
	head = (nba *)malloc(sizeof(nba));
	head->next = NULL;
	q = head;
	while (!feof(fp))
	{
		p = (nba *)malloc(sizeof(nba));
		fscanf(fp, "%s %d %s %f %f %f\n", \
			p->name, &p->num, p->team, &p->score, &p->block, &p->assist);
		q->next = p;  //令p为第一节点
		q = p;
	}
	q->next = NULL;
	printf("\n\t文件已读出，按任意键显示！");
	fclose(fp);
	getch();

	p = head->next;    //p接收文件的头结点
	printf("\n\n                              --球员信息--                                            \n\n");
	printf("\t------------------------------------------------------------------------------------------\n");
	printf("\t姓名------------号码-------------球队-----------得分------------篮板-------------助攻-----\n");
	while (p)
	{
		printf("\t%-17s%-16d%-15s%-16.1f%-17.1f%-17.1f\n", p->name, p->num, p->team, p->score, p->block, p->assist);
		p = p->next;
	}
	printf("\n          按任意键返回！");
	getch();
	return head;

}


//文件操作
//1.建立或打开文件
//2.文件的读或写
//3.关闭文件
//
//打开文件  fopen --FILE *fopen（filename，char *mode）
//FILE *fp
//1.打开同目录下文件
//fp = fopen（“文件名”，“操作格式”）
//2.打开任一路径下文件
//fp = fopen（“文件路径”，“操作格式”）

//操作格式
//rt 只读
//wt 只写
//r 读
//w 写
//a 追加
//t 文本文件（可不写）
//b 二进制文件
//+ 读和写

//关闭文件
//fclose（FILE *fp）

//字符串读写
//fgets   fputs
//格式化读写
//fscanf  fprintf




nba* save(nba *head)		//保存文件
{
	system("cls");
	FILE *fp;   //定义文件指针
	nba *p;

	char filmname[40];
	printf("\t完成所有操作后便可存入文件中！\n");
	printf("\n\t输入要保存的文件名：  ");
	scanf("%s", filmname);
	if ((fp = fopen(filmname, "a+")) == NULL)
	{
		printf("\t写文件出错，按任意键退出！");
		getch();
		exit(1);
	}
	for (p = head->next; p != NULL; p = p->next)
	{
		//数据的写入
		fprintf(fp, "%s %d %s %.1f %.1f %.1f\n", p->name, p->num, p->team, p->score, p->block, p->assist);
	}
	fclose(fp);
	printf("\n\t文件已经保存成功！");
	getch();
	return head;
}

