// product_management.c
#include <stdio.h>
#include <string.h>
#include "retail_shoop.h"

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (currentUser == NULL || currentUser->isSeller == 0) {
        printf("Only sellers can add products!\n");
        return;
    }
    if (productCount >= MAX_PRODUCTS) {
        printf("Product limit reached!\n");
        return;
    }
    products[productCount].id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", products[productCount].name);
    printf("Enter product description: ");
    scanf("%s", products[productCount].description);
    printf("Enter product price: ");
    scanf("%f", &products[productCount].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[productCount].quantity);
    strcpy(products[productCount].seller, currentUser->username);
    productCount++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    printf("Available Products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d, Seller: %s\n", 
               products[i].id, products[i].name, products[i].price, products[i].quantity, products[i].seller);
    }
}

void updateProduct() {
    if (currentUser == NULL || currentUser->isSeller == 0) {
        printf("Only sellers can update products!\n");
        return;
    }
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id && strcmp(products[i].seller, currentUser->username) == 0) {
            printf("Enter new product name: ");
            scanf("%s", products[i].name);
            printf("Enter new product description: ");
            scanf("%s", products[i].description);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found or you are not authorized to update it!\n");
}

void deleteProduct() {
    if (currentUser == NULL || currentUser->isSeller == 0) {
        printf("Only sellers can delete products!\n");
        return;
    }
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id && strcmp(products[i].seller, currentUser->username) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found or you are not authorized to delete it!\n");
}
