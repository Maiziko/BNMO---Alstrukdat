#include <stdio.h>
#include "mesinkata.c"
#include "mesinkarakter.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomDadu()
{
    srand((unsigned)time(0));
    return (rand() % 100) + 1;
}

int toInteger(Word kata)
{
    int i = 0;
    int result = 0;
    while (i < kata.Length)
    {
        result = result * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return result;
}

int main()
{
    int count = randomDadu();
    int n;
    int hitung = 0;
    printf("Tebakan: ");
    STARTWORD();
    Word Kata;
    Kata = currentWord;
    while (toInteger(Kata) != count)
    {
        if (toInteger(Kata) > count)
        {
            printf("Lebih Kecil\n");
            printf("Tebakan: ");
            STARTWORD();
        }
        else if (toInteger(Kata) < count)
        {
            printf("Lebih Besar\n");
            printf("Tebakan: ");
            STARTWORD();
        }
        Kata = currentWord;
        hitung += 1;
    }
    printf("Ya, X adalah %d\n", count);
    printf("Anda salah menebak dalam %d kali percobaan\n", hitung); // Percobaan menebak yang gagal
    printf("Score anda adalah %d\n", 100 - hitung);
    // Perhitungan Score yang disetujui adalah 100 untuk nilai full
    return 0;
}
