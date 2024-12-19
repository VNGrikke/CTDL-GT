#include <stdio.h>

void findDuplicates(int arr[], int n) {
    int check = 0; 

    for (int i = 0; i < n; i++) {
        int count = 1; 
        if (arr[i] != -1) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; 
                }
            }
            if (count > 1) {
                printf("Phan tu %d xuat hien %d lan.\n", arr[i], count);
                check = 1;
            }
        }
    }

    if (!check) {
        printf("Khong co phan tu lap lai.\n");
    }
}

int main() {
    int n;

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findDuplicates(arr, n);

    return 0;
}

