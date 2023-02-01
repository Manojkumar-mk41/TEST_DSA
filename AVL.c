// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>
#define size 10

// Create Node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};
struct Node *root=NULL;

int max(int a, int b);

// Calculate height
int height(struct Node *N) {
  if (N == NULL)
    return -1;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *root) {
  if (root == NULL)
    return 0;
  return height(root->left) - height(root->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void print2D(struct Node*root,int count)
{
    if(root==NULL)
    {
        return;
    }
    count+=size;
    print2D(root->right,count);
    printf("\n");
    for(int i=size;i<count;i++)
    {
        printf(" ");
    }      
    printf("%d\n",root->key);
    print2D(root->left,count);

}

int main()
{
    int user_choice, data;
    char user_continue = 'y';
    
    struct Node* result=NULL;
 
    while (user_continue == 'y' || user_continue == 'Y')
    {
        printf("\n\n------- AVL TREE --------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder");
        printf("\n5. print2D");
        printf("\n6. exit");
        
 
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &user_choice);
 
        switch(user_choice)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                
                break;
 
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
 
            /*case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result == NULL)
                {
                    printf("\nNode not found!");
                }
                else
                {
                    printf("\n Node found");
                }
                break;*/
            case 4:
                printPreOrder(root);
                printf("%d",height(root));
                break;
            case 5:
            {
                print2D(root,0);
                break;
            }
 
       
 
            case 6:
                printf("\n\tProgram Terminated\n");
                return 1;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
 
        printf("\n\nDo you want to continue? ");
        scanf(" %c", &user_continue);
    }
 
    return 0;
}