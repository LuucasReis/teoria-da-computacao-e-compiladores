#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,count;
    printf("Entre com um numero para efetuar a tabuada: \n");
    scanf("%d", &n);
    count = 0;
    while(count <= 10)
    {
        int result = n * count;
        printf("%d x %d = %d\n" , n, count, result);
        count++;
    };

    return 0;
}
