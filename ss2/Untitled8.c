#include <stdio.h>

void inMang(int Arr[], int n) {
    printf("Mang da nhap: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void timSoThieu(int Arr[], int n) {
    int s = n * (n + 1) / 2; 
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += Arr[i];
    }
    printf("So thieu la: %d\n", s - sum);
}

int kiemTraLap(int Arr[], int X, int index) {
    for (int i = 0; i < index; i++) {
        if (Arr[i] == X) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int n;

    printf("Nhap do dai mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) { 
        printf("Do dai mang phai trong khoang 1-1000\n");
        return 1;
    }

    int Arr[n - 1];

    printf("Nhap cac phan tu cua mang (1 den %d, tru 1 so bat ky):\n", n);
    for (int i = 0; i < n - 1; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &Arr[i]);
        
        if (Arr[i] < 1 || Arr[i] > n) {
            printf("Phan tu phai nam trong khoang 1 den %d\n", n);
            return 1;
        }
        
        if (!kiemTraLap(Arr, Arr[i], i)) { 
            printf("Co su lap lai. Vui long nhap lai.\n");
            return 1;
        }
    }

    inMang(Arr, n);
    timSoThieu(Arr, n);

    return 0;
}

