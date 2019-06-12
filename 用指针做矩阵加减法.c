int main()
{
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int b[3][4] = { 12,11,10,9,8,7,6,5,4,3,2,1 };
	int *q1, *q2;   //指针变量
	int(*p1)[4], (*p2)[4];   //指针数组，存放整形的指针（数组元素的所有类型均为整形指针）
	//int (*p1) arr[1]    //数组指针（即数组的指针）  这个指针指向一个数组
	
	for (p1 = a, p2 = b; p1 < a + 3; p1++, p2++)  //控制行数
	{
		for (q1 = *p1, q2 = *p2; q1 < *p1 + 4; q1++, q2++)  //控制列数
		{
			*q1 = *q1 - *q2;    //解引用进行运算
		}
	}
	for (p1 = a; p1 < a + 3; p1++)  //打印
	{
		for (q1 = *p1; q1 < *p1 + 4; q1++)
			printf("%5d", *q1);
		printf("\n");
	}
	system("pause");
}
