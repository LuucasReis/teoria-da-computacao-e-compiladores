#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3,media;

    printf("Entre com a primeira nota: \n");
    scanf("%d", &n1);

    printf("Entre com a segunda nota: \n");
    scanf("%d", &n2);

    printf("Entre com a terceira nota: \n");
    scanf("%d", &n3);

    media = (n1 + n2 + n3)/3;

    printf("A media das notas e: %d" , media);

    return 0;
}
