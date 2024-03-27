#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Stack {
   struct Node* top;
};

struct Stack* createStack() {
   struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
   stack->top = NULL;
   return stack;
}

int isEmpty(struct Stack* stack) {
   return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
   struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = stack->top;
   stack->top = newNode;
}

int pop(struct Stack* stack) {
   if (isEmpty(stack)) {
       return -1;
   }
   
   struct Node* temp = stack->top;
   stack->top = stack->top->next;
   int data = temp->data;
   free(temp);
   
   return data;
}

void printStack(struct Stack* stack) {
   struct Node* current = stack->top;
   while (current != NULL) {
       printf("%d ", current->data);
       current = current->next;
   }
   printf("\n");
}

int main() {
   struct Stack* stack = createStack();
   
   push(stack, 10);
   push(stack, 20);
   push(stack, 30);
   push(stack, 40);
   push(stack, 50);
   
   printf("Stack: ");
   printStack(stack);
   
   printf("Popped: %d\n", pop(stack));
   printf("Popped: %d\n", pop(stack));
   
   printf("Stack: ");
   printStack(stack);
   
   return 0;
}