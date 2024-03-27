#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Queue {
   struct Node* front;
   struct Node* rear;
};

struct Queue* createQueue() {
   struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
   queue->front = queue->rear = NULL;
   return queue;
}

int isEmpty(struct Queue* queue) {
   return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
   struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   
   if (isEmpty(queue)) {
       queue->front = queue->rear = newNode;
       return;
   }
   
   queue->rear->next = newNode;
   queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
   if (isEmpty(queue)) {
       return -1;
   }
   
   struct Node* temp = queue->front;
   queue->front = queue->front->next;
   
   if (queue->front == NULL) {
       queue->rear = NULL;
   }
   
   int data = temp->data;
   free(temp);
   
   return data;
}

void printQueue(struct Queue* queue) {
   struct Node* current = queue->front;
   while (current != NULL) {
       printf("%d ", current->data);
       current = current->next;
   }
   printf("\n");
}

int main() {
   struct Queue* queue = createQueue();
   
   enqueue(queue, 10);
   enqueue(queue, 20);
   enqueue(queue, 30);
   enqueue(queue, 40);
   enqueue(queue, 50);
   
   printf("Queue: ");
   printQueue(queue);
   
   printf("Dequeued: %d\n", dequeue(queue));
   printf("Dequeued: %d\n", dequeue(queue));
   
   printf("Queue: ");
   printQueue(queue);
   
   return 0;
}