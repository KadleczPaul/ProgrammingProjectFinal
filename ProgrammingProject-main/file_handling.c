// file_handling.c
#include "proiect.h"

void load_books_from_file(const char *user_name, const char *user_surname) {
    FILE *books_file = fopen("books.txt", "r");
    if (books_file == NULL) {
        printf("Error opening 'books.txt' file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), books_file)) {
        char *title = strtok(line, ",");
        char *author = strtok(NULL, ",");
        char *copies = strtok(NULL, ".");
        if (title != NULL && author != NULL && copies != NULL) {
            trim(title);
            trim(author);

            int copies_val = atoi(copies);

            strcpy(books[num_books].title, title);
            strcpy(books[num_books].author, author);
            books[num_books].available_copies = copies_val;

            num_books++;
        }
    }

    fclose(books_file);
}

void load_loans_from_file(const char *user_name, const char *user_surname) {
    FILE *loans_file = fopen("loans.txt", "r");
    if (loans_file == NULL) {
        printf("Error opening 'loans.txt' file.\n");
        return;
    }

    while (fgets(borrowed_books[num_borrowed][0].title, 100, loans_file) != NULL) {
        trim(borrowed_books[num_borrowed][0].title);
        fgets(borrowed_books[num_borrowed][0].author, 100, loans_file);
        trim(borrowed_books[num_borrowed][0].author);
        fscanf(loans_file, "%d\n", &borrowed_books[num_borrowed][0].borrowed_copies);
        num_borrowed++;
    }

    fclose(loans_file);
}
