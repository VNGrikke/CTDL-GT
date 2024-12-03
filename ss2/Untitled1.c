#include <stdio.h>

int findMax(int Arr[], int n) {
    int max = Arr[0];
    for (int i = 1; i < n; i++) {
        if (Arr[i] > max) {
            max = Arr[i];
        }
    }
    return max;
}

int main() {
    int n;

    printf("Nhap do dai mang: ");
    scanf("%d", &n);

    if (n <= 0 ) {
        printf("Do dai mang phai lon hon 0\n");
        return 1; 
    }
    
    if (n > 100 ) {
        printf("Do dai mang phai nho hon 100\n");
        return 1; 
    }

    int Arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &Arr[i]);
    }
    
    int numberMax = findMax(Arr, n); 

    printf("Gia tri lon nhat trong mang la: %d\n", numberMax);

    return 0;
}



