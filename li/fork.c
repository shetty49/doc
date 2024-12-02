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
        printf("I'm the child. PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("I'm the parent. PID: %d, PPID: %d\n", getpid(), getppid());
    }

    return 0;
}
