//两个条件：
//1.存在限制条件，当满足这个限制条件的时候，递归便不再继续。
//2.每次递归调用之后越来越接近这个限制条件


//递归的主要思考方式在于：把大事化小
void print(int n)
{
    if(n>9)
    {
    print(n/10);
    }
    printf("%d ", n%10);
}
int main()
{
    int num = 1234;
    print(num);
    return 0;
}



#incude <stdio.h>
int Strlen(const char*str)
{
    if(*str == '\0')
    return 0;
    else return 1+Strlen(str+1);
}
int main()
{
    char *p = "abcdef";
    int len = Strlen(p);
    printf("%d\n", len);
    return 0;
}
