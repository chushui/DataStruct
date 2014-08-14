#include<stdio.h>
int Partion(int a[],int low,int high)
{
    int pivot=a[low];
    while(low<high)
    {
        while(a[high]>=pivot && low<high)
	    high--;
	if(low<high)
	    a[low++]=a[high];
	while(a[low]<=pivot && low<high)
	    low++;
        if(low<high)
	    a[high--]=a[low];
        
    }
    a[low]=pivot;
    return low;
}
int QuickSort(int a[],int low,int high)
{
    int pivotpos;
    if(low<high)
    {
	pivotpos=Partion(a,low,high);
	QuickSort(a,low,pivotpos-1);
	QuickSort(a,pivotpos+1,high);
    }
}
int HeapAjust(int a[],int low,int high)
{
    int i,j;
    for(i=low;i<high;i*=2)
    {
	j=2*i;
        if( j<high && a[j+1]>a[j])
	    j++;
	if(a[i]>=a[j]) break;
        if(a[j]>a[i])
	{
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
	    i=j;
	}
    }

}
int swap(int a[],int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int HeapSort(int a[],int n)
{
    int i=0;
    for(i=n/2;i>0;i--)
	HeapAjust(a,i,n);
    for(i=n;i>1;i--)
    {
	swap(a,1,i);
	HeapAjust(a,1,i-1);
    }

}
int main()
{
     int i=0;
     int a[]={0,4,5,3,56,7};
     HeapSort(a,5);
     for(i=0;i<6;i++)
     {
	 printf(" %d ",a[i]);
     }
}
