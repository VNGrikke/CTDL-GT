#include<stdio.h>

int giaiThua(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * giaiThua(n - 1);
}

int toHop(int n, int m) {
    if (m > n || m < 0) {
        return 0;
    }
    return giaiThua(n) / (giaiThua(m) * giaiThua(n - m));
}

int main() {
    int n, m;

    printf("Nhap so n va m: ");
    scanf("%d %d", &n, &m);

    if (n < 0 & n > m) {
        printf("n khong duoc nho hon 0 va nho hon m\n");
    } else {
        int result = toHop(n, m); 
        if (result == 0 && m > n) {
            printf("m khong duoc lon hon n\n");
        } else {
            printf("Ket qua: %d\n", result);
        }
    }

    return 0;
}

