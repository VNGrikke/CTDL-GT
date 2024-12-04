#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0; 
    if (n == 1) return 1; 
    return fibonacci(n - 1) + fibonacci(n - 2); 
}

int main() {
    int n;
    
    printf("Nhap so lan hien thi so fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("so lan hien thi phai lon hon 0.\n");
    } else {
        printf("Day Fibonacci:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacci(i)); 
        }
        printf("\n");
    }

    return 0;
}

