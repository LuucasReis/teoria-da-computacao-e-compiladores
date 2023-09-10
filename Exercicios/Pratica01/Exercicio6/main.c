#include <stdio.h>
#include <stdlib.h>

int main()
{
    double tCelsius,tFahrenheit;

    printf("Entre com a temperatura em celsius: \n");
    scanf("%lf", &tCelsius);


    tFahrenheit = (tCelsius * 1.8) + 32;

    printf("A temperatura em Fahrenheit e: %.2f \n",tFahrenheit);
    return 0;
}
