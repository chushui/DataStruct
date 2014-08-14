#include<stdio.h>
#include<string.h>
#include<malloc.h>
void Left(char s[],int n)
{
    char *q,*p;
    int len=strlen(s);
    char *s2=(char *)malloc(len+1);
    p=s;
    q=s2;
    s2=s2+len-n%len;
    while(*p)
    {
	*s2++=*p++;
	if(s2-q>=len)
	{
	    *s2='\0';
	    s2=q;
	}
    }
    strcpy(s,q);
    free(q);
}
int main()
{
    char s[]="123456";

    Left(s,1);

    printf("%s\n",s);
}
