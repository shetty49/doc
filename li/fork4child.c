#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int i;
    char *commands[4][3] = {
        {"ls", NULL},         // First child executes "ls"
        {"ls", "-l", NULL},   // Second child executes "ls -l"
        {"pwd", NULL},        // Third child executes "pwd"
        {"date", NULL}        // Fourth child executes "date"
    };

    for (i = 0; i < 4; i++) {
        pid = fork();

        if (pid < 0) {
            // Fork failed
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child %d (PID: %d) executing '%s' command...\n", i + 1, getpid(), commands[i][0]);
            execvp(commands[i][0], commands[i]);  // Execute the command
            perror("execvp failed");              // This will only print if execvp fails
            exit(1);                              // Exit if execvp fails
        }
    }

    // Parent process
    for (i = 0; i < 4; i++) {
        wait(NULL);  // Wait for each child to complete
    }
    printf("Parent process (PID: %d) completed after all children.\n", getpid());

    return 0;
}
