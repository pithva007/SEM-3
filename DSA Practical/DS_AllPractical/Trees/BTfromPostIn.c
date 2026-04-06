#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int target) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == target)
            return i;
    }
    return -1;
}

struct Node* buildtreeRec(int* postorder, int* inorder, int start, int end, int* postIdx) {
    if(start>end)
        return NULL;

    int rootValue = postorder[(*postIdx)--];
    struct Node* root = createNode(rootValue);

    if (start==end) return root;

    int inIdx = findIndex(inorder, start, end, rootValue);

    root->right = buildtreeRec(postorder, inorder, inIdx+1, end, postIdx);
    root->left = buildtreeRec(postorder, inorder, start, inIdx-1, postIdx);

    return root;
}

struct Node* buildTree(int* postorder, int* inorder, int n){
    int postIdx = n-1;
    return buildtreeRec(postorder, inorder, 0, n-1, &postIdx);
}

void printInorder(struct Node* root){
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
}

void printPostorder(struct Node* root){
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->value);
}

int main() {
    int n;
    scanf("%d", &n);

    int postorder[n], inorder[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &postorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(postorder, inorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);
    printf("\n");

    printf("Postorder of constructed tree: ");
    printPostorder(root);
    printf("\n");

    return 0;
}
