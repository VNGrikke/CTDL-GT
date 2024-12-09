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

void insertPosition(Node** head, int position, int value) {
    Node* newNode = createNode(value);

    if (position == 0) {
        newNode->next = *head;
        if (*head) {
            (*head)->previous = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp) {
        printf("Loi vi tri khong hop le>\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->previous = temp;
    if (temp->next) {
        temp->next->previous = newNode;
    }
    temp->next = newNode;
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
	printfLinkedList(linkedList);
	
	int a, b;
	
	printf("Nhap vi tri can chen va gia tri: ");
    scanf("%d %d", &a, &b);
    
    insertPosition(&linkedList, a, b);
	printfLinkedList(linkedList);

	freeLinkedList(linkedList);
    return 0;
}

