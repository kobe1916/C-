#include<stdio.h>
#include<stdlib.h>
 

typedef int DataType;
 
typedef struct Node
{
	DataType data;
	struct Node * next;
}Node, *pNode;
 
pNode cur = NULL;//当前节点
pNode pre = NULL;//当前结点的前一个节点
pNode head = NULL;//头节点
 
pNode CreateNode( DataType n)//用单循环链表创建约瑟夫环
{
	int i = 0;
	for (i = 1; i <= n;i++)
	{
		pNode tmp = (pNode)malloc(sizeof(Node));
		if (NULL == tmp)
		{
			printf("out of memory !\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			cur = tmp;
			cur->data = i;
			cur->next = NULL;
		}
		if (head == NULL)
		{
			head = cur;
		}
		else
		{
			pre->next = cur;
		}
		pre = cur;	
	}
	cur ->next = head;//链表尾节点指向头节点形成环
	return head;
}
 
void JosephCircle(DataType num, DataType count)
{
	int i = 0;
	int j = 0;
	cur =CreateNode(num);
	while (cur->next != cur)//判断链表中是否只剩下一个人
	{
		for (i = 1; i <num ;i++)
		{
			for (j = 1;j < count ; j++)
			{
				pre = cur;
				cur = cur->next;
			}
			
			printf("第%d个出局的人是第%d 位\n", i, cur->data);
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
	}
	printf("最终活下来的人是第 %d 位\n", cur->data);
}
 
int main()
{
	int num;//约瑟夫环总人数
	int count;//出局的人所报的数
	printf("请输入约瑟夫环问题的总人数num-> ");
	scanf("%d", &num);
	printf("请输入约瑟夫环问题中第几个报数的人出局-> ");
	scanf("%d", &count);
	JosephCircle( num,  count);
	system("pause");
}
