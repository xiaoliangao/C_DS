#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct EdgeNode//�߱��� 
{   int adjvex;        //�洢�����Ӧ���±�   �洢����һ��λ�ã����Ǿ���Ԫ�أ�Ϊ���Ժ�ı����ݷ������ 
	struct EdgeNode *next;//����ָ����һ���ڽӵ� 
	int weight;      //Ȩֵ����������Ȩֵ���ã� 
}EdgeNode;
typedef struct VertexNode//������� 
{	char data;//��Ŷ�����Ϣ 
	EdgeNode *firstedge;//ָ��߱��е�һ����� 
}VertexNode;
typedef struct
{	VertexNode adjlist[20];
	int n,e;
}GraphAdjlist;//����ͼ���ڽӱ����� 
int visited[10];//���ʱ�־���� �����ʹ���ֵΪ1����֮Ϊ0�� 

void create(GraphAdjlist *G)//�����ڽӱ� 
{	int i,j,k;
	EdgeNode *e;
	printf("�����붥�����ͱ�����");
	scanf("%d%d",&G->n,&G->e);
	getchar();//������� 
	printf("�����붥��ߺţ�\n");
	for(i=0;i<G->n;i++)
	{   scanf("%c",&G->adjlist[i].data);//���붥����
		G->adjlist[i].firstedge=NULL;//���߱��ÿ� 
		getchar(); 
	}
	for(k=0;k<G->e;k++)
	{   printf("����ߣ�Vi,Vj���ϵĶ�����ţ�\n");
		scanf("%d%d",&i,&j);//ͷ�巨���㣬����   �����β�巨��Ҫָ�������β����̫�� 
		/*ʹ��ͷ�巨����߱���*/
		e=(EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex=j;
		e->next=G->adjlist[i].firstedge; 
		G->adjlist[i].firstedge=e;
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode));//��Ϊ������ͼ��һ���߶�Ӧ�������� 
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
	int queue[max],front=0,rear=0;//����ѭ�����в���ʼ�� 
	int w,i;
	for(i=0;i<G->n;i++)//��־�����ʼ�� 
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
	printf("������ȱ�����");
	DFSTraverse(&G);
		printf("������ȱ�����");
	BFS(&G,0); 
	return 0;
}

