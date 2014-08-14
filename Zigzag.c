#include<stdio.h>
int main()
{
    int N=8,cross,a[8][8];
    int count=0;
    int i;
    for(cross=0;cross<N;cross++)
    {
	if(cross%2==0)
	    for(i=cross;i>=0;i--)
		a[i][cross-i]=count++;
	else
            for(i=cross;i>=0;i--)
		a[cross-i][i]=count++;
    }
   
    int limit=1;
    for(cross=N-2;cross>=0;cross--)
    {
	if(cross%2==0)
	{
	    for(i=N-1;i>=limit;i--)
	    {
		a[i][limit+N-1-i]=count++;
	    }
	    limit++;
	}
	else
	{
	     for(i=N-1;i>=limit;i--)
	     {
		a[N-1+limit-i][i]=count++;
	     }
	     limit++;
	}
    }

 for(i=0;i<8;i++)
    {
	int j=0;
	for(j=0;j<8;j++)
	    printf("\t%d",a[i][j]);
	printf("\n");
    }

    
}
