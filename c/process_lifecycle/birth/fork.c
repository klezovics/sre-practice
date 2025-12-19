#include <stdio.h>
#include <unistd.h>

int main(void) {
    // lets try to create a child process
    pid_t pid = fork();

    if (pid == 0) {
        // pid = 0 -> no child process handle -> you are the child
        // Child process
        printf("Child:  PID=%d, PPID=%d\n", getpid(), getppid());
    } else if (pid > 0) {
        // Child born -> you have its pid
        // Parent process
        printf("Parent: PID=%d, ChildPID=%d\n", getpid(), pid);
    } else {
        // pid < 0 -> no child was created
        // fork failed
        perror("fork");
    }

    return 0;
}
