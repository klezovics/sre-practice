#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child: become hello.out
        char *argv[] = {"./hello.out", NULL};
        execv("./hello.out", argv);

        // Only reached if exec fails
        perror("execv");
        exit(1);
    }

    if (pid > 0) {
        // Parent: wait for child
        wait(NULL);
        printf("Parent: child finished\n");
        return 0;
    }

    // fork failed
    perror("fork");
    return 1;
}
