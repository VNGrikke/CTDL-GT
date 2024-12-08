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

Node* createLinkedList(int arr[], int n) {
    if (n <= 0) {
        printf("Danh sach trong.\n");
        return NULL;
    }
    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

Node* insert(Node* head, int value, int position) {
    Node* newNode = createNode(value);

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Vi tri nam ngoai pham vi.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

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
    int n;

    printf("Nhap so phan tu trong danh sach: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cho phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    Node* linkedList = createLinkedList(arr, n);

    printf("Danh sach lien ket ban dau:\n");
    printLinkedList(linkedList);

    int a, b;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &a);
    printf("Nhap vi tri can chen : ");
    scanf("%d", &b);

    linkedList = insert(linkedList, a, b);

    printf("Danh sach lien ket sau khi chen:\n");
    printLinkedList(linkedList);

    return 0;
}

