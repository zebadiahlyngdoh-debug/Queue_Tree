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

// Insert node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value in BST
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Find maximum value in BST
int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
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

    printf("\nMinimum value in BST = %d\n", findMin(root));
    printf("Maximum value in BST = %d\n", findMax(root));

    return 0;
}

