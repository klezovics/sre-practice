#include <stdio.h>
#include <string.h>

// 1. Define a struct
struct Person {
    int age;
    float height;
};

struct Stock {
    char symbol[5];
    int amount;
};

int main() {
    // 2. Create a struct variable
    struct Person p;

    // 3. Assign values
    p.age = 30;
    p.height = 1.80f;

    // 4. Use it
    printf("Age: %d\n", p.age);
    printf("Height: %.2f\n", p.height);

    struct Stock s;

    strcpy(s.symbol, "BTC");   // fits: B T C \0
    s.amount = 100;

    printf("Symbol: %s\n", s.symbol);
    printf("Amount: %d\n", s.amount);

    return 0;
}
