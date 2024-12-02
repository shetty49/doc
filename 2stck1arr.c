#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the array

struct TwoStacks {
    int arr[MAX];
    int top1; // Top for the first stack
    int top2; // Top for the second stack
};

// Function to initialize the stacks
void initialize(struct TwoStacks *ts) {
    ts->top1 = -1;
    ts->top2 = MAX;
}

// Function to push an element to stack1
void push1(struct TwoStacks *ts, int data) {
    // Check for overflow
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = data;
        printf("Pushed %d to Stack 1\n", data);
    } else {
        printf("Stack Overflow! Cannot push %d to Stack 1\n", data);
    }
}

// Function to push an element to stack2
void push2(struct TwoStacks *ts, int data) {
    // Check for overflow
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = data;
        printf("Pushed %d to Stack 2\n", data);
    } else {
        printf("Stack Overflow! Cannot push %d to Stack 2\n", data);
    }
}

// Function to pop an element from stack1
int pop1(struct TwoStacks *ts) {
    // Check for underflow
    if (ts->top1 >= 0) {
        int popped = ts->arr[ts->top1--];
        return popped;
    } else {
        printf("Stack Underflow! Stack 1 is empty.\n");
        return -1;
    }
}

// Function to pop an element from stack2
int pop2(struct TwoStacks *ts) {
    // Check for underflow
    if (ts->top2 < MAX) {
        int popped = ts->arr[ts->top2++];
        return popped;
    } else {
        printf("Stack Underflow! Stack 2 is empty.\n");
        return -1;
    }
}

// Main function to demonstrate the two stacks
int main() {
    struct TwoStacks ts;
    initialize(&ts);

    push1(&ts, 5);
    push2(&ts, 10);
    push1(&ts, 15);
    push2(&ts, 20);
    push1(&ts, 25);
    push2(&ts, 30);

    printf("Popped from Stack 1: %d\n", pop1(&ts));
    printf("Popped from Stack 2: %d\n", pop2(&ts));

    return 0;
}
