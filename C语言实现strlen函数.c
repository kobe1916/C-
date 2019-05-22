
int My_strlen(char* x)
{
	int count = 0;
	while(*x !='\0')
	{
		count++;
		x++;
	}
	return count;

}
