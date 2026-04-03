#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* makeTree(){
    int data;
    printf("Enter data: [enter -1 for NULL] \n");
    scanf("%d", &data);

    if(data == -1) return NULL;
    struct Node* node = createNode(data);

    printf("Enter left child of %d\n", node->data);
    node->left = makeTree();

    printf("Enter right child of %d\n", node->data);
    node->right = makeTree();

    return node;
}

void preorder(struct Node* root){
    if(root == NULL) return ;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root == NULL) return ;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root == NULL) return ;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct Node* root = NULL;
    printf("Create a Binary Tree: \n");
    root = makeTree();

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}

