#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}


void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}


struct Node* deleteNode(struct Node* root, int key) {
     struct Node* temp = root->right;
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
          
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
       
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


struct Node* mirrorTree(struct Node* root) {
    struct Node* temp = root->left;
    if (root == NULL) return NULL;
   
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);
    return root;
}


void countNodes(struct Node* root, int* internal, int* external) {
    if (root == NULL) return;
    if (root->left || root->right) {
        (*internal)++;
    } else {
        (*external)++;
    }
    countNodes(root->left, internal, external);
    countNodes(root->right, internal, external);
}


struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (root->data < key) return search(root->right, key);
    return search(root->left, key);
}


int treeHeight(struct Node* root) {
   int leftHeight,rightHeight;   
    if (root == NULL) return 0;
     leftHeight = treeHeight(root->left);
     rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}


struct Node* findSmallest(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


struct Node* findLargest(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

int main() {
    struct Node* root = NULL;
	 struct Node* result;
	  struct Node* smallest;
	   struct Node* largest;
    int choice, data, key;
    int internal = 0, external = 0;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n2. Preorder Traversal\n3. Postorder Traversal\n4. Inorder Traversal\n");
        printf("5. Delete a Node\n6. Create Mirror Image\n7. Count Nodes (Internal and External)\n");
        printf("8. Search for an Element\n9. Height of the Tree\n10. Find Smallest Element\n");
        printf("11. Find Largest Element\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 6:
                root = mirrorTree(root);
                printf("Mirror image created.\n");
                break;
            case 7:
                countNodes(root, &internal, &external);
                printf("Internal Nodes: %d\n", internal);
                printf("External Nodes: %d\n", external);
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &key);
                 result = search(root, key);
                if (result != NULL) {
                    printf("Element found in the tree.\n");
                } else {
                    printf("Element not found in the tree.\n");
                }
                break;
            case 9:
                printf("Height of the Tree: %d\n", treeHeight(root));
                break;
            case 10:
                if (root != NULL) {
                     smallest = findSmallest(root);
                    printf("Smallest element: %d\n", smallest->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 11:
                if (root != NULL) {
                     largest = findLargest(root);
                    printf("Largest element: %d\n", largest->data);
                } else {
                    printf("Tree is empty");
                break;
            case 12:
              
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        };
		
    }

   
}
while (choice != 12);
  return 0;
}

