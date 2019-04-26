#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double Distance(double x1,double y1,double x2,double y2)
{
	//double x = sqrt((pow(x1 - x2), 2) + (pow(y1 - y2), 2));
	double x = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	return x;
}
int main()
{
	double x1, y1;
	double x2, y2;
	scanf("%lf%lf", &x1, &y1);
	scanf("%lf%lf", &x2, &y2);
	double d = Distance(x1,y1,x2,y2);
	printf("两点间距离为：%lf", d);
	system("pause");
	return 0;
}
