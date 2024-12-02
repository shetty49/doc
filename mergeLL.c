// Consider two liked list A and B in sorted order. Write a program to merge the linked list
// A and B such that the final list C is in sorted order.



#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted linked lists into a sorted linked list C
struct Node* mergeLists(struct Node* A, struct Node* B) {
    struct Node* C = NULL; // Head of the merged list
    struct Node** lastPtr = &C;

    while (A != NULL && B != NULL) {
        if (A->data <= B->data) {
            *lastPtr = A;
            A = A->next;
        } else {
            *lastPtr = B;
            B = B->next;
        }
        lastPtr = &((*lastPtr)->next);
    }

    // Append remaining elements from list A or B
    *lastPtr = (A != NULL) ? A : B;

    return C;
}

// Function to display a linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* A = NULL;
    struct Node* B = NULL;

    // Insert nodes into sorted list A
    insertNode(&A, 1);
    insertNode(&A, 3);
    insertNode(&A, 5);
    insertNode(&A, 7);

    // Insert nodes into sorted list B
    insertNode(&B, 2);
    insertNode(&B, 4);
    insertNode(&B, 6);
    insertNode(&B, 8);

    // Display lists A and B
    printf("List A: ");
    displayList(A);
    printf("List B: ");
    displayList(B);

    // Merge lists A and B into list C
    struct Node* C = mergeLists(A, B);

    // Display the merged list C
    printf("Merged List C: ");
    displayList(C);

    return 0;
}
