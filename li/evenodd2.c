// main_series.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int n;
    if (argc == 2) {
        n = atoi(argv[1]);
        
    }
    else{
        printf("enter a valid number");
        scanf("%d", &n);
    }

    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process: Executes even_series program
        printf("Child process (PID: %d) generating even series:\n", getpid());
        execl("./even", "even", argv[1], (char *) NULL);
        perror("exec failed");  // Only reached if exec fails
        exit(1);
    } else {
        // Parent process: Waits for child and then executes odd_series program
        wait(NULL);  // Wait for child to complete
        printf("Parent process (PID: %d) generating odd series:\n", getpid());
        execl("./odd", "odd", argv[1], (char *) NULL);
        perror("exec failed");  // Only reached if exec fails
    }

    return 0;
}
