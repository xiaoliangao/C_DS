#include <stdio.h>
#include <stdlib.h>
#define InitSize 100
using namespace std;

typedef struct{
    int *data;
    int Maxsize,Length;
}SeqList;

//��ʼ��˳���
void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.Maxsize = InitSize;
    L.Length = 0;
}

//˳������Ԫ��
bool InsertList(SeqList &L,int i,int e)
{
    if(i<1 || i>L.Length+1)
        return false;
    if(L.Length >= L.Maxsize)
    {
      return false;
    }
    for(int j = L.Length; j>=i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.Length++;
    return true;
}

//˳���ɾ��Ԫ��
bool DeleteList(SeqList &L,int i,int &e)
{
    if(i < 1 || i > L.Length + 1)
        return false;
    e = L.data[i-1];
    for(int j = i; j<L.Length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.Length--;
    return true;
}

//��ֵ����
int LocateElem(SeqList L,int e)
{
    for(int i = 0; i<L.Length; i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}

int Length(SeqList L)
{
    return L.Length;
}

int GetElem(SeqList L,int i)
{
    for(int j = 0; j<L.Length; j++)
    {
        if(j+1 == i)
            return L.data[j];
    }
    return 0;
}

//���˳���
void PrintList(SeqList L)
{
    for(int i = 0; i<L.Length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}

//����˳���
void createList(SeqList &L)
{
    int e;
    printf("������˳����Ԫ��(����-1����):\n");
    InitList(L);
    while(true)
    {
        scanf("%d",&e);
        if(e == -1)
            break;
        InsertList(L,L.Length+1,e);
    }
}

//����sqlist
void Console(SeqList &L)
{
    int i,e;
    while(true)
    {
        printf("0.����˳���\n");
        printf("1.����Ԫ��\n");
        printf("2.ɾ��Ԫ��\n");
        printf("3.����Ԫ��\n");
        printf("4.���˳���\n");
        printf("5.��ȡԪ��\n");
        printf("6.����\n");
        printf("7.�˳�\n");
        printf("������ѡ��:");
        scanf("%d",&i);
        switch(i)
        {        
            case 0:
                createList(L);
                break;
            case 1:
                printf("���������λ��:");
                scanf("%d",&i);
                printf("���������Ԫ��:");
                scanf("%d",&e);
                InsertList(L,i,e);
                break;
            case 2:
                printf("������ɾ��λ��:");
                scanf("%d",&i);
                DeleteList(L,i,e);
                printf("ɾ����Ԫ��Ϊ:%d\n",e);
                break;
            case 3:
                printf("���������Ԫ��:");
                scanf("%d",&e);
                i = LocateElem(L,e);
                if(i == 0)
                    printf("Ԫ�ز�����\n");
                else
                    printf("Ԫ��λ��Ϊ:%d\n",i);
                break;
            case 4:
                PrintList(L);
                break;
            case 5:
                printf("�������ȡԪ��λ��:");
                scanf("%d",&i);
                e = GetElem(L,i);
                printf("Ԫ��Ϊ:%d\n",e);
                break;
            case 6:
                printf("˳�����Ϊ:%d\n",Length(L));
                break;
            case 7:
                exit(0);
            default:
                printf("�������,����������\n");
        }
    }
}

int main()
{
    SeqList L;
    Console(L);
    return 0;
}