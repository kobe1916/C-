#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define N 3

//需求： 键盘输入学号、姓名、性别、四门课成绩、并求四门课平均成绩、平均成绩排序、并输出

struct Score
{
	int chinese;
	int math;
	int english;
	int clang;

};

struct stu
{
	char name[200];
	char sex;
	char num[200];
	struct Score score;
	
};


int main()
{
	int i = 0;
	int j = 0;
	struct stu cls[N];
	struct Score score;
	for (i = 0; i < N; i++)
	{
		printf("请输入第%d个同学的信息。\n", i + 1);
		printf("姓名：");
		scanf("%s", &cls->name);
		printf("语文 数学 英语 C语言（中间用空格隔开）\n");
		scanf("%d%d%d%d", &score.chinese, &score.math, &score.english, &score.clang);
		printf("学号\n");
		scanf("%s", &cls->num);
		printf("性别\n");
		scanf("%s", &cls->sex);
	}
	for (j = 0; j < N; j++)
	{
		printf("学号：%s 姓名：%s 性别：%s 语文%d 数学%d 英语%d C语言%d\n",
			cls->num, cls->name, cls->sex,score.chinese, score.math, score.english, score.clang);
	}
	system("pause");
	return 0;
}
