#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX         26               // 矩阵最大容量
#define INF         (~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define isLetter(a) ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)   (sizeof(a)/sizeof(a[0]))
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
    int weight;
    char *des1;
    int numv=0,nume=0;
    for(int i=0;i<=25;i++)
    	for(int j=0;j<=25;j++)
    		pG.matrix[i][j]=0;
    while(scanf("%c-%c-%d\n",&source,&des,&weight)!=EOF) 
    {
    	if (numv==0)
    		start=source;
    	numv++;
    	int temp2=des-'A';
    	int temp1=source-'A';
    	pG.matrix[temp1][temp2]=weight;
    	pG.matrix[temp2][temp1]=weight;
    	nume++;	
	}
	pG.edgnum=nume/2;
	pG.vexnum=numv/2;
	return pG;
}


void Djstra(Graph G,char start)
{
	int distance[26];
	int root=start-'A';
	int queue[26];
	int rear=0,front=0;
	int visited[26];
	int parent[26]; 
	for(int i=0;i<=25;i++)
	{
		visited[i]=0;
		distance[i]=100;
	}
	distance[root]=0;
	//所有顶点进队列 
	for(int i=0;i<=25;i++)
	{
		for(int j=0;j<=25;j++)
			if(G.matrix[i][j]>0&&G.matrix[i][j]<100&&visited[j]==0)
				{
					queue[rear++]=j;
					visited[j]=1;
				}
				
	}
	for(int i=0;i<=25;i++)
	{
		visited[i]=0;
	}
	//算法部分 
	while(rear!=front)
	{
		int n;
		for (int i=0;i<=25;i++)
		{
			for (int j=0;j>=i&&j<=25;j++)
				if(distance[queue[i]]<distance[queue[j]])
				{
					n=queue[i];		
					front++; 
				}			
		}
		visited[n]=1;
		for(int i=0;i<=25;i++)
		{
			if(G.matrix[n][i]>0&&G.matrix[n][i]<100&&visited[i]==0)
				{
					if(distance[n]+G.matrix[n][i]<distance[i])
					{
						distance[i]=distance[n]+G.matrix[n][i];
						parent[i]=n;
					}
				}
		}
		
		
	}
	
    for(int i=0;i<=25;i++)
		{
			if(G.matrix[n][i]>0&&G.matrix[n][i]<100)
			{	
        		if(i!=root)
		        {
		        	char temp2=i+'A';
		            printf("%c",temp2);
		            j=i;
		            do
		            {
		                j=parent[j];
		                char temp=j+'A';
		                printf("-%c",temp);
		            }while(j!=root);
		            printf("-%d\n",distance[j]);
		    	}
		    	else
		    	{
		    		printf("%c-0",start);
				}
			}
}

void main()
{
	Graph G=create_graph();
	Djstra(G,start);
}


