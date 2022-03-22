#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node TREE;
struct node
{
  int val;
  TREE* left;
  TREE* right;
  int height;
};

// create avl tree
/*TREE *createNode(int val)
{
  TREE *newNode = (TREE *)malloc(sizeof(TREE));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 1;
  return newNode;
}*/



// find unbalanced node in avl tree

// balance avl tree

// print avl tree
/*void printTree(struct node* root)
{
  if (root == NULL)
  {
    return;
  }
  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);
}*/

TREE *rightRotate(TREE *Y)
{
    TREE *x = Y->left;
    TREE *T2 = X->right;
    X->right = Y;
    Y->left = T2;
    Y->height = MAX(height(Y->left), height(Y->right))+1;
    X->height = MAX(height(X->left), height(X->right))+1;
    return X;
}

TREE *leftRotate(TREE *X)
{
    TREE *Y = X->right;
    TREE *T2 = Y->left;
    Y->left = X;
    X->right = T2;
    X->height = MAX(height(x->left), height(x->right))+1;
    Y->height = MAX(height(y->left), height(y->right))+1;
    return Y;
}
int getbal(TREE *node)
{
    if(node == NULL) return 0;
    return height(node->left) - height(node->right);
}

int height(TREE *node)
{
    if(node == NULL) return 0;
    return node->height;
}

int MAX(int x, int y)
{
    if(x>y) return x;
    else return y;
}

// insert node into avl tree
TREE *insert(TREE* node, int val)
{
    if (node == NULL)
    {
        TREE* node = (TREE*)malloc(sizeof(TREE));
        node->val   = val;
        node->left   = NULL;
        node->right  = NULL;
        node->height = 1;
    }
    if(val < node->val)
    {
        node->left = insert(node->left,val);
    }
    else if (val > node->val)
    {
        node->right = insert(node->right,val);
    }
    else
    {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    int bal = getbal(node);
    if (bal > 1 && val < node->left->val)
    {
        return rightRotate(node);
    }
    if (bal < -1 && val > node->right->val)
    {
        return leftRotate(node);
    }
    if (bal > 1 && val > node->left->val)
    {
       node->left = leftRotate(node->left);
       return rightRotate(node);
    }
    if (bal < -1 && val < node->right->val)
    {
       node->right = rightRotate(node->right);
       return leftRotate(node);
    }
    return node;
}

int main()
{
    TREE *node = NULL;
    int opt,val;
    while(1)
    {
        scanf("%d",&opt);
        switch (opt)
        {
            case 1;
                scanf("%d",&val);
                node = insert(node,val);
                break;
            case 2;                
                scanf("%d",&val);
                node = delete(node,val);
                break;
            case 3;
                printf("ROOT:");
                preOrder(node);
                puts(" ");
                break;
            case 4;
                scanf("%d",&val);
                node = insertinTree(node,val);
                break;
            case 5;
                return 0;
            default:
                break;
        }
    }
}