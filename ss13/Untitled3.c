#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

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
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int arr[n];

    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    int searchValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);

    int result = binarySearch(arr, 0, n - 1, searchValue);

    if (result != -1) {
        printf("Phan tu %d co trong mang tai vi tri %d\n", searchValue, result);
    } else {
        printf("Phan tu %d khong co trong mang\n", searchValue);
    }

    return 0;
}

