#include <stdio.h>
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/boolean.h"

int random()
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

void RNG()
{
    int RandAngka = random();
    int hitung = 0;
    printf("Tebakan: ");
    STARTCOMMAND();
    Word Kata;
    Kata = currentWord;
    while (toInteger(Kata) != RandAngka)
    {
        if (toInteger(Kata) > RandAngka)
        {
            printf("Lebih Kecil\n");
            printf("Tebakan: ");
            STARTCOMMAND();
        }
        else if (toInteger(Kata) < RandAngka)
        {
            printf("Lebih Besar\n");
            printf("Tebakan: ");
            STARTCOMMAND();
        }
        Kata = currentWord;
        hitung += 1;
    }
    printf("Ya, X adalah %d\n", RandAngka);
    printf("Anda salah menebak dalam %d kali percobaan\n", hitung); // Percobaan menebak yang gagal
    printf("Score anda adalah %d\n", 100 - hitung);
    // Perhitungan Score yang disetujui adalah 100 untuk nilai full
}



