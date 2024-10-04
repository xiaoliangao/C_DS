#include <stdio.h>
#include <stdlib.h>
#include <stack>
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{
    int indegree;
    ArcNode *firstedge;
}VNode;
typedef struct{
    VNode *vertices;
    int vexnum, arcnum;
}Graph;

bool TopoLogicalSort(Graph G)
{
    InitStack(S);
    int i;
    for (i = 0; i < vexnum; i++)
    {
        if (indegree[i] == 0)
            Push(S, i);
    }
    int count = 0;
    while (!Isempty(S))
    {
        Pop(S, i);
        print[count++] = i;
        for(p=G.vertices[i].firstedge;p;p=p->next){
            v=p->adjvex;
            if(!(--indegree[v]))
                Push(S, v);
        }
    }
    if (count!= vexnum)
        return false;
    else
        return true;
}

