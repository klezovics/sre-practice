#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("main:   PID=%d, PPID=%d\n", getpid(), getppid());

    pid_t pid = fork();


    if (pid == 0) {
        // Child
        printf("Child:  PID=%d, PPID=%d\n", getpid(), getppid());
    } else if (pid > 0) {
        // Parent
        printf("Parent: PID=%d, ChildPID=%d\n", getpid(), pid);

        // parents tend to wait for children to finish
        // this is useful to figure out what happened to the child ?
        wait(NULL);  // wait for child to finish
    } else {
        // Error
        perror("fork");
    }

    return 0;
}
