#include <stdio.h>

int main() {
    int i;            // variable declaration
    int sum = 0;

    for (i = 1; i <= 5; i++) { // loop
        if (i % 2 == 0) {      // if
            sum += i;
        } else {               // else
            sum += 1;
        }
    }

    printf("Sum = %d\n", sum);
    return 0;
}
