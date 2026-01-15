#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));

    if (!a || !b || !c) {
        perror("malloc");
        return 1;
    }

    printf("Address of a: %p\n", (void *)a);
    printf("Address of b: %p\n", (void *)b);
    printf("Address of c: %p\n", (void *)c);

    free(a);
    free(b);
    free(c);

    return 0;
}
