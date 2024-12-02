#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ls' command...\n", getpid());
        execlp("ls", "ls", NULL);  // Execute 'ls' command
        perror("execlp failed");    // This will only print if execlp fails
    } else {
        // Parent process without wait()
        printf("Parent process (PID: %d) running without waiting for child.\n", getpid());
    }

    return 0;
}
