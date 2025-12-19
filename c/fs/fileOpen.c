#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>

int main() {
    // 1️⃣ open: create open-file state (struct file + fd)
    int fd = open("demo.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // 2️⃣ lock: create kernel lock metadata (inode-level)
    if (flock(fd, LOCK_EX) < 0) {
        perror("flock");
        return 1;
    }

    // 3️⃣ use the file
    write(fd, "hello\n", 6);
    sleep(10); // keep file open + locked

    // 4️⃣ unlock: remove lock record
    flock(fd, LOCK_UN);

    // 5️⃣ close: free open-file state, release any remaining locks
    close(fd);

    return 0;
}
