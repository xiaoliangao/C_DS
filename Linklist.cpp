#include <stdio.h>
#include <stdlib.h>
using namespace std;

// ��������ڵ�
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *LinkList;

// ��ʼ������,���Ǵ�ͷ��������
bool InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    return true;
}

// //����ͷ��������
// bool InitList(LinkList &L)
// {
//     L = NULL;
//     return true;
// }

// ��������
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

// ����Ų��ҽ��
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

// ��ֵ���ҽ��
Node *SearchElem(LinkList L, int value)
{
    Node *p = L->next;
    while (p != NULL && p->data != value)
        p = p->next;
    return p;
}

// ������
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

// ɾ�����
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

// ͷ�巨��������
LinkList HeadInsertElem(LinkList &L)
{
    InitList(L);
    int value;
    printf("��������ֵ(-1����):\n");
    scanf("%d", &value);
    while (value != -1)
    {
        InsertElem(L, 1, value);
        scanf("%d", &value);
    }
    return L;
}

// β�巨��������
LinkList TailInsertElem(LinkList &L)
{
    InitList(L);
    int value;
    Node *p, *s=L;
    printf("��������ֵ(-1����):\n");
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

// ��ӡ����
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
1.ͷ�巨��������
2.β�巨��������
1��2ֻ��ѡ������һ�����в���������ͬʱ���С�
3.��ӡ����
4.��������
5.����Ų��ҽ��
6.��ֵ���ҽ��
7.������
8.ɾ�����
9.�˳�
*/
void menu(LinkList &L)
{
    int choice;
    while (true)
    {
        printf("\n");
        printf("��ӭʹ���������ϵͳ��\n");
        printf("1.ͷ�巨��������\n");
        printf("2.β�巨��������\n");
        printf("3.��ӡ����\n");
        printf("4.��������\n");
        printf("5.����Ų��ҽ��\n");
        printf("6.��ֵ���ҽ��\n");
        printf("7.������\n");
        printf("8.ɾ�����\n");
        printf("9.�˳�\n");
        printf("����������ѡ��");
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
            printf("������Ϊ��%d\n", Lenth(L));
            break;
        case 5:
        {
            int index;
            printf("����������ţ�");
            scanf("%d", &index);
            Node *p = GetElem(L, index);
            if (p == NULL)
                printf("�����ڸý�㣡\n");
            else
                printf("���ֵΪ��%d\n", p->data);
        }
        break;
        case 6:
        {
            int value;
            printf("��������ֵ��");
            scanf("%d", &value);
            Node *p = SearchElem(L, value);
            if (p == NULL)
                printf("�����ڸý�㣡\n");
            else
                printf("������Ϊ��%d\n", Lenth(L) - Lenth(p));
        }
        break;
        case 7:
        {
            int index, value;
            printf("����������ţ�");
            scanf("%d", &index);
            printf("��������ֵ��");
            scanf("%d", &value);
            InsertElem(L, index, value);
        }
        break;
        case 8:
        {
            int index;
            printf("����������ţ�");
            scanf("%d", &index);
            DeleteElem(L, index);
        }
        break;
        case 9:
            break;
        default:
            printf("�������\n");
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