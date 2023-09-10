#include <stdio.h>
#include <stdlib.h>

int main()
{
    int birthYear,currentYear,Age,Age50;

    printf("Entre com o ano em que voce nasceu: \n");
    scanf("%d", &birthYear);

    printf("Entre com o ano atual: \n");
    scanf("%d", &currentYear);

    Age = currentYear - birthYear;
    printf("A sua idade e: %d\n anos", Age);

    Age50 = 2050 - birthYear;
    printf("A sua idade em 2050 sera: %d anos", Age50);

    return 0;
}
