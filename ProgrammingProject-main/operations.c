// operations.c
#include "proiect.h"

void returnBorrowedBook() {
    system("cls || clear");
    int loan_index;
    printf("Enter the loan index for return: ");
    scanf("%d", &loan_index);

    if (loan_index >= 0 && loan_index < num_borrowed) {
        for (int i = 0; i < num_books; i++) {
            if (strcmp(books[i].title, borrowed_books[loan_index][0].title) == 0 && strcmp(books[i].author, borrowed_books[loan_index][0].author) == 0) {
                books[i].available_copies += borrowed_books[loan_index][0].borrowed_copies;
                break;
            }
        }
        for (int i = loan_index; i < num_borrowed - 1; i++) {
            strcpy(borrowed_books[i][0].title, borrowed_books[i + 1][0].title);
            strcpy(borrowed_books[i][0].author, borrowed_books[i + 1][0].author);
            borrowed_books[i][0].borrowed_copies = borrowed_books[i + 1][0].borrowed_copies;
        }
        num_borrowed--;
        printf("Return successful.\n");
    } else {
        printf("Invalid loan index.\n");
    }
}

void donateBook() {
    system("cls || clear");
    char title[100];
    char author[100];
    int num_copies;
    int valid_input = 0;

    printf("Enter the book title: ");
    scanf(" %[^\n]", title);
    trim(title);
    printf("Enter the book author: ");
    scanf(" %[^\n]", author);
    trim(author);

    while (!valid_input) {
        printf("Enter the number of copies donated: ");
        if (scanf("%d", &num_copies) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            valid_input = 1;
        }
    }

    FILE *books_file = fopen("books.txt", "a");
    if (books_file == NULL) {
        printf("Error opening 'books.txt' file for adding donated books.\n");
        return;
    }

    fprintf(books_file, "%s, %s, %d.\n", title, author, num_copies);
    fclose(books_file);

    printf("The book '%s' has been successfully donated.\n", title);
}

void return_book() {
    system("cls || clear");
    display_menu();
    int option;
    printf("1. Return borrowed book\n");
    printf("2. Donate a book to the library\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            returnBorrowedBook();
            break;
        case 2:
            donateBook();
            break;
        default:
            printf("Invalid option.\n");
    }
}

void borrow_book() {
    system("cls || clear");
    char title[100];
    char author[100];
    int num_copies;
    int valid_input = 0;

    printf("Enter the book title: ");
    scanf(" %[^\n]", title);
    trim(title);
    printf("Enter the book author: ");
    scanf(" %[^\n]", author);
    trim(author);

    while (!valid_input) {
        printf("Enter the number of copies needed: ");
        if (scanf("%d", &num_copies) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            valid_input = 1;
        }
    }

    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0 && strcmp(books[i].author, author) == 0) {
            if (books[i].available_copies >= num_copies) {
                strcpy(borrowed_books[num_borrowed][0].title, books[i].title);
                strcpy(borrowed_books[num_borrowed][0].author, books[i].author);
                borrowed_books[num_borrowed][0].borrowed_copies = num_copies;
                books[i].available_copies -= num_copies;
                num_borrowed++;
                printf("The book '%s' has been borrowed successfully.\n", title);
            } else {
                printf("There are not enough available copies for '%s'.\n", title);
            }
            return;
        }
    }
    printf("The book '%s' by '%s' was not found in the library.\n", title, author);
}

void search_book() {
    system("cls || clear");
    char search[100 + 100];
    int book_found = 0;

    printf("Enter (title) or (author) or (title,author) to search: ");
    scanf(" %[^\n]", search);

    char *title = strtok(search, ",");
    char *author = strtok(NULL, ",");

    if (author == NULL) {
        printf("Search results for '%s':\n", title);
        for (int i = 0; i < num_books; i++) {
            if (strstr(books[i].title, title) != NULL || strstr(books[i].author, title) != NULL) {
                printf("- %s by %s (%d copies)\n", books[i].title, books[i].author, books[i].available_copies);
                book_found = 1;
            }
        }
    } else {
        printf("Search results for '%s' by '%s':\n", title, author);
        for (int i = 0; i < num_books; i++) {
            if (strstr(books[i].title, title) != NULL && strstr(books[i].author, author) != NULL) {
                printf("- %s by %s (%d copies)\n", books[i].title, books[i].author, books[i].available_copies);
                book_found = 1;
            }
        }
    }

    if (book_found == 0) {
        printf("The searched book does not exist.\n");
    }
}
