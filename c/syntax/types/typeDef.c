#include <stdio.h>

// look, we're defining a type here
typedef struct {
    int id;
    int value;
} Item;

int main() {
    // instead of: struct Item x, because we defined a type
    Item it = {1, 42};
    printf("%d %d\n", it.id, it.value);
    return 0;
}
