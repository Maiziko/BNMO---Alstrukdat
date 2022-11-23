#include <stdio.h>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/queue/queue.c"
#include "../../ADT/arraydin/arraydin.c"
<<<<<<< HEAD
#include "../RNG/RNG.c"
=======
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8

int random()
{
    srand((unsigned)time(0));
    return (rand() % 100) + 1;
}
<<<<<<< HEAD

=======
char tochar(int a)
{
    return a + '0';
}
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
int tointeger(char kat)
{
    return (kat - '0');
}

<<<<<<< HEAD
void Dinner_Dash()
=======
int main()
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
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
<<<<<<< HEAD
    char commm[10];
    int a = 0;
=======
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8

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
<<<<<<< HEAD
                for (i = 0; i <= memasak2.juml; i++)
                {
                    if (memasak2.Din[i].Durasi == 0)
                    {

                        DelMem(&memasak2, i);
                    }
                }
=======
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
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
<<<<<<< HEAD
=======
            int j = 0;
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
            if (serve.juml != 0)
            {
                for (i; i <= memasak2.juml; i++)
                {
                    if (memasak2.Din[i].Durasi == 0)
                    {
<<<<<<< HEAD
                        serve.Din[i].ID = memasak2.Din[i].ID;
                        serve.Din[i].Ketahanan = memasak2.Din[i].Ketahanan;
                        serve.juml++;
                        // DelMem(&memasak2, i);
=======
                        serve.Din[j].ID = memasak2.Din[i].ID;
                        serve.Din[j].Ketahanan = memasak2.Din[i].Ketahanan;
                        serve.juml++;
                        // DelMem(&memasak2, i);
                        j++;
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
                    }
                    printf("M%d \t| %d\t\t\t\n", memasak2.Din[j].ID, memasak2.Din[i].Durasi);
                }
            }
            else if (serve.juml == 0)
            {
                printf(" \t| \t\t\t\n");
            }
        }
<<<<<<< HEAD
        printf("\n");
        printf("MASUKKAN COMMAND : ");
        STARTCOMMAND();
        int i = 0;
        for (i; i < 8; i++)
=======
        printf("MASUKKAN COMMAND : ");
        STARTCOMMAND();
        int i = 0;
        for (i; i < 7; i++)
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
        {
            command[i] = CCommand.TabWord[i];
        }
        command[i] = '\0';
        for (i = 0; i < 4; i++)
        {
            command1[i] = command[i];
        }
        command1[i] = '\0';

<<<<<<< HEAD
        for (i = 0; i < 5; i++)
        {
            commm[i] = command[i];
        }
        commm[i] = '\0';

        int m = tointeger(command[6]);
        int n = tointeger(command[7]);

        if (IsKataSama(toKata(command1), toKata("COOK")) || IsKataSama(toKata(command1), toKata("SKIP")) || IsKataSama(toKata(commm), toKata("SERVE")))
