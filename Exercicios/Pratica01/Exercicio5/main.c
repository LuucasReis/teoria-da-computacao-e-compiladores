#include <stdio.h>
#include <stdlib.h>

int main()
{
    double dMaior,dMenor,Area;

    printf("Entre com a diagonal menor: \n");
    scanf("%lf", &dMenor);

    printf("Entre com a diagonal maior: \n");
    scanf("%lf", &dMaior);


    Area = (dMaior * dMenor)/2;
    printf("A area do Losango e de: %.2f m2\n",Area);
    return 0;
}
