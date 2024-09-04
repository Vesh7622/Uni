// user_management.c
#include <stdio.h>
#include <string.h>
#include "retail_shoop.h"

User users[MAX_USERS];
int userCount = 0;
User *currentUser = NULL;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    printf("Are you registering as a seller? (1 for Yes, 0 for No): ");
    scanf("%d", &users[userCount].isSeller);
    userCount++;
    printf("User registered successfully!\n");
}

void loginUser() {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            currentUser = &users[i];
            printf("Login successful! Welcome, %s.\n", currentUser->username);
            return;
        }
    }
    printf("Invalid username or password!\n");
}
