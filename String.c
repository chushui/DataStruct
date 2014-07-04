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
int main()
{
    char S[]="abcjkdjkabcjkdfkjabc";
    char T[]="abc";
    Index(S,T);
    printf("%d\n",Length(T));
}
