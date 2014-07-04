#include<stdio.h>
#include<malloc.h>
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode,*QNodePtr;
typedef struct
{
    struct QNode *front;
    struct QNode *rear;
}LinkQueue;
int InitQueue(LinkQueue *Q)
{
    QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
    p->next = NULL;
    Q->front=Q->rear=p;
}
int EnQueue(LinkQueue *Q,int m)
{
    QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
    p->data = m;
    Q->rear->next = p;
    Q->rear = p;
}
int DeQueue(LinkQueue *Q,int *m)
{
     QNodePtr p = Q->front->next;
     *m = p->data;
     Q->front->next = p->next;
     if(p==Q->rear)
	 Q->rear=Q->front;
     free(p);
}
int main()
{
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q,4);
    EnQueue(&Q,4);
    int m;
    DeQueue(&Q,&m);
    printf("%d\t",m);
    DeQueue(&Q,&m);
    printf("%d\t",m);


}
