#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
#define MAX_STRING 100 

typedef struct Element {
    int priority;      
    char data[MAX_STRING]; 
} Element;

typedef struct Queue {
    Element queues[MAX_SIZE];
    int front;
    int rear;
    int maxSize; 
} Queue;

void initializeQueue(Queue* queue, int maxSize) {
    queue->front = -1;
    queue->rear = 0;
    queue->maxSize = maxSize;
}

bool isEmpty(Queue* q) {
    return (q->front >= q->rear - 1);
}

bool isFull(Queue* q) {
    return (q->rear == q->maxSize);
}

void enqueue(Queue* q, int priority, char* data) {
    if (isFull(q)) {
        printf("Hang doi day\n");
        return;
    }
    int i = q->rear - 1;
    while (i >= q->front + 1 && q->queues[i].priority > priority) {
        q->queues[i + 1] = q->queues[i];
        i--;
    }
    q->queues[i + 1].priority = priority;
    strcpy(q->queues[i + 1].data, data); 
    q->rear++;
}

Element dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return (Element){-1, ""};
    }
    return q->queues[++q->front];
}

Element peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return (Element){-1, ""};
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
        printf("(%d, %s) ", q->queues[i].priority, q->queues[i].data);
    }
    printf("\n");
}

int main() {
    Queue q;
    int n;

    printf("Nhap kich thuoc toi da cua hang doi (1-%d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Kich thuoc khong hop le. Vui long nhap so trong khoang 1-%d.\n", MAX_SIZE);
        return 1;
    }

    initializeQueue(&q, n);
    
    for (int i = 0; i < n; i++) {
        int priority;
        char value[MAX_STRING];

        printf("Nhap do uu tien va chuoi gia tri: ");
        scanf("%d", &priority);
        getchar(); 
        fgets(value, MAX_STRING, stdin);
        value[strcspn(value, "\n")] = '\0'; 
        enqueue(&q, priority, value);
    }

    printQueue(&q);

    Element front = peek(&q);
    if (front.priority != -1) { 
        printf("Phan tu dau tien: (%d, %s)\n", front.priority, front.data);
    }

    Element removed = dequeue(&q);
    if (removed.priority != -1) { 
        printf("Da xoa phan tu: (%d, %s)\n", removed.priority, removed.data);
    }

    printQueue(&q);

    return 0;
}

