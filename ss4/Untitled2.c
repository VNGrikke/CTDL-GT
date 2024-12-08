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

void insertHeadData(Node** head, int newValue) {
    Node* newNode = createNode(newValue); 
    newNode->next = *head;            
    *head = newNode;                    
}

Node* createLinkedList(int n) {
    if (n <= 0) {
        printf("So phan tu phai lon hon 0.\n");
        return NULL;
    }
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri cho phan tu %d: ", i + 1);
        scanf("%d", &value);

        insertHeadData(&head, value);
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

int main() {
    int n, x;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    Node* linkedList = createLinkedList(n); 

    printLinkedList(linkedList);
	
	printf("Nhap gia tri muon them: ");
	scanf("%d", &x);
	
	insertHeadData(&linkedList, x);
	
	printLinkedList(linkedList);


    return 0;
}

