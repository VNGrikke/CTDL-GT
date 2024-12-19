#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("khong the cap phat bo nho");
		exit(1);
	}
	
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

Node* createLinkedList(int n){
	if(n <= 0){
		printf("So phan tu phai lon hon 0");
		return NULL;
	}
	
	Node* head = NULL;
	Node* temp = NULL;
	
	int value;
	for(int i = 0; i < n; i++){
		printf("Nhap gia tri cho phan tu: ");
		scanf("%d", &value);
		
		Node* newNode = createNode(value);
		if(head == NULL){
			head = newNode;
		}else{
			temp->next = newNode;
		}	
		temp = newNode;
	}
	return head;
}


void searchNode(Node* head, int value) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            printf("Tim thay gia tri %d trong danh sach.\n", value);
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay gia tri %d trong danh sach.\n", value);
}

void printfLinkedList(Node* head){
	Node* current = head;
	printf("Danh sach lien ket: ");
	while(current != NULL){
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL \n");
}

int main(){
	int n;
	printf("nhap so phan tu trong danh sach lien ket: ");
	scanf("%d",&n);
	
	Node* linkedList = createLinkedList(n);
	printfLinkedList(linkedList);
	
	int search;

	printf("Nhap gia tri can tim: ");
	scanf("%d",&search);

	searchNode(linkedList, search);
}
