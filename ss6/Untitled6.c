#include <stdio.h>
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

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0'; 
    }
    return stack->data[stack->top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValidExpression(char expr[]) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), ch)) {
                return 0; 
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char expr[MAX];

    printf("Nhap vao bieu thuc: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (isValidExpression(expr)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}
