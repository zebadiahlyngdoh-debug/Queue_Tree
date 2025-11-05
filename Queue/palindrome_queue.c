#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1,i;

// Enqueue function
void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = val;
}

// Check Palindrome Function
bool isPalindrome() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return false;
    }

    int i = front, j = rear;
    while (i < j) {
        if (queue[i] != queue[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    int n, x;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("Queue Overflow! Max allowed = %d\n", MAX);
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for( i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    if (isPalindrome())
        printf("Queue is Palindrome ?\n");
    else
        printf("Queue is NOT Palindrome ?\n");
    
    return 0;
}

