#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
  int i;
  for (i = 0; i < n; i++) {
    if (arr[i] == x)
      return i;
  }
  return -1;
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  int x = 1;
  int n = sizeof(arr)/sizeof(arr[0]);
  int result = linearSearch(arr, n, x);
  (result == -1) ? printf("Khong tim thay") : printf("Phan tu o vi tri thu %d", result);
  return 0;
}

//Truong hop tot nhat: Phan tu can tim o vi tri dau tien Do phuc tap la O(1) 
//Truong hop xau nhat: Phan tu can tim o vi tri cuoi cung hoac khong co trong mang Do phuc tap la O(n)
//Truong hop trung binh: Do phuc tap van la O(n)
