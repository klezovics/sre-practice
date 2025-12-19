#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child: replace process image
        printf("Child: exec ls\n");
        execlp("ls", "ls", "-l", NULL);

        // Only reached if exec fails
        perror("execlp");
        exit(1);

    } else if (pid > 0) {
        // Parent: wait for child
        wait(NULL);
        printf("Parent: child finished\n");

    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}
