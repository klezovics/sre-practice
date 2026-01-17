#include <stdio.h>

int adjust(int x) {
    if (x % 2 == 0)
        return x;
    else
        return 1;
}

int main() {
    int i;
    int sum = 0;

    for (i = 1; i <= 5; i++) {
        sum += adjust(i);   // function call
    }

    printf("Sum = %d\n", sum);
    return 0;
}
