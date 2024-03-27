#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull() {
    return rear == SIZE - 1;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1 || rear == -1;
}

// Insert an element into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = value;
    printf("Inserted %d\n", value);
}

// Remove and return the first element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot remove\n");
        return -1;
    }

    int value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }

    printf("Removed %d\n", value);
    return value;
}

// Return the first element of the queue without removing it
int frontValue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot get front value\n");
        return -1;
    }

    return queue[front];
}

// Return the last element of the queue without removing it
int rearValue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot get rear value\n");
        return -1;
    }

    return queue[rear];
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    dequeue();
    dequeue();

    printf("Front value: %d\n", frontValue());
    printf("Rear value: %d\n", rearValue());

    return 0;
}