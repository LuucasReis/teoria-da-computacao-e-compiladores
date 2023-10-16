#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CITIES 3

// Definindo os nomes das cidades
char cities[MAX_CITIES][30] = {
    "Rio de Janeiro",
    "Sao Paulo",
    "Belo Horizonte"
};

// Estrutura para representar uma aresta com r�tulo (dist�ncia)
typedef struct {
    int destination; // O �ndice da cidade de destino
    int distance;    // A dist�ncia entre as cidades
} Edge;

// Matriz de adjac�ncia para representar o grafo
int graph[MAX_CITIES][MAX_CITIES] = {0};

// Fun��o para inserir uma aresta (arco) no grafo
void addEdge(int source, int destination, int distance) {
    graph[source][destination] = distance;
}

// Fun��o recursiva para calcular o comprimento do caminho entre duas cidades
int findPathLength(int source, int destination, int pathLength) {
    if (source == destination) {
        return pathLength;
    }

    int minLength = -1; // Inicializa com um valor que indica que n�o h� caminho
    for (int i = 0; i < MAX_CITIES; i++) {
        if (graph[source][i] > 0) {
            int length = findPathLength(i, destination, pathLength + graph[source][i]);
            if (length > 0 && (minLength == -1 || length < minLength)) {
                minLength = length;
            }
        }
    }

    return minLength;
}

// Fun��o para verificar se h� ciclos no grafo (utiliza DFS)
bool hasCycle(int node, bool visited[], bool stack[]) {
    if (!visited[node]) {
        visited[node] = true;
        stack[node] = true;

        for (int i = 0; i < MAX_CITIES; i++) {
            if (graph[node][i] > 0) {
                if (!visited[i] && hasCycle(i, visited, stack)) {
                    return true;
                } else if (stack[i]) {
                    return true;
                }
            }
        }
    }

    stack[node] = false;
    return false;
}

// Fun��o para calcular o grau de entrada de cada n�
void inDegree() {
    int inDegrees[MAX_CITIES] = {0};

    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            if (graph[j][i] > 0) {
                inDegrees[i]++;
            }
        }
    }

    printf("Grau de entrada de cada cidade:\n");
    for (int i = 0; i < MAX_CITIES; i++) {
        printf("%s: %d\n", cities[i], inDegrees[i]);
    }
}

// Fun��o para calcular o grau de sa�da de cada n�
void outDegree() {
    printf("Grau de sa�da de cada cidade:\n");
    for (int i = 0; i < MAX_CITIES; i++) {
        int outDegree = 0;
        for (int j = 0; j < MAX_CITIES; j++) {
            if (graph[i][j] > 0) {
                outDegree++;
            }
        }
        printf("%s: %d\n", cities[i], outDegree);
    }
}

int main() {
    // Inserir arestas (arcos) no grafo
    addEdge(0, 1, 450); // Rio de Janeiro para S�o Paulo: 450 km
    addEdge(1, 2, 600); // S�o Paulo para Belo Horizonte: 600 km
    addEdge(2, 0, 500); // Belo Horizonte para Rio de Janeiro: 500 km

    // Calcular e apresentar o comprimento do caminho entre duas cidades
    int source, destination;
    printf("Digite o �ndice da cidade de origem (0 - Rio de Janeiro, 1 - S�o Paulo, 2 - Belo Horizonte): ");
    scanf("%d", &source);
    printf("Digite o �ndice da cidade de destino (0 - Rio de Janeiro, 1 - S�o Paulo, 2 - Belo Horizonte): ");
    scanf("%d", &destination);

    int pathLength = findPathLength(source, destination, 0);
    if (pathLength > 0) {
        printf("O comprimento do caminho entre %s e %s � %d km.\n", cities[source], cities[destination], pathLength);
    } else {
        printf("N�o h� um caminho direto entre %s e %s.\n", cities[source], cities[destination]);
    }

    // Verificar se h� ciclos no grafo
    bool visited[MAX_CITIES] = {false};
    bool stack[MAX_CITIES] = {false};
    bool hasCycles = false;

    for (int i = 0; i < MAX_CITIES; i++) {
        if (!visited[i] && hasCycle(i, visited, stack)) {
            hasCycles = true;
            break;
        }
    }

    if (hasCycles) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo n�o possui ciclos.\n");
    }

    // Calcular o grau de entrada de cada n�
        inDegree();

    // Calcular o grau de sa�da de cada n�
    outDegree();

    return 0;
}
