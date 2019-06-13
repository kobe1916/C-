#include <stdio.h>
int main()
{
	int i, j, n, *tem[3];
	int p[2][3], q[3][2], r[2][2];
	tem[0] = p[0]; tem[1] = q[0]; tem[2] = r[0];
	printf("请输入第1个矩阵:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			r[i][j] = 0;
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", tem[0] + 3 * i + j);
		}
	}
	printf("请输入第2个矩阵:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%d", tem[1] + 2 * i + j);
		}
	}
	printf("输出2个矩阵相乘得到的矩阵:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (n = 0; n < 3; n++)
			{
				r[i][j] += (*(tem[0] + 3 * i + n))*(*(tem[1] + 2 * n + j));
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d\t", *(tem[2] + i * 2 + j));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
