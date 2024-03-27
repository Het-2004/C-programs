#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int is_full() {
    if ((rear + 1) % MAX_SIZE == front)
        return 1;
    return 0;
}

int is_empty() {
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int value) {
    if (is_full()) {
        printf("Error: Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
}

int dequeue() {
    int value;
    if (is_empty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("Enqueued all elements\n");

    int i;
    for (i = 0; i < 5; i++) {
        int dequeued = dequeue();
        if (dequeued != -1)
            printf("Dequeued element: %d\n", dequeued);
    }
    return 0;
}