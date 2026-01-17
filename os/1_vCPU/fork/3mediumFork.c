#include <stdio.h>
#include <unistd.h>

int main(void) {

    printf("== BASE: PID=%d, PPID=%d ==\n", getpid(), getppid());
    int basePid = getpid();

    // Have a guess as to how many lines will be printed ?? :)
    for (int i = 0; i < 3; i++) {
        fork();
    }

    printf("PID=%d, PPID=%d\n", getpid(), getppid());
    return 0;
}
