#include <stdio.h>

struct Item {
    int id;
};

struct Product {
    char name;
    int price;
};

int main() {
    // list of Item
    struct Item items[] = {
        {1}, {2}, {3}, {4}, {5}
    };

    // list of Product
    struct Product products[] = {
        {'A', 10},
        {'B', 20},
        {'C', 30},
        {'D', 40}
    };

    int item_count = sizeof(items) / sizeof(items[0]);
    int product_count = sizeof(products) / sizeof(products[0]);
    int i;

    // iterate Item: print every second
    for (i = 0; i < item_count; i++) {
        if (i % 2 == 1) {
            printf("Item id: %d\n", items[i].id);
        }
    }

    // iterate Product: print every second
    for (i = 0; i < product_count; i++) {
        if (i % 2 == 1) {
            printf("Product %c price: %d\n",
                   products[i].name,
                   products[i].price);
        }
    }

    return 0;
}
