#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Function to enqueue (insert) an element
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory not allocated. Queue Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into the queue\n", value);
}

// Function to dequeue (delete) an element
void dequeue() {
    if(front == NULL) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted element: %d\n", front->data);
    front = front->next;
    free(temp);

    if(front == NULL)
        rear = NULL;
}

// Function to display queue elements
void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n----- Queue using Linked List -----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

