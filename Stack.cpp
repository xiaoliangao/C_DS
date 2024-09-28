#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MaxSize 100

typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack &S, int x)
{
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, int &x)
{
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

void PrintStack(SqStack S)
{
    for (int i = S.top; i >= 0; i--)
    {
        printf("%d ", S.data[i]);
    }
    printf("\n");
}

void menu(SqStack &S)
{
    int choice;
    InitStack(S);
    while (true)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. GetTop\n");
        printf("4. PrintStack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter the element to be pushed: ");
            scanf("%d", &x);
            if (Push(S, x))
            {
                printf("Element pushed successfully.\n");
            }
            else
            {
                printf("Stack overflow.\n");
            }
            break;
        }
        case 2:
        {
            int x;
            if (Pop(S, x))
            {
                printf("Element popped: %d\n", x);
            }
            else
            {
                printf("Stack underflow.\n");
            }
            break;
        }
        case 3:
        {
            int x;
            if (GetTop(S, x))
            {
                printf("Top element: %d\n", x);
            }
            else
            {
                printf("Stack is empty.\n");
            }
            break;
        }
        case 4:
        {
            PrintStack(S);
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Invalid choice.\n");
            break;
        }
        }
    }
}

int main()
{
    SqStack S;
    menu(S);
    return 0;
}