// Given the root node of binary tree, write a program that will compute the following
// a. The number of leaf nodes
// b. Total number of nodes in the tree.
// c. Display all the values of the nodes



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

// Function to count the number of leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    // If it's a leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recur for left and right subtrees and sum up the leaf counts
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count total nodes in the tree
int countTotalNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Count the current node plus the nodes in left and right subtrees
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

// Function to display all node values
void displayNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Display the current node's value
    printf("%d ", root->data);
    
    // Recur for left and right subtrees
    displayNodes(root->left);
    displayNodes(root->right);
}

// Main function
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("All node values: ");
    displayNodes(root);
    printf("\n");

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    int totalCount = countTotalNodes(root);
    printf("Total number of nodes: %d\n", totalCount);

    return 0;
}
