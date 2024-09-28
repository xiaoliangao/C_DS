#include <stdio.h>

#define MAX_SIZE 1000

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void InitStack(Stack &s)
{
    s.top = -1;
}

bool IsEmpty(Stack s)
{
    return s.top == -1;
}

bool IsFull(Stack s)
{
    return s.top == MAX_SIZE - 1;
}

void Push(Stack &s, char c)
{
    if (IsFull(s))
    {
        printf("Stack is full\n");
        return;
    }
    s.data[++s.top] = c;
}

void Pop(Stack &s, char &c)
{
    if (IsEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    c = s.data[s.top--];
}

bool Match(char *exp)
{
    Stack s;
    InitStack(s);
    int i = 0;
    while (exp[i])
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            Push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (IsEmpty(s))
            {
                return false;
            }
            char c;
            Pop(s, c);
            if ((exp[i] == ')' && c != '(') ||
                (exp[i] == ']' && c != '[') ||
                (exp[i] == '}' && c != '{'))
            {
                return false;
            }
        }
        i++;
    }
    return IsEmpty(s);
}

int main()
{
    char exp[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (Match(exp))
    {
        printf("The expression is valid\n");
    }
    else
    {
        printf("The expression is invalid\n");
    }
    return 0;
}
