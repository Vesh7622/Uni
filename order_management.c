// order_management.c
#include <stdio.h>
#include "retail_shoop.h"

Order orders[MAX_ORDERS];
int orderCount = 0;

void addToCart() {
    if (currentUser == NULL || currentUser->isSeller == 1) {
        printf("Only buyers can add products to cart!\n");
        return;
    }
    int id, quantity;
    printf("Enter product ID to add to cart: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            if (products[i].quantity < quantity) {
                printf("Not enough stock available!\n");
                return;
            }
            orders[orderCount].orderId = orderCount + 1;
            strcpy(orders[orderCount].buyer, currentUser->username);
            orders[orderCount].productId = id;
            orders[orderCount].quantity = quantity;
            orders[orderCount].totalPrice = products[i].price * quantity;
            products[i].quantity -= quantity;
            orderCount++;
            printf("Product added to cart!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void checkout() {
    if (currentUser == NULL || currentUser->isSeller == 1) {
        printf("Only buyers can checkout!\n");
        return;
    }
    printf("Order Summary:\n");
    for (int i = 0; i < orderCount; i++) {
        if (strcmp(orders[i].buyer, currentUser->username) == 0) {
            printf("Order ID: %d, Product ID: %d, Quantity: %d, Total Price: %.2f\n", 
                   orders[i].orderId, orders[i].productId, orders[i].quantity, orders[i].totalPrice);
        }
    }
    printf("Checkout completed!\n");
}

void viewOrders() {
    if (currentUser == NULL) {
        printf("Please login first!\n");
        return;
    }
    if (currentUser->isSeller) {
        printf("Your Products' Orders:\n");
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < productCount; j++) {
                if (products[j].id == orders[i].productId && strcmp(products[j].seller, currentUser->username) == 0) {
                    printf("Order ID: %d, Buyer: %s, Quantity: %d, Total Price: %.2f\n", 
                           orders[i].orderId, orders[i].buyer, orders[i].quantity, orders[i].totalPrice);
                }
            }
        }
    } else {
        printf("Your Orders:\n");
        for (int i = 0; i < orderCount; i++) {
            if (strcmp(orders[i].buyer, currentUser->username) == 0) {
                printf("Order ID: %d, Product ID: %d, Quantity: %d, Total Price: %.2f\n", 
                       orders[i].orderId, orders[i].productId, orders[i].quantity, orders[i].totalPrice);
            }
        }
    }
}
