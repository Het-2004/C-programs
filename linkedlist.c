#include <stdio.h>
#include <stdlib.h>

// Defining structure of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initializing head to NULL
Node* head = NULL;

// Function to insert a node at the end of the linked list
void insert(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to delete a node by its key
void delete(int key) {
    Node* temp = head, *prev;

    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to get the total number of nodes in the linked list
int total_node_count() {
    int count = 0;
    Node* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Driver function to test the above functions
int main() {
    insert(10);
    insert(20);
    insert(30);
    printf("Total number of nodes in the linked list: %d\n", total_node_count());
    delete(20);
    printf("Total number of nodes in the linked list after deletion: %d\n", total_node_count());
    return 0;
}