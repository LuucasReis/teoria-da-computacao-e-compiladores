#include <stdio.h>
#include <stdlib.h>


int* AlocarVetor(int n);
void PreencherVetor(int *Array, int n);
void PrintarVetor(int *Array, int n);

int main()
{
    int  n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int* array = AlocarVetor(n);

    PreencherVetor(array, n);
    PrintarVetor(array, n);

    free(array);
}

int* AlocarVetor(int n)
{
    int *array = array = (int *) malloc(n * sizeof(int));

    if (array == NULL)
        {
            printf("Falha na alocação de memória.\n");
            return NULL;
        }
    return array;
}

void PreencherVetor(int *Array, int n)
{
    for (int i = 0; i < n ; i++)
        {
            Array[i] = i * 10;
        }

}

void PrintarVetor(int *Array, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
        {
            printf("%d ", Array[i]);
        }
}
