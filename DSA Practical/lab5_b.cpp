#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree function
Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return NULL;

    // Pick current node from preorder
    int current = preorder[preIndex++];
    Node* node = new Node(current);

    // If node has no children
    if (inStart == inEnd) return node;

    // Find the index of this node in inorder
    int pos = inMap[current];

    // Recursively construct left and right subtrees
    node->left = buildTree(preorder, inorder, inStart, pos - 1, preIndex, inMap);
    node->right = buildTree(preorder, inorder, pos + 1, inEnd, preIndex, inMap);

    return node;
}

// To verify tree, we print postorder
void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int preorder[n], inorder[n];
    unordered_map<int, int> inMap;

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++) cin >> preorder[i];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inMap[inorder[i]] = i;
    }

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n - 1, preIndex, inMap);

    cout << "Postorder traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
