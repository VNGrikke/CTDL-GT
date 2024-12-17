#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int matrix[MAX][MAX];
int visited[MAX];             

void createMatrix(int n, int m, bool isDirected) {
    int i, dinh1, dinh2;

    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("Nhap danh sach %d canh, moi canh duoc mo ta boi hai dinh (dinh1 dinh2):\n", m);
    for (i = 0; i < m; i++) {
        printf("Nhap canh %d: ", i + 1);
        scanf("%d %d", &dinh1, &dinh2);

        if (dinh1 >= 0 && dinh1 < n && dinh2 >= 0 && dinh2 < n) {
            matrix[dinh1][dinh2] = 1;
            if (!isDirected) {
                matrix[dinh2][dinh1] = 1; 
            }
        } else {
            printf("Canh khong hop le, vui long nhap lai!\n");
            i--; 
        }
    }
}

void displayMatrix(int n) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool DFSHasDirection(int u, int visited[], int recStack[], int n) {
    visited[u] = 1;
    recStack[u] = 1; 

    for (int v = 0; v < n; v++) {
        if (matrix[u][v]) { 
            if (!visited[v] && DFSHasDirection(v, visited, recStack, n)) {
                return true;
            } else if (recStack[v]) { 
                return true;
            }
        }
    }

    recStack[u] = 0; 
    return false;
}

bool DFSNoDirection(int u, int parent, int visited[], int n) {
    visited[u] = 1;

    for (int v = 0; v < n; v++) {
        if (matrix[u][v]) {
            if (!visited[v]) {
                if (DFSNoDirection(v, u, visited, n)) {
                    return true;
                }
            } else if (v != parent) {
                return true;
            }
        }
    }
    return false;
}

void symmetryCheck(int n, bool isDirected) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    if (isDirected) {
        int recStack[MAX] = {0};
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (DFSHasDirection(i, visited, recStack, n)) {
                    printf("Do thi co chu ky\n");
                    return;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (DFSNoDirection(i, -1, visited, n)) {
                    printf("Do thi co chu ky\n");
                    return;
                }
            }
        }
    }
    printf("Do thi khong co chu ky\n");
}

int main() {
    int n, m;
    int type; 

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("So dinh khong hop le!\n");
        return 1;
    }

    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &m);

    printf("Nhap loai do thi (0: Vo huong, 1: Co huong): ");
    scanf("%d", &type);

    createMatrix(n, m, type);

    displayMatrix(n);

    symmetryCheck(n, type);

    return 0;
}

