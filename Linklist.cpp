#include <stdio.h>
#include <stdlib.h>
using namespace std;

// 定义链表节点
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *LinkList;

// 初始化链表,这是带头结点的链表
bool InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    return true;
}

// //不带头结点的链表
// bool InitList(LinkList &L)
// {
//     L = NULL;
//     return true;
// }

// 求链表长度
int Lenth(LinkList L)
{
    int len = 0;
    Node *p = L;
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 按序号查找结点
Node *GetElem(LinkList L, int index)
{
    LinkList p = L;
    int i = 0;
    while (p != NULL && i < index)
    {
        p = p->next;
        i++;
    }
    return p;
}

// 按值查找结点
Node *SearchElem(LinkList L, int value)
{
    Node *p = L->next;
    while (p != NULL && p->data != value)
        p = p->next;
    return p;
}

// 插入结点
bool InsertElem(LinkList &L, int index, int value)
{
    Node *p = L;
    int i = 0;
    while (p != NULL && i < index - 1)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return false;
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = value;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除结点
bool DeleteElem(LinkList &L, int index)
{
    Node *p = L;
    int i = 0;
    while (p != NULL && i < index - 1)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return false;
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

// 头插法建立链表
LinkList HeadInsertElem(LinkList &L)
{
    InitList(L);
    int value;
    printf("请输入结点值(-1结束):\n");
    scanf("%d", &value);
    while (value != -1)
    {
        InsertElem(L, 1, value);
        scanf("%d", &value);
    }
    return L;
}

// 尾插法建立链表
LinkList TailInsertElem(LinkList &L)
{
    InitList(L);
    int value;
    Node *p, *s=L;
    printf("请输入结点值(-1结束):\n");
    scanf("%d", &value);
    while (value != -1)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = value;
        s->next = p;
        s = p;
        scanf("%d", &value);
    }
    s->next = NULL;
    return L;
}

// 打印链表
void PrintList(LinkList L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// menu
/*
1.头插法建立链表
2.尾插法建立链表
1、2只能选择其中一个进行操作，不能同时进行。
3.打印链表
4.求链表长度
5.按序号查找结点
6.按值查找结点
7.插入结点
8.删除结点
9.退出
*/
void menu(LinkList &L)
{
    int choice;
    while (true)
    {
        printf("\n");
        printf("欢迎使用链表操作系统！\n");
        printf("1.头插法建立链表\n");
        printf("2.尾插法建立链表\n");
        printf("3.打印链表\n");
        printf("4.求链表长度\n");
        printf("5.按序号查找结点\n");
        printf("6.按值查找结点\n");
        printf("7.插入结点\n");
        printf("8.删除结点\n");
        printf("9.退出\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            HeadInsertElem(L);
            break;
        case 2:
            TailInsertElem(L);
            break;
        case 3:
            PrintList(L);
            break;
        case 4:
            printf("链表长度为：%d\n", Lenth(L));
            break;
        case 5:
        {
            int index;
            printf("请输入结点序号：");
            scanf("%d", &index);
            Node *p = GetElem(L, index);
            if (p == NULL)
                printf("不存在该结点！\n");
            else
                printf("结点值为：%d\n", p->data);
        }
        break;
        case 6:
        {
            int value;
            printf("请输入结点值：");
            scanf("%d", &value);
            Node *p = SearchElem(L, value);
            if (p == NULL)
                printf("不存在该结点！\n");
            else
                printf("结点序号为：%d\n", Lenth(L) - Lenth(p));
        }
        break;
        case 7:
        {
            int index, value;
            printf("请输入结点序号：");
            scanf("%d", &index);
            printf("请输入结点值：");
            scanf("%d", &value);
            InsertElem(L, index, value);
        }
        break;
        case 8:
        {
            int index;
            printf("请输入结点序号：");
            scanf("%d", &index);
            DeleteElem(L, index);
        }
        break;
        case 9:
            break;
        default:
            printf("输入错误！\n");
            break;
        }
    }
}

int main()
{
    LinkList L;
    menu(L);
    return 0;
}