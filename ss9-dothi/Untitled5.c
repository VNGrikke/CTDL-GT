#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INF 1e9 

int matrix[MAX][MAX]; 
int visited[MAX];            

void createMatrix(int n, int m, bool isDirected) {
    int i, dinh1, dinh2, trongSo;

    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("Nhap danh sach %d canh, moi canh duoc mo ta boi hai dinh va trong so (dinh1 dinh2 trongSo):\n", m);
    for (i = 0; i < m; i++) {
        printf("Nhap canh %d: ", i + 1);
        scanf("%d %d %d", &dinh1, &dinh2, &trongSo);

        if (dinh1 >= 0 && dinh1 < n && dinh2 >= 0 && dinh2 < n) {
            matrix[dinh1][dinh2] = trongSo;
            if (!isDirected) {
                matrix[dinh2][dinh1] = trongSo; 
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

int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void Dijkstra(int n, int source) {
    int dist[MAX];   
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0; 

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1; 

        for (int v = 0; v < n; v++) {
            if (!visited[v] && matrix[u][v] && dist[u] != INF && dist[u] + matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + matrix[u][v];
            }
        }
    }

    printf("Khoang cach ngan nhat tu dinh %d:\n", source);
    for (int i = 0; i < n; i++) {
        printf("Dinh %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, m, start;
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

    printf("Nhap dinh nguon de thuc hien thuat toan Dijkstra: ");
    int source;
    scanf("%d", &source);
    if (source >= 0 && source < n) {
        Dijkstra(n, source);
    } else {
        printf("Dinh nguon khong hop le!\n");
    }

    return 0;
}

