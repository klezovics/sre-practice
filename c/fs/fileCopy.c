#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 4096

int main() {
    int in = open("demo.txt", O_RDONLY);
    if (in < 0) {
        perror("open source");
        return 1;
    }

    int out = open("demo1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (out < 0) {
        perror("open dest");
        return 1;
    }

    char buf[BUF_SIZE];
    ssize_t n;

    while ((n = read(in, buf, sizeof(buf))) > 0) {
        if (write(out, buf, n) != n) {
            perror("write");
            return 1;
        }
    }

    if (n < 0) {
        perror("read");
        return 1;
    }

    close(in);
    close(out);
    return 0;
}
