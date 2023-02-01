#include "stdio.h"
int GAP = 10;
int heap[50];
void swap(int *a,int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int n,int i){
    int smallest,left,right;
    smallest = i;
    left = 2*i+1;
    right = 2*i+2;
    if(left<n&&heap[left]<heap[smallest]){
        smallest = left;
    }
    if(right<n&&heap[right]<heap[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(&heap[i],&heap[smallest]);
        heapify(n,i);
    }
}
int insert(int n){
    int data;
    printf("enter the data : ");
    scanf("%d",&data);
    heap[n] = data;
    n++;
    for(int i = n/2-1;i >= 0;i--){
        heapify(n,i);
    }
    return n;
}
int sort(int n){
    int i;
    for(i = n/2-1;i >= 0;i--){
        heapify(n,i);
    }
    for(i = n-1;i > 0;i--){
        swap(&heap[i],&heap[0]);
        heapify(i,0);
    }
}
int remov(int n){
    int data,i;
    printf("enter the data : ");
    scanf("%d",&data);
    for(i = 0;i < n;i++){
        if(heap[i] == data);
        break;
    }
    if(i != n){
        swap(&heap[i],&heap[n-1]);
        n--;
        for(i = n/2-1;i >= 0;i--){
            heapify(n,i);
        }
    }
    return n;
}
void display(int n,int i,int space){
    int j,left,right;
    if(i<n){
        left = 2*i+1;
        right = 2*i+2;
        space = space + GAP;
        display(n,right,space);
        printf("\t");
        for(int i = GAP;i < space;i++){
            printf(" ");
        }
        printf("%d\n",heap[i]);
        display(n,left,space);
    }
}
void main(){
    int n = 0,choice;
    while(1){
        printf("\n1.insert\n");
        printf("2.delete\n");
        printf("3.sort\n");
        printf("enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            n = insert(n);
            display(n,0,0);
            break;
            case 2:
            n = remov(n);
            display(n,0,0);
            break;
            case 3:
            sort(n);
            display(n,0,0);
            break;
        }
    }
}