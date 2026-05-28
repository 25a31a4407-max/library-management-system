#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

FILE *fp;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void addBook() {
    struct Book b;

    fp = fopen("library.dat", "ab");

    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Title: ");
    scanf(" %[^
]", b.title);

    printf("Enter Author Name: ");
    scanf(" %[^
]", b.author);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks() {
    struct Book b;

    fp = fopen("library.dat", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n===== BOOK LIST =====\n");

    while (fread(&b, sizeof(b), 1, fp)) {
        printf("ID: %d\n", b.id);
        printf("Title: %s\n", b.title);
        printf("Author: %s\n", b.author);
        printf("Quantity: %d\n", b.quantity);
        printf("----------------------\n");
    }

    fclose(fp);
}

void searchBook() {
    struct Book b;
    int id, found = 0;

    fp = fopen("library.dat", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", b.id);
            printf("Title: %s\n", b.title);
            printf("Author: %s\n", b.author);
            printf("Quantity: %d\n", b.quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }

    fclose(fp);
}

void issueBook() {
    struct Book b;
    int id, found = 0;

    fp = fopen("library.dat", "rb+");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            found = 1;

            if (b.quantity > 0) {
                b.quantity--;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book issued successfully!\n");
            } else {
                printf("Book not available!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }

    fclose(fp);
}

void returnBook() {
    struct Book b;
    int id, found = 0;

    fp = fopen("library.dat", "rb+");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            found = 1;
            b.quantity++;

            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);

            printf("Book returned successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }

    fclose(fp);
}
