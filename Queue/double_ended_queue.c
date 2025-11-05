#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
}

void insertRear(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    if (rear == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted Front Element: %d\n", deque[front]);
    
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (rear == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted Rear Element: %d\n", deque[rear]);
    
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty!\n");
        return;
    }
    int i = front;
    printf("Deque Elements: ");
    
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", deque[rear]);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

