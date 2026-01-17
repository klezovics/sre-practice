/* types.c
 *
 * A quick, practical overview of common C types, plus the most common
 * types you’ll constantly see in Linux systems programming.
 */
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>     // size_t, ptrdiff_t
#include <stdbool.h>    // bool
#include <inttypes.h>   // PRIu64 etc.

#include <sys/types.h>  // pid_t, uid_t, gid_t, ssize_t, off_t, mode_t, time_t
#include <sys/stat.h>   // mode_t (sometimes here)
#include <unistd.h>     // getpid(), getuid(), getgid()

static void print_sizes_elementary(void) {
    printf("=== Elementary C types (sizes in bytes) ===\n");
    printf("char                 : %zu\n", sizeof(char));
    printf("signed char          : %zu\n", sizeof(signed char));
    printf("unsigned char        : %zu\n", sizeof(unsigned char));

    printf("short                : %zu\n", sizeof(short));
    printf("unsigned short       : %zu\n", sizeof(unsigned short));
    printf("int                  : %zu\n", sizeof(int));
    printf("unsigned int         : %zu\n", sizeof(unsigned int));
    printf("long                 : %zu\n", sizeof(long));
    printf("unsigned long        : %zu\n", sizeof(unsigned long));
    printf("long long            : %zu\n", sizeof(long long));
    printf("unsigned long long   : %zu\n", sizeof(unsigned long long));

    printf("float                : %zu\n", sizeof(float));
    printf("double               : %zu\n", sizeof(double));
    printf("long double          : %zu\n", sizeof(long double));

    printf("bool                 : %zu\n", sizeof(bool));
    printf("void* (pointer)      : %zu\n", sizeof(void*));

    printf("\n=== Fixed-width integers (stdint.h) ===\n");
    printf("int8_t / uint8_t     : %zu / %zu\n", sizeof(int8_t),  sizeof(uint8_t));
    printf("int16_t / uint16_t   : %zu / %zu\n", sizeof(int16_t), sizeof(uint16_t));
    printf("int32_t / uint32_t   : %zu / %zu\n", sizeof(int32_t), sizeof(uint32_t));
    printf("int64_t / uint64_t   : %zu / %zu\n", sizeof(int64_t), sizeof(uint64_t));
}

static void print_linux_top10_types(void) {
    printf("\n=== Top 10 common Linux systems programming types ===\n");
    /* 1) size_t: sizes/lengths, returned by sizeof, used by read/write counts */
    printf("size_t   (sizes/lengths)            : %zu\n", sizeof(size_t));

    /* 2) ssize_t: signed size, returned by read()/write() (-1 on error) */
    printf("ssize_t  (signed size / syscall rc) : %zu\n", sizeof(ssize_t));

    /* 3) pid_t: process IDs */
    printf("pid_t    (process id)               : %zu\n", sizeof(pid_t));

    /* 4) uid_t: user IDs */
    printf("uid_t    (user id)                  : %zu\n", sizeof(uid_t));

    /* 5) gid_t: group IDs */
    printf("gid_t    (group id)                 : %zu\n", sizeof(gid_t));

    /* 6) off_t: file offsets (lseek, pread/pwrite) */
    printf("off_t    (file offset)              : %zu\n", sizeof(off_t));

    /* 7) mode_t: permissions + file type bits (open, chmod, stat) */
    printf("mode_t   (file mode/permissions)    : %zu\n", sizeof(mode_t));

    /* 8) time_t: timestamps (seconds since epoch, etc.) */
    printf("time_t   (time value)               : %zu\n", sizeof(time_t));

    /* 9) ino_t: inode number (from stat) */
    printf("ino_t    (inode number)             : %zu\n", sizeof(ino_t));

    /* 10) dev_t: device ID (major/minor packed) */
    printf("dev_t    (device id)                : %zu\n", sizeof(dev_t));

    /* Tiny usage demo so you see them in context */
    pid_t pid = getpid();
    uid_t uid = getuid();
    gid_t gid = getgid();

    printf("\n--- Example values ---\n");
    printf("pid=%ld uid=%ld gid=%ld\n", (long)pid, (long)uid, (long)gid);

    uint64_t x = 1234567890123ULL;
    printf("uint64_t example: %" PRIu64 "\n", x);
}

int main(void) {
    print_sizes_elementary();
    print_linux_top10_types();
    return 0;
}
