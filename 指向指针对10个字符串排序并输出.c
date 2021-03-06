#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(char *str[], int n)
{
	int i;
	char **p;
	for (p = str, i = 0; p < str + n; i++, p++) {
		printf("Please enter No.%d string: ", i + 1);
		scanf("%s", *p);
	}
}
void sort(char *str[], int n)
{
	int i, j;
	char *temp;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (strcmp(str[i], str[j]) > 0) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
}
void print(char *str[], int n)
{
	char **p;
	for (p = str, printf("Sort by:\n"); p < str + n; puts(*p), p++);
}

int main()
{
	int num, i;
	char **string;
	printf("Please enter number: ");
	scanf("%d", &num);
	string = (char**)malloc(num * sizeof(char*));
	for (i = 0; i < num; string[i++] = (char*)malloc(30 * sizeof(char)));
	input(string, num);
	sort(string, num);
	print(string, num);
	system("pause");
	return 0;
}
