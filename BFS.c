#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct QueueNode* createQueueNode(struct TreeNode* treeNode) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* treeNode) {
    struct QueueNode* newNode = createQueueNode(treeNode);
    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

struct TreeNode* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL)
        return NULL;

    struct QueueNode* temp = *front;
    struct TreeNode* treeNode = (*front)->treeNode;

    if (*front == *rear)
        *rear = NULL;

    *front = (*front)->next;
    free(temp);

    return treeNode;
}

void bfs(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, root);

    while (front != NULL) {
        struct TreeNode* currentNode = dequeue(&front, &rear);
        printf("%d ", currentNode->data);

        if (currentNode->left != NULL)
            enqueue(&front, &rear, currentNode->left);
        if (currentNode->right != NULL)
            enqueue(&front, &rear, currentNode->right);
    }
}

int main() {
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);

    // Perform BFS traversal
    printf("BFS traversal of the tree: ");
    bfs(root);
    printf("\n");

    return 0;
}
