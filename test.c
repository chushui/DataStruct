#include"stdio.h"
#include<math.h>
#define m(a,b,c)    (a > b ? (b > c ? b:(a>c?c:a)):(a>c?a:(b<c?b:c)))
#define min(a,b,c)  a<b?(a<c?a:c):(b<c?b:c)
int main()
{
    int a[5],i,j,temp=100;
    int m,n;
    for(i=0;i<5;i++)
    {
	scanf("%d",&a[i]);
	for(j=0;j<i;j++)
	{
	    if(abs(a[i]-a[j])<temp)
	    {
		temp=abs(a[i]-a[j]);
		if(a[i]<a[j])
		{
                     m=i;
		     n=j;
		}
		else
		{
                    m=j;
		    n=i;
		}
		
	    }
	    else if ( abs(a[i]-a[j])==temp && a[m]<a[i] && a[n]<a[i])
	    {
	         if(a[i]<a[j])
		 {
		       m=i;
		       n=j;
		 }
		 else
		 {
		      m=j;
		      n=i;
		 }

	    }

	}
	printf("i=%d\n",i);
    }
    printf("%d,%d",a[m],a[n]);
}
