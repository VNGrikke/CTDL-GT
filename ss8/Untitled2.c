#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm t?o m?t nút m?i
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertLevelOrder(Node** root, int value, Node* queue[], int* front, int* rear) {
    Node* newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode; 
    } else {
        Node* parent = queue[*front];
        if (parent->left == NULL) {
            parent->left = newNode; 
        } else if (parent->right == NULL) {
            parent->right = newNode;
            (*front)++; 
        }
    }
    queue[++(*rear)] = newNode; 
}

void printLevel2(Node* root, int level) {
    if (root == NULL) return;
    if (level == 2) { 
        printf("%d ", root->data);
        return;
    }
    printLevel2(root->left, level + 1);
    printLevel2(root->right, level + 1);
}

int main() {
    Node* root = NULL;
    Node* queue[100]; 
    int front = 0, rear = -1;

    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap day so: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertLevelOrder(&root, value, queue, &front, &rear);
    }

    printf("Cac dinh lop 2: ");
    printLevel2(root, 1); 
    printf("\n");

    return 0;
}

