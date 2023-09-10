#include <stdio.h>
#include <stdlib.h>

int main()
{
    double cotDollar,Saldo,conversion;

    printf("Entre com a cotacao do dolar: \n");
    scanf("%lf", &cotDollar);

    printf("Entre com o seu saldo em dolar: \n");
    scanf("%lf", &Saldo);


    conversion = cotDollar * Saldo;
    printf("A conversao em reais e de: %.2f\n",conversion);
    return 0;
}
