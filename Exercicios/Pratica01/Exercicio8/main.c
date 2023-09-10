#include <stdio.h>
#include <stdlib.h>

int main()
{
    double Peso,peso15,peso20;

    printf("Entre com o peso do inviduo: \n");
    scanf("%lf", &Peso);

    peso15 = Peso *1.15;
    printf("Se o individuo engordar, seu peso sera: %.1f \n",peso15);

    peso20 = Peso *0.8;
    printf("Se o individuo emagrecer, seu peso sera: %.1f \n",peso20);

    return 0;
}
