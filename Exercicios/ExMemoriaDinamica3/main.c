#include <stdio.h>
#include <stdlib.h>

#define TAM 255

typedef struct Veiculo{
    char Chassi[TAM];
    char Marca [TAM];
    char Modelo [TAM];
    double Preco;
} tveiculo;


tveiculo* AlocarVetor(int n);
void PreencherVetor(tveiculo *Array, int n);
void PreencherVetorRealoc(tveiculo *Array, int n1, int n2);
void PrintarVetor(tveiculo *Array, int n);
void imprimeStr (char str[TAM]);
tveiculo* RealocMemoria(tveiculo *Array, int n);

int main()
{

    int  n, n2;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    tveiculo *array = AlocarVetor(n);

    PreencherVetor(array, n);
    printf("Array (Antes do realoc): ");
    PrintarVetor(array, n);

    printf("\nDigite o tamanho do novo array: ");
    scanf("%d", &n2);

    int new_tamanho = n + n2;

    tveiculo *new_array = RealocMemoria(array,new_tamanho);

    PreencherVetorRealoc(new_array, n, new_tamanho);

    printf("\nArray (pos realoc): ");
    PrintarVetor(new_array, new_tamanho);
    free(new_array);
}



tveiculo* AlocarVetor(int n)
{
    tveiculo *array = (tveiculo *) malloc(n * sizeof(tveiculo));

    if (array == NULL)
        {
            printf("Falha na alocação de memória.\n");
            return NULL;
        }
    return array;
}

void PreencherVetor(tveiculo *Array, int n)
{
    for (int i = 0; i < n ; i++)
        {
            tveiculo v;

            printf ("\n Informe o Chassi: ");
            scanf("%s",v.Chassi);


            printf ("\n Informe a Marca: ");
            scanf("%s",v.Marca);

            printf ("\n Informe o Modelo: ");
            scanf("%s",v.Modelo);

            printf ("\n Informe o Preco: ");
            scanf ("%lf", &(v.Preco));

            Array[i] = v;
        }
}

void PreencherVetorRealoc(tveiculo *Array, int n1, int n2)
{
    for (int i = n1; i < n2 ; i++)
        {
            tveiculo v;

            printf ("\n Informe o Chassi: ");
            scanf("%s",v.Chassi);


            printf ("\n Informe a Marca: ");
            scanf("%s",v.Marca);

            printf ("\n Informe o Modelo: ");
            scanf("%s",v.Modelo);

            printf ("\n Informe o Preco: ");
            scanf ("%lf", &(v.Preco));

            Array[i] = v;
        }
}

void PrintarVetor(tveiculo *Array, int n)
{
    for (int i = 0; i < n; i++)
        {
            printf ("\n\nVeiculo #%d:",(i+1));
            printf ("\n\nChassi: ");
            imprimeStr(Array[i].Chassi);
            printf ("\n\nMarca: ");
            imprimeStr(Array[i].Marca);
            printf ("\n\nModelo: ");
            imprimeStr(Array[i].Modelo);
            printf ("\n\nPreco: %.2f ", Array[i].Preco);
        }
}

tveiculo* RealocMemoria(tveiculo *Array, int n)
{

   tveiculo *array = (tveiculo *) realloc(Array, n * sizeof(tveiculo));
    if (array == NULL) {
        printf("Falha na realocação de memória.\n");
        return NULL;
    }

    return array;
}

void imprimeStr (char str[TAM])
{
    int i;
    for (i = 0; (str[i] != '\0') && (i < TAM); i++)
    {
        printf ("%c", str[i]);
    }
}
