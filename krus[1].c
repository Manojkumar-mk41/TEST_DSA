#include <stdio.h>
#include <stdlib.h>
int num, i, j, cost[10][10], n=1, min, a, b, u, v, parent[10], mincost=0, gap=1, edge[50], tree[50], edgen=0, m=0;

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if(i!=j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int display(int n, int i , int space)
{
	int j,left,right;
	if(i<n)
	{
		space=space+gap;
		left=(2*i)+1;
		right=(2*i)+2;
		display(n,right,space);
		printf("\n");
		for(j=gap;j<space;j++)
		{
			printf("\t");
		}
		printf("(%d)%c---->",edge[i], edge[i]+64);
		printf("Weight is %d\n",tree[i]);
		display(n,left,space);
	}
}

void main() {
    printf("Enter the Number of Nodes: ");
    scanf("%d", &num);
    printf("Enter the Cost of Adjacency Matrix\n");
    for(i=1; i<=num; i++) {
        for(j=1; j<=num; j++) {
            printf("Cost of [%c][%c]: ", i+64, j+64);
            scanf("%d", &cost[i][j]);
        }
    }
    printf("The Cost Adjacency Matrix is:\n");
     for(i=1; i<=num; i++) {
        for(j=1; j<=num; j++) {
            printf("%3d", cost[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    for(i=1; i<=num; i++) {
        for(j=1; j<=num; j++) {
            if(cost[i][j]==0) {
                cost[i][j] = 999;
            }
        }
    }
    while(n<num){
        for(i=1, min=999; i<=num; i++) {
            for(j=1; j<=num; j++) {
                if(cost[i][j]<min) {
                    min = cost[i][j];
                    a=u=i;
                    b = v= j;               
                }
            }
        }
        u = find(u);
        v = find(v);
        if(uni(u, v)) {
            printf("\nEdge %d: (%c, %c): Cost: %d", n++, a+64, b+64, min);
            mincost += min;
            tree[m++]=min;
			edge[edgen++]=n-1;
			display(m,0,0);
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nThe Total Minimum Cost of the Spanning Tree: %d", mincost);
}
