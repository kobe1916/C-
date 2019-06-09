#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int num;
	struct student *next;
}stu;

int * sort(int *nums[5], int n)
{
	int i, j, t;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
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
