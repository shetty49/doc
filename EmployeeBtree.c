// Write a program to insert N employee information into the Binary tree. Write a function
// to
// a. Search an Employee and display his details.
// b. Display the Average salary of Employees between the age 20 and 25.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee
struct Employee {
    char name[50];
    int age;
    float salary;
    struct Employee* left;
    struct Employee* right;
};

// Function to create a new employee node
struct Employee* createEmployee(char* name, int age, float salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(newEmployee->name, name);
    newEmployee->age = age;
    newEmployee->salary = salary;
    newEmployee->left = newEmployee->right = NULL;
    return newEmployee;
}

// Function to insert an employee into the binary tree
struct Employee* insertEmployee(struct Employee* root, char* name, int age, float salary) {
    if (root == NULL) {
        return createEmployee(name, age, salary);
    }

    // Inserting based on the name for simplicity
    if (strcmp(name, root->name) < 0) {
        root->left = insertEmployee(root->left, name, age, salary);
    } else {
        root->right = insertEmployee(root->right, name, age, salary);
    }
    return root;
}

// Function to search for an employee by name
struct Employee* searchEmployee(struct Employee* root, char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchEmployee(root->left, name);
    } else {
        return searchEmployee(root->right, name);
    }
}

// Function to calculate the average salary of employees between age 20 and 25
float averageSalary(struct Employee* root, int* count) {
    if (root == NULL) {
        return 0.0;
    }

    float sum = 0.0;
    
    // Check age and accumulate salary if within the specified range
    if (root->age >= 20 && root->age <= 25) {
        sum += root->salary;
        (*count)++;
    }

    // Recur for left and right subtrees
    sum += averageSalary(root->left, count);
    sum += averageSalary(root->right, count);

    return sum;
}

// Function to display average salary
void displayAverageSalary(struct Employee* root) {
    int count = 0;
    float totalSalary = averageSalary(root, &count);
    
    if (count > 0) {
        printf("Average salary of employees between age 20 and 25: %.2f\n", totalSalary / count);
    } else {
        printf("No employees found in the age range of 20 to 25.\n");
    }
}

// Main function
int main() {
    struct Employee* root = NULL;
    int n, age;
    float salary;
    char name[50];

    printf("Enter the number of employees to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of employee %d: ", i + 1);
        scanf("%s", name);
        printf("Enter age of employee %d: ", i + 1);
        scanf("%d", &age);
        printf("Enter salary of employee %d: ", i + 1);
        scanf("%f", &salary);
        root = insertEmployee(root, name, age, salary);
    }

    printf("\n--- Searching for an employee ---\n");
    printf("Enter the name of the employee to search: ");
    scanf("%s", name);
    struct Employee* foundEmployee = searchEmployee(root, name);
    if (foundEmployee != NULL) {
        printf("Employee found:\nName: %s\nAge: %d\nSalary: %.2f\n", foundEmployee->name, foundEmployee->age, foundEmployee->salary);
    } else {
        printf("Employee with name %s not found.\n", name);
    }

    printf("\n--- Displaying average salary ---\n");
    displayAverageSalary(root);

    return 0;
}
