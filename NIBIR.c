#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    struct Contact *next;
} Contact;

Contact *head = NULL;

void addContact() {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    printf("Enter name: ");
    scanf("%[^\n]", newContact->name);
    getchar();
    printf("Enter phone: ");
    scanf("%s", newContact->phone);
    getchar();
    printf("Enter email: ");
    scanf("%s", newContact->email);
    getchar();
    newContact->next = NULL;

    if (head == NULL) {
        head = newContact;
    } else {
        Contact *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
    printf("Contact added successfully.\n");
}

void deleteContact(char *name) {
    if (head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    Contact *prev = NULL;
    Contact *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Contact deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Contact not found.\n");
}


void searchContact(char *name) {
    Contact *current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", current->name, current->phone, current->email);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts() {
    Contact *current = head;
    if (current == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Contacts:\n");
    while (current != NULL) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n\n", current->name, current->phone, current->email);
        current = current->next;
    }
}

void saveContacts() {
    FILE *fp = fopen("contacts.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Contact *current = head;
    while (current != NULL) {
        fprintf(fp, "%s %s %s\n", current->name, current->phone, current->email);
        current = current->next;
    }

    fclose(fp);
    printf("Contacts saved to file.\n");
}


void loadContacts() {
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }