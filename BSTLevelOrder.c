//WAP to create and delete a node from a binary Search tree. Traverse the BST using Level Order Traversing Technique.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Simple insertion logic
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("Node not found\n");
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function for Level Order Traversal
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*)); // Create a queue
    int front = 0, rear = 0;

    queue[rear++] = root; // Enqueue the root

    while (front < rear) {
        struct Node* current = queue[front++]; // Dequeue

        printf("%d ", current->data); // Print current node

        // Enqueue left child
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        // Enqueue right child
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    free(queue); // Free the allocated memory for queue
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\n1. Insert a node\n2. Delete a node\n3. Level Order Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d into the BST\n", data);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                if (root != NULL) {
                    printf("Deleted %d from the BST\n", data);
                }
                break;
            case 3:
                printf("Level Order Traversal: ");
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
