#include <stdio.h>
#include <stdlib.h>

// Structure for each node
struct node {
    int data;
    struct node *next;
};

// Queue front and rear
struct node *front = NULL;
struct node *rear = NULL;

// Function to insert element into queue (Enqueue)
void enqueue(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    // If queue is empty
    if(front == NULL && rear == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp; // Current rear will point to new node
        rear = temp;       // Update rear to the new node
    }
    printf("Inserted: %d\n", value);
}

// Function to delete element from queue (Dequeue)
void dequeue() {
    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted: %d\n", temp->data);

    front = front->next;  // Move front to the next node

    if(front == NULL)     // If queue becomes empty
        rear = NULL;

    free(temp);           // Free removed node
}

// Function to display the queue
void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; // Move to next node
    }
    printf("\n");
}

// Main function for testing the queue
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}

