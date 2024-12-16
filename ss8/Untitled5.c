#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;                
    struct Node* left;       
    struct Node* right;      
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value); 
    } else if (value > root->data) {
        root->right = insertNode(root->right, value); 
    }
    return root; 
}

Node* searchNode(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root; 
    }

    if (value < root->data) {
        return searchNode(root->left, value); 
    } else {
        return searchNode(root->right, value); 
    }
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);   
    printf("%d ", root->data);    
    inorderTraversal(root->right); 
}

int main() {
    Node* root = NULL; 
    int choice, value;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Chen gia tri vao cay\n");
        printf("2. Tim kiem gia tri trong cay\n");
        printf("3. Duyet cay (Inorder)\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can chen: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Da chen gia tri %d vao cay.\n", value);
                break;

            case 2: 
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (searchNode(root, value) != NULL) {
                    printf("Gia tri %d ton tai trong cay.\n", value);
                } else {
                    printf("Gia tri %d khong ton tai trong cay.\n", value);
                }
                break;

            case 3: 
                printf("Cac gia tri trong cay (Inorder): ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4: 
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    } while (choice != 4);

    return 0;
}

