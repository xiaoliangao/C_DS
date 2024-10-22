#include <stdio.h>
#include <stdlib.h>

void SelectSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        if(min!= i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

//建立大根堆
void BuildMaxHeap(int arr[], int n)
{
    for(int i=n/2; i>0; i--)
    {
        HeadAdjust(arr, i, n);
    }
}

void HeadAdjust(int arr[], int k, int n)
{
    arr[0] = arr[k];
    for(int i=2*k; i<=n; i*=2)
    {
        if(i<n && arr[i]<arr[i+1])
            i++;
        if(arr[0]>=arr[i])
            break;
        else{
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}

//堆排序
void HeapSort(int arr[], int n)
{
    BuildMaxHeap(arr, n);
    for(int i=n; i>=2; i--){
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        HeadAdjust(arr, 1, i-1);
    }
}