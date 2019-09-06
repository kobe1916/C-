int main()
{
	int len;
	int *p = 0;
	int i;
	printf("请输入个数：");
	scanf("%d", &len);
	p = (int *)malloc(sizeof(int)*len);
	printf("请输入每个数组元素的值：");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &p[i]);
	}
	for (i = 0; i < len; i++)
	{
		printf("p[%d] = %d \n ", i, p[i]);
	}
	free(p);
	system("pause");
	return 0;
}
