#include<stdio.h>
#include<stdlib.h>
#define n 10
int hash[n],counter=0,h=n;
int load = 7;
void Insert(int val, int h);
void display();
void init(){
    for(int i = 0; i<h; i++){
        hash[i] = -1;
    }
    display();
}

void display(){
    for(int i = 0; i<h; i++){
    printf("\n|| %d  |  %d  ||",i,hash[i]);
    }
}

void rehash(){
    printf("\nRehashing");
    int temp[h];
    for(int i =0; i<h; i++){
        temp[i] = hash[i];
        printf("\n temp[%d]-> %d", i, temp[i]);
    }
    hash[h*2];
    h=h*2;
  	load = load * 2;
    counter = 0;
    init();
    for( int i = 0; i < h/2; i++ ){
         printf("\n temp[%d]-> %d", i, temp[i]);
         if(temp[i]!= -1) Insert(temp[i],h);
         printf("\n hash[%d]-> %d", i, hash[i]);
    }
    display();
}

int hashkey(int key,int h){
    int hk;
    for(int i=0; i < h; i++){
    hk = (key + i)% h;
    if(hash[hk] == -1){
        return hk;
        break;
        }
    }
}

void Insert(int val, int h){
    int hkey;
    hkey = hashkey(val,h);
    hash[hkey] = val;
    printf("\n%d->%d",hkey, hash[hkey]);
    if(val != -1) counter++;
    printf("\nCount: %d",counter);
}

void main(){
    int choice,val;
    init();
    while(1){
        if(counter > load) {
                rehash();
                }
        printf("\n0.Exit\n1.Insert\n2.Display");
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("\nValue: ");
                scanf("%d", &val);
                Insert(val,h);
                break;
            case 2:
                display();
                break;
		}
	}
}