// Consider two liked list A of size N. Write a program to Split the linked list two parts i.e.
// B and C each of size N/2.


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

// Function to split the list A into two parts B and C
void splitList(struct Node* A, struct Node** B, struct Node** C) {
    if (A == NULL) return;

    struct Node* slow = A;
    struct Node* fast = A;
    struct Node* prev = NULL;

    // Use fast and slow pointers to find the midpoint
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // `prev` is the last node of the first half, so we break the link here
    *B = A;
    *C = slow;
    if (prev != NULL) {
        prev->next = NULL;
    }
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
    struct Node* C = NULL;

    int n, data;
    printf("Enter the number of elements in the list (even number): ");
    scanf("%d", &n);

    // Insert elements into list A
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&A, data);
    }

    // Display the original list A
    printf("Original List A: ");
    displayList(A);

    // Split the list into B and C
    splitList(A, &B, &C);

    // Display the split lists B and C
    printf("List B (first half): ");
    displayList(B);
    printf("List C (second half): ");
    displayList(C);

    return 0;
}
