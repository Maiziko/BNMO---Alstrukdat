/* *** ******* ******* ******* ******** ******* ******** KELOMPOK 04 ******* ******** *** ******* ******* ******* ******** */
/* 18221007 Nurshafa Qonita */
/* 18221008 Gyan Maiziko */
/* 18221018 Jennifer Grachel A */
/* 18221019 Anindita Putri Paramarta */
/* 18221011 Muhammad Rifky Fahrizain */

/* *** ******* ******* ******* ******** ******* ******** Library yang Digunakan ******* ******** *** ******* ******* ******* ******** */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* *** ******* ******* ******* ******** ******* ******** File Header ******* ******** *** ******* ******* ******* ******** */

<<<<<<< HEAD
#include "src/ADT/mesinkata/mesinkata.h"
#include "src/ADT/mesinkarakter/mesinkarakter.h"
#include "src/ADT/queue/queue.h"
#include "src/ADT/arraydin/arraydin.h"
=======
#include "src/ADT/mesinkata/mesinkata.c"
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/queue/queue.c"
#include "src/ADT/arraydin/arraydin.c"
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8

/* *** ******* ******* ******* ******** ******* ******** Fungsi Pembantu ******* ******** *** ******* ******* ******* ******** */

int random()
{
    time_t t;
    srand((unsigned)time(&t));
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

/* *** ******* ******* ******* ******** ******* ******** Fungsi Utama ******* ******** *** ******* ******* ******* ******** */

void ListGame(ArrayDin file)
{
    int k = 0;
    for (int j = 1; j < file.Neff; j++)
    {
        printf("%d. ", k + j);
        PrintWord(file.A[j]);
        // PrintWord(currentWord);
    }
}

ArrayDin Load(Word kata)
{
    ArrayDin ffile = MakeArrayDin();
    char gm[100];
    char gm1[100];
    char gm2[100];
    char m[100];
    int i = 0;
    int j = 0;
    for (j = 0; j < CCommand.Length; j++)
    {
        gm[j] = CCommand.TabWord[j];
    }
    gm[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        m[j] = CCommand.TabWord[j + 5];
    }

    for (j = 0; j < CCommand.Length; j++)
    {
        gm1[j] = gm[j + 5];
    }
    gm1[j] = '\0';

    for (j = 0; j < 4; j++)
    {
        gm2[j] = CCommand.TabWord[j];
    }
    gm2[j] = '\0';

    if (IsKataSama(toKata(gm2), toKata("LOAD")))
    {
        if (IsKataSama(toKata(gm1), toKata(m)))
        {
            STARTGAME(gm1);
            while (!EndWord)
            {
                for (int j = 0; j < currentWord.Length; j++)
                {
                    ffile.A[i].TabWord[j] = currentWord.TabWord[j];
                }
                ffile.A[i].Length = currentWord.Length;
                ADVWORD();
                i++;
            }
            ffile.Neff = i;
        }
    }
    return (ffile);
}
void RNG()
{
    printf("Selamat datang di game RNG. Uji Keberuntungan anda dengan menebak X.\n");
    int RandAngka = random();
    int hitung = 0;
    printf("Tebakan: ");
    STARTCOMMAND();
    while (toInteger(CCommand) != RandAngka)
    {
        if (toInteger(CCommand) > RandAngka)
        {
            printf("Lebih Kecil\n");
            printf("Tebakan: ");
            STARTCOMMAND();
        }
        else if (toInteger(CCommand) < RandAngka)
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
    printf("\n");
}

void SAVE(ArrayDin file, Word kata)
{
    FILE *fptr;
    char filename[100];
    char filetxt[100];
    char filetxt2[10];
    int i = 0;
    for (i = 0; i < kata.Length; i++)
    {
        filename[i] = kata.TabWord[i];
    }
    filename[i] = '\0';

    for (i = 0; i < kata.Length; i++)
    {
        filetxt[i] = kata.TabWord[i + 5];
    }
    filetxt[i] = '\0';

    for (i = 0; i < 4; i++)
    {
        filetxt2[i] = kata.TabWord[i];
    }
    filetxt2[i] = '\0';
    Word Kata = toKata(filetxt);
    if (IsKataSama(toKata(filetxt2), toKata("SAVE")))
    {
        wordStringCopy(filetxt, Kata);
        fptr = fopen(filetxt, "w");
        for (int i = 0; i < file.Neff; i++)
        {
            for (int j = 0; j < file.A[i].Length; j++)
            {
                fprintf(fptr, "%c", file.A[i].TabWord[j]);
            }
            fprintf(fptr, "\n");
        }
        fprintf(fptr, ".");
    }
    printf("Save file berhasil disimpan.\n");
    fclose(fptr);
}

/* *** ******* ******* ******* ******** ******* ******** Program Utama ******* ******** *** ******* ******* ******* ******** */
int main()
{
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("     BBBBBBBBBBBBBBBBBBBBBBBBBBB          NNNNNNNNNN                 NNNNN          MMMMMMMMM                     MMMMMMMMM          OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("     BBBBBBBBBBBBBBBBBBBBBBBBBBB          NNNNNNNNNNN                NNNNN          MMMMMMMMMM                   MMMMMMMMMM          OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("     BBBBB                BBBBBB          NNNNN  NNNNN               NNNNN          MMMMM MMMMM                 MMMMM MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                BBBBBB          NNNNN   NNNNN              NNNNN          MMMMM  MMMMM               MMMMM  MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                BBBBBB          NNNNN    NNNNN             NNNNN          MMMMM   MMMMM             MMMMM   MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                BBBBBB          NNNNN     NNNNN            NNNNN          MMMMM    MMMMM           MMMMM    MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                BBBBBB          NNNNN      NNNNN           NNNNN          MMMMM     MMMMM         MMMMM     MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                BBBBBB          NNNNN       NNNNN          NNNNN          MMMMM      MMMMM       MMMMM      MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBBBBBBBBBBBBBBBBBBBBBBB           NNNNN        NNNNN         NNNNN          MMMMM       MMMMM     MMMMM       MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBBBBBBBBBBBBBBBBBBBBBB            NNNNN         NNNNN        NNNNN          MMMMM        MMMMM   MMMMM        MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBBBBBBBBBBBBBBBBBBBBBBBB          NNNNN          NNNNN       NNNNN          MMMMM         MMMMM MMMMM         MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                 BBBBBB         NNNNN           NNNNN      NNNNN          MMMMM          MMMMMMMMM          MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                 BBBBBB         NNNNN            NNNNN     NNNNN          MMMMM                             MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                 BBBBBB         NNNNN             NNNNN    NNNNN          MMMMM                             MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                 BBBBBB         NNNNN              NNNNN   NNNNN          MMMMM                             MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                 BBBBBB         NNNNN               NNNNN  NNNNN          MMMMM                             MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBB                 BBBBBB         NNNNN                NNNNN NNNNN          MMMMM                             MMMMM          OOOOO                    OOOOO\n");
    printf("     BBBBBBBBBBBBBBBBBBBBBBBBBBBB         NNNNN                 NNNNNNNNNN          MMMMM                             MMMMM          OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("     BBBBBBBBBBBBBBBBBBBBBBBBBBBB         NNNNN                  NNNNNNNNN          MMMMM                             MMMMM          OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("\n");
    printf("----------------------------- Kelas K3 ---------------------- IF2111 Algoritma dan Struktur Data STI -------------------------- Kelompok 4 ---------------------------\n");
    printf("Silahkan Masukkan COMMAND (START/LOAD) untuk memulai : ");
    STARTCOMMAND();
    printf("\n");

    char *state = CCommand.TabWord;
    char namafile[100];
    char nas[100];
    char nas1[100];
    char kata[100];
    char kata1[100];
    char num[10];
    char nummm[10];
    int l = 0;
    ArrayDin file = MakeArrayDin();
    ArrayDin read = MakeArrayDin();
    Queue Game;
    Word first;
    CreateQueue(&Game);
    int i = 0;
    int j = 0;
    for (j = 0; j < 4; j++)
    {
        nas[j] = CCommand.TabWord[j];
    }
    nas[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        namafile[j] = CCommand.TabWord[j + 5];
    }
    namafile[j] = '\0';
    for (j = 0; j < CCommand.Length; j++)
    {
        nas1[j] = CCommand.TabWord[j + 5];
    }
    nas1[j] = '\0';
    while ((!IsKataSama(toKata(nas), toKata("LOAD")) && !IsKataSama(CCommand, toKata("START"))))
    {
        printf("Inputan Tidak Valid! \n");
        printf("(START/LOAD namafile.txt) : ");
        STARTCOMMAND();
        printf("\n");
    }

    if ((IsKataSama(toKata(nas), toKata("LOAD"))))
    {
        if (IsKataSama(toKata(namafile), toKata(nas1)))
        {
            file = Load(CCommand);
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
            printf("\n");
        }
    }

    else if (IsKataSama(CCommand, toKata("START")))
    {
        int i = 0;
        STARTGAME("config.txt");
        while (!EndWord)
        {
            for (int j = 0; j < currentWord.Length; j++)
            {
                file.A[i].TabWord[j] = currentWord.TabWord[j];
            }
            file.A[i].Length = currentWord.Length;
            ADVWORD();
            i++;
        }
        file.Neff = i;
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        printf("\n");
    }

    while (!IsKataSama(CCommand, toKata("QUIT")))
    {
        printf("Masukkan COMMAND \n");
        printf("ENTER COMMAND: ");
        STARTCOMMAND();
        for (i = 0; i < CCommand.Length; i++)
        {
            kata1[i] = CCommand.TabWord[i];
        }
        kata1[i] = '\0';

        for (i = 0; i < 8; i++)
        {
            num[i] = kata1[i];
        }
        num[i] = '\0';

        for (i = 0; i < 1; i++)
        {
            nummm[i] = kata1[i + 9];
        }
        nummm[i] = '\0';
        for (j = 0; j < 4; j++)
        {
            nas[j] = CCommand.TabWord[j];
        }
        nas[j] = '\0';

        for (j = 0; j < CCommand.Length; j++)
        {
            namafile[j] = CCommand.TabWord[j + 5];
        }
        namafile[j] = '\0';
        for (j = 0; j < CCommand.Length; j++)
        {
            nas1[j] = CCommand.TabWord[j + 5];
        }
        nas1[j] = '\0';

        if (IsKataSama(CCommand, toKata("LIST GAME")))
        {
            printf("Berikut adalah daftar game yang tersedia\n");
            ListGame(file);
            printf("\n");
        }
        else if (IsKataSama(CCommand, toKata("DELETE GAME")))
        {
            ListGame(file);
            printf("Masukkan nomor game yang akan dihapus: ");
            STARTCOMMAND();
            int k = toInteger(CCommand);
            if (k < file.Neff)
            {

                if (k >= 6)
                {
                    DeleteAt(&file, k);
                    printf("Game Berhasil Dihapus\n");
                    printf("\n");
                }
                else
                {
                    printf("Game Gagal Dihapus\n");
                    printf("\n");
                }
            }
        }
        else if (IsKataSama(CCommand, toKata("CREATE GAME")))
        {
            printf("Masukkan nama game yang akan ditambahkan:");
            STARTCOMMAND();
            InsertLast(&file, CCommand);
            printf("Game Berhasil Ditambahkan\n");
            printf("\n");
        }
        else if (IsKataSama(CCommand, toKata("QUEUE GAME")))
        {
            printf("Berikut adalah daftar antrian game-mu\n");
            printf("\n");
            if (Game.idxHead == IDX_UNDEF)
            {
                printf("Antrian kosong\n");
            }
            else
            {
                for (int i = Game.idxHead; i < Game.idxTail + 1; i++)
                {
                    printf("%d. ", i + 1);
                    PrintWord(Game.buffer[i]);
                }
            }

            printf("\n");
            printf("Berikut adalah daftar game yang tersedia\n");
            printf("\n");
            ListGame(file);
            printf("\n");
            printf("Nomor game yang mau ditambahkan ke antrian: ");
            STARTCOMMAND();
            int m = toInteger(CCommand);
            int n = file.Neff;
            if (m < file.Neff && m != 0)
            {

                enqueue(&Game, file.A[m]);

                printf("Game Berhasil Ditambahkan ke dalam daftar antrian\n");
                printf("\n");
            }
            else if (m >= file.Neff || m <= 0)
            {
                printf("Nomor permainan tidak valid, Silahkan masukkan nomor game pada list\n");
                printf("\n");
            }
        }
        else if (IsKataSama(CCommand, toKata("PLAY GAME")))
        {
            printf("Berikut adalah daftar antrian Game-mu\n");
            if (Game.idxHead == IDX_UNDEF)
            {
                printf("Antrian kosong\n");
            }
            else
            {
                if (Game.idxHead != IDX_UNDEF)
                {
                    for (int i = Game.idxHead; i < Game.idxTail + 1; i++)
                    {
                        printf("%d. ", i + 1);
                        PrintWord(Game.buffer[i]);
                    }
                }
            }
            wordStringCopy(kata, Game.buffer[Game.idxHead]);
<<<<<<< HEAD

=======
            printf("%s\n", kata);
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
            if (IsKataSama(toKata(kata), toKata("RNG")))
            {
                printf("Loading %s ...", kata);
                printf("\n");
                RNG();
            }
<<<<<<< HEAD
            else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Diner DASH")))
=======
            else if (IsKataSama(toKata(kata), toKata("Diner DASH")))
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
            {
                printf("Loading %s ...", kata);
                printf("\n");
                printf("\n");
                // Ini game Dinner DASH
                printf("Selamat datang di game Diner DASH. Uji kecepatan anda dalam melayani pelanggan.\n");
            }
<<<<<<< HEAD
            else if (!IsKataSama(Game.buffer[Game.idxHead], toKata("Diner DASH")) && !IsKataSama(toKata(kata), toKata("RNG")) && Game.idxHead != IDX_UNDEF)
=======
            else if (!IsKataSama(toKata(kata), toKata("Diner DASH")) && !IsKataSama(toKata(kata), toKata("RNG")) && Game.idxHead != IDX_UNDEF)
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
            {

                char karak[100];
                wordStringCopy(karak, Game.buffer[Game.idxHead]);
                printf("Game %s masih dalam maintenace, belum dapat dimainkan.", karak);
                printf("\n");
            }
            dequeuee(&Game, &(Game.buffer[Game.idxHead]));
        }

        else if (IsKataSama(toKata(num), toKata("SKIPGAME")) && (toInteger(toKata(nummm)) == toInteger(toKata(&kata1[9]))))
        {

            int i = 0;
            int skip = toInteger(toKata(nummm));
            printf("\n");
            printf("Berikut adalah daftar Game-mu\n");
            printf("\n");
            for (i = 0; i < Game.idxTail + 1; i++)
            {
                printf("%d. ", i + 1);
                PrintWord(Game.buffer[i]);
            }
            printf("\n");
            if (skip < (Game.idxTail + 1) && !isEmpty(Game))
            {
                for (i = Game.idxHead; i < skip; i++)
                {
                    dequeuee(&Game, &(Game.buffer[i - 1]));
                }
            }

<<<<<<< HEAD
            else if (skip > Game.idxTail || Game.idxHead == IDX_UNDEF)
            {
                printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
                if (!isEmpty(Game))
                {
                    for (i = Game.idxHead; i < Game.idxTail + 1; i++)
                    {
                        dequeuee(&Game, &(Game.buffer[i - 1]));
                    }
                }
=======
            else if (skip > Game.idxTail || isEmpty(Game))
            {
                printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
                printf("\n");
            }

            if (IsKataSama(Game.buffer[Game.idxHead], toKata("RNG")) && !isEmpty(Game))
            {
                wordStringCopy(kata, Game.buffer[Game.idxHead]);
                printf("Loading %s ...", kata);
                printf("\n");
                RNG();
            }
            else if (IsKataSama((Game.buffer[Game.idxHead]), toKata("Diner DASH")) && !isEmpty(Game))
            {
                wordStringCopy(kata, Game.buffer[Game.idxHead]);
                printf("Loading %s ...", kata);
                printf("\n");
                printf("\n");
                // Ini game Dinner DASH
                printf("Selamat datang di game Diner DASH. Uji kecepatan anda dalam melayani pelanggan.\n");
            }
<<<<<<< HEAD
            else if (!IsKataSama((Game.buffer[Game.idxHead]), toKata("RNG")) && !IsKataSama((Game.buffer[Game.idxHead]), toKata("Diner DASH")) && Game.idxHead != IDX_UNDEF)
=======
            else if (!IsKataSama((Game.buffer[Game.idxHead]), toKata("RNG")) && !IsKataSama((Game.buffer[Game.idxHead]), toKata("Diner DASH")) || !isEmpty(Game))
>>>>>>> 52991f5ae262ead82e97899e2a2094c85b0917e8
            {
                char karak[100];
                wordStringCopy(karak, Game.buffer[Game.idxHead]);
                printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", karak);
                printf("\n");
            }
            dequeuee(&Game, &(Game.buffer[Game.idxHead]));
        }
        else if (IsKataSama(CCommand, toKata("HELP")))
        {
            printf("Berikut adalah daftar perintah yang tersedia:\n");
            printf("1. START - Masukkan COMMAND : 'START' saat BNMO mulai berjalan\n");
            printf("2. LOAD <filename>.txt - Masukkan COMMAND : LOAD + <filename>.txt saat BNMO mulai berjalan, jika tidak masukkan COMMAND: START\n");
            printf("3. SAVE <filename>.txt - Masukkan COMMAND : 'LIST GAME' untuk melihat daftar game yang tersedia\n");
            printf("4. LIST GAME - Masukkan COMMAND : LIST GAME jika ingin melihat list game yang tersedia pada sistem\n");
            printf("5. DELETE GAME - Masukkan COMMAND : DELETE GAME jika ingin menghapus Game buatan\n");
            printf("6. CREATE GAME - Masukkan COMMAND : CREATE GAME jika ingin membuat sebuah game baru\n");
            printf("7. QUEUE GAME - Masukkan COMMAND : QUEUE GAME jika ingin melihat antrian game yang bisa dimainkan\n");
            printf("8. PLAY GAME - Masukkan COMMAND : PLAY GAME jika ingin memainkan sebuah permainan (RNG/Diner Dash/Lainya)\n");
            printf("9. SKIPGAME <n> - Masukkan COMMAND : SKIPGAME <n>  jika ingin berpindah pada <n> game berikutnya\n");
            printf("10. HELP - Jika Tidak tahu COMMAND yang sesuai\n");
            printf("11. QUIT - Jika Ingin Keluar dari mesin BNMO\n");
            printf("\n");
        }
        else if ((IsKataSama(toKata(nas), toKata("SAVE"))))
        {
            if (IsKataSama(toKata(namafile), toKata(nas1)))
            {
                SAVE(file, CCommand);
            }
        }
        else if (!IsKataSama(CCommand, toKata("QUIT")))
        {
            printf("Inputan Tidak Valid!\n");
            printf("\n");
        }
    }
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...");
}