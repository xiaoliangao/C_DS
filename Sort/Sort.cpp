#include <stdio.h>
#include <stdlib.h>

int n;
int *B = (int *)malloc((n+1)*sizeof(int));

void merge(int A[],int low,int mid,int high){
    int i,j,k;
    for(k=low;k<=high;k++)
        B[k]=A[k];  //将A数组拷贝到B数组
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)
        if(B[i]<=B[j])
            A[k]=B[i++];
        else
            A[k]=B[j++];
    while(i<=mid)
        A[k++]=B[i++];
    while(j<=high)
        A[k++]=B[j++];
}

void mergeSort(int A[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

void CountSort(int A[],int B[],int n,int k){
    int i,C[k];
    for(i=0;i<k;i++)
        C[i]=0;
    for(i=0;i<n;i++)
        C[A[i]]++;
    for(i=1;i<k;i++)
        C[i]+=C[i-1];
    for(i=n-1;i>=0;i--){
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
}