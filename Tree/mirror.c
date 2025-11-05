#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
int i;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Preorder traversal
void preOrder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Function to mirror the binary tree
void mirror(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left & right pointers
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nPreorder before mirroring: ");
    preOrder(root);

    mirror(root);

    printf("\nPreorder after mirroring: ");
    preOrder(root);

    return 0;
}

