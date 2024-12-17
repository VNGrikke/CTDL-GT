#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    int isDirected;
    int adjacencyMatrix[MAX][MAX];
    Node* adjacencyList[MAX];
} Graph;

Graph* createGraph(int isDirected);
void addVertex(Graph* graph);
void addEdge(Graph* graph, int start, int end);
void displayMatrix(Graph* graph);
void displayList(Graph* graph);
Node* createNode(int vertex);

int main() {
    int choice, isDirected;
    printf("Nhap 1 de tao do thi co huong, 0 de tao do thi vo huong: ");
    scanf("%d", &isDirected);

    Graph* graph = createGraph(isDirected);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Them dinh\n");
        printf("2. Them canh\n");
        printf("3. Hien thi ma tran ke\n");
        printf("4. Hien thi danh sach ke\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVertex(graph);
                break;
            case 2: {
                int start, end;
                printf("Nhap dinh bat dau va dinh ket thuc: ");
                scanf("%d %d", &start, &end);
                addEdge(graph, start, end);
                break;
            }
            case 3:
                displayMatrix(graph);
                break;
            case 4:
                displayList(graph);
                break;
            case 5:
                printf("Thoat...\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

Graph* createGraph(int isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->isDirected = isDirected;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addVertex(Graph* graph) {
    if (graph->numVertices >= MAX) {
        printf("So dinh da dat toi da!\n");
        return;
    }
    graph->numVertices++;
    printf("Da them dinh %d.\n", graph->numVertices - 1);
}

void addEdge(Graph* graph, int start, int end) {
    if (start >= graph->numVertices || end >= graph->numVertices || start < 0 || end < 0) {
        printf("Dinh khong hop le!\n");
        return;
    }

    graph->adjacencyMatrix[start][end] = 1;
    if (!graph->isDirected) {
        graph->adjacencyMatrix[end][start] = 1;
    }

    Node* newNode = createNode(end);
    newNode->next = graph->adjacencyList[start];
    graph->adjacencyList[start] = newNode;

    if (!graph->isDirected) {
        newNode = createNode(start);
        newNode->next = graph->adjacencyList[end];
        graph->adjacencyList[end] = newNode;
    }

    printf("Da them canh giua %d va %d.\n", start, end);
}

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void displayMatrix(Graph* graph) {
    printf("Ma tran ke:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayList(Graph* graph) {
    printf("Danh sach ke:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

