#include <stdio.h>

void daoNguoc(int Arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = Arr[start];
        Arr[start] = Arr[end];
        Arr[end] = temp;

        start++; 
        end--;   
    }

    printf("\nMang dao nguoc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }
}

int main() {
    int n;

    printf("Nhap do dai mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Do dai mang phai trong khoang 1-100\n");
        return 1;
    }

    int Arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &Arr[i]);
    }

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }

    daoNguoc(Arr, n);

    return 0;
}

