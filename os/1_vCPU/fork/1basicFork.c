#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();

    // Both parent and child execute this
    // Simplest case process just divided itself into two
    printf("Hello from PID=%d, fork() returned %d\n", getpid(), pid);

    return 0;
}
