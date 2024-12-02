#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void generate_fibonacci(int n) {
    int first = 1, second = 1, next;

    printf("Fibonacci series up to %d terms:\n", n);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == 2) {
            printf("%d ", first);
        } else {
            next = first + second;
            printf("%d ", next);
            first = second;
            second = next;
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number of terms>\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);  // Convert command line argument to integer
    if (n <= 0) {
        fprintf(stderr, "Please enter a positive integer for the number of terms.\n");
        exit(1);
    }

    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) generating Fibonacci series:\n", getpid());
        generate_fibonacci(n);
        exit(0);  // Child process exits after generating Fibonacci
    } else {
        // Parent process
        wait(NULL);  // Wait for child process to complete
        printf("Parent process (PID: %d) finished waiting for child.\n", getpid());
    }

    return 0;
}
