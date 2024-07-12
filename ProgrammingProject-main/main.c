#include "proiect.h"

int main(int argc, char **argv) {
    // Read user name and surname
    if (argc == 3) {
        strcpy(user_name, argv[1]);
        strcpy(user_surname, argv[2]);
    } else {
        printf("Enter your first and last name: ");
        scanf("%s %s", user_name, user_surname);
    }

    // Load books and loans from files
    load_books_from_file(user_name, user_surname);
    load_loans_from_file(user_name, user_surname);

    int option;
    char input[10];
    do {
        // Display menu
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%s", input);

        if (sscanf(input, "%d", &option) != 1) {
            printf("Invalid option. Please try again.\n");
            continue;
        }

        switch (option) {
            case 1:
                display_available_books();
                break;
            case 2:
                borrow_book();
                break;
            case 3:
                display_borrowed_books();
                break;
            case 4:
                return_book();
                break;
            case 5:
                search_book();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 6);

    return 0;
}
