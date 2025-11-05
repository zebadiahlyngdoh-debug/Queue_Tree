#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in level-order (Binary Tree)
struct Node* insert(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    if (root == NULL)
        return newNode;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

// Count leaf nodes
int countLeaf(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Count non-leaf nodes
int countNonLeaf(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nTotal Leaf Nodes: %d\n", countLeaf(root));
    printf("Total Non-Leaf Nodes: %d\n", countNonLeaf(root));

    return 0;
}

