#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void createMatrix(int matrix[MAX][MAX], int n, int m) {
    int i, j, dinh1, dinh2;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("Nhap danh sach %d canh, moi canh duoc mo ta boi hai dinh (dinh1 dinh2):\n", m);
    for (i = 0; i < m; i++) {
        printf("Nhap canh %d: ", i + 1);
        scanf("%d %d", &dinh1, &dinh2);

        if (dinh1 >= 0 && dinh1 < n && dinh2 >= 0 && dinh2 < n) {
            matrix[dinh1][dinh2] = 1;
            matrix[dinh2][dinh1] = 1;
        } else {
            printf("Canh khong hop le, vui long nhap lai!\n");
            i--; 
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int n) {
    int i, j;
    printf("Ma tran ke cua do thi:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void symmetryCheck(int matrix[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Ma tran ke khong doi xung!\n");
                return;
            }
        }
    }
    printf("Ma tran ke doi xung. Do thi la do thi vo huong.\n");
}

int main() {
    int n, m;
    int matrix[MAX][MAX];

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("So dinh khong hop le!\n");
        return 1;
    }

    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &m);
    if (m < 0 || m > n * (n - 1) / 2) {
        printf("So canh khong hop le!\n");
        return 1;
    }

    createMatrix(matrix, n, m);

    displayMatrix(matrix, n);

    symmetryCheck(matrix, n);

    return 0;
}

