strcmp(char *s1,char *s2)
{
  while(*s1==*s2)
  {
    if(*s1==0)return(0);
    s1++;s2++;
    }
    return(*s1-*s2);
}
main()
{
  char a[20],b[20];
  printf("input a,b:");
  gets(a);
  gets(b);
  printf(" strcmp(a,b)=&d",strcmp(a,b));
 }
