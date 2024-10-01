#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct ThreadNode {
    int data;
    struct ThreadNode* lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

//中序线索化
void Inthread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        // 递归左子树进行线索化
        Inthread(p->lchild, pre);
        // 左指针为空，建立前驱线索
        if (p->lchild == NULL) {
            p->lchild = pre;    // 当前节点的左指针指向前驱
            p->ltag = 1;        // 标记为线索
        }       
        // 右指针为空，前驱的右指针指向当前节点
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;    // 前驱的右指针指向当前节点
            pre->rtag = 1;      // 标记为线索
        }        
        // 更新前驱为当前节点
        pre = p;
        // 递归右子树进行线索化
        Inthread(p->rchild, pre);
    }
}

void CreateThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if(T!= NULL) {
        Inthread(T, pre);
        pre->rchild = NULL; // 最后一个节点的右指针置空
        pre->rtag = 1;      // 最后一个节点的右指针标记为1
    }
}

ThreadNode *Firstnode(ThreadNode *p)
{
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}

ThreadNode *Nextnode(ThreadNode *p)
{
    if(p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;
}

void Inorder(ThreadNode *T)
{
    for(ThreadNode *p = Firstnode(T); p!= NULL; p = Nextnode(p))
        printf("%d ", p->data);
    printf("\n");
}