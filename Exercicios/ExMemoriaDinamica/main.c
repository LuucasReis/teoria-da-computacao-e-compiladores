#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = (int *) malloc(n * sizeof(int));
    if (array == NULL)
        {
            printf("Falha na alocação de memória.\n");
            return 1;
        }

    for (int i = 0; i < n; i++)
        {
            array[i] = i * 10;
        }

    printf("Array: ");
    for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }

    free(array);
}
