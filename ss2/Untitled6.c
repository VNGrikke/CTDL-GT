#include <stdio.h>
#include <string.h>

void inMang(int Arr[], int x){
    for(int i = 0; i < x; i++){
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Nhap do dai mang 1: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("Do dai mang phai trong khoang 1-1000\n");
        return 1;
    }

    int Arr1[n];

    printf("Nhap cac phan tu cua mang 1:\n");
    for (int i = 0; i < n; i++) {
        printf("Arr1[%d] = ", i);
        scanf("%d", &Arr1[i]);
    }
    
    int m;

    printf("Nhap do dai mang 2: "); 
    scanf("%d", &m);

    if (m <= 0 || m > 1000) {
        printf("Do dai mang phai trong khoang 1-1000\n");
        return 1;
    }

    int Arr2[m];

    printf("Nhap cac phan tu cua mang 2:\n");
    for (int i = 0; i < m; i++) {
        printf("Arr2[%d] = ", i);
        scanf("%d", &Arr2[i]);
    }
    
    inMang(Arr1, n);
    inMang(Arr2, m);
    
    int result[n + m];  
    
    memcpy(result, Arr1, n * sizeof(int));  
    memcpy(&result[n], Arr2, m * sizeof(int));  
    
    inMang(result, n + m);  

    return 0;
}

