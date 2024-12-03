#include <stdio.h>

void sapXep(int Arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
	    for (int j = i + 1; j < n; j++) {
	        if (Arr[i] > Arr[j]) { 
	            int temp = Arr[i];
	            Arr[i] = Arr[j];
	            Arr[j] = temp;
	        }
	    }
	}

    printf("\nMang sap xep: ");
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

    sapXep(Arr, n);

    return 0;
}

