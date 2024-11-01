#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertAtBeginning(struct Node* last, int data) {
    struct Node* newNode = createNode(data);

    if (last == NULL) {
        newNode->next = newNode; 
        last = newNode;
    } else {
        newNode->next = last->next; 
        last->next = newNode; 
    }

    return last;
}


struct Node* deleteAtBeginning(struct Node* last) {
     struct Node* first = last->next;
	if (last == NULL) {
        printf("List is empty.\n");
        return last;
    }

  
    
    if (first->next == first) {
        free(first);
        last = NULL; 
    } else {
        last->next = first->next;
        free(first);
    }

    return last;
}


struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* newNode = createNode(data);

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode; 
        last = newNode;
    }

    return last;
}


struct Node* deleteAtEnd(struct Node* last) {
     struct Node* temp = last->next;
    struct Node* prev = NULL;

   
    if (last == NULL) {
        printf("List is empty.\n");
        return last;
    }

    while (temp->next != last->next) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        free(temp);
        last = NULL; 
    } else {
        prev->next = last->next;
        free(temp);
        last = prev;
    }

    return last;
}


void display(struct Node* last) {
    struct Node* temp = last->next;
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

int main() {
    struct Node* last = NULL;
    int choice, data;

    do {
        printf("1. Insert at Beginning\n2. Delete at Beginning\n3. Insert at End\n4. Delete at End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                last = insertAtBeginning(last, data);
                break;
            case 2:
                last = deleteAtBeginning(last);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                last = insertAtEnd(last, data);
                break;
            case 4:
                last = deleteAtEnd(last);
                break;
            case 5:
                display(last);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

