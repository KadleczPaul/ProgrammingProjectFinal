// proiect.c
#include "proiect.h"

// global variables
char user_name[50];
char user_surname[50];

Book books[100];
int num_books = 0;

BorrowedBook borrowed_books[10][100];
int num_borrowed = 0;

// trim function
void trim(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) start++;
    while ((end >= start) && isspace(str[end])) end--;
    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}
