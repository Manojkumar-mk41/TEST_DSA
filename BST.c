#include<stdio.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst* left;
    struct bst* right;
};

typedef struct bst node;
node* root = NULL;
node* temp;

node* createNode(int key){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insertNode(node* root,int val){
    if(root==NULL) return createNode(val);
    if(val<=root->data) root->left = insertNode(root->left,val);
    else if(val>root->data) root->right = insertNode(root->right,val);
    return root;
}

int minRight(node* nod){
    temp = nod->left;
    while(nod!=NULL){
        nod = nod->left;
    }
    return nod->data;
}

node* deleteNode(node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data>val){
        root->left = deleteNode(root->left,val);
    }
    else if(root->data<val){
        root->right = deleteNode(root->right,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->right==NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else{
            int rightMin = minRight(root->right);
            root->data = rightMin;
            root->right = deleteNode(root->right,rightMin);
        }
    }
    return root;
}

node* preorder(node* root){
    if(root==NULL) return root;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

node* inorder(node* root){
    if(root==NULL) return root;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

node* postorder(node* root){
    if(root==NULL) return root;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

node* searchNode(node* root,int val){
    if(root==NULL) return 0;
    if(root->data==val) return root;
    else if(root->data>val) root->left = searchNode(root->left,val);
    else if(root->data<val) root->right = searchNode(root->right,val);
}

int main(){
    int choice,val;
    printf("\nBINARY SEARCH TREE\n");
    while(1){
        printf("\n1. Insertion\n2. Deletion\n3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n5. Postorder Traversal\n6. Seach\n");
        printf("\nEnter a choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\nEnter a value : ");
                     scanf("%d",&val);
                     root = insertNode(root,val);
                     printf("\nInsertion successful\n");
                     break;

            case 2 : if(root==NULL){
                        printf("\nTree is empty\n");
                     }
                     else{
                        printf("\nEnter a value to delete : ");
                        scanf("%d",&val);
                        root = deleteNode(root,val);
                     }
                     break;

            case 3 : if(root==NULL){
                        printf("\nTree is empty\n");
                     }
                     else inorder(root);
                     break;
            
            case 4 : if(root==NULL){
                        printf("\nTree is empty\n");
                     }
                     else preorder(root);
                     break;

            case 5 : if(root==NULL){
                        printf("\nTree is empty\n");
                     }
                     else postorder(root);
                     break;

            case 6 : if(root==NULL){
                        printf("\nTree is empty\n");
                     }
                     else{
                        printf("\nEnter an value to search : ");
                        scanf("%d",&val);
                        temp = searchNode(root,val);
                        if(temp==0) printf("\nNode with value not found in the tree\n");
                        else printf("\nNode with value is found in the tree\n");
                     }
                     break;
                     
            case 7 : printf("\nThank you\n");
                     exit(0);

            default : printf("\nEnter a correct choice : ");
        }
    }
}