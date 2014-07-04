#include<stdio.h>
#include<malloc.h>
typedef struct BiTree
{
    int data;
    struct BiTree * l,*r;
}*BiTree,BNode;
int SearchBST(BiTree T,int key,BiTree p,BiTree *f)
{
    if(T==NULL)
    {
    	*f = p;
	return 0;
    }
    else if(T->data==key)
    {
	*f = T;
	return 1;
    }
    else if(T->data>key)
        return SearchBST(T->l,key,T,f);
    else if(T->data<key)
	return SearchBST(T->r,key,T,f);
}
int InsertBST(BiTree *T,int key)
{
    BiTree f,s;
    if(!SearchBST(*T,key,NULL,&f))
    {
        s = (BiTree)malloc(sizeof(BNode));
	s->data = key;
	s->r = NULL;
	s->l = NULL;
        if(f==NULL)
            *T=s;
        else if(f->data>key)
	    f->l=s;
        else f->r=s;
    }
}
int PreOrderTarverse(BiTree T)
{
    if(T==NULL)
	return;
    printf("%d\n",T->data);
    PreOrderTarverse(T->r);
    PreOrderTarverse(T->l);
}
int MiddleOrderTarverse(BiTree T)
{
        if(T==NULL)
            return;
	MiddleOrderTarverse(T->l);
        printf("%d\n",T->data);
	MiddleOrderTarverse(T->r);
}
int Delete(BiTree *p)
{
    BiTree q,s;
    if((*p)->r==NULL)
    {
	q = *p;
	*p =(*p)->l;
	free(q);
    }else if((*p)->r==NULL)
    {
	 q = *p;
	 *p =(*p)->r;
	 free(q);
    }else
    {
        q=*p;
	s=(*p)->l;
	while(s->r)
	{
	    q=s;
	    s=s->r;
	}
	(*p)->data=s->data;
	if(q!=*p)
	    q->r=s->l;
	else
	    q->l=s->l;
	free(s);
    }
}
int DeleteBST(BiTree *T,int key)
{
    if((*T)->data==key)
	return Delete(T);
    else if(key<(*T)->data)
	return DeleteBST(&(*T)->l,key);
    else 
        return DeleteBST(&(*T)->r,key);
}
int main()
{
    BiTree T=NULL;
    int a[]={5,3,4,2,7};
    int i;
    for(i=0;i<5;i++)
	InsertBST(&T,a[i]);
    MiddleOrderTarverse(T);
    DeleteBST(&T,5);
    MiddleOrderTarverse(T);
}
