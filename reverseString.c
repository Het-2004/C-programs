#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    char item = stack->array[stack->top];
    stack->array[stack->top] = '\0';
    stack->top--;
    return item;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

void reverseString(char str[]) {
    int len = strlen(str);
    struct Stack* stack = createStack(len);
    
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    
    for (int i = 0; i < len; i++) {
        str[i] = pop(stack);
    }
    
    free(stack->array);
    free(stack);
}

int main() {
    char str[] = "GeeksforGeeks";
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}