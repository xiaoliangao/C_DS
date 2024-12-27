#include <iostream>
#include "change_Sort.cpp"

using namespace std;

int main()
{
    int arr[] = {5, 2, 8, 3, 9, 1};     
    QuickSort(arr, 0, 5);
    for(int i=0; i<6; i++)
        cout<<arr[i]<<" ";
    return 0;
}