=======
        int m = tointeger(command[6]);

        if (IsKataSama(toKata(command1), toKata("COOK")) || IsKataSama(toKata(command1), toKata("SKIP")) || IsKataSama(toKata(command1), toKata("SERVE")))
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
        {

            if (IsKataSama(toKata(command1), toKata("COOK")) && IsKataSama(toKata(&command[5]), toKata(&CCommand.TabWord[5])) && IsKataSama(toKata(&command[6]), toKata(&CCommand.TabWord[6])))
            {
<<<<<<< HEAD
                int x = 0;
                for (int i = 0; i < memasak.juml; i++)
                {
                    if (m <= memasak.Din[i].ID && m < memasak.juml && memasak2.juml <= 5)
                    {
                        memasak2.Din[memasak2.juml].ID = memasak.Din[m].ID;
                        memasak2.Din[memasak2.juml].Durasi = memasak.Din[m].Durasi;
                        memasak2.juml++;
                        for (i = 0; i < memasak2.juml; i++)
                        {
                            memasak2.Din[i - 1].Durasi -= 1;
                        }
                        for (i = 0; i < memasak2.juml; i++)
                        {
                            if (memasak2.Din[i].Durasi == 0)
                            {

                                serve.Din[serve.juml].ID = memasak2.Din[i].ID;
                                serve.Din[serve.juml].Ketahanan = memasak2.Din[i].Ketahanan;
                                serve.juml += 1;
                                DelMem(&memasak2, i);
                            }
                        }
                        if (serve.juml != 0)
                        {
                            for (int i = 0; i < serve.juml; i++)
                            {
                                serve.Din[i].Ketahanan -= 1;
                            }
                        }
                        memasak.juml += 1;
                    }
                    if (m >= memasak.juml && m != memasak.Din[i].ID)
                    {
                        x = 1;
                    }
                }
                if (x == 1)
                {
                    printf("Makanan Tidak ada\n");
                    printf("\n");
                }
=======
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
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
            }
            else if (IsKataSama(CCommand, toKata("SKIP")))
            {
                memasak.juml += 1;
<<<<<<< HEAD
                for (i = 0; i < memasak2.juml; i++)
                {
                    memasak2.Din[i].Durasi -= 1;
                }
                for (i = 0; i < memasak2.juml; i++)
                {
                    if (memasak2.Din[i].Durasi == 0)
                    {
                        serve.Din[serve.juml].ID = memasak2.Din[i].ID;
                        serve.Din[serve.juml].Ketahanan = memasak2.Din[i].Ketahanan;
                        serve.juml += 1;
                        DelMem(&memasak2, i);
                    }
                }
                if (serve.juml != 0)
                {
                    for (int i = 0; i < serve.juml; i++)
                    {
                        serve.Din[i].Ketahanan -= 1;
                    }
                }
            }
            else if (IsKataSama(toKata(commm), toKata("SERVE")) && IsKataSama(toKata(&command[6]), toKata(&CCommand.TabWord[6])) && IsKataSama(toKata(&command[7]), toKata(&CCommand.TabWord[7])))
            {
                // if (memasak2. juml <= 5){
                //     for (i = 0; i <= memasak2.juml; i++)
                //     {
                //         memasak2.Din[i].Durasi -= 1;
                //     }
                //     int j = 0;
                //     for (i = 0; i <= memasak2.juml; i++)
                //     {
                //         if (memasak2.Din[i].Durasi == 0)
                //         {

                //             serve.Din[j].ID = memasak2.Din[i].ID;
                //             serve.Din[j].Ketahanan = memasak2.Din[i].Ketahanan;
                //             j += 1;
                //             serve.juml += 1;
                //             DelMem(&memasak2, i);
                //         }
                //     }
                // }
                if (memasak2.juml <= 5)
                {
                    for (i = 0; i <= serve.juml; i++)
                    {
                        if (serve.Din[i].ID == n && memasak2.Din[i].ID == n && memasak2.Din[i].Durasi == 0)
                        {
                            printf("Makanan M%d disajikan\n", n);
                            memasak.juml += 1;
                            DelMem(&serve, i);
                            for (int j = 0; j <= memasak2.juml; j++)
                            {
                                memasak2.Din[j].Durasi -= 1;
                            }
                        }
                        else if (serve.Din[i].ID == n && memasak2.Din[i].ID == n && memasak2.Din[i].Durasi != 0)
                        {
                            printf("Makanan M%d belum matang\n", n);
                        }
                        else if (serve.Din[i].ID == n && memasak2.Din[i].ID != n)
                        {
                            printf("Makanan M%d belum dimasak\n", n);
                        }
                    }
                }
            }
            for (int i = 0; i < memasak.juml; i++)
            {
                if (memasak.juml <= 7 && m <= memasak.Din[i].ID && !IsKataSama(CCommand, toKata("SKIP")))
                {
                    a = 1;
                }
                else if (IsKataSama(CCommand, toKata("SKIP")))
                {
                    a = 0;
                }
            }
            if (a == 1)
            {
                printf("\n");
                printf("Berhasil memasak M%d\n", m);
                printf("================================================================\n");
            }
=======
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
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
        }
        else
        {
            while (!IsKataSama(CCommand, toKata("COOK")) || !IsKataSama(CCommand, toKata("SKIP")) || !IsKataSama(CCommand, toKata("SERVE")))
            {
                printf("Command tidak valid, masukkan command yang valid\n");
                printf("================================================================\n");
<<<<<<< HEAD
                printf("\n");
=======
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
                printf("MASUKKAN COMMAND : ");
                STARTCOMMAND();
            }
        }
    }
<<<<<<< HEAD
    printf("\n");
    printf("================================================================\n");
    printf("Antrian Pesanan Sudah 7 Makanan atau pelanggan yang terlayani sudah lebih sama dengan 15\n");
    printf("================================================================\n");
    printf("Sayang Sekali T_T \n");
}
=======

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
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
