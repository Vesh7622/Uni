// main.c
#include <stdio.h>
#include "retail_shoop.h"

int 
main() {
    int choice;
    loadData();  // Load data from files if implemented

    while (1) {
        printf("\nOnline Retail Shop\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Add Product (Sellers)\n");
        printf("4. View Products\n");
        printf("5. Update Product (Sellers)\n");
        printf("6. Delete Product (Sellers)\n");
        printf("7. Add to Cart (Buyers)\n");
        printf("8. Checkout (Buyers)\n");
        printf("9. View Orders\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                addProduct();
                break;
            case 4:
                viewProducts();
                break;
            case 5:
                updateProduct();
                break;
            case 6:
                deleteProduct();
                break;
            case 7:
                addToCart();
                break;
            case 8:
                checkout();
                break;
            case 9:
                viewOrders();
                break;
            case 10:
                saveData();  // Save data to files if implemented
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
