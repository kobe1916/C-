
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

//my_strlen("abc")
//1+my_strlen("bc")
//1+1+my_strlen("c")
//1+1+1+my_strlen("")
//1+1+1+0
//3
int My_strlen(char* x)
{
	if (*x == '\0')
		return 0;
	else
		return 1 + My_strlen(x + 1);
}

int main()
{
	//char x = "I am a student !";
	int ret = My_strlen("I am a student !");
	printf("%d \n", ret);
	system("pause");
	return 0;
}

