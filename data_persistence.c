// data_persistence.c
#include <stdio.h>
#include "retail_shoop.h"

void saveData() {
    FILE *file = fopen("users.dat", "wb");
    fwrite(users, sizeof(User), userCount, file);
    fclose(file);

    file = fopen("products.dat", "wb");
    fwrite(products, sizeof(Product), productCount, file);
    fclose(file);

    file = fopen("orders.dat", "wb");
    fwrite(orders, sizeof(Order), orderCount, file);
    fclose(file);
}

void loadData() {
    FILE *file = fopen("users.dat", "rb");
    if (file) {
        fread(users, sizeof(User), MAX_USERS, file);
        fclose(file);
        for (userCount = 0; users[userCount].username[0] != '\0'; userCount++);
    }

    file = fopen("products.dat", "rb");
    if (file) {
        fread(products, sizeof(Product), MAX_PRODUCTS, file);
        fclose(file);
        for (productCount = 0; products[productCount].name[0] != '\0'; productCount++);
    }

    file = fopen("orders.dat", "rb");
    if (file) {
        fread(orders, sizeof(Order), MAX_ORDERS, file);
        fclose(file);
        for (orderCount = 0; orders[orderCount].orderId != 0; orderCount++);
    }
}
