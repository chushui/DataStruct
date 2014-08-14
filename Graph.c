#include<stdio.h>
typedef struct
{
    int vertex[10];
    int arc[10][10];
    int numNodes,numEdges;
}MGraph;
int visit[10];
int CreateMGraph(MGraph*G)
{
    printf("Input vertex and edge Numbers.\n");
    scanf("%d,%d",&G->numNodes,&G->numEdges);
    int i,j,k;
    for(i=0;i<G->numNodes;i++)
	scanf("%d",&G->vertex[i]);

    printf("Input edges.\n");
    for(j=0;j<G->numNodes;j++)
	for(k=0;k<G->numNodes;k++)
	{
	    G->arc[j][k] = -1;
	    printf("%d,%d = %d \n",j,k,G->arc[j][k]);
	}

    for(k=0;k<G->numEdges;k++)
    {
        scanf("%d,%d",&i,&j);
	G->arc[i][j]=1;
	G->arc[j][i]=1;
    }

    for(i=0;i<G->numNodes;i++)
        printf("%d ",G->vertex[i]);

    for(j=0;j<G->numNodes;j++)
    {
	for(k=0;k<G->numNodes;k++)
           printf("%d ",G->arc[j][k]);
	printf("\n");
    }	  

}
int DFS(MGraph G,int i)
{
    printf("%d\n",G.vertex[i]);
    visit[i]=1;
    int j;
    for(j=0;i<G.numNodes;j++)
    {
	if(G.arc[i][j]==1 && visit[j]==0)
	    DFS(G,j);
    }
}
int DFSTarverse(MGraph G)
{
    int i;
    for(i=0;i<G.numNodes;i++)
	visit[i]=0;
    for(i=0;i<G.numNodes;i++)
    {
	if(!visit[i])
	DFS(G,i);
    }
}
int main()
{
    MGraph G;
    CreateMGraph(&G);
//    DFSTarverse(G);
}
