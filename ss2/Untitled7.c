#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void inMang(int Arr[], int x) {
    for (int i = 0; i < x; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void timCapSo(int Arr[], int n, int k) {
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (Arr[i] + Arr[j] == k) {
                flag = true;
                printf("(%d, %d)\n", Arr[i], Arr[j]); 
            }
        }
    }
    if (!flag) {
        printf("Khong co cap nao.......\n");
    }
}

int main() {
    int n;

    printf("Nhap do dai mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("Do dai mang phai trong khoang 1-1000\n");
        return 1;
    }

    int Arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &Arr[i]);
    }

    inMang(Arr, n);

    int k;
    printf("Nhap so k: ");
    scanf("%d", &k);

    timCapSo(Arr, n, k); 

    return 0;
}

