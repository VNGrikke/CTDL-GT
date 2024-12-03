#include <stdio.h>

int soLanXuatHien(int x, int Arr[], int n) {
    int amount = 0;
    for (int i = 0; i < n; i++) {
        if (Arr[i] == x) {
            amount++;
        }
    }
    return amount;
}

int main() {
    int n, x;

    printf("Nhap do dai mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Do dai mang phai lon hon 0\n");
        return 1; 
    }

    if (n > 100) {
        printf("Do dai mang phai nho hon 100\n");
        return 1; 
    }

    int Arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &Arr[i]);
    }

    printf("Nhap so can dem: ");
    scanf("%d", &x);

    int count = soLanXuatHien(x, Arr, n); 
    printf("So lan xuat hien cua so %d la: %d\n", x, count);

    return 0;
}

