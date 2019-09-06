#define N 99
struct Stu
{
	int num;
	char name[20];
	int score;
};
int main()
{
	int i, j;
	int n;
	struct Stu student[N] = { 0 };
	struct Stu temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%s%d", &student[i].num, student[i].name, &student[i].score);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (student[i].score < student[j].score)
			{
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d %6s  %d\n", student[i].num, student[i].name, student[i].score);
	}
	system("pause");
	return 0;
}
