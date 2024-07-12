// display.c
#include "proiect.h"

void display_menu() {
    printf("\nMenu:\n");
    printf("1. View available books in the library\n");
    printf("2. Borrow books\n");
    printf("3. View borrowed books\n");
    printf("4. Return/Donate books\n");
    printf("5. Search books\n");
    printf("6. Exit\n");
}

void display_available_books() {
    system("cls || clear");
    printf("Books available in the library:\n");
    for (int i = 0; i < num_books; i++) {
        printf("- %s by %s (%d copies)\n", books[i].title, books[i].author, books[i].available_copies);
    }
}

void display_borrowed_books() {
    system("cls || clear");
    printf("Books borrowed by %s %s:\n", user_name, user_surname);
    for (int i = 1; i < num_borrowed; i++) {
        printf("Loan %d:\n", i);
        for (int j = 0; j < num_books; j++) {
            if (borrowed_books[i][j].borrowed_copies > 0) {
                printf("- %s by %s (%d copies)\n", borrowed_books[i][j].title, borrowed_books[i][j].author, borrowed_books[i][j].borrowed_copies);
            }
        }
    }
}
