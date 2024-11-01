  #include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}


struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
   struct Node* current = head;
    if (head == NULL) {
        return newNode;
    }
   
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}


struct Node* insertBeforeElement(struct Node* head, int data, int key) {
    struct Node* newNode = createNode(data);
	  struct Node* current = head;
	
    if (head == NULL) {
        return newNode;
    }
    if (head->data == key) {
        newNode->next = head;
        return newNode;
    }
   
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}


struct Node* deleteFromBeginning(struct Node* head) {
     struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
   
    head = head->next;
    free(temp);
    return head;
}


struct Node* deleteFromEnd(struct Node* head) {
    struct Node* current = head;
  
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
   
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}


struct Node* deleteAfterNode(struct Node* head, int key) {
    struct Node* current = head;
	 struct Node* temp = current->next;
    if (head == NULL || head->next == NULL) {
        printf("List is empty or contains only one element.\n");
        return head;
    }
   
    while (current->next != NULL && current->data != key) {
        current = current->next;
    }
    if (current->next == NULL || current->next->next == NULL) {
        printf("Node not found or no node to delete after.\n");
        return head;
    }
   
    current->next = current->next->next;
    free(temp);
    return head;
}


int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; 
}


void replaceValue(struct Node* head, int oldVal, int newVal) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == oldVal) {
            current->data = newVal;
            return;
        }
        current = current->next;
    }
    printf("Node with old value not found.\n");
}


void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key,position;

    while (1) {
        printf("\n");
        printf("1. Insert in the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert before a given element\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete after a given node\n");
        printf("7. Search for a node\n");
        printf("8. Replace value of a node\n");
        printf("9. Display list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the key before which to insert: ");
                scanf("%d", &key);
                head = insertBeforeElement(head, data, key);
                break;

            case 4:
                head = deleteFromBeginning(head);
                break;

            case 5:
                head = deleteFromEnd(head);
                break;

            case 6:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                head = deleteAfterNode(head, key);
                break;

            case 7:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                 position = searchNode(head, data);
                if (position != -1) {
                    printf("Node found at position %d.\n", position);
                } else {
                    printf("Node not found.\n");
                }
                break;

            case 8:
                printf("Enter the old value of the node: ");
                scanf("%d", &data);
                printf("Enter the new value to replace with: ");
                scanf("%d", &key);
                replaceValue(head, data, key);
                break;

            case 9:
                displayList(head);
                break;

            case 10:
                exit(0);

            default:
            printf("\nInvalid Choice!!");
        }
    }
}

