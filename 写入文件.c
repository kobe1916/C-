#include <stdio.h>  
  
int main()  
{  
    //下面是写数据，将数字0~9写入到data.txt文件中  
    FILE *fpWrite=fopen("data.txt","w");  
    if(fpWrite==NULL)  
    {  
        return 0;  
    }  
    for(int i=0;i<10;i++)  
        fprintf(fpWrite,"%d ",i);  
    fclose(fpWrite);  
    //下面是读数据，将读到的数据存到数组a[10]中，并且打印到控制台上  
    int a[10]={0};  
    FILE *fpRead=fopen("data.txt","r");  
    if(fpRead==NULL)  
    {  
        return 0;  
    }  
    for(int i=0;i<10;i++)  
    {  
        fscanf(fpRead,"%d ",&a[i]);  
        printf("%d ",a[i]);  
    }  
    getchar();//等待  
  
    return 1;  
}  
--------------------- 
作者：博瓦 
来源：CSDN 
原文：https://blog.csdn.net/u010925447/article/details/75046810 
版权声明：本文为博主原创文章，转载请附上博文链接！
