#include<stdio.h>

int sum(int n, int m) {
    if (n > m) { 
        return 0;
    }
    return n + sum(n + 1, m); 
}

int main() {
    int n, m;

    printf("Nhap n và m: ");
    scanf("%d %d", &n, &m);

    if (n > m) {
        printf("n phai nho hon hoac bang m");
        return 1;
    }

    int result = sum(n, m);
    printf("%d", result);

    return 0;
}

