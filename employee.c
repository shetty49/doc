// Write a program to insert N employee information into the Linked List.
// a. Write a function to Search an Employee and display his details.
// b. Display the Average salary of all the Employees with designation Manager. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char designation[50];
    double salary;
    struct Employee *next;
};

// Function to create a new employee node
struct Employee* createEmployee(int id, char name[], char designation[], double salary) {
    struct Employee *newEmployee = (struct Employee*) malloc(sizeof(struct Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    strcpy(newEmployee->designation, designation);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to insert an employee at the end of the list
void addEmployee(struct Employee **head, int id, char name[], char designation[], double salary) {
    struct Employee *newEmployee = createEmployee(id, name, designation, salary);
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        struct Employee *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

// Function to search for an employee by ID
struct Employee* searchEmployee(struct Employee *head, int id) {
    struct Employee *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to calculate the average salary of employees with the designation "Manager"
double calculateAverageSalaryOfManagers(struct Employee *head) {
    struct Employee *temp = head;
    double totalSalary = 0;
    int count = 0;

    while (temp != NULL) {
        if (strcmp(temp->designation, "Manager") == 0) {
            totalSalary += temp->salary;
            count++;
        }
        temp = temp->next;
    }

    return count > 0 ? totalSalary / count : 0;
}

// Function to display an employee's details
void displayEmployee(struct Employee *emp) {
    if (emp != NULL) {
        printf("ID: %d\n", emp->id);
        printf("Name: %s\n", emp->name);
        printf("Designation: %s\n", emp->designation);
        printf("Salary: %.2f\n", emp->salary);
    } else {
        printf("Employee not found.\n");
    }
}

// Function to display all employees
void displayAllEmployees(struct Employee *head) {
    struct Employee *temp = head;
    while (temp != NULL) {
        displayEmployee(temp);
        printf("-------------------\n");
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Employee *head = NULL;
    int n, id, searchId;
    char name[50], designation[50];
    double salary;

    printf("Enter the number of employees to insert: ");
    scanf("%d", &n);

    // Insert employee data
    for (int i = 0; i < n; i++) {
        printf("Enter details of employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Name: ");
        scanf(" %[^\n]%*c", name); // Read string with spaces
        printf("Designation: ");
        scanf(" %[^\n]%*c", designation);
        printf("Salary: ");
        scanf("%lf", &salary);
        addEmployee(&head, id, name, designation, salary);
    }

    // Search for an employee by ID
    printf("Enter the employee ID to search: ");
    scanf("%d", &searchId);
    struct Employee *emp = searchEmployee(head, searchId);
    if (emp != NULL) {
        printf("Employee found:\n");
        displayEmployee(emp);
    } else {
        printf("Employee not found.\n");
    }

    // Calculate and display the average salary of managers
    double avgSalary = calculateAverageSalaryOfManagers(head);
    printf("Average salary of employees with designation 'Manager': %.2f\n", avgSalary);

    return 0;
}
