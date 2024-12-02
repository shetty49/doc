//WAP to implement Queue operations INSERT and DELETE using 2 stacks. 

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push an element to the stack
void push(struct Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Queue structure using two stacks
struct Queue {
    struct Stack s1, s2;
};

// Initialize queue
void initQueue(struct Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Insert an element to the queue
void insert(struct Queue *q, int data) {
    push(&q->s1, data); // Push the new element to stack s1
    printf("Inserted %d into the queue\n", data);
}

// Delete an element from the queue
int delete(struct Queue *q) {
    // If both stacks are empty, queue is empty
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue Underflow\n");
        return -1;
    }

    // If s2 is empty, transfer all elements from s1 to s2
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            int data = pop(&q->s1);
            push(&q->s2, data);
        }
    }

    // Pop the top element from s2
    return pop(&q->s2);
}

// Main function to test the queue operations
int main() {
    struct Queue q;
    initQueue(&q);

    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);

    printf("Deleted element: %d\n", delete(&q));
    printf("Deleted element: %d\n", delete(&q));

    insert(&q, 40);
    printf("Deleted element: %d\n", delete(&q));

    return 0;
}
