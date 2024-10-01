#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct ThreadNode {
    int data;
    struct ThreadNode* lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

//����������
void Inthread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        // �ݹ�����������������
        Inthread(p->lchild, pre);
        // ��ָ��Ϊ�գ�����ǰ������
        if (p->lchild == NULL) {
            p->lchild = pre;    // ��ǰ�ڵ����ָ��ָ��ǰ��
            p->ltag = 1;        // ���Ϊ����
        }       
        // ��ָ��Ϊ�գ�ǰ������ָ��ָ��ǰ�ڵ�
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;    // ǰ������ָ��ָ��ǰ�ڵ�
            pre->rtag = 1;      // ���Ϊ����
        }        
        // ����ǰ��Ϊ��ǰ�ڵ�
        pre = p;
        // �ݹ�����������������
        Inthread(p->rchild, pre);
    }
}

void CreateThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if(T!= NULL) {
        Inthread(T, pre);
        pre->rchild = NULL; // ���һ���ڵ����ָ���ÿ�
        pre->rtag = 1;      // ���һ���ڵ����ָ����Ϊ1
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