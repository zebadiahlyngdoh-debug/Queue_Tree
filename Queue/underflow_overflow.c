#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1,i;

void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow while inserting %d\n", value);
        return;
    }
    if(front == -1)
        front = 0;

    queue[++rear] = value;
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow while deleting\n");
        return;
    }
    front++;
}

void display() {
    if(front == -1 || front > rear) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nRemaining Queue: ");
    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main() {
    int n, i, value;
    int del;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Enter number of elements to delete: ");
    scanf("%d", &del);

    for(i = 0; i < del; i++) {
        dequeue();
    }

    display();

    return 0;
}

