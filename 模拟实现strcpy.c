//char* mystrcpy(char* des, const char* src)
//{
//	char* ret=des;
//	while (*src != '\0' )
//	{
//		*des = *src;
//		des++;
//		src++;
//	}
//	*des = '\0';
//	return ret;
//
//}

char* mystrcpy(char* des, const char* src)
{
	char* ret = des;
	while (*(des++) = *(src++));
	return ret;
}


int main()
{
	char a;
	char b;
	char* c;
	scanf("%s", &a);
	scanf("%s", &b);
	c = mystrcpy(&a, &b);
	printf("%s\n", c);
	system("pause");
	return 0;
}
