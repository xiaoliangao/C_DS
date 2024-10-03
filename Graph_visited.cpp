#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct EdgeNode//边表结点 
{   int adjvex;        //存储顶点对应的下标   存储的是一个位置，而非具体元素，为了以后改变数据方便操作 
	struct EdgeNode *next;//链域指向下一个邻接点 
	int weight;      //权值（问题中有权值再用） 
}EdgeNode;
typedef struct VertexNode//顶点表结点 
{	char data;//存放顶点信息 
	EdgeNode *firstedge;//指向边表中第一个结点 
}VertexNode;
typedef struct
{	VertexNode adjlist[20];
	int n,e;
}GraphAdjlist;//声明图的邻接表类型 
int visited[10];//访问标志数组 （访问过赋值为1，反之为0） 

void create(GraphAdjlist *G)//创建邻接表 
{	int i,j,k;
	EdgeNode *e;
	printf("请输入顶点数和边数：");
	scanf("%d%d",&G->n,&G->e);
	getchar();//清除缓冲 
	printf("请输入顶点边号：\n");
	for(i=0;i<G->n;i++)
	{   scanf("%c",&G->adjlist[i].data);//输入顶点编号
		G->adjlist[i].firstedge=NULL;//将边表置空 
		getchar(); 
	}
	for(k=0;k<G->e;k++)
	{   printf("输入边（Vi,Vj）上的顶点序号：\n");
		scanf("%d%d",&i,&j);//头插法方便，快速   如果用尾插法需要指针遍历到尾部，太慢 
		/*使用头插法加入边表结点*/
		e=(EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex=j;
		e->next=G->adjlist[i].firstedge; 
		G->adjlist[i].firstedge=e;
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode));//因为是无向图，一条边对应两个顶点 
		e->adjvex=i;
		e->next=G->adjlist[j].firstedge; 
		G->adjlist[j].firstedge=e;	
	 } 
	printf("\n");
}
void DFS(GraphAdjlist *G,int i)
{	EdgeNode *p;
	visited[i]=1;
	printf("%c ",G->adjlist[i].data);
	p=G->adjlist[i].firstedge;
	while(p!=NULL)
	{	if(visited[p->adjvex]==0)
		  DFS(G,p->adjvex);
		p=p->next;
	}
}
void DFSTraverse(GraphAdjlist *G)
{	int i;
	for(i=0;i<G->n;i++)
	  visited[i]=0;
	for(i=0;i<G->n;i++)
	  if(visited[i]==0)
	    DFS(G,i);
}
void BFS(GraphAdjlist *G,int v)
{	EdgeNode *p;
	int queue[max],front=0,rear=0;//定义循环队列并初始化 
	int w,i;
	for(i=0;i<G->n;i++)//标志数组初始化 
	    visited[i]=0;
	printf("%2c",G->adjlist[v].data);
	visited[v]=1;
	rear=(rear+1)%max;
	queue[rear]=v;
	while(front!=rear)
	{	front=(front+1)%max;
		w=queue[front];
		p=G->adjlist[w].firstedge;
		while(p!=NULL)
		{	if(visited[p->adjvex]==0)
			{	printf("%2c",G->adjlist[p->adjvex].data);
				visited[p->adjvex]=1;
				rear=(rear+1)%max;
				queue[rear]=p->adjvex;
			}
			p=p->next;
		}
	}
	printf("\n");
}
int main()//A B C D E
{	GraphAdjlist G;
	create(&G);
	printf("深度优先遍历：");
	DFSTraverse(&G);
		printf("广度优先遍历：");
	BFS(&G,0); 
	return 0;
}

