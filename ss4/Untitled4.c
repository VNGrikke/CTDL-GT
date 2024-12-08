#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          
    struct Node* next; 
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList(int n) {
    if (n <= 0) {
        printf("So phan tu phai lon hon 0.\n");
        return NULL;
    }
    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri cho phan tu %d: ", i + 1);
        scanf("%d", &value);

        Node* newNode = createNode(value);

        if (head == NULL) { 
            head = newNode; 
        } else {
            temp->next = newNode; 
        }
        temp = newNode;
    }
    return head;
}

int traverseList(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return 1; 
        }
        current = current->next;
    }
    return -1; 
}

void printLinkedList(Node* head) {
    Node* current = head;
    printf("Danh sach lien ket: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int n, x;

    printf("Nhap so phan tu trong danh sach lien ket: ");
    scanf("%d", &n);

    Node* linkedList = createLinkedList(n);

    printLinkedList(linkedList);

    printf("Nhap so can tim: ");
    scanf("%d", &x);

    int result = traverseList(linkedList, x);
    printf("Ket qua: %d\n", result);

    return 0;
}

