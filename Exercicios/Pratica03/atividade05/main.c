#include <stdio.h>

#define MAX_CITIES 4

int graph[MAX_CITIES][MAX_CITIES] = {0}; // Inicializa a matriz com todas as dist�ncias como 0

// Procedimento para inserir a dist�ncia entre duas cidades na matriz
void insertDistance(int city1, int city2, int distance) {
    if (city1 >= 0 && city1 < MAX_CITIES && city2 >= 0 && city2 < MAX_CITIES) {
        graph[city1][city2] = distance;
        graph[city2][city1] = distance; // O grafo � n�o-direcionado, portanto, atualizamos ambas as dire��es
    }
}

// Procedimento para contar quantas estradas ligam as cidades
int countRoads(int city) {
    int count = 0;
    for (int i = 0; i < MAX_CITIES; i++) {
        if (graph[city][i] > 0) {
            count++;
        }
    }
    return count;
}

// Procedimento para imprimir a matriz de dist�ncias
void printGraph() {
    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Fun��o recursiva para obter a dist�ncia entre duas cidades
int getDistance(int city1, int city2) {
    if (city1 >= 0 && city1 < MAX_CITIES && city2 >= 0 && city2 < MAX_CITIES) {
        if (graph[city1][city2] > 0) {
            return graph[city1][city2];
        }
    }
    return 0; // Retorna 0 se n�o houver estrada ligando as cidades
}

int main() {
    // Inserir dist�ncias entre cidades
    insertDistance(0, 1, 10); // Cidade 0 para Cidade 1: 10 km
    insertDistance(1, 2, 15); // Cidade 1 para Cidade 2: 15 km
    insertDistance(2, 3, 20); // Cidade 2 para Cidade 3: 20 km

    // Contar estradas ligando cidades
    int city = 1; // Cidade 1
    int roadCount = countRoads(city);
    printf("Cidade %d tem %d estradas ligando outras cidades.\n", city, roadCount);

    // Imprimir a matriz de dist�ncias
    printf("Matriz de Dist�ncias:\n");
    printGraph();

    // Obter dist�ncia entre cidades
    int cityA = 0; // Cidade 0
    int cityB = 2; // Cidade 2
    int distance = getDistance(cityA, cityB);
    if (distance > 0) {
        printf("A dist�ncia entre Cidade %d e Cidade %d � %d km.\n", cityA, cityB, distance);
    } else {
        printf("N�o h� estrada ligando Cidade %d e Cidade %d.\n", cityA, cityB);
    }

    return 0;
}
