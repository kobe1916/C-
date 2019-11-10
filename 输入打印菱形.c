int main()
{
	int i,j;
	int x;
	scanf("%d",&x);//x即要打印的行数
	for(i=1;i<=x;i++)
	{
                for(j=1;j<=x-i;j++)
		//for(j=1;j<=5-i;j++)
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	}
	for(i=1;i<=x-1;i++)
	{
		for(j=1;j<=i;j++)
			printf(" ");
		for(j=1;j<=2*x-1-2*i;j++)
			printf("*");
		printf("\n");
	}
}
