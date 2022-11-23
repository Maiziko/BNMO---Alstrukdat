#include <stdio.h>
<<<<<<< HEAD
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
=======
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
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
<<<<<<< HEAD
    printf("Selamat datang di game RNG. Uji Keberuntungan anda dengan menebak X.\n");
=======
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
    int RandAngka = random();
    int hitung = 0;
    printf("Tebakan: ");
    STARTCOMMAND();
<<<<<<< HEAD
    while (toInteger(CCommand) != RandAngka)
    {
        if (toInteger(CCommand) > RandAngka)
=======
    Word Kata;
    Kata = currentWord;
    while (toInteger(Kata) != RandAngka)
    {
        if (toInteger(Kata) > RandAngka)
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
        {
            printf("Lebih Kecil\n");
            printf("Tebakan: ");
            STARTCOMMAND();
        }
<<<<<<< HEAD
        else if (toInteger(CCommand) < RandAngka)
=======
        else if (toInteger(Kata) < RandAngka)
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
        {
            printf("Lebih Besar\n");
            printf("Tebakan: ");
            STARTCOMMAND();
        }
        hitung += 1;
    }
    printf("Ya, X adalah %d\n", RandAngka);
    printf("Anda salah menebak dalam %d kali percobaan\n", hitung); // Percobaan menebak yang gagal
    printf("Score anda adalah %d\n", 100 - hitung);
<<<<<<< HEAD
    printf("\n");
=======
    // Perhitungan Score yang disetujui adalah 100 untuk nilai full
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
}



