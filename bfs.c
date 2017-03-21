#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX         26               // 矩阵最大容量
#define INF         (~(0x1<<31))        // 最大值(即0X7FFFFFFF)
char start;
// 邻接矩阵
typedef struct _graph
{
    //char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;

Graph create_graph()
{
    Graph pG;
    char source,des;
    char *des1;
    int numv=0,nume=0;
    for(int i=0;i<=25;i++)
    	for(int j=0;j<=25;j++)
    		pG.matrix[i][j]=0;
    while(scanf("%c-%s\n",&source,des1)！=EOF) 
    {
    	int d=strlen(des1);
    	if (numv==0)
    		start=source;
    	numv++;
    	for(int j=0;j<d;j++)
    	{
    		int temp2=des1[j]-'A';
    		int temp1=source-'A';
    		pG.matrix[temp1][temp2]=1;
    		pG.matrix[temp2][temp1]=1;
    		nume++;
		}
	}
	pG.edgnum=nume;
	pG.vexnum=numv;
	return pG;
}
void BFS(Graph G, char s)
{
	int root=start-'A';
	int distance[26];
	int visited[26];
	int queue[26];
	int rear=0,front=0;
	for(int i=0;i<=25;i++)
	{
		visited[i]=0;
		distance[i]=INF;
	}
	queue[rear++]=root;
	distance[root]=0;
	visited[root]=1;
	while(rear!=front)
	{
		int n=queue[front++];
		for(int j=0;j<=25;j++)
		{
			if(G.matrix[n][j]==1)
				{
					if(visited[j]==0)
					{
						visited[j]=1;
						distance[j]=distance[n]+1;
						char temp='A'+ j;
						printf ("%c",temp);
						queue[rear++]=j;
					}
						
				}
		}
	}
	printf("\n");
}

void main()
{
	freopen("in1.txt", "r", stdin);
	Graph G=create_graph();
	BFS(G,start);
}
