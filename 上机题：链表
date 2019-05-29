
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}LNode, *LinkList;
LinkList list = NULL;
int n; //人数
int m; //报数号
//n为总人数，k为第一个开始报数的人，m为出列者喊到的数
void JosephRing(int n, int k, int m)
{
	int i;
	LinkList p ; /* p为当前结点,r为辅助结点，指向p的前驱结点*/
	
	for (int i = 1; i <= n; i++) /*建立循环链表*/
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		if (list == NULL) list = p;
		else r->next = p;
		r = p;
	}
	p->next = list; /*使链表循环起来*/
	p = list; /*使p指向头节点*/
	/*把当前指针移动到第一个报数的人*/
	for (i = 1; i < k; i++)
	{
		r = p;
		p = p->next;
	}
	printf("%d", p->data);
	/*循环地删除队列结点*/
	while (p->next != p)
	{
		for (i = 1; i < m; i++)
		{
			r = p;
			p = p->next;
		}
		r->next = p->next;
		printf("%4d ", p->data);
		free(p);
		p = r->next;
	}
	printf("%4d", p->data);
}
void main()
{
	printf("input m=");
	scanf("%d", &m);
	scanf("%d", &n);
	JosephRing(n, 1, m);
	system("pause");
	
}
