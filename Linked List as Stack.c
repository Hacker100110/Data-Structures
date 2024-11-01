#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Book {
    char name[100];
    int pages;
    float price;
    struct Book* next;
};


struct Book* createBook(char name[], int pages, float price) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newBook->name, name);
    newBook->pages = pages;
    newBook->price = price;
    newBook->next = NULL;
    return newBook;
}


struct Book* push(struct Book* top, char name[], int pages, float price) {
    struct Book* newBook = createBook(name, pages, price);
    newBook->next = top;
    return newBook;
}


struct Book* pop(struct Book* top) {
   struct Book* temp = top;
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return top;
    }
   
    top = top->next;
    free(temp);
    return top;
}


void peek(struct Book* top) {
    if (top == NULL) {
        printf("Stack is empty. Nothing to peek.\n");
    } else {
        printf("Top Book:\n");
        printf("Name: %s\n", top->name);
        printf("Pages: %d\n", top->pages);
        printf("Price: %.2f\n", top->price);
    }
}


void display(struct Book* top) {
    struct Book* current = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

  
    printf("Books in the Stack:\n");
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Pages: %d\n", current->pages);
        printf("Price: %.2f\n", current->price);
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct Book* top = NULL;
    int choice;
    char name[100];
    int pages;
    float price;

    do {
        printf("1. Push a Book\n2. Pop a Book\n3. Peek at Top Book\n4. Display All Books\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book Details:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Pages: ");
                scanf("%d", &pages);
                printf("Price: ");
                scanf("%f", &price);
                top = push(top, name, pages, price);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
               
                while (top != NULL) {
                    struct Book* temp = top;
                    top = top->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

