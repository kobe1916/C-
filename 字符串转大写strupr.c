#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>







void Upper(char a[])
{
	int t = strlen(a);
	for(int i=0;i<t;i++)
	{
		while (a[i] != '\0')
		{
			a[i] -= 32;
			i++;
		}
		
	}	
	
}


int main()
{
	int i = 0;
	char arr[30] = "helloworld";
	int t = strlen(arr);
	Upper(arr);
	printf("%s", arr);
	printf("\n");
	system("pause");

}
