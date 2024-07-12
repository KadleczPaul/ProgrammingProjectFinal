#ifndef PROIECT_H_INCLUDED
#define PROIECT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char title[100];
    char author[100];
    int available_copies;
} Book;

typedef struct {
    char title[100];
    char author[100];
    int borrowed_copies;
} BorrowedBook;

extern char user_name[50];
extern char user_surname[50];

extern Book books[100];
extern int num_books;

extern BorrowedBook borrowed_books[10][100];
extern int num_borrowed;

void display_menu();
void borrow_book();
void return_book();
void donateBook();
void returnBorrowedBook();
void display_borrowed_books();
void display_available_books();
void search_book();
void load_books_from_file(const char *user_name, const char *user_surname);
void load_loans_from_file(const char *user_name, const char *user_surname);
void trim(char *str);

#endif // PROIECT_H_INCLUDED
