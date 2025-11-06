#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

void addContact(Contact contacts[], int *count);
void searchContact(Contact contacts[], int count);
void editContact(Contact contacts[], int count);
void displayContacts(Contact contacts[], int count);

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                searchContact(contacts, count);
                break;
            case 3:
                editContact(contacts, count);
                break;
            case 4:
                displayContacts(contacts, count);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter phone: ");
    scanf("%s", contacts[*count].phone);
    printf("Enter email: ");
    scanf("%s", contacts[*count].email);

    (*count)++;
    printf("Contact added successfully!\n");
}

void searchContact(Contact contacts[], int count) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }

    printf("Contact not found!\n");
}

void editContact(Contact contacts[], int count) {
    char name[NAME_LENGTH];
    printf("Enter name to edit: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Editing contact:\n");
            printf("Enter new phone: ");
            scanf("%s", contacts[i].phone);
            printf("Enter new email: ");
            scanf("%s", contacts[i].email);
            printf("Contact updated successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display!\n");
        return;
    }

    printf("Contact List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Phone: %s, Email: %s\n",
               contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}