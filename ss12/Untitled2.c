#include<stdio.h>

void linearSearch(int arr[], int n){    
    int min = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }    
    }
    printf("Phan tu nho nhat: %d", min);
}

int main(){
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    
    if(n <= 0){
        printf("Khong co gia tri lon nhat");
        return 0;
    }
    
    int arr[n];
    printf("Nhap vao cac phan tu cua mang: ");
    
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);    
    }
    
    linearSearch(arr, n);

    return 0;
}

