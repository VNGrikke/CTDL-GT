#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
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

void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Ngan xep da day!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Cac phan tu trong ngan xep: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%c", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    char input[MAX];
    printf("Nhap vao mot chuoi: ");
    fgets(input, MAX, stdin); 


    input[strcspn(input, "\n")] = '\0';


    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }


    printStack(&stack);

    return 0;
}

