#include <stdio.h>

int sum(int Arr[], int n) {
    if (n < 0) {
        return 0; 
    }
    return Arr[n] + sum(Arr, n - 1); 
}

int main() {
    int n;

    printf("Nhap n: ");
    scanf("%d", &n);

    int Arr[n]; 

    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &Arr[i]); 
    }

    int total = sum(Arr, n - 1); 
    printf("%d\n", total);

    return 0;
}

