#include <stdio.h>

int xoa(int Arr[], int *n, int x) {
    int found = 0; 

    for (int i = 0; i < *n; i++) {
        if (Arr[i] == x) {
            found = 1;
        }
        if (found && i < *n - 1) {
            Arr[i] = Arr[i + 1]; 
        }
    }

    if (found) {
        (*n)--; 
    } else {
        printf("Khong tim thay phan tu %d trong mang.\n", x);
        return 0;
    }
    return 1;
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
    
    int x;

    printf("\nNhap so can xoa: ");
    scanf("%d", &x);

	if( xoa( Arr, &n, x ) ){
		printf("Mang sau khi xoa: ");
    	for (int i = 0; i < n; i++) {
        	printf("%d ", Arr[i]);
    	}
	}
    

    return 0;
}

