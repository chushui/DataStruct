#include<stdio.h>
#include<malloc.h>
#define SIZE 20
#define NULLKEY -32768
typedef struct
{
    int * data;
    int count;
}HashTable;

int Hash(int key)
{
    return key%SIZE;
}

int InitHash(HashTable * H)
{
    H->count = 0;
    H->data = (int *)malloc(sizeof(int)*SIZE);
    int i = 0;
    for(i=0;i<SIZE;i++)
    {
	H->data[i] = NULLKEY;
    }
    return 1;
}

int InsertHash(HashTable *H,int key)
{
    int addr = Hash(key);
    if(H->count==SIZE)
	return 0;
    while(H->data[addr]!=NULLKEY)
    {
	addr = (addr+1)%SIZE;
    }
    H->count++;
    H->data[addr] = key;
    return 1;
}

int SearchHash(HashTable *H, int key, int *addr)
{
    *addr = Hash(key);
    while(H->data[*addr]!=key)
    {
	*addr=(*addr+1)%SIZE;
	if(H->data[*addr]==NULLKEY || *addr==Hash(key))
	    return 0;
    }
    return 1;
}
int main()
{
    HashTable H;
    InitHash(&H);
    InsertHash(&H,1);
    InsertHash(&H,21);
    InsertHash(&H,12);
    int r;
    printf("1 is %d, 22 is %d",SearchHash(&H,1,&r),SearchHash(&H,22,&r));
}
