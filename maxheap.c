#include <stdio.h>
int heap[50];
int GAP=1;
void swap(int *a,int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}
void heapify(int n,int i)
{
	int largest,left,right;
    largest=i;
    left=(2*i)+1;
    right=(2*i)+2;
    if (left<n&&heap[left]>heap[largest])
    	largest=left;
    if (right<n&&heap[right]>heap[largest])
    	largest=right;
    if (largest!=i)
    {
    	swap(&heap[i],&heap[largest]);
    	heapify(n,largest);
    }
}
int insert(int n)
{
	int node,i;
	printf("\nEnter the node: ");
	scanf("%d",&node);
    heap[n]=node;
    n++;
    for(i=n/2-1;i>=0;i--)
    	heapify(n,i);
    
    return n;
}
int remov(int n)
{
	int node,i;
	printf("\nEnter the node: ");
	scanf("%d",&node);
	for(i=0;i<n;i++)
	{
		if(heap[i]==node)
			break;
	}
	if(i!=n)
	{
		swap(&heap[i],&heap[n-1]);
		n--;
		for(i=n/2-1;i>=0;i--)
    		heapify(n,i);
	}
    return n;
}
int sort(int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
    	heapify(n,i);
    for(i=n-1;i>0;i--)
    {
    	swap(&heap[i],&heap[0]);
    	heapify(i,0);
	}
}
void display(int n,int i,int space)
{
	int j,left,right;
    if(i<n) 
    {
        space=space+GAP;
        left=(2*i)+1;
        right=(2*i)+2;
        display(n,right,space);
        printf("\n");
        for(j=GAP;j<space;j++)
            printf("\t");
        printf("%d\n",heap[i]);
        display(n,left,space);
    }
}
void main()
{
	printf("Max Heap Implementation");
    int choice,n=0;
    printf("\n1.Insert\t2.Delete\t3.Sort\t4.End");
    do
    {
    	printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: n=insert(n);
					display(n,0,0);
					break;
			case 2: n=remov(n);
					display(n,0,0);
					break;
			case 3: sort(n);
					display(n,0,0);
					break;
			case 4: printf("\nThank You");
					break;
			default:printf("\nInvalid Choice");
		}
	}while(choice!=4);
}