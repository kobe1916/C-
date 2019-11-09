#include <stdio.h>
int main()
{
	int x[5] = {0};
	int i = 0;
	int j = 0;
	for(j = 0;j<5;j++)
	{
		scanf("%d",&x[j]);
	}
	for(j = 0;j<5;j++)
	{
		if(x[j]<=30&&x[j]>=1)
		{
			for(i = 0;i< x[j];i++)
			{
				printf("*");
			}
			printf("\n");
		}
	
	}
	
	
 } 
