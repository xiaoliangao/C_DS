#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));//Í·½áµã
    Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q) {
    return (Q.front->next == NULL);
}

void EnQueue(LinkQueue &Q, int x) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}                                                               

void DeQueue(LinkQueue &Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    }
    LinkNode *p = Q.front->next;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
}

void PrintQueue(LinkQueue Q) {
    LinkNode *p = Q.front->next;
    while (p!= NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    PrintQueue(Q);
    DeQueue(Q);
    DeQueue(Q);
    PrintQueue(Q);
    return 0;
}