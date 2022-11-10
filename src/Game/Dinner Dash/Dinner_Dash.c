#include <stdio.h>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/queue/queue.c"
#include "../../ADT/arraydin/arraydin.c"

int random()
{
    srand((unsigned)time(0));
    return (rand() % 100) + 1;
}
char tochar(int a)
{
    return a + '0';
}
int tointeger(char kat)
{
    return (kat - '0');
}

int main()
{
    printf("Selamat Datang di Diner Dash!\n");
    memmen memasak;
    CreateMem(&memasak);
    memmen memasak2;
    CreateMem(&memasak2);
    memmen serve;
    CreateMem(&serve);
    Word first;
    ArrayDin comm = MakeArrayDin();
    memasak.juml = 3;
    memasak2.juml = 0;
    serve.juml = 0;
    int COUNT = 0;
    time_t t;
    srand((unsigned)time(&t));
    int durasi;
    int ketahanan;
    int harga;
    char command[100];
    char command1[100];

    printf("\n");
    int saldo = 0;

    while (memasak.juml <= 7)
    {
        printf("SALDO : %d\n", saldo);
        printf("\n");
        printf("Daftar Pesanan\n");
        printf("Makanan\t\t | Durasi memasak\t | Ketahanan\t | Harga\t\n");
        printf("-----------------------------------------------------------------\n");

        int j = 0;
        for (j; j < memasak.juml; j++)
        {
            if (memasak.Din[j].Harga == IDX_UNDEF)
            {
                harga = (rand() % 40 + 10) * 1000;
                memasak.Din[j].Harga = harga;
                durasi = rand() % 5 + 1;
                memasak.Din[j].Durasi = durasi;
                ketahanan = rand() % 5 + 1;
                memasak.Din[j].Ketahanan = ketahanan;
                memasak.Din[j].ID = j;
            }

            printf("M%d \t\t | %d\t\t\t | %d\t\t | %d\t\n", memasak.Din[j].ID, memasak.Din[j].Durasi, memasak.Din[j].Ketahanan, memasak.Din[j].Harga);
        }

        if (memasak2.juml <= 5)
        {
            printf("\n");
            printf("Daftar Makanan yang sedang dimasak\n");
            printf("Makanan\t| Sisa durasi memasak \t\n");
            printf("-----------------------------\n");

            int i = 0;
            if (memasak2.juml != 0)
            {
                while (i < memasak2.juml)
                {
                    if (memasak2.Din[i].Durasi == IDX_UNDEF)
                    {
                        memasak2.Din[i].Durasi = memasak.Din[i].Durasi;
                    }
                    printf("M%d \t| %d\t\t\t\n", memasak2.Din[i].ID, memasak2.Din[i].Durasi);
                    i++;
                }
            }
            else if (memasak2.juml == 0)
            {
                printf(" \t| \t\t\t\n");
            }
        }

        if (COUNT <= 15)
        {
            printf("\n");
            printf("Daftar Makanan yang dapat disajikan\n");
            printf("Makanan\t| Sisa ketahanan makanan \t\n");
            printf("-----------------------------\n");

            int i = 0;
            int j = 0;
            if (serve.juml != 0)
            {
                for (i; i <= memasak2.juml; i++)
                {
                    if (memasak2.Din[i].Durasi == 0)
                    {
                        serve.Din[j].ID = memasak2.Din[i].ID;
                        serve.Din[j].Ketahanan = memasak2.Din[i].Ketahanan;
                        serve.juml++;
                        // DelMem(&memasak2, i);
                        j++;
                    }
                    printf("M%d \t| %d\t\t\t\n", memasak2.Din[j].ID, memasak2.Din[i].Durasi);
                }
            }
            else if (serve.juml == 0)
            {
                printf(" \t| \t\t\t\n");
            }
        }
        printf("MASUKKAN COMMAND : ");
        STARTCOMMAND();
        int i = 0;
        for (i; i < 7; i++)
        {
            command[i] = CCommand.TabWord[i];
        }
        command[i] = '\0';
        for (i = 0; i < 4; i++)
        {
            command1[i] = command[i];
        }
        command1[i] = '\0';

        int m = tointeger(command[6]);

        if (IsKataSama(toKata(command1), toKata("COOK")) || IsKataSama(toKata(command1), toKata("SKIP")) || IsKataSama(toKata(command1), toKata("SERVE")))
        {

            if (IsKataSama(toKata(command1), toKata("COOK")) && IsKataSama(toKata(&command[5]), toKata(&CCommand.TabWord[5])) && IsKataSama(toKata(&command[6]), toKata(&CCommand.TabWord[6])))
            {
                if (m <= memasak.juml && memasak2.juml <= 5)
                {
                    printf("Makanan M%d dimasak\n", m);
                    memasak2.Din[memasak2.juml].ID = memasak.Din[m].ID;
                    memasak2.Din[memasak2.juml].Durasi = memasak.Din[m].Durasi;
                    memasak2.juml++;
                    for (i = 0; i < memasak2.juml; i++)
                    {
                        memasak2.Din[i - 1].Durasi -= 1;
                    }
                    int j = 0;
                    for (i = 0; i <= memasak2.juml; i++)
                    {
                        if (memasak2.Din[i].Durasi == 0)
                        {

                            serve.Din[j].ID = memasak2.Din[i].ID;
                            serve.Din[j].Ketahanan = memasak2.Din[i].Ketahanan;
                            j++;
                        }
                        serve.juml += 1;
                    }
                }
                else
                {
                    printf("Makanan tidak ada\n");
                }
                memasak.juml += 1;
            }
            else if (IsKataSama(CCommand, toKata("SKIP")))
            {
                memasak.juml += 1;
                for (i = 0; i <= memasak2.juml; i++)
                {
                    memasak2.Din[i].Durasi -= 1;
                }
                int j = 0;
                for (i = 0; i <= memasak2.juml; i++)
                {
                    if (memasak2.Din[i].Durasi == 0)
                    {

                        serve.Din[j].ID = memasak2.Din[i].ID;
                        serve.Din[j].Ketahanan = memasak2.Din[i].Ketahanan;
                        j++;
                    }
                    serve.juml += 1;
                }
            }
            else if (IsKataSama(CCommand, toKata("SERVE")) && IsKataSama(toKata(&command[5]), toKata(&CCommand.TabWord[5])) && IsKataSama(toKata(&command[6]), toKata(&CCommand.TabWord[6])))
            {
                COUNT += 1; // jUMLAH PELANGGAN YANG TERLAYANI
                memasak.juml += 1;
            }
            printf("Berhasil memasak M%d\n", m);
            printf("================================================================\n");
        }
        else
        {
            while (!IsKataSama(CCommand, toKata("COOK")) || !IsKataSama(CCommand, toKata("SKIP")) || !IsKataSama(CCommand, toKata("SERVE")))
            {
                printf("Command tidak valid, masukkan command yang valid\n");
                printf("================================================================\n");
                printf("MASUKKAN COMMAND : ");
                STARTCOMMAND();
            }
        }
    }

    return 0;
}
=======
#include "queuev2.h"

int main() {
    int saldo = 0, pelanggan = 0, antrian = 0;
    int cmd;
    Queue pesan, masak, saji;
    CreateQueue(&pesan);
    srand(time(NULL));

    for(int urutan=0; urutan<3; urutan++) {
        CreatePesanan(&pesan, urutan);
    }

    printf("\nSelamat Datang di DINNER DASH\n\n");
    printf("SALDO : %d\n\n", saldo);

    displayPesanan(pesan);
    printf("\n1. COOK\n2. SERVE\n\nMasukkan Perintah : ");
    
    // scanf("&d", cmd);

}
>>>>>>> fc1601a522ff3d98096e8d145598c34ce0d77e31
