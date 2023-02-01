#include<stdio.h>
#include<stdlib.h>

int print(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[],int low,int high){
    int i,j;
    int pivot = a[high];
    i = low-1;
    for(j=low;j<high;j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

int quicksort(int a[],int lb,int ub){
    if(lb<ub){
        int piv = partition(a,lb,ub);
        quicksort(a,lb,piv-1);
        quicksort(a,piv+1,ub);
    }
}

int main(){
    int a[20],n,i;
    printf("\nEnter the no of element in array : ");
    scanf("%d",&n);
    printf("\nEnter the elements in the array : \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nUnsorted array : ");
    print(a,n);
    quicksort(a,0,n-1);
    printf("\nSorted array : ");
    print(a,n);
}