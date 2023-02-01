#include<stdio.h>
#include<stdlib.h>

void dijkstra(int n,int s,int dist[],int cost[][10]){
    int i,v,count=1,min,visited[10];
    for(i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    visited[s]=1;
    dist[s]=0;
    while(count<=n){
        min=999;
        for(i=1;i<=n;i++){
           if(dist[i]<min && visited[i]==0){
               min=dist[i];
               v=i;
           } 
        }
        visited[v]=1;
        count++;
        for(i=1;i<=n;i++){
            if(dist[i]>dist[v]+cost[v][i]){
                dist[i]=dist[v]+cost[v][i];
            }
        }
    }
}

int main(){
    int i,j,n,s,d,dist[10],cost[10][10];
    printf("\nEnter the no of nodes : ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("Cost matrix[%d][%d] : ",i,j);
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    printf("\nEnter the source node : ");
    scanf("%d",&s);
    printf("\nEnter the destination node : ");
    scanf("%d",&d);
    dijkstra(n,s,dist,cost);
    printf("\nShortest path for source node %d is ",s);
    for(i=1;i<=n;i++){
        if(s!=i && d==i){
            printf("\n%d -> %d = %d",s,i,dist[i]);
        }
    }
    return 0;
}