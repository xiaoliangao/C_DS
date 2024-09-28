#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX_SIZE 50

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, int x) {
    if((Q.rear+1)%MAX_SIZE == Q.front)
        return false;
    else {
        Q.rear = (Q.rear+1)%MAX_SIZE;
        Q.data[Q.rear] = x;
        return true;
    }
}

bool DeQueue(SqQueue &Q, int &x) {
    if(Q.front == Q.rear)
        return false;
    else {
        x = Q.data[Q.front];
        Q.front = (Q.front+1)%MAX_SIZE;
        return true;
    }
}

void PrintQueue(SqQueue Q) {
    int i;
    if(isEmpty(Q))
        printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for(i=Q.front; i!=Q.rear; i=(i+1)%MAX_SIZE)
            printf("%d ", Q.data[i]);
        printf("%d\n", Q.data[Q.rear]);
    }
}

int main() {
    SqQueue Q;
    int x, choice;
    InitQueue(Q);
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &x);
                if(EnQueue(Q, x))
                    printf("Element enqueued successfully.\n");
                else
                    printf("Queue is full.\n");
                break;
            case 2:
                if(DeQueue(Q, x))
                    printf("Element dequeued: %d\n", x);
                else
                    printf("Queue is empty.\n");
                break;
            case 3:
                PrintQueue(Q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!=4);
    return 0;
}