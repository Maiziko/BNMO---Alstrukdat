#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/stack/stack.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"

void displayTower(Stack S, char X)
{
    printf("______________________________\n");
    printf("\n");
    for (int i = 0; i < 4 - IDX_TOP(S); i++)
    {
        printf("\t      |\n");
    }
    for (int i = IDX_TOP(S); i >= 0; i--)
    {
        printf("\t  ");
        for (int k = 0; k < (9 - S.buffer[i]) / 2; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < S.buffer[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\t ");
    for (int k = 0; k < 11; k++)
    {
        printf("-");
    }
    printf("\n");
    printf("\t   TOWER %c\n", X);
}

char toABC(Word kata)
{
    char huruf = ' ';
    if (IsKataSama(kata, toKata("A")))
    {
        huruf = 'A';
    }
    else if (IsKataSama(kata, toKata("B")))
    {
        huruf = 'B';
    }
    else if (IsKataSama(kata, toKata("C")))
    {
        huruf = 'C';
    }
    return huruf;
}

boolean isTowerAvail(Stack awal, Stack S1, Stack S2)
{
    return (TOP(S1) > TOP(awal) || TOP(S2) > TOP(awal) || isEmpty(S1) || isEmpty(S2));
}

int TowerOfHanoi()
{
    typedef struct
    {
        int score;
        Word name;
    } player;
    player data;
    int val, score, step = 0;
    Stack A, B, C, finish;
    char awal, akhir;
    CreateStack(&A);
    CreateStack(&B);
    CreateStack(&C);

    for (int i = 4; i >= 0; i--)
    {
        push(&A, (2 * i + 1));
    }

    printf("==============================\n");
    printf("\tTOWER OF HANOI\t\n");
    printf("==============================\n");

    displayTower(A, 'A');
    displayTower(B, 'B');
    displayTower(C, 'C');

    while (IDX_TOP(C)!=4)
    {

        printf("==============================\n");
        printf("Tiang Asal : ");
        STARTCOMMAND();
        awal = toABC(CCommand);
        while (toABC(CCommand) == ' ')
        {
            printf("Masukkan tidak valid!\n");
            printf("Tiang Asal : ");
            STARTCOMMAND();
            awal = toABC(CCommand);
        }

        if (awal == 'A' && isEmpty(A))
        {
            while (awal == 'A' && isEmpty(A))
            {
                printf("Tiang Kosong.\nMasukkan tidak valid!\n");
                printf("Tiang Asal : ");
                STARTCOMMAND();
                awal = toABC(CCommand);
            }
        }

        else if (awal == 'B' && isEmpty(B))
        {
            while (awal == 'B' && isEmpty(B))
            {
                printf("Tiang Kosong.\nMasukkan tidak valid!\n");
                printf("Tiang Asal : ");
                STARTCOMMAND();
                awal = toABC(CCommand);
            }
        }

        else if (awal == 'C' && isEmpty(C))
        {
            while (awal == 'C' && isEmpty(C))
            {
                printf("Tiang Kosong.\nMasukkan tidak valid!\n");
                printf("Tiang Asal : ");
                STARTCOMMAND();
                awal = toABC(CCommand);
            }
        }

        printf("Tiang Tujuan : ");
        STARTCOMMAND();
        akhir = toABC(CCommand);
        while (toABC(CCommand) == ' ')
        {
            printf("Masukkan tidak valid!\n");
            printf("Tiang Tujuan: ");
            STARTCOMMAND();
            akhir = toABC(CCommand);
        }

        if (awal == 'A')
        {
            if (isTowerAvail(A, B, C))
            {
                while (akhir == 'A')
                {
                    printf("\nMasukkan tidak valid!\n");
                    printf("Tiang Tujuan: ");
                    STARTCOMMAND();
                    akhir = toABC(CCommand);
                }
                if (akhir == 'B')
                {
                    if (TOP(B) > TOP(A) || isEmpty(B))
                    {
                        push(&B, TOP(A));
                        printf("Memindahkan piringan ke B...\n");
                        step++;
                    }
                    else
                    {
                        while (akhir == 'B' || akhir == 'A')
                        {
                            printf("Masukkan tidak valid!\n");
                            printf("Tiang Tujuan: ");
                            STARTCOMMAND();
                            akhir = toABC(CCommand);
                        }
                        push(&C, TOP(A));
                    }
                }
                else if (akhir == 'C')
                {
                    if (TOP(C) > TOP(A) || isEmpty(C))
                    {
                        push(&C, TOP(A));
                        printf("Memindahkan piringan ke C...\n");
                        step++;
                    }
                    else
                    {
                        while (akhir == 'C' || akhir == 'A')
                        {
                            printf("Masukkan tidak valid!\n");
                            printf("Tiang Tujuan: ");
                            STARTCOMMAND();
                            akhir = toABC(CCommand);
                        }
                        push(&B, TOP(A));
                    }
                }
                pop(&A, &val);
            }
            else
            {
                printf("Masukkan tidak valid!\n");
                continue;
            }
        }

        else if (awal == 'B')
        {
            if (isTowerAvail(B, A, C))
            {
                while (akhir == 'B')
                {
                    printf("\nMasukkan tidak valid!\n");
                    printf("Tiang Tujuan: ");
                    STARTCOMMAND();
                    akhir = toABC(CCommand);
                }
                if (akhir == 'A')
                {
                    if (TOP(A) > TOP(B) || isEmpty(A))
                    {
                        push(&A, TOP(B));
                        printf("Memindahkan piringan ke A...\n");
                        step++;
                    }
                    else
                    {
                        while (akhir == 'A' || akhir == 'B')
                        {
                            printf("Masukkan tidak valid!\n");
                            printf("Tiang Tujuan: ");
                            STARTCOMMAND();
                            akhir = toABC(CCommand);
                        }
                        push(&C, TOP(B));
                    }
                }
                else if (akhir == 'C')
                {
                    if (TOP(C) > TOP(B) || isEmpty(C))
                    {
                        push(&C, TOP(B));
                        printf("Memindahkan piringan ke C...\n");
                        step++;
                    }
                    else
                    {
                        while (akhir == 'C' || akhir == 'B')
                        {
                            printf("Masukkan tidak valid!\n");
                            printf("Tiang Tujuan: ");
                            STARTCOMMAND();
                            akhir = toABC(CCommand);
                        }
                        push(&A, TOP(B));
                    }
                }
                pop(&B, &val);
            }
            else
            {
                printf("Masukkan tidak valid!\n");
                continue;
            }
        }

        else if (awal == 'C')
        {
            if (isTowerAvail(C, B, A))
            {
                while (akhir == 'C')
                {
                    printf("Tiang Tujuantidak boleh sama\ndengan tiang awal.\nMasukkan tidak valid!\n");
                    printf("Tiang Tujuan: ");
                    STARTCOMMAND();
                    akhir = toABC(CCommand);
                }
                if (akhir == 'A')
                {
                    if (TOP(A) > TOP(C) || isEmpty(A))
                    {
                        push(&A, TOP(C));
                        printf("Memindahkan piringan ke A...\n");
                        step++;
                    }
                    else
                    {
                        while (akhir == 'A' || akhir == 'C')
                        {
                            printf("Masukkan tidak valid!\n");
                            printf("Tiang Tujuan: ");
                            STARTCOMMAND();
                            akhir = toABC(CCommand);
                        }
                        push(&B, TOP(C));
                    }
                }
                else if (akhir == 'B')
                {
                    if (TOP(B) > TOP(C) || isEmpty(B))
                    {
                        push(&B, TOP(C));
                        printf("Memindahkan piringan ke B...\n");
                        step++;
                    }
                    else
                    {
                        while (akhir == 'B' || akhir == 'C')
                        {
                            printf("Masukkan tidak valid!\n");
                            printf("Tiang Tujuan: ");
                            STARTCOMMAND();
                            akhir = toABC(CCommand);
                        }
                        push(&A, TOP(B));
                    }
                }
                pop(&C, &val);
            }
            else
            {
                printf("Masukkan tidak valid!\n");
                continue;
            }
        }

        printf("==============================\n");
        printf("\t  steps : %d\n", step);
        displayTower(A, 'A');
        displayTower(B, 'B');
        displayTower(C, 'C');
    }
    printf("==============================\n");
    printf("\tKamu Berhasil!  \n");
    printf("\t  steps : %d\n", step);
    printf("==============================\n");
    printf("MASUKKAN USERNAME : ");
    STARTCOMMAND();
    data.name = CCommand;
    if (step == 31)
    {
        score = 100;
    }
    else if (step > 31 && step <= 69)
    {
        score = 100 - (step - 31);
    }
    else
    {
        data.score = 0;
        score = 0;
    }
    return score;
}