#include <stdio.h>
#include <stdlib.h>

int main()
{
    double minSalary,Salary,amount;

    printf("Entre com o salario minimo: \n");
    scanf("%lf", &minSalary);

    printf("Entre com o salario do funcionario: \n");
    scanf("%lf", &Salary);


    amount = Salary/minSalary;
    printf("A quantidade em Salarios minimos do funcionario e de: %.1f salarios\n",amount);
    return 0;
}
