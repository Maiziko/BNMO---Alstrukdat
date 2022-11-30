#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/boolean.h"
// #include "../../ADT/map/map.h"
int random(int x)
{
    srand((unsigned)time(0));
    return (rand() % x) + 1;
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
    system("cls");
    printf("+=========================================================================================================================+\n");
    printf("| S E L A M A T   D A T A N G  D I  G A M E  R N G  U J I  K E B E R U N T U N G A N M U  D E N G A N  M E N E B A K   X. |\n");
    printf("+=========================================================================================================================+\n");
    printf("\n");
    int angka = 100;
    int RandAngka = random(angka);
    int hitung = 0;
    printf("+============================+\n");
    printf(" MASUKKAN ANGKA TEBAKANMU : ");
    STARTCOMMAND();
    system("cls");
    printf("+============================+\n");
    while (toInteger(CCommand) != RandAngka && hitung < 100)
    {
        if (toInteger(CCommand) > RandAngka && toInteger(CCommand) <= 100 && toInteger(CCommand) >= 1)
        {
            printf("\n");
            printf("UPS ^-^ ...., X LEBIH KECIL. TEBAK LAGI YAA !!\n");
            printf("\n");
            printf("+============================+\n");
            printf(" MASUKKAN ANGKA TEBAKANMU : ");
            STARTCOMMAND();
            system("cls");
            printf("+============================+\n");
            hitung += 1;
        }
        else if (toInteger(CCommand) < RandAngka && toInteger(CCommand) <= 100 && toInteger(CCommand) >= 1)
        {
            printf("\n");
            printf("UPS ^-^ ...., X LEBIH BESAR. TEBAK LAGI YAA !!\n");
            printf("\n");
            printf("+============================+\n");
            printf(" MASUKKAN ANGKA TEBAKANMU : ");
            STARTCOMMAND();
            system("cls");
            printf("+============================+\n");
            hitung += 1;
        }
        else if ((toInteger(CCommand) < 0 || toInteger(CCommand) > 100))
        {
            printf("\n");
            printf(" INPUTANMU TIDAK ADA PADA RANGE ANGKA ATAU TIDAK VALID T_T.\n");
            printf("\n");
            printf(" COBA TEBAK LAGI YUK {^-^}.\n");
            printf("\n");
            printf("+============================+\n");
            printf(" MASUKKAN ANGKA TEBAKANMU : ");
            STARTCOMMAND();
            system("cls");
            printf("+============================+\n");
        }
    }
    if (100 - hitung > 0)
    {
        printf("\n");
        printf("KEREN DEH KAMU BISA NEBAK ANGKA X, YAP BENAR X = %d\n", toInteger(CCommand));
        printf("\n");
        printf("KAMU MENEBAK ANGKANYA DALAM %d KALI PERCOBAAN {^-^} !!! \n", hitung); // Percobaan menebak yang gagal
        printf("\n");
        printf("+============================+\n");
        printf("    SCORE  KAMU  ADALAH %d\n", 100 - hitung);
        printf("+============================+\n");
        printf("\n");
        printf("MASUKKAN USERNAME YANG INGIN DIGUNAKAN : ");
        STARTCOMMAND();
    }
    if (100 - hitung <= 0)
    {
        printf("\n");
        printf("KAMU TIDAK MENDAPATKAN SKOR, KARENA KAMU TIDAK BERHASIL MENEBAK ANGKANYA (T-T).\n");
        printf("\n");
    }
}