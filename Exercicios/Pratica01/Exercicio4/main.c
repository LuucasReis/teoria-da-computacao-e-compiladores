#include <stdio.h>
#include <stdlib.h>

int main()
{
    double Salary,conversion, raise;

    printf("Entre com o Salario: \n");
    scanf("%lf", &Salary);

    raise = 1.25;
    conversion = Salary * raise;
    printf("O novo salario (pos aumento) e: %.2f\n",conversion);
    return 0;
}
