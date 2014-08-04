#include<stdio.h>
#include<malloc.h>
int Length(char S[])
{
    int i=0;
    while(S[i]!='\0')
    {
	i++;
    }
    return i;
}
//int Strcpy(char *source, char *dest)
char * Strcpy(char *dest, char *source)
{
    if(source==NULL ||dest==NULL)
	return 0;
    char *dest2 = dest;
    int i=0;
    while((*(dest++)=*(source++))!='\0')
	;
    return dest2;
    /*while(*(source+i)!='\0')
    {
	*(dest+i)=*(source+i);
	i++;
    }
    *(dest+i)='\0';*/
}
int Index(char S[],char T[])
{
    int i=0,j=0;
    for(i=0;S[i]!='\0';i++)
    {
	for(j=0;T[j]!='\0';j++)
	{
	    if(S[i+j]=='\0' || S[i+j]!=T[j])
		break;
	}
	if(T[j]=='\0')
	    printf("%d\n",i);
    }
}
int NumToChar(int num, char *a)
{
    int i=0,j=0;
    char temp;
    while(num)
    {
	*(a+i) = num%10+'0';
	i++;
        num = num/10;
    }
    *(a+i)='\0';
    for(j=0;j<(i-1)/2;j++)
    {
        temp =*(a+i-1-j);
	*(a+i-1-j)=*(a+j);
	*(a+j)=temp;	
    }
}

int CharToNum(char a[])
{
    int num=0;
    while(*(a)!='\0')
    {
	num=num*10+(*(a++)-'0');
    }
    return num;
}
int To(char b[],char a[])
{
    while(*b!='\0')
    {
	int i=0;
	while(*(b+i)==*b && *(b+i)!='\0')
	{
	    *(a+i)=*(b+i);
	    i++;
	}
	*(a+i)=i+'0';
	a=a+i+1;
	b=b+i;
    }
    *(a+1)='\0';
//    return a;
}
int main()
{
    char S[]="abcjkdjkabcjkdfkjabc";
    char T[]="aabdddcccc";
//    char *Q;
//    Index(S,T);
//    printf("%d\n",Length(T));
//    char *dest = Strcpy(S,T);
//    NumToChar(1234567,S);
//    printf("%s\n",S);
//    int num=CharToNum("98765");
    char  num[20];
    To(T,num);
    printf("%s\n",num);
}
