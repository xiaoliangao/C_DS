#include <stdio.h>
#include <stdlib.h>
#define InitSize 100
using namespace std;

typedef struct{
    int *data;
    int Maxsize,Length;
}SeqList;

//初始化顺序表
void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.Maxsize = InitSize;
    L.Length = 0;
}

//顺序表插入元素
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

//顺序表删除元素
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

//按值查找
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

//输出顺序表
void PrintList(SeqList L)
{
    for(int i = 0; i<L.Length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}

//建立顺序表
void createList(SeqList &L)
{
    int e;
    printf("请输入顺序表的元素(输入-1结束):\n");
    InitList(L);
    while(true)
    {
        scanf("%d",&e);
        if(e == -1)
            break;
        InsertList(L,L.Length+1,e);
    }
}

//控制sqlist
void Console(SeqList &L)
{
    int i,e;
    while(true)
    {
        printf("0.创建顺序表\n");
        printf("1.插入元素\n");
        printf("2.删除元素\n");
        printf("3.查找元素\n");
        printf("4.输出顺序表\n");
        printf("5.获取元素\n");
        printf("6.长度\n");
        printf("7.退出\n");
        printf("请输入选项:");
        scanf("%d",&i);
        switch(i)
        {        
            case 0:
                createList(L);
                break;
            case 1:
                printf("请输入插入位置:");
                scanf("%d",&i);
                printf("请输入插入元素:");
                scanf("%d",&e);
                InsertList(L,i,e);
                break;
            case 2:
                printf("请输入删除位置:");
                scanf("%d",&i);
                DeleteList(L,i,e);
                printf("删除的元素为:%d\n",e);
                break;
            case 3:
                printf("请输入查找元素:");
                scanf("%d",&e);
                i = LocateElem(L,e);
                if(i == 0)
                    printf("元素不存在\n");
                else
                    printf("元素位置为:%d\n",i);
                break;
            case 4:
                PrintList(L);
                break;
            case 5:
                printf("请输入获取元素位置:");
                scanf("%d",&i);
                e = GetElem(L,i);
                printf("元素为:%d\n",e);
                break;
            case 6:
                printf("顺序表长度为:%d\n",Length(L));
                break;
            case 7:
                exit(0);
            default:
                printf("输入错误,请重新输入\n");
        }
    }
}

int main()
{
    SeqList L;
    Console(L);
    return 0;
}