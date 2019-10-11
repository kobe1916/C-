
//类比1+2+3+4+...+n
//先对阶乘项求解，最后累加
int main()
{
	int i, j;
	int x;
	int ret = 1;
	int n = 0;
	scanf("%d", &x);
	//起始不能为0，否则相乘为0 
	for (i = 1; i <= x; i++)
	{
		ret *= i;
		/*for (j = 1; j <= i; j++)
		{
			ret *= j;
		}*/
		n += ret;
	}
	printf("x！结果为:%d", n);
	system("pause");
	return 0;
}
