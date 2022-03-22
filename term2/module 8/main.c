#include <stdio.h>
#include <stdlib.h>

//Create a binary search tree with the input given by the user\

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct tree {
    node *root;
} tree;

//create a binary search tree
tree *create_tree() {
    tree *t = (tree *)malloc(sizeof(tree));
    t->root = NULL;
    return t;
}

//right rotation
node *right_rotate(node *root) {
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

//left rotation
node *left_rotate(node *root) {
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

//insert a node in the tree
node *insert(node *root, int data) {
    if (root == NULL) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
        if (root->left->data - root->data > 1) {
            if (root->left->left->data - root->data > 0) {
                root = right_rotate(root);
            } else {
                root->left = left_rotate(root->left);
                root = right_rotate(root);
            }
        }
    } else {
        root->right = insert(root->right, data);
        if (root->data - root->right->data > 1) {
            if (root->right->right->data - root->data > 0) {
                root = left_rotate(root);
            } else {
                root->right = right_rotate(root->right);
                root = left_rotate(root);
            }
        }
    }
    return root;
}

//print the tree in inorder
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//print the tree in preorder
void preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//print the tree in postorder
void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

//main function
int main() {
    tree *t = create_tree();
    int data;
//if data != "-" then exit input loop
    while (1) {
        printf("Enter the data: ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        t->root = insert(t->root, data);
    }
    printf("\nInorder traversal of the tree is: ");
    inorder(t->root);
    printf("\nPreorder traversal of the tree is: ");
    preorder(t->root);
    printf("\nPostorder traversal of the tree is: ");
    postorder(t->root);
    return 0;
}

/* 
1
2
3
4
5
6
7
8
9
0
1
2
3
4
5
6
7
8
9
0
-1
 */