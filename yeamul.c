// Project.
// User authentication and management system 




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a user
struct node {
    char username[50];
    char password[50];
    struct node* next;
};

// Linked list to store users
struct node* userList = NULL;

int main() {
    int choice;
    while (1) {
        printf("\nUser Authentication and Management System\n\n");
        printf("Admin Section\n\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");


        printf("\nUser Section\n\n");
        printf("3. Login\n");
        printf("4. Logout\n");
        printf("5. Change Password\n");
        printf("6. Forget Password\n");

        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                login();
                break;
            case 4:
                logout();
                break;
            case 5:
                changePassword();
                break;
            case 6:
                forgetPassword();
                break;
            case 7:
                printf("Exiting...\n");
                // Free allocated memory for users
                while (userList != NULL) {
                    struct node* temp = userList;
                    userList = userList->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to add a user to the linked list
void addUser() {
    struct node* newUser = (struct node*)malloc(sizeof(struct node));
    if (newUser == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", newUser->username);
    printf("Enter password: ");
    scanf("%s", newUser->password);

    newUser->next = userList;
    userList = newUser;
    printf("User added successfully!\n");
}

// Function to display all users in the linked list
void displayUsers() {
    if (userList == NULL) {
        printf("No users found!\n");
        return;
    }

    printf("List of Users:\n");
    struct node* current = userList;
    while (current != NULL) {
        printf("Username: %s\n", current->username);
        current = current->next;
    }
}

// Function to change the password of a user
void changePassword() {
    char username[50];
    printf("Enter username to change password: ");
    scanf("%s", username);

    struct node* current = userList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", current->password);
            printf("Password changed successfully!\n");
            return;
        }
        current = current->next;
    }

    printf("User not found!\n");
}

// Function to simulate user login
void login() {
    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    struct node* current = userList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
        current = current->next;
    }

    printf("Invalid username or password!\n");
}

// Function to simulate user logout
void logout() {
    printf("Logged out successfully!\n");
}

// Function to forget password
void forgetPassword() {
    char username[50];
    printf("Enter your username: ");
    scanf("%s", username); 