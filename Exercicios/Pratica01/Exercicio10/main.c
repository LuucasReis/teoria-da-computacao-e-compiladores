#include <stdio.h>
#include <stdlib.h>
#include <math.h> //pow (), M_PI.

double ComprimentoEsfera(double raio);
double AreaEsfera(double raio);
double VolumeEsfera(double raio);

int main()
{
    double Raio, comprimento, area, volume;

    printf("Entre com o valor do Raio: ");
    scanf("%lf", &Raio);

    comprimento = ComprimentoEsfera(Raio);
    printf("O valor do Comprimento da Esfera e de %.1f\n", comprimento);

    area = AreaEsfera(Raio);
    printf("O valor da Area da Esfera e de %.1f\n", area);

    volume = VolumeEsfera(Raio);
    printf("O valor do Volume da Esfera e de %.2f\n", volume);

    return 0;
}

double ComprimentoEsfera(double raio)
{

    return 2 * raio * M_PI ;
}

double AreaEsfera(double raio)
{
    return M_PI * (pow(raio,2));
}

double VolumeEsfera(double raio)
{
    return (3/4.0) * M_PI * (pow(raio,3));
}
