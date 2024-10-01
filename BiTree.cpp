#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;    
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T);
void printBiTree(BiTree T);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

int main(){
    BiTree T;
    CreateBiTree(T);
    printf("PreOrder:\n");
    PreOrder(T);
    printf("\nInOrder:\n");
    InOrder(T);
    printf("\nPostOrder:\n");
    PostOrder(T);
    return 0;
}

void CreateBiTree(BiTree &T)
{
    int data;
    printf("请输入二叉树的结点数据(输入-1表示结束)：");  //输入根结点数据
    scanf("%d", &data);
    if(data == -1)
    {
        T = NULL;
        return;
    }
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = data;
    printf("创建%d的左子树\n", data);
    CreateBiTree(T->lchild);
    printf("创建%d的右子树\n", data);
    CreateBiTree(T->rchild);
}

void visit(BiTree T)
{
    if (T == NULL)
    {
        printf("空树\n");
        return;
    }
    printf("%d ", T->data);
}

void PreOrder(BiTree T)
{
    if( T!= NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if( T!= NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if( T!= NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}