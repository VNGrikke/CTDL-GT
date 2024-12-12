#include <stdbool.h>
#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = 0;
}

bool isEmpty(Queue* q) { return (q->front == q->rear - 1); }

bool isFull(Queue* q) { return (q->rear == MAX_SIZE); }

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Hang doi day\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear++;
}


void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    q->front++;
}


void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }

    printf("Phan tu trong hang doi: ");
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
	
	printQueue(&q);
	
    dequeue(&q);
    printQueue(&q);


    return 0;
}
