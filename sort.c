#include<stdio.h>
int Partion(int a[],int low, int high)
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
    int pos;
    if(low<high)
    {
        pos=Partion(a,low,high);
        QuickSort(a,low,pos-1);
        QuickSort(a,pos+1,high);
    }
}
int main()
{
    int i=0;
    int a[]={4,3,2,14,5};
    QuickSort(a,0,4);
    for(i=0;i<5;i++)
    {
	printf("%d ",a[i]);
    }
    
}
