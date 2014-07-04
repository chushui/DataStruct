#include<stdio.h>
#include<malloc.h>
typedef struct ListNode
{
    int data;
    struct ListNode * next;
}ListNode,*LinkList;

int InitList(LinkList * L)
{
    LinkList p=NULL,q=NULL;
    *L = (LinkList)malloc(sizeof(ListNode));
    (*L)->next=NULL;
    p = *L;
    int temp;
    printf("Put numbers.\n");
    while(scanf("%d",&temp))
    {
	if(temp=='#')
	   return 1;
	else
	{
            q = (LinkList)malloc(sizeof(ListNode));
	    q->data = temp;
	    q->next = NULL;
	    p->next = q;
	    p = q;
	}

    }
    printf("End.\n");
}

int PrintList(LinkList L)
{
    LinkList p;
    p = L->next;
    while(p!=NULL)
    {
	printf("\t%d",p->data);
	p = p->next;
    }
    return;
    
}

int InsertList(LinkList *L,int i,int key)
{
    int j=1;
    LinkList p=NULL,q=NULL;
    p=*L;
    while(j<i &&p!=NULL)
    {
	p = p->next;
	j++;
    }
    if(j>i || p==NULL)
	return 0;
    q = (LinkList)malloc(sizeof(ListNode));
    q->data=key;
    q->next=p->next;
    p->next=q;
}  

int DeleteList(LinkList *L,int i)
{
    int j=1;
    LinkList p=NULL,q=NULL;
    p=*L;
    while(j<i &&  p->next!=NULL)
    {
	p=p->next;
	j++;
    }
    if(j>i || p->next==NULL)
    return 0;
    q = p->next;
    p->next = q->next;
    free(q);   
}

int TarverseList(LinkList *L)
{
    LinkList p,q,s;
    p=*L;
    if(p==NULL || p->next==NULL)
	return 0;
    q=(*L)->next;
    while(q->next!=NULL)
    {
        s=q->next;
	q->next = p;
	p = q;
	q = s;
    }
    q->next = p;
    (*L)->next->next = NULL;
    (*L)->next=q;
}
int main()
{
    LinkList L;
    InitList(&L);
    PrintList(L);
    InsertList(&L,1,100);
    DeleteList(&L,1);
    TarverseList(&L);
    PrintList(L);
}
