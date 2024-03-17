#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void dfs_preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data); 
    dfs_preorder(root->left);  
    dfs_preorder(root->right); 
}

void dfs_inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    dfs_inorder(root->left);   
    printf("%d ", root->data); 
    dfs_inorder(root->right);  
}
void dfs_postorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    dfs_postorder(root->left); 
    dfs_postorder(root->right); 
    printf("%d ", root->data);
}

int main() {
    
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);
    
    printf("DFS preorder traversal of the tree: ");
    dfs_preorder(root);
    printf("\n");

    printf("DFS inorder traversal of the tree: ");
    dfs_inorder(root);
    printf("\n");

    printf("DFS postorder traversal of the tree: ");
    dfs_postorder(root);
    printf("\n");

    return 0;
}
