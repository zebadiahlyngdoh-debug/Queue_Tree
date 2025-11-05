#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

// Insert by priority (higher priority first)
void enqueue(int value, int priority) {
    struct node *temp, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->priority = priority;
    temp->next = NULL;

    // If queue is empty or new node has higher priority than front
    if(front == NULL || priority > front->priority) {
        temp->next = front;
        front = temp;
    } else {
        q = front;
        while(q->next != NULL && q->next->priority >= priority) {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
    }
    printf("Inserted: %d (Priority: %d)\n", value, priority);
}

// Remove highest priority element
void dequeue() {
    if(front == NULL) {
        printf("Priority Queue Underflow!\n");
        return;
    }
    struct node *temp = front;
    printf("Deleted: %d (Priority: %d)\n", front->data, front->priority);
    front = front->next;
    free(temp);
}

// Display queue
void display() {
    if(front == NULL) {
        printf("Priority Queue is Empty!\n");
        return;
    }
    
    struct node *temp = front;
    printf("Priority Queue: ");
    while(temp != NULL) {
        printf("%d(%d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(30, 2);
    enqueue(10, 5);
    enqueue(50, 1);
    enqueue(20, 4);

    display();

    dequeue();
    display();

    enqueue(40, 6);
    display();

    return 0;
}

