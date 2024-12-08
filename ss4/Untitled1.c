#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          
    struct Node* next; 
} Node;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không the cap phat bo nho.\n");
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

void printLinkedList(Node* head) {
    Node* current = head;
    printf("Danh sach lien ket: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeLinkedList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next; 
        free(current);           
        current = nextNode;     
    }
    
}

int main() {
    int n;

    printf("Nhap so phan tu trong danh sach lien ket: ");
    scanf("%d", &n);

    Node* linkedList = createLinkedList(n);

    printLinkedList(linkedList);

    freeLinkedList(linkedList);

    return 0;
}

