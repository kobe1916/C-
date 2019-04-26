#include<stdio.h>
//选择排序法；
//输入一个数组并从小到大排序； 
main()
{
	int s[20],n,i,j,k;
	printf("输入数组的长度(长度在20个单位内):\n");
	scanf("%d",&n);
	printf("请输入一个数组(长度在20个单位内):\n");
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);
	i=0;
	for(i=0;i<n;i++)
	{
		for(j=(i+1);j<n;j++)
		{
			if(s[i]>s[j])
			{
				k=s[j];
				s[j]=s[i];
				s[i]=k;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d,",s[i]);
	
 } 


//左对齐：printf("%-d",1234);
//右对齐：printf("%d",1234);
//左对齐的话只需在%后面加一个负号，不加的话系统默认右对齐
