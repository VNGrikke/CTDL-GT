#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

Node* createLinkedList(int Arr[], int n) {
    if (n <= 0) {
        printf("Danh sach trong.\n");
        return NULL;
    }
    Node* head = NULL;
    Node* temp = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(Arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }
    return head;
}

void freeLinkedList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteLastElement(Node** head) {
    if (*head == NULL) { 
        printf("Danh sach rong.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* tail = *head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->previous->next = NULL; 
    free(tail); 
}


void printfLinkedList(Node* head) {
    Node* temp = head;
    
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;

    printf("Nhap so phan tu cua danh sach: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Danh sach rong.\n");
        return 0;
    }

    int Arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &Arr[i]);
    }

    Node* linkedList = createLinkedList(Arr, n);
    printf("Danh sach ban dau: ");
	printfLinkedList(linkedList);
	
    printf("\nDanh sach moi: ");
    deleteLastElement(&linkedList);
	printfLinkedList(linkedList);

	freeLinkedList(linkedList);
    return 0;
}

