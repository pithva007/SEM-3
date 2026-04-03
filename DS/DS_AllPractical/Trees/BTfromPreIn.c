#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int target) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == target)
            return i;
    }
    return -1;
}

struct TreeNode* buildTreeRec(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    int rootValue = preorder[*preIndex]; 
    (*preIndex)++;                       
    struct TreeNode* root = createNode(rootValue);

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, rootValue);

    root->left = buildTreeRec(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTreeRec(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int* inorder, int n) {
    int preIndex = 0;
    return buildTreeRec(preorder, inorder, 0, n - 1, &preIndex);
}

void printInorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct TreeNode* root = buildTree(preorder, inorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
