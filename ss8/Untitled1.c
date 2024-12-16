#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* right;
    struct Node* left;
} Node;

Node* createNode(int value) {
    Node* newMode = (Node*)malloc(sizeof(Node));
    newMode->value = value;
    newMode->left = NULL;
    newMode->right = NULL;
    return newMode;
}

Node* insert(Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }

    return node;
}

// Duyet cay theo phuong phap tien thu tu (preorder traversal)
void preorderTraversal(Node* node) {
    if (node != NULL) {
        printf("%d ", node->value);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Duyet cay theo phuong phap trung thu tu (inorder traversal)
void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->value);
        inorderTraversal(node->right);
    }
}

// Duyet cay theo phuong phap hau thu tu (postorder traversal)
void postorderTraversal(Node* node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->value);
    }
}

void stringToArray(char* str, int* arr, int* size) {
    char* token;
    int index = 0;

    token = strtok(str, " ");
    while (token != NULL) {
        arr[index++] = atoi(token); 
        token = strtok(NULL, " "); 
    }

    *size = index;
}

int main() {
    Node* tree = NULL;
    
    char input[100];
    int array[100], size;

    printf("Nhap vao cac gia tri: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 0) {
        printf("Chuoi nhap vao trong.\n");
        return 1;
    }
    
    stringToArray(input, array, &size);

    for (int i = 0; i < size; i++) {
        tree = insert(tree, array[i]);
    }

    printf("Duyet cay theo tien thu tu: ");
    preorderTraversal(tree);
    printf("\n");

    printf("Duyet cay theo trung thu tu: ");
    inorderTraversal(tree);
    printf("\n");

    printf("Duyet cay theo hau thu tu: ");
    postorderTraversal(tree);
    printf("\n");

    return 0;
}

