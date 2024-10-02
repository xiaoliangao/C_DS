#include <stdio.h>
#include <stdlib.h>

//邻接矩阵
#define MaxVertexNum 100
typedef char VertexType; //顶点类型
typedef int EdgeType; //边的权值类型

typedef struct {
    VertexType vex[MaxVertexNum]; //顶点数组
    EdgeType edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵
    int vertexNum, edgeNum; //图的顶点数和边数
}MGraph;

//邻接表
#define MaxVertexNum 100
typedef struct ArcNode {
    int adjvex; //该弧所指向的顶点
    struct ArcNode *nextarc; //指向下一个弧的指针
}ArcNode;

typedef struct VNode {
    VertexType data; //顶点信息
    ArcNode *firstarc; //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum]; //邻接表

typedef struct {
    AdjList adjList; //邻接表
    int vexNum, arcNum; //图的顶点数
}ALGraph;