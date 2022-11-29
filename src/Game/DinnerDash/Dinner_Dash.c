#include "Dinner_Dash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/queue/queue.c"
#include "../../ADT/arraydin/arraydin.c"
#include "../RNG/RNG.c"

int tointeger(char kat)
{
    return (kat - '0');
}

int main()
{
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
    int harga;
    int Durasi;
    int Ketahanan;

    time_t t;
    srand((unsigned)time(0));

    char command[100];
    char command1[100];
    char commm[10];

    // Bikin pesan
    // int j = 0;
    while (pesan.juml <= 7 && pelanggan < 15 && masak.juml <= 5)
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
                printf("M%d \t| %d\t\t\t\n", masak.Din[i].ID, masak.Din[i].Durasi);
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
            for (i = 0; i < (idx_ekor(saji) + 1); i++)
            {
                printf("M%d \t| %d\t\t\t\n", saji.Din[i].ID, saji.Din[i].Ketahanan);
            }
        }

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

                enqdin(&masak, &pesan, m);
                if (saji.juml != IDX_UNDEf)
                {
                    for (int i = 0; i < (idx_ekor(saji) + 1); i++)
                    {
                        saji.Din[i].Ketahanan -= 1;
                        if (saji.Din[i].Ketahanan == 0)
                        {
                            printf("Makanan M%d telah basi\n", saji.Din[i].ID);
                        }
                    }
                }

                for (int i = idx_Kepala(masak); i < (masak.juml - 1); i++)
                {
                    masak.Din[i].Durasi -= 1;
                    if (masak.Din[i].Durasi == 0)
                    {
                        enqdin(&saji, &masak, i);
                    }
                }

                pesan.juml++;
            }
            else if (IsKataSama(toKata(commm), toKata("SERVE")) && IsKataSama(toKata(&command[6]), toKata(&CCommand.TabWord[6])) && IsKataSama(toKata(&command[7]), toKata(&CCommand.TabWord[7])))
            {

                if (saji.juml != IDX_UNDEf)
                {
                    for (int i = 0; i < (idx_ekor(saji) + 1); i++)
                    {
                        saji.Din[i].Ketahanan -= 1;
                        // if (saji.Din[i].Ketahanan == 0)
                        // {
                        //     DelDin(&saji, i);
                        // }
                    }
                }
                for (int i = idx_Kepala(masak); i < (masak.juml - 1); i++)
                {
                    masak.Din[i].Durasi -= 1;
                    if (masak.Din[i].Durasi == 0)
                    {
                        // DelDin(&masak);
                        enqdin(&saji, &masak, (i));
                    }
                }
                if (saji.juml != IDX_UNDEf)
                {
                    for (int i = 0; i < (idx_ekor(saji) + 1); i++)
                    {
                        if (saji.Din[i].ID == n)
                        {
                            // DelDin(&saji, i);
                            printf("Berhasil mengantar M%d ke pelanggan\n", n);
                            saldo += pesan.Din[n].Harga;
                            pelanggan++;
                        }
                    }
                }
                pesan.juml++;
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
                            // DelDin(&saji, i);
                        }
                    }
                }
                for (int i = idx_Kepala(masak); i < (masak.juml - 1); i++)
                {
                    masak.Din[i].Durasi -= 1;
                    if (masak.Din[i].Durasi == 0)
                    {
                        // DelDin(&masak);
                        enqdin(&saji, &masak, (i));
                    }
                }
                pelanggan++;
                pesan.juml++;
            }
            else
            {
                printf("COMMAND TIDAK VALID\n");
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
    return 0;
}