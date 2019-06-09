#include <stdio.h>
#include <stdlib.h>

//创建结构体并声明
typedef struct student
{
	int num;
	struct student *next;
}stu;

//排序    
int * sort(int *nums[5], int n)
{
	int i, j, t;
	for (i = 0; i < n - 1; i++)
	{
		//for(j= 0;j<n-i-1;j++);
		/*两个循环的次数是一样多的，都是n-(j+1)次，
		但在循环过程中i的值不一样
		前者是0,1,2 …… n-(j+1)-1
		后者是j+1,j+2,j+3……n-1*/
		for (j = i + 1; j < n; j++)
		{
			//二级指针
			if (**(nums + i) > **(nums + j))
			{
				t = **(nums + j);
				**(nums + j) = **(nums + i);
				**(nums + i) = t;
			}
		}
	}
	return *nums;
}

void main()
{
	int i;
	//定义指针数组
	int * nums[5];
	stu h, *p, *q;
	scanf("%d", &h.num);
	nums[0] = &h.num;
	p = &h;
	h.next = NULL;
	for (i = 1; i < 5; i++)
	{
		q = (stu*)malloc(sizeof(q));
		scanf("%d", &q->num);
		nums[i] = &q->num;
		p->next = q;
		p = q;
	}
	sort(nums, 5);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", **(nums + i));
	}
	printf("\n");
	system("pause");
}
