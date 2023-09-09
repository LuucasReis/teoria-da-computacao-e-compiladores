#include <stdio.h>
#include <stdlib.h>

#define TAM 255

typedef struct Pessoa{
    char CPF[TAM];
    char Nome [TAM];
    double Salario;
} tpessoa;


tpessoa* AlocarVetor(int n);
void PreencherVetor(tpessoa *Array, int n);
void PrintarVetor(tpessoa *Array, int n);
void imprimeStr (char str[TAM]);

int main()
{

    int  n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    tpessoa *array = AlocarVetor(n);

    PreencherVetor(array, n);
    PrintarVetor(array, n);

    free(array);
}

tpessoa* AlocarVetor(int n)
{
    tpessoa *array = (tpessoa *) calloc(n , sizeof(tpessoa));

    if (array == NULL)
        {
            printf("Falha na alocação de memória.\n");
            return NULL;
        }
    return array;
}

void PreencherVetor(tpessoa *Array, int n)
{
    for (int i = 0; i < n ; i++)
        {
            tpessoa p;

            printf ("\n Informe o nome: ");
            scanf("%s",p.Nome);


            printf ("\n Informe a CPF: ");
            scanf("%s",p.CPF);

            printf ("\n Informe o salario: ");
            scanf ("%lf", &(p.Salario));

            Array[i] = p;
        }
}

void PrintarVetor(tpessoa *Array, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
        {
            printf ("\n\nPessoa #%d:",(i+1));
            printf ("\n\nNome: ");
            imprimeStr(Array[i].Nome);
            printf ("\n\nCpf: ");
            imprimeStr(Array[i].CPF);
            printf ("\n\nSalario: %.2f ", Array[i].Salario);
        }
}

void imprimeStr (char str[TAM])
{
    int i;
    for (i = 0; (str[i] != '\0') && (i < TAM); i++)
    {
        printf ("%c", str[i]);
    }
}
