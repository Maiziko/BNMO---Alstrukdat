#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomDadu()
{
    srand((unsigned)time(0));
    return (rand() % 100) + 1;
}

int main()
{
    int count = randomDadu();
    int n;
    printf("Tebakan: ");
    scanf("%d", &n);
    while (n != count)
    {
        if (n > count)
        {
            printf("Lebih Kecil\n");
            printf("Tebakan: ");
            scanf("%d", &n);
        }
        else if (n < count)
        {
            printf("Lebih Besar\n");
            printf("Tebakan: ");
            scanf("%d", &n);

        }
    }
    printf("Ya, X adalah %d\n", n);
    return 0;
}