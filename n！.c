//1.函数写法
#include <stdio.h>
#include <stdlib.h>
 
int fac(int n)
{
    int ret = 1;
    int i = 0;
    for (i = 1; i <=n; i++)
    {
        ret = ret*i;
    }
    return ret;
}
int main()
{
    int n = 0;
    printf("请输入一个数：");
    scanf_s("%d", &n);
    int fac(n);
    printf("%d\n", fac(n));
    system("pause");
    return 0;
}

//2.递归写法
#include <stdio.h>
#include <stdlib.h>
 
int fac(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n*fac(n - 1);
    }
    
}
int main()
{
    int n = 0;
    printf("请输入一个数：");
    scanf_s("%d", &n);
    int fac(n);
    printf("%d\n", fac(n));
    system("pause");
    return 0;
}
