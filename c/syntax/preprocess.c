#include <stdio.h>      // include header

// C preprocessing is: include code, define names, and choose what exists at compile time.

#define MAX 100         // macro constant
#define SQR(x) ((x)*(x))// macro function

#ifdef DEBUG             // conditional compile
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#ifndef VERSION          // include guard style
#define VERSION 1
#endif

int main() {
#if MAX > 50              // compile-time condition
    LOG("MAX is big\n");
#else
    LOG("MAX is small\n");
#endif

    printf("Square: %d\n", SQR(5));
    return 0;
}
