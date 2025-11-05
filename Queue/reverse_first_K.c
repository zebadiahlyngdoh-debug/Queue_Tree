#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1,i;

// Enqueue
void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1)
        front = 0;
    queue[++rear] = value;
}

// Dequeue
int dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return queue[front++];
}

// Display queue
void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for( i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Reverse first K elements
void reverseK(int k) {
    if(front == -1 || k > (rear - front + 1) || k <= 0) {
        printf("Invalid K value!\n");
        return;
    }

    int stack[MAX];
    int top = -1;

    // Push first K elements to stack
    for( i = 0; i < k; i++)
        stack[++top] = dequeue();

    // Pop from stack back to queue
    while(top != -1)
        enqueue(stack[top--]);

    // Move remaining elements to back
    int size = rear - front + 1 - (k);
    for( i = 0; i < size; i++)
        enqueue(dequeue());
}

int main() {
    int n, value, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for( i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("\nOriginal ");
    display();

    printf("Enter K value to reverse first K elements: ");
    scanf("%d", &k);

    reverseK(k);

    printf("After reversing first %d elements:\n", k);
    display();

    return 0;
}

