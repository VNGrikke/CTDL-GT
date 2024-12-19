#include <stdio.h>

int binarySearch(int arr[], int left, int right, int value) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2; 

    if (arr[mid] == value) {
        return mid; 
    }

    if (arr[mid] > value) {
        return binarySearch(arr, left, mid - 1, value); 
    }

    return binarySearch(arr, mid + 1, right, value);
}

int main() {
    int n, value;

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang (tang dan): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    int result = binarySearch(arr, 0, n - 1, value);

    if (result != -1) {
        printf("Phan tu %d nam o vi tri: %d\n", value, result + 1);
    } else {
        printf("Khong tim thay phan tu trong mang.\n");
    }

    return 0;
}

