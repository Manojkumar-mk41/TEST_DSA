#include<stdio.h>
#include<stdlib.h>

int printarr(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int insertsort(int arr[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
    arr[j+1]=temp;
    }
}

void main(){
    int arr[20],n,i;
    printf("\nEnter the no of terms in the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements in the array : \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nUnsorted array using insertion sort : ");
    printarr(arr,n);
    insertsort(arr,n);
    printf("\nSorted array using insertion sort : ");
    printarr(arr,n);
}