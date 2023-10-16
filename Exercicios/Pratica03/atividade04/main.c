#include <stdio.h>

// Fun��o para verificar se [n, m] est� em MQ
int is_in_MQ(int n, int m) {
    if (n == 0 && m == 1) {
        return 1; // Caso base: [0, 1] pertence a MQ
    } else if (n < m) {
        return 0; // [n, m] n�o pertence a MQ se n < m
    }
    return 0; // [n, m] n�o pertence a MQ para outros casos
}

// Fun��o para gerar e imprimir MQ at� um valor dado de i
void generate_MQ(int i) {
    for (int j = 0; j <= i; j++) {
        printf("I %d | j %d | ", i, j);
        for (int m = j + 1; m <= i + 1; m++) {
            if (is_in_MQ(j, m)) {
                printf("[%d,%d] ", j, m);
            }
        }
        printf("\n");
    }
}

int main() {
    int i;

    printf("Informe o valor de i: ");
    scanf("%d", &i);

    printf("Conjunto MQ para i = %d:\n", i);
    generate_MQ(i);

    return 0;
}
