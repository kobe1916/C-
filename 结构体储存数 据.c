# include "stdio.h"
# define N 30
struct fengshu
{
	int chinese;
	int math;
	int english;
	int Clanguage;
};
struct xinxi
{
	int num;
	int ave;
	char name[15];
	char sex;
	struct fengshu score;
};
average(int a, int b, int c, int d)
{
	int sum = 0;
	float ave;
	sum = a + b + c + d;
	ave = sum / 4.0;
	return(ave);
}
main()
{
	int i, j;
	struct xinxi s[N];
	struct xinxi t;
	for (i = 0; i<N;i++)
		{
		  printf("请输入第%d个同学的信息:\n",i + 1);
		  printf("姓名:");
		  gets(s[i].name);
		  printf("语文，数学，英语和C语言的成绩（中间用空格分开） :");
		  scanf("%d %d %d %d",&s[i].score.chinese,&s[i].score.math,&s[i].score.english,&s[i].score.Clanguage);
		  getchar();
		}
}
	for (i = 0; i<N;i++)
		s[i].ave = average(s[i].score.chinese, s[i].score.math, s[i].score.english, s[i].score.Clanguage);
		for (i = 0; i < N; i++)
			for (j = i + 1; j < N; j++)
				if (s[i].ave > s[j].ave)
				{
					t = s[i];
						s[i] = s[j];
						s[j] = t;
				}
printf("按平均分排序为:\n");
for (i = 0; i < N; i++)
	printf("学号:%d  姓名:%s  性别:%c  语文,数学,英语,C语言成绩:%d %d %d %d   平均成绩:%d  \n", s[i].num, s[i].name, s[i].sex, s[i].score.chinese, s[i].score.math, s[i].score.english, s[i].score.Clanguage, s[i].ave);
}

