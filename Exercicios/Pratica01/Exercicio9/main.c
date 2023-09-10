#include <stdio.h>
#include <stdlib.h>
#include <math.h> //pow (), sqrt ().

double TPitagoras(double c1, double c2);
int main()
{
    double cateto1, cateto2, hipotenusa;

    printf("Entre com o valor do primeiro cateto: ");
    scanf("%lf", &cateto1);

    printf("Entre com o valor do segundo cateto: ");
    scanf("%lf", &cateto2);

    hipotenusa = TPitagoras(cateto1, cateto2);
    printf("O valor da hipotenusa e de %.1f", hipotenusa);

    return 0;
}

double TPitagoras (double c1, double c2)
{
    double h = pow(c1,2) + pow(c2,2);

    return sqrt(h);
}
