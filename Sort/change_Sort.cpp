#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivotpos = partition(arr, low, high);
        QuickSort(arr, low, pivotpos-1);
        QuickSort(arr, pivotpos+1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= pivot)
            high--;
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}
