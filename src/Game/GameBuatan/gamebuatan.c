#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/boolean.h"
#include "../RNG/RNG.c"

int KerangAjaib()
{
    int score = 0;
    int i = 0;
    int abstrak = random(10);
    printf("\n");
    printf("+==================================================================================+\n");
    printf("|      SELAMAT DATANG DI GAME KERANG AJAIB, COBA TANYAKAN SUATU HAL PADANYA        |\n");
    printf("+==================================================================================+\n");
    printf("\n");
    printf("+-----------------------------------------------------+\n");
    printf("| C O M M A N D / P E R I N T A H  Y A N G  V A L I D |\n");
    printf("| 1. Command 'Q' untuk keluar dari game kerang ajaib  |\n");
    printf("+-----------------------------------------------------+\n");
    printf("\n");
    printf("MAU NANYA APA NIH......HEHE :  ");
    STARTCOMMAND();

    while (IsKataSama(CCommand, toKata("QUIT")))
    {
        printf("\n");
        printf("COMMAND GAK VALID !! \n");
        printf("\n");
        printf("MAU NANYA APA NIH......HEHE :  ");
        STARTCOMMAND();
        abstrak = random(10);
    }

    while (toChar(CCommand) != 'Q' && (abstrak <= 10 && abstrak > 0))
    {
        if (abstrak == 1)
        {
            printf("\n");
            printf("YA.....!!!\n");
            printf("\n");
        }
        else if (abstrak == 2)
        {
            printf("\n");
            printf("TIDAK.....!!!\n");
            printf("\n");
        }
        else if (abstrak == 3)
        {
            printf("\n");
            printf("MUNGKIN.....!!!\n");
            printf("\n");
        }
        else if (abstrak == 4)
        {
            printf("\n");
            printf("LAH MANA SAYA TAU SAYA KAN IKAN T-T....!!!\n");
            printf("\n");
        }
        else if (abstrak == 5)
        {
            printf("\n");
            printf("KERANG LAGI TIDUR MALAS JAWAB....!!!\n");
            printf("\n");
        }
        else if (abstrak == 6)
        {
            printf("\n");
            printf("COBA LAGI AJA MAS/MBAK...!!!\n");
            printf("\n");
        }
        else if (abstrak == 7)
        {
            printf("\n");
            printf("KASIHAN KAMU.....!!!\n");
            printf("\n");
        }
        else if (abstrak == 8)
        {
            printf("\n");
            printf("FOKUS MAS FOKUS MBAK.....!!!\n");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("YNTKS (YO NDA TAU KOK NANYA SAYA).....!!!\n");
            printf("\n");
        }

        printf("MAU NANYA APA NIH......HEHE :  ");
        STARTCOMMAND();
        abstrak = random(10);
    }
    if (toChar(CCommand) == 'Q')
    {
        printf("\n");
        printf("MAKASIH UDAH MAIN KERANG AJAIB, .....!!!\n");
        score += 10;
        printf("Score kamu adalah %d", score);
    }

    printf("\n");
    return score;
}