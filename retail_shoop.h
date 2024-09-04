// retail_shop.h
#ifndef RETAIL_SHOP_H
#define RETAIL_SHOP_H

#define MAX_USERS 100
#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

typedef struct {
    char username[50];
    char password[50];
    int isSeller;
} User;

typedef struct {
    int id;
    char name[50];
    char description[200];
    float price;
    int quantity;
    char seller[50];  // Seller's username
} Product;

typedef struct {
    int orderId;
    char buyer[50];
    int productId;
    int quantity;
    float totalPrice;
} Order;

// Declare currentUser as extern
extern User *currentUser;

// Other external declarations
extern User users[MAX_USERS];
extern int userCount;
extern Product products[MAX_PRODUCTS];
extern int productCount;
extern Order orders[MAX_ORDERS];
extern int orderCount;

// Function prototypes
void registerUser();
void loginUser();
void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();
void addToCart();
void checkout();
void viewOrders();
void saveData();
void loadData();

#endif // RETAIL_SHOP_H
