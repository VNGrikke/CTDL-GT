#include <stdio.h>
#include <stdbool.h> 

void bubbleSort(int arr[], int n) {
    int i, j, temp, count = 0;
    bool swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = false;
        count++;

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }

    printf("Mang da duoc sap xep sau %d lan lap.\n", count);
}

int main() {
    int n;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
