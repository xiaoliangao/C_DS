#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int UFSets[SIZE];

void Initial(int S[])
{
    for(int i=0;i<SIZE;i++)
        S[i]=-1;
}

int Find(int S[],int x)
{
    int root=x;
    while(S[root]>=0)
        root=S[root];
    while(x!=root)
    {
        int temp=S[x];
        S[x]=root;
        x=temp;
    }
    return root;
}

void Union(int S[],int root1,int root2)
{
    if(root1==root2)
        return;
    if(S[root2]>S[root1])
    {
        S[root1]+=S[root2];
        S[root2]=root1;
    }else{
        S[root2]+=S[root1];
        S[root1]=root2;
    }
}