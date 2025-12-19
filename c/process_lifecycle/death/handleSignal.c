#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t stop = 0;

void handle_signal(int sig) {
    stop = 1;   // async-signal-safe: just set a flag
}

// Send kill -TERM <pid> from another terminal
int main(void) {
    // you can set signal handlers for your app
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);   // Ctrl+C

    printf("PID %d running. Send SIGTERM or Ctrl+C.\n", getpid());

    while (!stop) {
        sleep(1);
        printf("Working...\n");
    }

    printf("Shutting down cleanly\n");
    return 0;
}
