#include "Dinner_Dash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/arraydin/arraydin.h"
#include "../RNG/RNG.h"

int tointeger(char kat)
{
    return (kat - '0');
}

int dinerDASH()
{   
    int score = 0;
    printf("\n");
    printf("+========================================================================================+\n");
    printf("|                          SELAMAT DATANG DI GAME Diner DASH <^-^>                       |\n");
    printf("+========================================================================================+\n");
    printf("\n");
    // Ini game Dinner DASH
    printf("UJI KECEPATAN ANDA DALAM MELAYANI PELANGGAN {^-^}.\n");
    printf("\n");

    Dinner_food pesan, masak, saji, temp_masak;
    CreateDinner(&pesan);
    CreateDinner(&masak);
    CreateDinner(&saji);
    CreateDinner(&temp_masak);
    Dinner_Temp temp;
    temp = MakeDinner_Temp();

    int pelanggan = 0;
    int saldo = 0;
    pesan.juml = 3;
    int jlh = 0;
    int i = 0;
    int a = 0;
    int harga, score;
    int Durasi;
    int Ketahanan;
    int count_m = 0;
    int count_s = 0;

    time_t t;
    srand((unsigned)time(0));

    char command[100];
    char command1[100];
    char commm[10];

    // Bikin pesan
    // int j = 0;
    while (pesan.juml < 7 && pelanggan <= 15 && masak.juml <= 5)
    {
        printf("SALDO : %d\n", saldo);
        printf("\n");
        printf("Daftar pesan\n");
        printf("Makanan\t\t | Durasi pesan\t\t | Ketahanan\t | Harga\t\t\n");
        printf("-----------------------------------------------------------------\n");

        for (int i = 0; i < pesan.juml; i++)
        {
            if (pesan.Din[i].Harga == IDX_UNDEf)
            {
                harga = (rand() % 40 + 10) * 1000;
                pesan.Din[i].Harga = harga;
                Durasi = rand() % 5 + 1;
                pesan.Din[i].Durasi = Durasi;
                Ketahanan = rand() % 5 + 1;
                pesan.Din[i].Ketahanan = Ketahanan;
                pesan.Din[i].ID = i;
            }
            printf("M%d \t\t | %d\t\t\t | %d\t\t | %d\t\n", pesan.Din[i].ID, pesan.Din[i].Durasi, pesan.Din[i].Ketahanan, pesan.Din[i].Harga);
        }

        printf("\n");
        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n");
        printf("Makanan\t| Sisa durasi pesan \t\n");
        printf("-----------------------------\n");

        if (masak.juml == IDX_UNDEf)
        {
            printf("\t|\t\t\t\n");
        }
        else
        {
            int i = 0;
            for (i = idx_Kepala(masak); i < masak.juml; i++)
            {
                if (masak.Din[i].Durasi > 0)
                {
                    printf("M%d \t| %d\t\t\t\n", masak.Din[i].ID, masak.Din[i].Durasi);
                }
            }
        }
        printf("\n");
        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan\t| Sisa ketahanan makanan \t\n");
        printf("-----------------------------\n");
        if (saji.juml == IDX_UNDEf)
        {
            printf("\t|\t\t\t\n");
        }

        else
        {
            int i = 0;
            for (i = 0; i < (saji.juml); i++)
            {
                if (saji.Din[i].Ketahanan > 0)
                {
                    printf("M%d \t| %d\t\t\t\n", saji.Din[i].ID, saji.Din[i].Ketahanan);
                }
            }
        }
        printf("\n");
        printf("\n");

        printf("================================================================\n");
        printf("MASUKKAN COMMAND : ");
        STARTCOMMAND();

        int i = 0;

        for (i; i < 8; i++)
        {
            command[i] = CCommand.TabWord[i];
        }
        command[i] = '\0';
        for (i = 0; i < 4; i++)
        {
            command1[i] = command[i];
        }
        command1[i] = '\0';

        for (i = 0; i < 5; i++)
        {
            commm[i] = command[i];
        }
        commm[i] = '\0';

        int m = tointeger(CCommand.TabWord[6]);
        int n = tointeger(CCommand.TabWord[7]);

        if (IsKataSama(toKata(command1), toKata("COOK")) || IsKataSama(toKata(command1), toKata("SKIP")) || IsKataSama(toKata(commm), toKata("SERVE")))
        {
            if (IsKataSama(toKata(command1), toKata("COOK")) && ((command[5]) == (CCommand.TabWord[5])) && tointeger(command[6]) == tointeger(CCommand.TabWord[6]))
            {
                for (int i = 0; i < pesan.juml; i++)
                {
                    if (m == pesan.Din[i].ID)
                    {
                        enqdin(&masak, &pesan, m);
                        for (int i = idx_Kepala(masak); i < (masak.juml - 1); i++)
                        {
                            masak.Din[i].Durasi -= 1;
                            if (masak.Din[i].Durasi == 0)
                            {
                                enqdin(&saji, &masak, i);
                            }
                            else
                            {
                                enqdin(&temp_masak, &masak, i);
                            }
                        }
                        for (int i = 0; i < (saji.juml - 1); i++)
                        {
                            saji.Din[i].Ketahanan--;
                            if (saji.Din[i].Ketahanan == 0)
                            {
                                printf("Makanan M%d telah Basi\n", saji.Din[i].ID);
                                saji.juml -= 1;
                            }
                        }
                        pesan.juml++;
                    }
                }
            }

            else if (IsKataSama(toKata(commm), toKata("SERVE")) && IsKataSama(toKata(&command[6]), toKata(&CCommand.TabWord[6])) && (tointeger(command[7]) == tointeger(CCommand.TabWord[7])))
            {
                for (int j = 0; j < saji.juml; j++)
                {
                    if (n == saji.Din[j].ID && saji.Din[j].Ketahanan != 0)
                    {
                        for (int i = 0; i < masak.juml; i++)
                        {
                            masak.Din[i].Durasi -= 1;
                            if (masak.Din[i].Durasi == 0)
                            {
                                enqdin(&saji, &masak, i);
                            }
                        }
                        if (saji.juml != IDX_UNDEf)
                        {
                            for (int i = 0; i < (saji.juml); i++)
                            {
                                if (saji.Din[i].ID == n && saji.Din[i].Ketahanan > 0)
                                {
                                    if (saji.juml != IDX_UNDEf)
                                    {
                                        for (int i = 0; i < (idx_ekor(saji) + 1); i++)
                                        {
                                            saji.Din[i].Ketahanan -= 1;
                                            if (saji.Din[i].Ketahanan == 0)
                                            {
                                                printf("Makanan M%d telah Basi\n", saji.Din[i].ID);
                                            }
                                        }
                                    }
                                    saji.Din[i].Ketahanan = 0;
                                    saldo += saji.Din[i].Harga;
                                    pelanggan++;
                                    printf("Berhasil mengantar M%d ke pelanggan\n", n);
                                }
                            }
                        }
                        pesan.juml++;
                    }
                }
            }
            else if (IsKataSama(toKata(command1), toKata("SKIP")))
            {
                if (saji.juml != IDX_UNDEf)
                {
                    for (int i = 0; i < (idx_ekor(saji) + 1); i++)
                    {
                        saji.Din[i].Ketahanan -= 1;
                        if (saji.Din[i].Ketahanan == 0)
                        {
                            saji.juml -= 1;
                        }
                    }
                }
                for (int i = idx_Kepala(masak); i < masak.juml; i++)
                {
                    masak.Din[i].Durasi -= 1;
                    if (masak.Din[i].Durasi == 0)
                    {
                        enqdin(&saji, &masak, i);
                    }
                }
                pesan.juml++;
                pelanggan++;
            }
            else
            {
                printf("COMMAND TIDAK VALID\n");
            }
            if (pesan.juml == 7 || pelanggan == 15 || masak.juml == 5)
            {
                printf("\n");
                printf("================================================================\n");
                printf("SAYANG SEKALI ANTRIAN SUDAH PENUH\n");
                score = saldo / 1000;
                printf("SCORE ANDA ADALAH %d \n", score);
                printf("================================================================\n");
                printf("\n");
            }
        }
        while (((!IsKataSama(CCommand, toKata("COOK")) && ((command[5]) != (CCommand.TabWord[5])) && tointeger(command[6]) != tointeger(CCommand.TabWord[6]))))
        {
            printf("Command tidak valid, masukkan command yang valid\n");
            printf("================================================================\n");
            printf("MASUKKAN COMMAND : ");
            STARTCOMMAND();
        }
    }
    return score;
}