#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child: compute something
        int result = 42;
        printf("Child (pid%d): computed %d\n", getpid() ,result);

        // note that since no exec, need to use this syscall
        _exit(result);   // return data to parent
    }

    if (pid > 0) {
        // Parent: examine child's result
        int status;

        // wait is not very verbose
        // like in WW2: child either returns home safely or you get a notificiation that he died a hero death
        // it can give us the child's exit status (arg)
        // and it also gives us the child's pid, so parent knows which child is it
        int childPid = wait(&status);

        if (WIFEXITED(status)) {
            int value = WEXITSTATUS(status);
            printf("Parent: child (pid %d) returned %d\n", childPid ,value);
        }
    }

    return 0;
}
