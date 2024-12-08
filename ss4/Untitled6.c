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

Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return NULL;
    }

    Node* temp = head;

    if (position == 0) {
        head = head->next;
        free(temp);
        return head;
    }

    Node* prev = NULL;
    int index = 0;

    while (temp != NULL && index < position) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("Vi tri nam ngoai pham vi danh sach.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

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

    int x;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &x);

    linkedList = deleteAtPosition(linkedList, x);

    printf("Danh sach lien ket sau khi xoa:\n");
    printLinkedList(linkedList);

    return 0;
}

