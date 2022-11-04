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
    int hitung = 0;
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
        hitung += 1;
    }
    printf("Ya, X adalah %d\n", n);
    printf("Anda salah menebak dalam %d kali percobaan\n", hitung); // Percobaan menebak yang gagal
    printf("Score anda adalah %d\n", 100 - hitung);                 // Perhitungan Score yang disetujui adalah 100 untuk nilai full
    return 0;
}