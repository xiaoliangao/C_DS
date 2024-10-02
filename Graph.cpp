#include <stdio.h>
#include <stdlib.h>

//�ڽӾ���
#define MaxVertexNum 100
typedef char VertexType; //��������
typedef int EdgeType; //�ߵ�Ȩֵ����

typedef struct {
    VertexType vex[MaxVertexNum]; //��������
    EdgeType edge[MaxVertexNum][MaxVertexNum]; //�ڽӾ���
    int vertexNum, edgeNum; //ͼ�Ķ������ͱ���
}MGraph;

//�ڽӱ�
#define MaxVertexNum 100
typedef struct ArcNode {
    int adjvex; //�û���ָ��Ķ���
    struct ArcNode *nextarc; //ָ����һ������ָ��
}ArcNode;

typedef struct VNode {
    VertexType data; //������Ϣ
    ArcNode *firstarc; //ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MaxVertexNum]; //�ڽӱ�

typedef struct {
    AdjList adjList; //�ڽӱ�
    int vexNum, arcNum; //ͼ�Ķ�����
}ALGraph;