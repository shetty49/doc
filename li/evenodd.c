#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void generate_odd_series(int n) {
    printf("Odd series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", 2 * i + 1);
    }
    printf("\n");
}

void generate_even_series(int n) {
    printf("Even series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", 2 * i);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n;

    // Part (i): Use command-line argument if provided
    if (argc == 2) {
        n = atoi(argv[1]);
    }
    // Part (ii): Read `n` from the user if not provided as an argument
    else {
        printf("Enter the number of terms (n): ");
        scanf("%d", &n);
    }

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process: Generate even series
        printf("Child process (PID: %d) generating even series:\n", getpid());
        generate_even_series(n);
    } else {
        // Parent process: Generate odd series
        wait(NULL);  // Wait for the child process to complete
        printf("Parent process (PID: %d) generating odd series:\n", getpid());
        generate_odd_series(n);
    }

    return 0;
}
