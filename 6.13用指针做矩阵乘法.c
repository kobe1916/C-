/*
#include <stdio.h>
int main()
{
	int i, j, n, *tem[3];
	int p[2][3], q[3][2], r[2][2];
	// m*s   p*n --> m*n
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
*/


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
#define MID 4
int main()
{
	int arr1[ROW][MID] = { 0 };
	int arr2[MID][COL] = { 0 };
	int arr3[ROW][COL] = { 0 };
	int i = 0;
	int j = 0;
	int m = 0;
	printf("第一个矩阵\n" );
	for (i = 0; i < ROW; i++)
	{
		printf("第一个矩阵的%d行\n", i);
		for (j = 0; j < MID; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("第二个矩阵\n");
	for (i = 0; i < MID; i++)
	{
		printf("第二个矩阵第%d行\n", i);
		for (j = 0; j < COL; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}
	printf("第三个矩阵:\n");
	for (i = 0; i < ROW; i++)//运算
	{
		for (j = 0; j < COL; j++)
		{
			int sum = 0;
			for (m = 0; m < MID; m++)
			{
				sum = sum + arr1[i][m] * arr2[m][j];
			}
			arr3[i][j] = sum;
		}
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%3d", arr3[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

