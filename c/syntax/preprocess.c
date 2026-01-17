#include <stdio.h>      // include header

// All of these preprocessing directive and just dynamic source code modifiers
// #include → literally paste another file
// #define → text replacement
// #if / #ifdef → keep or delete blocks of text

// C preprocessing is: include code, define names, and choose what exists at compile time.

#define MAX 100         // macro constant
#define SQR(x) ((x)*(x))// macro function

// if you define or undefine this
// you can change what the log function will do
#define DEBUG 1

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
