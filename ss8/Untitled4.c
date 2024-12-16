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
    if (root == NULL) return createNode(value); 

    if (value < root->data) {
        root->left = insertNode(root->left, value); 
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root; 
}

int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);   
    int rightHeight = treeHeight(root->right); 
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; 
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value); 
    }

    int height = treeHeight(root);
    printf("Chieu cao cua cay: %d\n", height);

    return 0;
}

