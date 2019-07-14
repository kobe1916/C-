#include<stdio.h>
int main(void)
{
int i,j,n;
double item,s;
scanf("%d",&n);
s=0;
for(i=1;i<=n;i++){
item=0;
for(j=1;j<=i;j++)
item=item+j;
s=s+item;
}
printf("%f\n",s);
return 0;
}
