#include<stdio.h>
#include<malloc.h>
typedef struct StackNode
{
    int data;
    struct StackNode *next;
}SNode,*SNodePtr;
typedef struct
{
    SNodePtr top;
    int count;
}LinkStack;
int InitStack(LinkStack *S)
{
    S->top = (SNodePtr)malloc(sizeof(SNode)); 
    S->top = NULL;
    S->count=0;
}
int Push(LinkStack *S,int m)
{
    SNodePtr p;
    p = (SNodePtr)malloc(sizeof(SNode));
    p->data = m;
    p->next=S->top;
    S->top=p;
    S->count++;
}
int Pop(LinkStack *S,int *m)
{
    SNodePtr p;
    p = S->top;
    *m = p->data;
    S->top = p->next;
    free(p);
    S->count--;
}
int main()
{
    LinkStack S;
    InitStack(&S);
    Push(&S,3);
    int m;
    Pop(&S,&m);
    printf("%d",m);
}


