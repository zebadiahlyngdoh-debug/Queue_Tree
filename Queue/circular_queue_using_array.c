#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

// Insert element into circular queue
void enqueue(int value) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1)  // First insertion
        front = rear = 0;
    else
        rear = (rear + 1) % MAX; // Circular increment

    cqueue[rear] = value;
    printf("Inserted: %d\n", value);
}

// Delete element from circular queue
void dequeue() {
    if(front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted: %d\n", cqueue[front]);

    if(front == rear)  // Last element deleted
        front = rear = -1;
    else
        front = (front + 1) % MAX; // Circular increment
}

// Display the circular queue
void display() {
    if(front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;
    while(i != rear) {
        printf("%d ", cqueue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", cqueue[rear]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // Full
    enqueue(60);  // Overflow

    display();

    dequeue();
    dequeue();

    display();

    enqueue(70);
    enqueue(80);

    display();

    return 0;
}

