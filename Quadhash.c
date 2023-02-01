#include<stdio.h>
#include<stdlib.h>

#define size 10
int hash[size] = {0};

void insert(){
    int i,val,index,hashkey;
    printf("\nEnter the value to insert : ");
    scanf("%d",&val);
    hashkey = val % size;
    if(hash[hashkey] == 0){
        hash[hashkey] = val;
        printf("\nInsertion is success\n");
    }
    else{
        for(i=0;i<size;i++){
            index = (hashkey+i*i) % size;
            if(hash[index] == 0){
                hash[index] = val;
                printf("\nInsertion is success\n");
                break;
            }
        }
        if(i == size){
            printf("\nInsertion cannot be done\n");
        }
    }
}

void delete(){
    int i,val;
    printf("\nEnter a value to delete : ");
    scanf("%d",&val);
    for(i=0;i<size;i++){
        if(hash[i]==val){
            hash[i]=0;
            printf("\nDeletion successful\n");
            break;
        }
    }
    if(i==size){
        printf("\nElement not found\n");
    }
}

void search(){
    int i,val;
    printf("\nEnter a value to search : ");
    scanf("%d",&val);
    for(i=0;i<size;i++){
        if(hash[i]==val){
            printf("\nElement found in hash table at index %d\n",i);
            break;
        }
    }
    if(i==size){
        printf("\nElement not found\n");
    }
}

void display(){
    int i;
    printf("\nElements in the hash table is\n");
    for(i=0;i<size;i++){
        printf("Key : %d\tElement : %d\n",i,hash[i]);
    }
}

int main(){
    int choice;
    while(1){
        printf("\n1. Insertion\n2. Deletion\n3. Search\n4. Display\n");
        printf("\nEnter a choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : insert();
                     break;

            case 2 : delete();
                     break;

            case 3 : search();
                     break;

            case 4 : display();
                     break;

            case 5 : exit(0);

            default : printf("\nEnter correct choice\n");
        }
    }
}