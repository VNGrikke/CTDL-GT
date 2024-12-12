#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct Queue {
	int queues[MAX_SIZE];
	int front;
	int rear;
} Queue;

void initializeQueue(Queue* queue) {
	queue->front = -1;
	queue->rear = 0;
}

bool isEmpty(Queue* q) {
	return (q->front >= q->rear - 1);
}

bool isFull(Queue* q) {
	return (q->rear == MAX_SIZE);
}

void enqueue(Queue* q, int value) {
	if (isFull(q)) {
		printf("Hang doi day\n");
		return;
	}
	q->queues[q->rear] = value;
	q->rear++;
}

void dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("Hang doi rong\n");
		return;
	}
	q->front++;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return -1;
    }
    return q->queues[q->front + 1];
}

void printQueue(Queue* q) {
	if (isEmpty(q)) {
		printf("Hang doi rong\n");
		return;
	}
	printf("Phan tu trong hang doi: ");
	for (int i = q->front + 1; i < q->rear; i++) {
		printf("%d ", q->queues[i]);
	}
	printf("\n");
}

int main() {
	Queue q;
	initializeQueue(&q);
	
	enqueue(&q, 1);
	printf("Phan tu dau tien trong hang doi: %d\n", peek(&q));	

	enqueue(&q, 2);
	printf("Phan tu dau tien trong hang doi: %d\n", peek(&q));	

	enqueue(&q, 3);	
	printf("Phan tu dau tien trong hang doi: %d\n", peek(&q));	

	dequeue(&q);
	printf("Phan tu dau tien trong hang doi: %d\n", peek(&q));	

	return 0;
}

