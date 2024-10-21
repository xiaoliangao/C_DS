#include <stdio.h>
#include <stdlib.h>

void direct_insert_sort(int arr[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            arr[0] = arr[i];
            for (j = i - 1; arr[0] < arr[j]; --j)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = arr[0];
        }
    }
}
//ÕÛ°ë²åÈëÅÅÐò
void binary_insert_sort(int arr[], int n)
{
    int i, j, low, high, mid;
    for(i = 2; i <= n; i++)
    {
        arr[0] = arr[i];
        low = 1;
        high = i - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(arr[mid]>arr[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for(j = i - 1; j >= high + 1; --j)
            arr[j + 1] = arr[j];
        arr[high + 1] = arr[0];
    }
}

void Shell_sort(int arr[], int n)
{
    int dk, i, j;
    for(dk = n / 2; dk > 0; dk /= 2)
    {
        for(i = dk + 1; i <= n; ++i)
        {
            if(arr[i] < arr[i - dk])
            {
                arr[0] = arr[i];
                for(j = i-dk; j>0&&arr[0]<arr[j]; j=j-dk)
                {
                    arr[j+dk] = arr[j];
                }
                arr[j+dk] = arr[0];
            }
        }
    }
}