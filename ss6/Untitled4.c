#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return -1;
    } else {
        return stack->data[stack->top];
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    int n;
    printf("Nhap so luong phan tu (khong qua %d): ", MAX);
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("So luong phan tu khong hop li!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

	printf("Phan tu tren cung: %d", peek(&stack));
	
    return 0;
}

