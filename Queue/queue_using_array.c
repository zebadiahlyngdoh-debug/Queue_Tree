#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1,i;

// Insert element (Enqueue)
void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;

    queue[++rear] = value;
    printf("Inserted: %d\n", value);
}

// Delete element (Dequeue)
void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    front++;
}

// Display Queue
void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue Elements: ");
    for( i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

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

