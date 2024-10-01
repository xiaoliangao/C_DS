#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#define Maxsize 30
typedef char ElemType;
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
typedef struct BiTreeNode
{
	ElemType data;
	struct BiTreeNode* LChild, * RChild;
}*BiTree;
typedef struct SqStack
{
	BiTree data[Maxsize];
	int top;
}*Stack;
//����ջ
Stack InitStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(SqStack));
	S->top = -1;
	return S;
}
//ջ��
int StackEmpty(SqStack S)
{
	if (S.top == -1)return 1;
	else return 0;
}
//��ջ
void Push (Stack S,BiTree p)
{
	S->top++;
	S->data[S->top] = p;
}
//��ջ
void Pop(Stack S, BiTree* p)
{
	*p = S->data[S->top];
	S->top--;
}
BiTree CreateBiTree()
{
	char ch;
	BiTree T;
	scanf_s("%c",&ch,1);
	if (ch == '#')T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T->data = ch;
		T->LChild = CreateBiTree();
		T->RChild = CreateBiTree();
	}
	return T;
}
//�������������
void PreOrder(BiTree T)
{
	SqStack* S;
	S = InitStack();
	BiTreeNode* p;
	p = T;
	while (p|| !StackEmpty(*S))
	{
		if (p)
		{
			printf("%c",p->data);
			Push(S, p);
			p = p->LChild;
		}
		else
		{
			Pop(S, &p);
			p = p->RChild;
		}
	}
}
//�������������
void InOrder(BiTree T)
{
	SqStack* S;
	S = InitStack();
	BiTreeNode* p;
	p = T;
	while (p || !StackEmpty(*S))
	{
		if (p)
		{
			Push(S, p);
			p = p->LChild;
		}
		else
		{
			Pop(S, &p);
			printf("%c", p->data);
			p = p->RChild;
		}
	}
}
//�������
void Postorder(BiTree T)
{
	SqStack* S;
	S = InitStack();
	BiTreeNode* p;
	p = T;
	char tag[Maxsize] = {'0'};
	while (p || !StackEmpty(*S))
	{
		if (p)
		{
			Push(S, p);
			tag[S->top] = '0';//��־����Ƿ����������
			p = p->LChild;
		}
		else
		{
			while (tag[S->top] == '1') {
				Pop(S, &p);
				printf("%c",p->data);
			}
			if (S->top == -1) break;
			Pop(S, &p);
			Push(S, p);
			p = p->RChild;
			tag[S->top] = '1';
		}
		

	}
}
//��α���
void Levelorder(BiTree T)
{
	BiTree Q[Maxsize];
	int front, rear;
	if (T == NULL)return;
	front = -1;
	rear = 0;
	Q[rear] = T;
	while (front != rear)
	{
		front++;
		printf("%c",Q[front]->data);
		if (Q[front]->LChild != NULL)
		{
			rear++;
			Q[rear] = Q[front]->LChild;
		}
		if (Q[front]->RChild != NULL)
		{
			rear++;
			Q[rear] = Q[front]->RChild;
		}
	}
}
int GetHightOfTree(BiTree T)
{
	int rh = 0, lh = 0;
	if (!T)return 0;
	else
	{
		lh = GetHightOfTree(T->LChild);
		rh = GetHightOfTree(T->RChild);
		return(lh > rh ? lh : rh) + 1;
	}
}
void DisplayBinTree(BiTree T, int col, int row, int h)
{
	if (T)
	{
		gotoxy(col, row);
		printf("%c", T->data);
		DisplayBinTree(T->LChild, col - h, row + 1, h / 2);
		DisplayBinTree(T->RChild, col + h, row + 1, h / 2);
	}
}
void DisplayTree(BiTree T)
{
	int k = 0;
	k = GetHightOfTree(T);
	DisplayBinTree(T, (int)pow(2, k - 1) * 2 + 1, 4, (int)pow(2, k - 1));
	printf("\n\n\n");
}
int main()
{
	BiTree T;
	printf("����������������:\n");
	T = CreateBiTree();
	printf("��������������νṹ");
	DisplayTree(T);
	printf("\n����������\n");
	PreOrder(T);
	printf("\n����������\n");
	InOrder(T);
	printf("\n����������\n");
	Postorder(T);
	printf("\n��α������\n");
	Levelorder(T);
	return 1;
}

