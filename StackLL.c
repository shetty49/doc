#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root; // Returns 1 if root is NULL, otherwise 0
}

// Function to push an item to the stack
void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root; // Link the new node to the previous top
    *root = stackNode;       // Update the root (top) to the new node
    printf("%d pushed to stack\n", data);
}

// Function to pop an item from the stack
int pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        printf("Stack underflow\n");
        return INT_MIN; // Return INT_MIN to indicate an empty stack
    }
    struct StackNode* temp = *root; // Store the current top node
    *root = (*root)->next;          // Update root to the next node
    int popped = temp->data;        // Get the popped data
    free(temp);                     // Free memory
    return popped;
}

// Function to peek at the top item of the stack
int peek(struct StackNode* root) {
    if (isEmpty(root)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return root->data; // Return the data of the top node
}

// Function to display the stack elements
void display(struct StackNode* root) {
    if (isEmpty(root)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    struct StackNode* current = root;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Driver program to test the stack implementation
int main() {
    struct StackNode* root = NULL; // Initialize the stack as empty

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("%d popped from stack\n", pop(&root));
    
    printf("Top element is %d\n", peek(root));
    
    display(root); // Display remaining stack elements

    return 0;
}
