#include<stdio.h>
//在有序的数列中插入若干个数，使插入后的数列仍保持有序；
int main()
{
	int t[40]={1,5,6,7,9,10,13,15,18,19,30,36},k,i,n,j;
	printf("请问您要插入多少个数？(最多插入28个数)");
	scanf("%d",&n);
	printf("\n");
	printf("请输入数:\n");
	for(i=12;i<(n+12);i++)
	{
		scanf("%d",&t[i]);
		for(j=0;j<i;j++)
		{
			if(t[i]<t[j])
			{
				k=t[i];
				t[i]=t[j];
				t[j]=k;
			}
		}
		j=0;	
	}
	for(i=0;i<n+12;i++)
	{
		printf("%d,",t[i]);
	}
 } 

