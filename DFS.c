#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform DFS traversal of a tree (preorder)
void dfs_preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data); // Visit the node
    dfs_preorder(root->left);  // Traverse left subtree
    dfs_preorder(root->right); // Traverse right subtree
}

// Function to perform DFS traversal of a tree (inorder)
void dfs_inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    dfs_inorder(root->left);   // Traverse left subtree
    printf("%d ", root->data); // Visit the node
    dfs_inorder(root->right);  // Traverse right subtree
}

// Function to perform DFS traversal of a tree (postorder)
void dfs_postorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    dfs_postorder(root->left);  // Traverse left subtree
    dfs_postorder(root->right); // Traverse right subtree
    printf("%d ", root->data);  // Visit the node
}

// Sample usage
int main() {
    // Constructing a sample tree
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);

    // Perform DFS traversal (preorder)
    printf("DFS preorder traversal of the tree: ");
    dfs_preorder(root);
    printf("\n");

    // Perform DFS traversal (inorder)
    printf("DFS inorder traversal of the tree: ");
    dfs_inorder(root);
    printf("\n");

    // Perform DFS traversal (postorder)
    printf("DFS postorder traversal of the tree: ");
    dfs_postorder(root);
    printf("\n");

    return 0;
}
