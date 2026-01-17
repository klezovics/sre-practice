#include <stdio.h>

int main() {
    int x = 42;        // normal variable
    int *p = &x;       // pointer to x (stores x's address)

    printf("x value      = %d\n", x);
    printf("x address    = %p\n", (void *)&x);
    printf("p value      = %p\n", (void *)p);
    printf("p points to  = %d\n", *p);

    return 0;
}
